#ifndef TRACE_CONTROLLER_TEST_H
#define TRACE_CONTROLLER_TEST_H

#include "gtest/gtest.h"

#include <memory>

#include "TraceController.h"

class TraceSet;

class TraceController_test : public ::testing::Test
{
public:
   void SetUp() override;

   void TearDown() override;

public:
   // test default controller buidling its own 
   // trace set
   TraceController m_defaultController;   
};

#endif // !TRACE_CONTROLLER_TEST_H

