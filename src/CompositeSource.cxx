/** @file CompositeSource.cxx
    @brief Define CompositeSource

   $Header: /nfs/slac/g/glast/ground/cvs/FluxSvc/src/CompositeSource.cxx,v 1.18 2003/02/22 14:38:02 burnett Exp $
*/

#include "CompositeSource.h"  

#include "FluxSource.h"


#include <strstream>
#include <cassert>
#include <numeric> // for accumulate
#include <functional>
#include <iomanip>

CompositeSource::CompositeSource (double aRate)
: EventSource(aRate),m_numofiters(0), m_recent(0)
{
}

CompositeSource::~CompositeSource()
{
    for (std::vector<EventSource*>::iterator it = m_sourceList.begin();
    it != m_sourceList.end(); ++it ) delete (*it);
}

void CompositeSource::addSource (EventSource* aSource)
{
    m_sourceList.push_back(aSource);
#if 0 //THB does this do anything?
    EventSource::setFlux( flux(EventSource::time()) );
#endif
    //here, set up the associated vectors by default.
    m_unusedSource.push_back(0);
    m_sourceTime.push_back(-1);
    m_eventList.push_back(0);
}


FluxSource* CompositeSource::event (double time)
{
    int i=0; //for iterating through the m_unusedSource vector
    int winningsourcenum; //the number of the "winning" source
    
    EventSource::setTime(time);
    
    m_numofiters=0;
    double mr = rate(EventSource::time());
    
    if( m_sourceList.size()==1 || mr ==0) {
        m_recent = m_sourceList.front();
    }else {
        
        // more than one:: choose on basis of relative rates
        std::vector<EventSource*>::iterator  now = m_sourceList.begin();
        std::vector<EventSource*>::iterator  it = now;
        
        double intrval=0.,intrmin=100000.;
	int q;
        for (q=0 ; now != m_sourceList.end(); ++now) {
            if(m_unusedSource[i]==1){
                intrval=m_sourceTime[i]-time;
            }else{
                m_eventList[i] = (*now)->event(time); // to initialize particles, so that the real interval for the particle is gotten.
                intrval=m_sourceList[i]->interval(time);
                m_unusedSource[i]=1;
                m_sourceTime[i]=time + intrval;
            }
            
            if(intrval < intrmin){
                //the present source is "winning" here
                it=now;
                intrmin=intrval;
                m_numofiters=q;
                winningsourcenum=i;
            }
            
            m_recent = (*it);
            q++;
            i++;
        }
        //note:the internal interval() function takes absolute time.
        setInterval(time+intrmin);
    }
    m_unusedSource[winningsourcenum]=0; //the current "winning" source is getting used..
    // now ask the chosen one to return the event.
   return m_eventList[winningsourcenum];
}

std::string CompositeSource::fullTitle () const
{
    std::strstream  s;
    std::vector<EventSource*>::const_iterator	it = m_sourceList.begin();
    
    while (it != m_sourceList.end()) {
        
        s << (*it)->fullTitle() << " ";
        ++it;
        if (it != m_sourceList.end())    s << "+ ";
    }
    s << '\0';
    std::string t(s.str());
    s.freeze(false);
    return t;
}

std::string CompositeSource::displayTitle () const
{
    return (m_recent == 0) ? "" : m_recent->displayTitle();
}

double CompositeSource::rate(double time) const
{
    //m_time += m_time-time;
    std::vector<EventSource*>::const_iterator it = m_sourceList.begin();
    double	total_rate = 0.;
    for(;it != m_sourceList.end();++it) {
        double rr = fabs((*it)->rate(time));
        total_rate += rr;
    }
    return total_rate;
}

void CompositeSource::printOn(std::ostream& out)const
{
    out << "Source(s), total rate="<< rate(EventSource::time()) << std::endl;
    
    for( std::vector<EventSource*>::const_iterator it = m_sourceList.begin();
    it != m_sourceList.end();++it)	{
        out <<  std::setw(8) << std::setprecision(4) << (*it)->rate(EventSource::time()) <<" Hz, "
            << '#' << std::setw(6) << (*it)->eventNumber() <<' '
            << (*it)->name() << ' '<< (*it)->fullTitle() << std::endl;
        
    }
    
}

std::string CompositeSource::findSource()const
{
    return m_recent->fullTitle();
}

int CompositeSource::numSource()const
{
    ///Purpose: Return a unique number correcponding to the current spectrum.
    return m_numofiters;
}

