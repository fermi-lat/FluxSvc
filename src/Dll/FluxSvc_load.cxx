/** 
* @file FluxSvc_load.cpp
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/GlastSvc/src/Dll/GlastSvc_load.cpp,v 1.22 2003/02/14 21:02:39 usher Exp $
*/
#include "GaudiKernel/DeclareFactoryEntries.h"


DECLARE_FACTORY_ENTRIES(FluxSvc) {
    DECLARE_SERVICE( FluxSvc );
    DECLARE_ALGORITHM( FluxAlg );
    DECLARE_ALGORITHM( ExposureAlg );
    DECLARE_TOOL( FluxSvcRandom );
}

