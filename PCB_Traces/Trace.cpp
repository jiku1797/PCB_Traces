#include "Trace.h"

#include <algorithm>
#include <iterator>

Trace::Trace(Points points) : m_points{std::move(points)} {}

Trace::Trace(std::initializer_list<ptt::Point> points) : m_points{points} {}

void Trace::add(const ptt::Point& point) 
{ 
   m_points.push_back(point); 
}

void Trace::removeLast() 
{
   if(!m_points.empty())
   {
      m_points.pop_back(); 
   }
}

ptt::Point Trace::endPoint() const 
{ 
   return m_points.back();   
}

void Trace::clear() 
{
   m_points.clear();
}

std::size_t Trace::size() const 
{ 
   return m_points.size(); 
}

bool Trace::empty() const 
{ 
   return m_points.empty(); 
}

void Trace::print() const 
{
   std::for_each(std::begin(m_points), std::end(m_points), 
      [](const ptt::Point& pt) { pt.print(); });
}


