/** 
* @file SpectrumFactoryLoader.cxx
* @brief Load the external spectrum factory objects
*
*  $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/SpectrumFactoryLoader.cxx,v 1.1 2005/04/26 17:24:12 burnett Exp $
*/

#include "SpectrumFactoryLoader.h"
#include "flux/ISpectrumFactory.h"

// declare the external factories.
ISpectrumFactory & GRBmanagerFactory();
ISpectrumFactory & GRBobsFactory();
ISpectrumFactory & IsotropicFactory();
ISpectrumFactory & PulsarSpectrumFactory();


SpectrumFactoryLoader::SpectrumFactoryLoader()
{
    ISpectrumFactory& f =GRBmanagerFactory();
    m_names.push_back(f.name());
    f=GRBobsFactory();
    m_names.push_back(f.name());
}
