#ifndef TRACE_SET_H
#define TRACE_SET_H

#include <vector>
#include <utility>

#include "Trace.h"

/*
* Abstraction of a collection of non-crossing traces
*/

class TraceSet
{
   using Traces = std::vector<Trace>;

public:
   explicit TraceSet(Traces traces);
   TraceSet() = default;

   void add(const Trace& trace);
   
   // add trace w/ arbitrary number of PrimitiveTraceTypes::Point's 
   template<typename ...Ts>
   void add(Ts&&... points);

   void reserve(const std::size_t size);
   void clear();
   std::size_t size() const;
   bool empty() const;

   void print() const;

   // (forward) iterators
   using iterator = Traces::iterator;
   using const_iterator = Traces::const_iterator;
   iterator begin() { return m_traces.begin(); }
   const_iterator begin() const { return m_traces.begin(); }
   const_iterator cbegin() const { return m_traces.cbegin(); } 
   iterator end() { return m_traces.end(); }
   const_iterator end() const { return m_traces.end(); }
   const_iterator cend() const { return m_traces.cend(); } 

private:
   Traces m_traces;
};

#endif // !TRACE_SET_H

template <typename... Ts>
inline void TraceSet::add(Ts&&... points)
{
   const Trace newTrace{std::forward<Ts>(points)...};
   add(newTrace);
}
