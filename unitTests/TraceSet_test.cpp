#include "TraceSet_test.h"

//#include "gtest/gtest.h"

void TraceSet_test::SetUp() 
{
   m_traceSet.reserve(trace_set_test_details::defaultSize);

   for(auto i = 0; i < trace_set_test_details::defaultSize; ++i)
   {
      const auto pts{generatePoints(i)};
      m_traceSet.add(Trace(pts));
   }
}

void TraceSet_test::TearDown() 
{
   m_traceSet.clear();
}

Trace::Points TraceSet_test::generatePoints(const int seed) const 
{
   Trace::Points pts;
   pts.reserve(trace_set_test_details::defaultPointSize);

   for(auto i = 0; i < trace_set_test_details::defaultPointSize; ++i)
   {
      const auto curr{static_cast<double>(seed + i)};
      pts.emplace_back(curr, curr);
   }

   return pts;
}

TEST_F(TraceSet_test, testSize) 
{ 
   EXPECT_EQ(m_traceSet.size(), trace_set_test_details::defaultSize); 
}

TEST_F(TraceSet_test, testAdd) 
{ 
   const auto pts{generatePoints(0)};
   m_traceSet.add(Trace(pts));
   EXPECT_EQ(m_traceSet.size(), trace_set_test_details::defaultSize + 1); 
}
