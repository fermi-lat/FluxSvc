// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/test/FluxTestAlg.cxx,v 1.1.1.1 2001/01/04 01:03:32 burnett Exp $

// Include files
#include "FluxSvc/IFluxSvc.h"
#include "FluxSvc/IFlux.h"

#include "Gaudi/MessageSvc/MsgStream.h"
#include "Gaudi/Kernel/AlgFactory.h"
#include "Gaudi/Algorithm/Algorithm.h"

/*! \class FluxTestAlg
\brief 

  */

class FluxTestAlg : public Algorithm {

public:
  //! Constructor of this form must be provided
  FluxTestAlg(const std::string& name, ISvcLocator* pSvcLocator); 

  StatusCode initialize();
  StatusCode execute();
  StatusCode finalize();

private:
    IFlux* m_flux;
};


static const AlgFactory<FluxTestAlg>  Factory;
const IAlgFactory& FluxTestAlgFactory = Factory;

void WARNING (const char * text ){  std::cerr << "WARNING: " << text << '\n';}
void FATAL(const char* s){std::cerr << "\nERROR: "<< s;}


//------------------------------------------------------------------------------
//
FluxTestAlg::FluxTestAlg(const std::string& name, ISvcLocator* pSvcLocator) :
Algorithm(name, pSvcLocator){
 
}


//------------------------------------------------------------------------------
/*! */
StatusCode FluxTestAlg::initialize() {
    
    MsgStream log(msgSvc(), name());
    log << MSG::INFO << "initializing..." << endreq;
    
    // Use the Job options service to set the Algorithm's parameters
    setProperties();

    // get the pointer to the flux Service 
    IFluxSvc* fsvc;

    // get the service
    StatusCode sc = service("FluxSvc", fsvc);
    
    if( sc.isFailure()) {
        log << MSG::ERROR << "Could not find FluxSvc" << endreq;
        return sc;
    }
    log << MSG::INFO << "loading source..." << endreq;


    sc =  fsvc->source("default", m_flux);
    if( sc.isFailure()) {
        log << MSG::ERROR << "Could not find flux" << "default" << endreq;
        return sc;
    }

    log << MSG::INFO << "Source title: " << m_flux->title() << endreq;
    log << MSG::INFO << "       area: " << m_flux->targetArea() << endreq;
    log << MSG::INFO << "       rate: " << m_flux->rate() << endreq;


    return sc;
}


//------------------------------------------------------------------------------
StatusCode FluxTestAlg::execute() {
    
    StatusCode  sc = StatusCode::SUCCESS;
    MsgStream   log( msgSvc(), name() );

    m_flux->generate();
    HepPoint3D p = m_flux->launchPoint();
    HepPoint3D d = m_flux->launchDir();
    
    log << MSG::INFO << m_flux->particleName()
        << "(" << m_flux->energy()
        << " GeV), Launch: " 
        << "(" << p.x() <<", "<< p.y() <<", "<<p.z()<<")" 
        << " Dir " 
        << "(" << d.x() <<", "<< d.y() <<", "<<d.z()<<")" 
        << endreq;


    return sc;
}


//------------------------------------------------------------------------------
StatusCode FluxTestAlg::finalize() {
    
    return StatusCode::SUCCESS;
}





