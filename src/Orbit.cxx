// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/Orbit.cxx,v 1.11 2002/07/25 05:18:59 srobinsn Exp $

#include "Orbit.h"

#include "CLHEP/Random/RandFlat.h"
#include "GPS.h"

#include <cmath>
#include <cassert>
#include "CLHEP/Vector/Rotation.h"

Orbit::Orbit(double asclon, double alt, double inc, double phs
             , double pitch , double yaw, double roll) :
// constructor
m_ascendingLon(asclon),
m_altitude(alt),
m_period(1.6612e-4 * pow(alt+6371.2, 1.5)),// Kepler's Law
m_startphase(phs),
m_precessPeriod(66.*24.*60.),
m_degsPerRad(360./6.2831853),
m_secsperday(24.*60.*60.)

{
    inclination( inc );
    
}

void	Orbit::inclination ( double inc )
{
    m_inclination = inc;
    m_sini = (sin(m_inclination*M_2PI/360.));
    m_cosi = (cos(m_inclination*M_2PI/360.));
}

void	Orbit::ascendingLon ( double asc )
{
    m_ascendingLon = asc;
}

void    Orbit::startphase ( double phs )
{
    m_startphase = phs;
}

double Orbit::latitude(double timeInSeconds) const {
    double time = timeInSeconds/60.;
    // Purpose:  Return the latitude as a function of time (in minutes)
    // Input:  the current time
    return (360./M_2PI) * asin(m_sini * sin(M_2PI*time/m_period + startphase()));
}

double Orbit::longitude(double timeInSeconds) const {
    double time = timeInSeconds/60.;
    // Purpose:  Return the longitude as a function of time, taking into account the starting
    // longitude and the eastward rotation of the earth
    // Input:  current time
    double phase = M_2PI * time / m_period + startphase();
    double lon = (360./M_2PI) * atan2(m_cosi*sin(phase), cos(phase)) -
        360.* time /1440. + m_ascendingLon; // orbital motion - earth rotation
    lon = fmod(lon, 360.);   // Fold into the range [0, 360)
    if (lon < 0.) lon += 360.;
    return lon;
}

double Orbit::pitch (double timeInSeconds) const {
    double time = timeInSeconds/60.;
    return 0.;
}

double Orbit::yaw (double timeInSeconds) const {
    double time = timeInSeconds/60.;
    return 0.;
}

double Orbit::roll (double timeInSeconds) const {
    double time = timeInSeconds/60.;
    return 0.;
}

double Orbit::phase (double timeInSeconds) const {
    double time = timeInSeconds/60.;
    double p = period();
    return (p == 0) ? 0. : (time/p) * 2*M_PI + startphase();
}

std::pair<double,double> Orbit::coords(double timeInSeconds) const {
    return std::make_pair(latitude(timeInSeconds), longitude(timeInSeconds));
}

Rotation Orbit::CELTransform(double timeInSeconds){
    double time = timeInSeconds/60.;
    // Purpose:  Return the 3x3 matrix which transforms a vector from a galactic 
    // coordinate system to a local coordinate system.
    
    //THIS IS THE PART WHERE WE MAKE THE MATRIX CEL INTO SOMETHING WE CAN USE
    Rotation gal,cel,cel1,cel2,cel3,cel4;
    
    //the x axis must eventually be rotated so that it points east, instead of along
    //the direction of orbital travel
    double makeXeast = (m_inclination/m_degsPerRad)*cos(phase(timeInSeconds));
    
    //and here we construct the rotation matrices
    
    //gal is the matrix which rotates (cartesian)celestial coordiantes into (cartesian)galactic ones
    gal.rotateZ(-282.25/m_degsPerRad).rotateX(-62.6/m_degsPerRad).rotateZ(33./m_degsPerRad);
    
    //cel is the matrix which rotates (cartesian)local coordinates into (cartesian)celestial ones
    cel1.rotateZ(makeXeast);
    cel2.rotateY(phase(timeInSeconds));
    cel3.rotateZ(-m_inclination*M_2PI/360.);
    cel4.rotateY((time/m_precessPeriod)*M_2PI);
    
    //so gal*cel should be the matrix that makes local coordiates into galactic ones.
    Rotation glstToGal = gal*cel4*cel3*cel2*cel1;
    
    //displayRotation(glstToGal);
    
    //we want the rotation from galactic to local.
    return glstToGal.inverse();
}



void Orbit::computeAttitudes(double timeInSeconds){
    double time = timeInSeconds/60.;
    // Purpose: computation of pointing characteristics of GLAST - assumed, here, to be zenith-pointing
    
    //lat, lon, sidereal??? time becomes J2000.0 coordinates here:
    m_raz=((time/(24.0*60.0*60.0))*360.0)+longitude(timeInSeconds);  //need to take into account starting phase too!
    if(m_raz > 360.0) m_raz-=360.0;
    if(m_raz < 0.0 ) m_raz+=360.0;
    m_decz=latitude(timeInSeconds);
    //and then the eastward-pointing x-axis should have 90 degrees more ascension, and declination=0
    m_rax=m_raz-90.0;
    if(m_rax > 360.0) m_rax-=360.0;
    if(m_rax < 0.0 ) m_rax+=360.0;
    m_decx=0.;
}


//NEEDS TO BE CHECKED, since CELTransform has changed.
Rotation Orbit::latLonTransform(double timeInSeconds) const {
    double time = timeInSeconds/60.;
    Rotation CELtoLOC;  
    
    CELtoLOC.rotateZ(phase(timeInSeconds)).rotateX(m_inclination*M_2PI/360.).rotateZ((timeInSeconds/m_precessPeriod)*M_2PI);
    Rotation getLatLon=(CELtoLOC).rotateZ(((m_ascendingLon/360.)+((time)/1440.))*M_2PI*-1.);
    
    return getLatLon;
}

//NEEDS TO BE CHECKED
double Orbit::testLongitude(double timeInSeconds) const {
    double time = timeInSeconds/60.;
    // longitude as a function of time (in minutes)
    Vector v(1.,0,0);
    v=latLonTransform(time)*v;
    double lon = (360./M_2PI) * atan(v[1]/v[0]);
    lon = fmod(lon, 360.);   // Fold into the range [0, 360)
    if (lon < 0.) lon += 360.;
    return lon;
}

//NEEDS FIXING
double Orbit::testLatitude(double timeInSeconds) const {
    // latitude as a function of time (in minutes)
    Vector v(1.,0,0);
    v=latLonTransform(timeInSeconds)*v;
    return (360./M_2PI) * atan(v[2]/sqrt(pow(v[0],2)+pow(v[1],2)));
}



void Orbit::displayRotation(Rotation rot){
    
    std::cout << "{" << rot.xx() << ' ' << rot.xy() << ' ' << rot.xz() << std::endl
        << rot.yx() << ' ' << rot.yy() << ' ' << rot.yz() << std::endl
        << rot.zx() << ' ' << rot.zy() << ' ' << rot.zz() << "}" << std::endl;
}