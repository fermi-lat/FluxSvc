// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/FluxSvc/IFluxSvc.h,v 1.2 2001/04/19 02:11:34 burnett Exp $
// 
//!  \author: T. Burnett
//

#ifndef _H_IFluxSvc
#define _H_IFluxSvc

// includes
#include "GaudiKernel/IInterface.h"
#include <string>
#include <list>

// Declaration of the interface ID ( interface id, major version, minor version) 
static const InterfaceID IID_IFluxSvc(910, 1 , 0); 

// forward declarations
class IFlux;

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


};

#endif  // _H_IFluxSvc
