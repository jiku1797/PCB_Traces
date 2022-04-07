#include "SegmentValidator_test.h"

#include <vector>

#include "TraceSet.h"
#include "PrimitiveTraceTypes.h"

namespace ptt = PrimitiveTraceTypes;

void SegmentValidator_test::SetUp() 
{ 
   // Set up a trace set to validate against
   m_traceSet = std::make_unique<TraceSet>();
   m_traceSet->add(ptt::Point{0.0, 1.0}, ptt::Point{1.0, 0.0}, 
      ptt::Point{2.0, 1.0});
   m_traceSet->add(ptt::Point{1.0, 1.0}, ptt::Point{2.0, 2.0}, 
      ptt::Point{3.0, 1.0}, ptt::Point{4.0, 2.0});

   //m_traceSet->print();

   m_validator.setTraceSet(m_traceSet.get());
}

void SegmentValidator_test::TearDown() {}

TEST_F(SegmentValidator_test, testIsCrossing)
{  
   const auto doesCross = [this](const PrimitiveTraceTypes::Point& p1,
      const PrimitiveTraceTypes::Point& p2) -> bool
   {
      const ptt::LineSegment crossingSegment{ p1, p2 };
      return m_validator.isCrossing(crossingSegment);
   };

   // crossing
   EXPECT_TRUE(doesCross(ptt::Point(0.0, 0.0), ptt::Point(3.0 / 4, 3.0 / 4)));
   // no crossing
   EXPECT_FALSE(doesCross(ptt::Point(3.0, 0.0), ptt::Point(4.0, 1.0)));
   // touches at (3, 1) and thus a crossing
   EXPECT_TRUE(doesCross(ptt::Point(3.0, 1.0), ptt::Point(4.0, 2.0)));
}

TEST_F(SegmentValidator_test, testCollinearOverlap)
{
   namespace ptt = PrimitiveTraceTypes;
   // segment (3.5, 1.5) -> (4.0, 2.0) is collinear and overlapping 
   // w/ 2nd trace
   const ptt::LineSegment crossingSegment{ptt::Point(3.5, 1.5), 
      ptt::Point(4.0, 2.0)};
   const bool isCrossing = m_validator.isCrossing(crossingSegment);

   EXPECT_TRUE(isCrossing);
}

TEST_F(SegmentValidator_test, testCollinearNonOverlap)
{
   namespace ptt = PrimitiveTraceTypes;
   // segment (4.0, 1.0) -> (5.0, 2.0) is collinear but not overlapping 
   // w/ 2nd trace
   const ptt::LineSegment crossingSegment{ ptt::Point(4.0, 1.0),
      ptt::Point(5.0, 2.0) };
   const bool isCrossing = m_validator.isCrossing(crossingSegment);

   EXPECT_FALSE(isCrossing);
}


