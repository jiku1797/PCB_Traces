#include "SegmentValidator.h"

#include <iterator>

#include "TraceSet.h"

bool SegmentValidator::isCrossing(const ptt::LineSegment& ls) const 
{    
   if(!m_traceSet)
   {
      puts("Invalid trace set!");
      return false;
   }

   
   if(m_traceSet->empty())
      return false; // nothing to compare to
  
   for(const auto& trace : *m_traceSet)
   {
      if(segmentIntersectsTrace(trace, ls))
         return true;
   }    
   
   return false;
}

void SegmentValidator::setTraceSet(TraceSet* ts) 
{
   m_traceSet = ts;
}

bool SegmentValidator::segmentIntersectsTrace(const Trace& trace, const ptt::LineSegment& ls) const 
{ 
   for(auto it=trace.cbegin(); it!=std::prev(trace.cend()); ++it)
   {
      ptt::LineSegment ls2{*it, *(it+1)};
      if(segmentsIntersect(ls, ls2))
         return true;
   }

   return false;
}

bool SegmentValidator::segmentsIntersect(const ptt::LineSegment& ls1, const ptt::LineSegment& ls2) const 
{ 
   const auto p1{ls1.m_start};
   const auto q1{ls1.m_end};
   const auto p2{ls2.m_start};
   const auto q2{ls2.m_end};

   // Find the four orientations needed for general and
   // special cases
   const auto o1 = orientation(p1, q1, p2);
   const auto o2 = orientation(p1, q1, q2);
   const auto o3 = orientation(p2, q2, p1);
   const auto o4 = orientation(p2, q2, q1);

   // General case
   if(o1 != o2 && o3 != o4)
   {
      return true;
   } 

   // Special Cases
   // p1, q1 and p2 are collinear and p2 lies on segment p1q1
   if(o1 == orien::collinear && onSegment(p1, p2, q1)) 
      return true;

   // p1, q1 and q2 are collinear and q2 lies on segment p1q1
   if(o2 == orien::collinear && onSegment(p1, q2, q1)) 
      return true;

   // p2, q2 and p1 are collinear and p1 lies on segment p2q2
   if(o3 == orien::collinear && onSegment(p2, p1, q2)) 
      return true;

   // p2, q2 and q1 are collinear and q1 lies on segment p2q2
   if(o4 == orien::collinear && onSegment(p2, q1, q2)) 
      return true;

   return false; // Doesn't fall in any of the above cases
}

bool SegmentValidator::onSegment(const ptt::Point& p, const ptt::Point& q, const ptt::Point& r) const 
{
   const bool onSegment
   {
      q.m_x <= std::max(p.m_x, r.m_x) 
      && q.m_x >= std::min(p.m_x, r.m_x) 
      && q.m_y <= std::max(p.m_y, r.m_y) 
      && q.m_y >= std::min(p.m_y, r.m_y)
   };
   
   return onSegment;
}

SegmentValidator::orien SegmentValidator::orientation(const ptt::Point& p, const ptt::Point& q, const ptt::Point& r) const
{ 
   // Orientation based on comparison of slope of pq vs slope of qr
   const auto val = (q.m_y - p.m_y) * (r.m_x - q.m_x) - (q.m_x - p.m_x) * (r.m_y - q.m_y);

   if(val == 0.0) 
      return orien::collinear; 

   return (val > 0) ? orien::clockwise : orien::counterclockwise; 
}
