#include "Trace_test.h"

void Trace_test::SetUp() 
{ 
   for(auto i = 0; i < trace_test_details::defaultSize; ++i)
   {
      const auto curr{static_cast<double>(i)};
      m_trace.add({curr, curr+1.0}); 
   }
}

void Trace_test::TearDown() {}

TEST_F(Trace_test, testAdd) 
{ 
   m_trace.add({42.0, -12.0}); 
   EXPECT_EQ(m_trace.size(), trace_test_details::defaultSize + 1);
}

TEST_F(Trace_test, testRemove)
{
   m_trace.removeLast();
   EXPECT_EQ(m_trace.size(), trace_test_details::defaultSize - 1);
}

TEST_F(Trace_test, testSize)
{   
   EXPECT_EQ(m_trace.size(), trace_test_details::defaultSize);
}
