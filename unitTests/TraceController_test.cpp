#include "TraceController_test.h"

void TraceController_test::SetUp()
{
   const auto addSegment = [this](const PrimitiveTraceTypes::Point& p)
   {
      m_defaultController.addSegment(p);
   };

   // Build an initial trace set for our controller w/ 2 traces
   addSegment(ptt::Point{ 0.0, 1.0 }); 
   addSegment(ptt::Point{ 1.0, 0.0 });
   addSegment(ptt::Point{ 2.0, 1.0 });
   m_defaultController.traceCompleted();
   
   addSegment(ptt::Point{ 1.0, 1.0 }); 
   addSegment(ptt::Point{ 2.0, 2.0 });
   addSegment(ptt::Point{ 3.0, 1.0 });
   addSegment(ptt::Point{ 4.0, 2.0 });
   m_defaultController.traceCompleted();
}

void TraceController_test::TearDown()
{
   m_defaultController.reset();
}

TEST_F(TraceController_test, testAddSegment)
{
   const auto addSegment = [this](const PrimitiveTraceTypes::Point& p) -> bool
   {
      return m_defaultController.addSegment(p);
   };

   // start at (2.0, 0.0)
   EXPECT_TRUE(addSegment(ptt::Point(2.0, 0.0)));
   // finish segment at (3.0, 0.0)
   EXPECT_TRUE(addSegment(ptt::Point(3.0, 0.0)));
   // attempt to cross 2nd trace in our trace set
   // by adding segment to (3.0, 2.0)
   EXPECT_FALSE(addSegment(ptt::Point(3.0, 2.0)));
   // try instead by going to (4.0, 1.0)
   EXPECT_TRUE(addSegment(ptt::Point(4.0, 1.0)));
}

// test controller relying on an external trace set
TEST_F(TraceController_test, testPresetController)
{
   // external trace set
   
   auto ts = std::make_unique<TraceSet>();
   ts->add(ptt::Point{ 0.0, 1.0 }
         , ptt::Point{ 1.0, 0.0 }
         , ptt::Point{ 2.0, 1.0 });

   ts->add(ptt::Point{ 1.0, 1.0 }
         , ptt::Point{ 2.0, 2.0 }
         , ptt::Point{ 3.0, 1.0 }
         , ptt::Point{ 4.0, 2.0 });
   
   // construct a preset controller w/ above trace set
   TraceController m_presetController{std::move(ts)};
   
    // start at (2.0, 0.0)
   EXPECT_TRUE(m_presetController.addSegment(ptt::Point(2.0, 0.0)));
   // finish segment at (3.0, 0.0)
   EXPECT_TRUE(m_presetController.addSegment(ptt::Point(3.0, 0.0)));
   // attempt to cross 2nd trace in our trace set
   // by adding segment to (3.0, 2.0)
   EXPECT_FALSE(m_presetController.addSegment(ptt::Point(3.0, 2.0)));
   // try instead by going to (4.0, 1.0)
   EXPECT_TRUE(m_presetController.addSegment(ptt::Point(4.0, 1.0)));
}
