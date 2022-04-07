#ifndef TRACE_TEST_H
#define TRACE_TEST_H

#include "gtest/gtest.h"

#include "Trace.h"

namespace trace_test_details
{
static constexpr int defaultSize = 11;
}

class Trace_test : public ::testing::Test
{
public:
   void SetUp() override;

   void TearDown() override;

public:
   Trace m_trace;
};

#endif // !TRACE_TEST_H