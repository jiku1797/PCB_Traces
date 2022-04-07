#include "TraceSet.h"

TraceSet::TraceSet(Traces traces) : m_traces{std::move(traces)} {}

void TraceSet::add(const Trace& trace) 
{ 
   m_traces.push_back(trace); 
}

void TraceSet::reserve(const std::size_t size) 
{ 
   m_traces.reserve(size); }

void TraceSet::clear() 
{
   m_traces.clear();
}

std::size_t TraceSet::size() const 
{ 
   return m_traces.size(); 
}

bool TraceSet::empty() const 
{ 
   return m_traces.empty(); 
}

void TraceSet::print() const 
{ 
   for(auto i{0}; i<m_traces.size(); ++i)
   {
      std::cout << "Trace " << i << '\n';
      m_traces[i].print();
   }
 }
