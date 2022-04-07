#ifndef POLY_LINE_H
#define POLY_LINE_H

#include <vector>
#include <initializer_list>

#include "PrimitiveTraceTypes.h"

namespace ptt = PrimitiveTraceTypes;

/*
* Represents a polyline path (collection of 2D points)
*/

class Trace
{
public:
   using Points = std::vector<ptt::Point>;

   Trace() = default;
   explicit Trace(Points points);
   Trace(std::initializer_list<ptt::Point> points);

   void add(const ptt::Point& point);
   void removeLast();
   ptt::Point endPoint() const;
   void clear();
   std::size_t size() const;
   bool empty() const;

   void print() const;

   // (forward) iterators
   using iterator = Points::iterator;
   using const_iterator = Points::const_iterator;
   iterator begin() { return m_points.begin(); }
   const_iterator begin() const { return m_points.begin(); }
   const_iterator cbegin() const { return m_points.cbegin(); }
   iterator end() { return m_points.end(); }
   const_iterator end() const { return m_points.end(); }
   const_iterator cend() const { return m_points.cend(); } 

private:
   Points m_points;
};

#endif // !POLY_LINE_H
