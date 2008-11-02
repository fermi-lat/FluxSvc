/** 
* @file FluxSvc_load.cpp
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/Dll/FluxSvc_load.cxx,v 1.16 2008/05/15 20:14:25 usher Exp $
*/
#include "GaudiKernel/DeclareFactoryEntries.h"


DECLARE_FACTORY_ENTRIES(FluxSvc) {
    DECLARE_SERVICE( FluxSvc );
    DECLARE_SERVICE( OrbitSvc );
    DECLARE_ALGORITHM( FluxAlg );
    DECLARE_ALGORITHM( ExposureAlg );
    DECLARE_ALGORITHM( PointInfoAlg );
    DECLARE_TOOL( FluxSvcRandom );
}

