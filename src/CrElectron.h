//$Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/CrElectron.h,v 1.3 2002/01/18 11:22:04 srobinsn Exp $

#ifndef CrElectron_H
#define CrElectron_H


#include <vector>
#include <utility>
#include "FluxSvc/Spectrum.h"

class CrSpectrum;
//! The class that calls each cosmic-ray electron components based on
//!    their flux.
class CrElectron : public Spectrum
{
public:
  CrElectron(const std::string& params);
  ~CrElectron();

  CrSpectrum* selectComponent(HepRandomEngine* engine);

  virtual double energySrc(HepRandomEngine* engine);
  virtual std::pair<double,double> dir(double energy, HepRandomEngine* engine);

  CrSpectrum* component() const;

  //! calculate the flux, particles/m^2/sr.
  virtual double    flux (double time ) const;

  virtual const char * particleName()const{ return "e-";}
  virtual std::string title()const{return "CrElectron";}
  virtual double solidAngle( )const;

private:
  std::vector<CrSpectrum*>  m_subComponents;
  CrSpectrum*               m_component;
};
#endif // CrElectron_H

