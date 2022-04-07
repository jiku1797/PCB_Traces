#ifndef PRIMITIVE_TRACE_TYPES_H
#define PRIMITIVE_TRACE_TYPES_H

#include <iostream>

namespace PrimitiveTraceTypes
{
struct Point
{
   Point(const double x, const double y) : m_x{x}, m_y{y} {}
   Point() = default;

   void print() const 
   { 
      std::cout << "(" << m_x << ", " << m_y << ")\n"; 
   }


   double m_x{0.0};
   double m_y{0.0};
};

struct LineSegment
{
   LineSegment(const Point start, const Point end) 
      : m_start{start}, m_end{end} {}
   LineSegment() = default;   

   Point m_start{};
   Point m_end{};
};
} // namespace PrimitiveTraceTypes

#endif // !PRIMITIVE_TRACE_TYPES_H