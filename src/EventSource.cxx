/** @file EventSource.cxx
    @brief Implementation of class EventSource
   $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/EventSource.cxx,v 1.13 2003/02/22 05:42:25 burnett Exp $
*/

#include "EventSource.h"

#include "dom/DOM_Element.hpp"
#include "xml/Dom.h"
#include "FluxException.h"

#include <sstream>

unsigned int  EventSource::s_id = 0;
double  EventSource::s_total_area = 6.; // area in m^2

EventSource::EventSource (double aFlux, unsigned acode)
:  m_enabled(true), m_flux(aFlux),  m_code(acode)
{
    std::stringstream  s;
    
    s << "Source_" << (++s_id) << '\0';
    if (acode == 0) code(s_id); // automatically assign event codes...
    
    m_name = s.str();
}
EventSource::~EventSource()
{}

double EventSource::flux (double time) const
{
  // Purpose and Method: This method returns the flux of the particular source.
  // Inputs  - current time
  // Outputs - flux, in units of (particles/(m^2*sr*sec))
    return m_flux;  // default if not overridden
}


double  EventSource::rate (double time )const
{
  // Purpose and Method: This method returns the rate of particles entering the detector.
  // Inputs  - current time
  // Outputs - rate, in units of (particles/sec)
    return enabled()? (solidAngle()*flux(time)*s_total_area) :0;
}


double	EventSource::solidAngle () const{
    return m_solid_angle;
}

// UI titles
std::string EventSource::fullTitle () const 
{ return std::string("EventSource");   }
std::string EventSource::displayTitle () const  {  return m_name; }
