#include "TraceController.h"

TraceController::TraceController() 
   : m_validator{m_traceSet.get()}
{
}

TraceController::TraceController(std::unique_ptr<TraceSet>&& ts)
   : m_validator{ts.get()}
{    
   // take ownership of external trace set
   m_traceSet = std::move(ts);
}

bool TraceController::addSegment(const ptt::Point& pt)
{ 
   if(m_newTrace.empty())
   {
      m_newTrace.add(pt);
      return true;      
   }

   const auto currentEnd{m_newTrace.endPoint()};
   const ptt::LineSegment possibleSegment{currentEnd, pt};    
   const auto valid = !m_validator.isCrossing(possibleSegment);
   
   if(valid)
   {
      m_newTrace.add(pt);
   }

   return valid;
}

void TraceController::traceCompleted() 
{ 
   if(m_traceSet)
      m_traceSet->add(m_newTrace); 
   
   m_newTrace.clear();
}

void TraceController::reset()
{ 
   if(m_traceSet)
      m_traceSet->clear();
   
   m_newTrace.clear();
}

