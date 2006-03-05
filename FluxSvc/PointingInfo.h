/** @file PointingInfo.h
// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/FluxSvc/PointingInfo.h,v 1.5 2005/12/09 17:20:05 mcenery Exp $
*/

#ifndef PointingInfo_h
#define PointingInfo_h

#include <string>

class INTupleWriterSvc;
namespace Event { class Exposure;} 

/** @class PointingInfo
Manage the data in the FT2 definition

 the root tuple, a la FT2
 http://glast.gsfc.nasa.gov/ssc/dev/fits_def/definitionFT2.html
*/

class PointingInfo {
public:
    PointingInfo(){}

    //!@brief  associate it with the the FT2 tuple
    void setFT2Tuple(INTupleWriterSvc* tuple, const std::string& tname);

    //!@brief  associate it with the the Pt part of the "merit" tuple
    void setPtTuple(INTupleWriterSvc* tuple, const std::string& tname);

    //! fill the pointing info for the given start time, set SAA status for the interval
    void set(double start_time, bool insideSAA);

    //! finish it. 
    void finish(double stop_time, double live);

    //! accessor for time
    double start_time()const{return start;}

    // return TDS object for old scheme
    Event::Exposure* forTDS()const;
//private:
    double start, stop;
    float sc_position[3];
    float lat_geo, lon_geo;
    float lat_mag;
    float rad_geo;
    float ra_zenith, dec_zenith;
    float ra_scz, dec_scz;
    float ra_scx, dec_scx;
    float in_saa;
    float livetime;
    float L; ///< McIllwain L parameter
    float B; ///< magnetic field

};

#endif 