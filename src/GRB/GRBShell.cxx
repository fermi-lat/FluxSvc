///
///    GRBShell: Class that describes the a Shell
///    Authors: Nicola Omodei & Johann Cohen Tanugi 
///

#include "GRBShell.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "CLHEP/Random/RandomEngine.h"
#include "CLHEP/Random/RandGeneral.h"
#include "CLHEP/Random/RandExponential.h"
#include "CLHEP/Random/RandFlat.h"
#include "CLHEP/Random/RanluxEngine.h"

GRBShell::GRBShell(double ei) 
{ 
  _gamma = generateGamma(cst::gamma0,cst::dgamma);
  _mass = ei/(_gamma*cst::c2);
}


double GRBShell::generateGamma(double gamma0,double dgamma) 
{
  HepRandom::setTheEngine(new RanluxEngine);
  double gamma = gamma0 + (double (RandFlat::shoot(1.0)))*dgamma;
  //  double gamma = gamma0 + (double (rand())/RAND_MAX)*dgamma;
  return gamma;
}


double GRBShell::beta(const double gamma) 
{
  if(gamma<1)
    {
      cout << "warning: gamma undefined, returning beta=0" << endl;
      return 0;
    } else 
      {
	return sqrt(1. - 1./(gamma*gamma));  
      }
}


void GRBShell::evolve(double time) 
{
  _radius += beta(_gamma)*cst::c*cst::dt1;
}
