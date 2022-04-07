#ifndef SEGMENT_VALIDATOR_TEST_H
#define SEGMENT_VALIDATOR_TEST_H

#include "gtest/gtest.h"

#include <memory>

#include "SegmentValidator.h"

class TraceSet;

class SegmentValidator_test : public ::testing::Test
{
public:
   void SetUp() override;

   void TearDown() override;

public:
   SegmentValidator m_validator;
   std::unique_ptr<TraceSet> m_traceSet;
};

#endif // !SEGMENT_VALIDATOR_TEST_H

