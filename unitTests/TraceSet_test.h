#ifndef TRACE_SET_TEST_H
#define TRACE_SET_TEST_H

#include "gtest/gtest.h"

#include "TraceSet.h"

namespace trace_set_test_details
{
static constexpr int defaultSize = 11;
static constexpr int defaultPointSize = 15;
}

class TraceSet_test : public ::testing::Test
{
public:
   void SetUp() override;

   void TearDown() override;

public:
   Trace::Points generatePoints(const int seed) const;

   TraceSet m_traceSet;
};

#endif // !TRACE_TEST_H