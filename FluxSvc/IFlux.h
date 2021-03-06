// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/FluxSvc/IFlux.h,v 1.32 2006/12/22 20:36:02 burnett Exp $

#ifndef _H_IFlux_
#define _H_IFlux_

// includes
#include <string>
#include "CLHEP/Vector/Rotation.h"
#include "CLHEP/Vector/ThreeVector.h"

class ParticleProperty;
class EventSource;

class ISpectrumFactory;

/** 
* \class IFlux
* \brief The virtual interface for Flux-type objects.
*
* \author Toby Burnett tburnett@u.washington.edu
* 
  Abstract interface for an object that generates particles, Flux

  * $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/FluxSvc/IFlux.h,v 1.32 2006/12/22 20:36:02 burnett Exp $
*/
class IFlux {
public:
    /// ctor, select the name
    IFlux(std::string =""){};
    virtual ~IFlux(){}
    
    /// name of the flux
    virtual std::string name()const=0;
    
    /// full title of the flux
    virtual std::string title()const = 0;
    
    /// generate a new entry trajectory
    virtual void generate()=0;
    
    /// the particle name of the last particle generated 
    virtual std::string particleName()const=0;
    
    /// the particle property entry for the last particle generated 
    //virtual ParticleProperty* property()const=0;
    
    /// its kinetic energy
    virtual double energy()const=0;
    
    /// starting point 
    virtual CLHEP::Hep3Vector launchPoint()const=0;
    
    /// direction
    virtual CLHEP::Hep3Vector launchDir()const=0;
    
    /// time (s) (absolute or elapsed??)
    virtual double time()const=0;
    
    /// return rate ( /mm**2 /s)
    virtual double rate()const=0;
    
    /// set the area of the target
    virtual void setTargetArea( double area)=0;
    
    /// get the target area
    virtual double targetArea()const =0;
    
    /// find which spectrum created the current particle
    virtual std::string findSource()const=0;
    
    /// return a unique number correcponding to that spectrum
    virtual int numSource()const=0;
    
    /// pass a specific amount of time
    virtual void pass ( double t)=0;
    
    ///get the transformation matrix due to orientation of the Galaxy 
    virtual CLHEP::HepRotation CELTransform(double time)const=0;
    
    ///get the transformation matrix due to orientation of the spacecraft.
    virtual CLHEP::HepRotation orientTransform(double time)const=0;
    
    virtual void addFactory(std::string name, const ISpectrumFactory* factory )=0;
    
    virtual /*int*/double gpsTime()const=0;
    
    ///this transforms glast-local (cartesian) vectors into galactic (cartesian) vectors
    virtual CLHEP::HepRotation transformGlastToGalactic(double time)const=0;
    
    virtual EventSource* currentEvent()=0;
    virtual EventSource* currentFlux()=0;

    /// write the characteristics of the current source distribution to a stream
    virtual void writeSourceCharacteristic(std::ostream& out)=0;

    //get the transformtation matrix - the rest of these functions are now deprecated
    virtual CLHEP::HepRotation transformToGlast(double seconds,int  index)const=0;

};


#endif // _H_FluxSvc
