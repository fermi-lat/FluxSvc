// $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/FluxSvc/FluxSvc.h,v 1.1.1.1 2001/01/04 01:03:32 burnett Exp $
// 
//  Original author: Toby Burnett tburnett@u.washington.edu

#ifndef _H_FluxSvc_
#define _H_FluxSvc_

// includes
#include "Gaudi/Kernel/Service.h"
#include "FluxSvc/IFluxSvc.h"
#include <list>

//forward declarations
template <class TYPE> class SvcFactory;
class IFlux;  // interface
class FluxMgr;  // actual manager

/*! Service that implements the IFluxSvc interface, to return an IFlux object  
*/
class FluxSvc : virtual public Service, virtual public IFluxSvc
{  
public:

    /// return pointer to a flux object
    StatusCode source(std::string name, IFlux*&);

    /// return a list of possible names
    std::list<std::string> fluxNames()const;

    //------------------------------------------------------------------
    //  stuff required by a Service
    
    /// perform initializations for this service. 
    virtual StatusCode initialize ();
    
    /// 
    virtual StatusCode finalize ();
 
protected: 

    /// Standard Constructor
    FluxSvc ( const std::string& name, ISvcLocator* al );
    
    /// destructor
    virtual ~FluxSvc ();

private:
    // Allow SvcFactory to instantiate the service.
    friend class SvcFactory<FluxSvc>;

    FluxMgr * m_fluxMgr;
};


#endif // _H_FluxSvc