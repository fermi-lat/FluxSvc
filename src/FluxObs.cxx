/** @file FluxObs.cxx 
   @brief Implementation file for FluxSvc

gets adresses 
 of CLHEP random number engines used in Gleam shared libraries
 and sets seeds for them based on run and particle sequence
 number obtained from the MCHeader

 $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/Attic/FluxObs.cxx,v 1.1.2.1 2010/09/02 15:02:58 heather Exp $

 Author: Toby Burnett, Karl Young
*/

#include "FluxObs.h"
#include "facilities/Util.h"

#include <iterator>
#include <fstream>
#include "GaudiKernel/Incident.h"
#include "GaudiKernel/IIncidentSvc.h"
#include "GaudiKernel/SvcFactory.h"
#include "GaudiKernel/MsgStream.h"
#include "GaudiKernel/DataStoreItem.h"
#include "GaudiKernel/IDataProviderSvc.h"
#include "GaudiKernel/IDataManagerSvc.h"
#include "GaudiKernel/SmartDataPtr.h"


FluxObs::FluxObs():IToolSvc::Observer(), m_fluxSvc(0)
{
   
}


void FluxObs::onCreate(IAlgTool& tool) {

    IRegisterSource* ireg;
    StatusCode status =tool.queryInterface( IRegisterSource::interfaceID(), (void**)&ireg);
    if( status.isSuccess() ){
        ireg->registerMe(m_fluxSvc);
    }


}



FluxObs::~FluxObs () 
{
    // Purpose and Method: finish up, delete the list of engines
    //
    // Inputs:  none
    // Outputs: none
    // Dependencies: None
    // Restrictions and Caveats:  None

}


