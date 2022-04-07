#ifndef SEGMENT_VALIDATOR_H
#define SEGMENT_VALIDATOR_H

#include "PrimitiveTraceTypes.h"
#include "Trace.h"

class TraceSet;

namespace ptt = PrimitiveTraceTypes;

/*
* Validate whether a line segment crosses any 
* trace in a collection of traces
*/

class SegmentValidator
{
public:
   explicit SegmentValidator(TraceSet* ts) 
      : m_traceSet{ts} {}
   
   SegmentValidator() : SegmentValidator(nullptr) {}

   [[nodiscard]] bool isCrossing(const ptt::LineSegment& ls) const;
   void setTraceSet(TraceSet* ts);

private:
   // check if line segment crosses any trace segment
   bool segmentIntersectsTrace(const Trace& trace, const ptt::LineSegment& ls) const;
   // check whether two line segments cross
   bool segmentsIntersect(const ptt::LineSegment& ls1, const ptt::LineSegment& ls2) const;

   // Given 3 collinear points p, q and r, the function checks if
   // point q lies on line segment pr
   bool onSegment(const ptt::Point& p, const ptt::Point& q, const ptt::Point& r) const;   

   // to define orientation of point triplets
   enum class orien
   {
      collinear = 0,
      clockwise,
      counterclockwise
   };

   // find orientation of ordered triplet (p, q, r)
   SegmentValidator::orien orientation(const ptt::Point& p, 
      const ptt::Point& q, const ptt::Point& r) const;

   TraceSet* m_traceSet;
};

#endif // !SEGMENT_VALIDATOR_H
