#ifndef TRACE_CONTROLLER_H
#define TRACE_CONTROLLER_H

#include <memory>

#include "TraceSet.h"
#include "PrimitiveTraceTypes.h"
#include "SegmentValidator.h"

namespace ptt = PrimitiveTraceTypes;

class TraceController
{
public:
   // start w/ an empty trace set and build it up
   TraceController();
   
   // start w/ an external existing trace set
   TraceController(std::unique_ptr<TraceSet>&& ts);

   // Add line segment from m_newTrace's endpoint to pt. 
   // Only adding valid segments as communicated by return value 
   bool addSegment(const ptt::Point& pt);
   
   // Adds m_newTrace to m_traceSet   
   void traceCompleted();

   void reset();

private:
   std::unique_ptr<TraceSet> m_traceSet{std::make_unique<TraceSet>()};
   // tmp trace w/ valid segments 
   Trace m_newTrace;
   SegmentValidator m_validator;
};

#endif // !TRACE_CONTROLLER_H