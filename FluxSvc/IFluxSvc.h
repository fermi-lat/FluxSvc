// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/FluxSvc/IFluxSvc.h,v 1.4 2001/07/07 01:27:09 burnett Exp $
// 
//!  \author: T. Burnett
//

#ifndef _H_IFluxSvc
#define _H_IFluxSvc

// includes
#include "GaudiKernel/IInterface.h"
#include <string>
#include <list>
#include "flux/SpectrumFactoryTable.h"

// Declaration of the interface ID ( interface id, major version, minor version) 
static const InterfaceID IID_IFluxSvc(910, 1 , 0); 

// forward declarations
class IFlux;
class HepRandomEngine;

/** Abstract interface for the flux service

  */
class  IFluxSvc : virtual public IInterface {
public:

    /// just set an IFlux object by name
    virtual  StatusCode source(std::string name, IFlux*&)=0;
    
    /// return a list of legal names
    virtual std::list<std::string> fluxNames()const=0;

        /// Retrieve interface ID
    static const InterfaceID& interfaceID() { return IID_IFluxSvc; }

    /// add a new source
    virtual void addFactory(std::string name, const ISpectrumFactory* factory )=0;


	/// access to the local random engine (testing)
	virtual HepRandomEngine* getEngine()=0;
};

#endif  // _H_IFluxSvc
