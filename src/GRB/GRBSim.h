/*!
 * \class GRBSim
 *
 * \author Nicola Omodei       nicola.omodei@pi.infn.it 
 * \author Johann Cohen-Tanugi johann.cohen@pi.infn.it
 *
 */

#include "GRBShell.h"
#include "GRBShock.h"
#include "GRBConstants.h"

#ifndef GRBSIM_H
#define GRBSIM_H 1

//!  Simulator engine of a GRB source
class GRBSim 
{
 public:

  //! Gathers all relevant constants for the simulation 
  GRBConstants *myParam;

  //! Constructor takes a parameter file as argument.
  GRBSim(char);
  //! Destructor
  ~GRBSim();

  /*!
  * \brief Starts the GRB simulation
  *
  * \arg Step 1: Creation of the shells
  * \arg Step 2: Calculation of the evolution
  * \arg Step 3: Sorting the Shocks with respect to \c tobs. 
  */
  void Start();
  /*! \arg Step 4:Compute the Flux (m_spectrum), at given time.
   * \param time is the time in which the spectrum is calculated.
   */
  void ComputeFlux(double time);
  
  //! The direction of the GRB is chosen randomly in the sky.
  std::pair<float,float> GRBdir()       {return m_grbdir;}
  //! The Spectrum() vector contains the flux \f$\phi\f$ in \f$ph/s/MeV/m^2\f$
  std::vector<double>    Spectrum()     {return m_spectrum;}
  //! Is the vectror that contains the energy bin,in \f$eV\f$, in wich the flux is evaluated.
  std::vector<double>    Energy()       {return m_energy;}
  //! Is the energy bin size in \f$eV\f$ (the energy is in log scale!)
  std::vector<double>    DeltaE()       {return m_de;}
  //! It conresponds to the time (in the GLAST frame) in which the burst ends
  double                 Tmax()         {return m_tmax;}
  /*! Is the Area of sphere having as radius 
   * the distance of the source (in \f$cm^2\f$)
   */ 
  double                 Area()         {return m_Area;}
  //!  Return the value of the flux (\f$ph/s/MeV/m^2\f$)
  double                 Flux(int en)   {return m_spectrum[en];}
  //! Return the \c en energy bin.
  double                 Energy(int en) {return m_energy[en];}
  /*! \brief Return the integrated flux (\f$eV/(m^2 s)\f$ for energy greather than \en enmin.
   *
   * It calculates the following integral:
   * \f[ \int_{enmin}^{enmax} \phi(E) E dE\f]
   * \param emin minimal energy below which no photon energy is drawn. This 
   * is to avoid generation of low energy photons without interest to GLAST. 
   */

  double              IFlux(double enmin=cst::enph); 
  /*! \brief Return the integrated photon rate (\f$ ph/(m^2 s)\f$) for energy greather than enmin.
   *
   * It calculates the following integral:
   * \f[ \int_{enmin}^{enmax} \phi(E) dE\f]
   * \param emin minimal energy below which no photon energy is drawn. This 
   * is to avoid generation of low energy photons without interest to GLAST. 
   */
  double              IRate(double enmin=cst::enph);
  /*! \brief Integrated flux of energy for energy > enmin that flows in a time step dt
   *
   * \f[ \int_{enmin}^{enmax} \phi(E) E dE*dt\f], is in (\f$eV/m^2\f$)
   * \param emin minimal energy below which no photon energy is drawn. This 
   * is to avoid generation of low energy photons without interest to GLAST. 

   */
  double              IEnergy(double enmin=cst::enph);

  /*!
   * \brief returns a photon energy sampled from the current spectrum vector.
   *
   * This is essentially a copycat from the ROOT TH1::GetRandom() method.
   * \param spctrmVec the current spectrum vector \c m_spectrum.
   * \param u uniform random number.
   * \param emin minimal energy below which no photon energy is drawn. This 
   * is to avoid generation of low energy photons without interest to GLAST.
   */
  float DrawPhotonFromSpectrum(std::vector<double>, float u=0.0, double emin=cst::enph);
  
 private:
  //data member
  std::vector<GRBShell*> theShells;
  std::vector<GRBShock*> theShocks;
  std::vector<double>    m_energy, m_de, m_spectrum;
  std::pair<float,float> m_grbdir;
  double m_tmax;
  double m_ftot;
  double m_phtot;
  double m_Area;
};

#endif


