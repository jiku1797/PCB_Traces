About PCB_Traces 1.0.0

The main component is the TraceController. It requires ownership of
a collection of traces (polygonal paths), called a trace set. 
At construction the trace set can be either preoccupied by 
a number of traces or it can be empty. 

The main function to apply to a TraceController is the 
addSegment, taking a 2D-point as input. It validates the input
to see whether the segment constructed from the last previous valid 
input crosses any other traces in its trace set. If it does not the 
input is considered valid and a new segment is added to its 
temporary segment under construction. To complete the temporary trace 
a call is made to the traceCompleted function. At this point the newly 
constructed trace is added to the trace set and a new one can be 
started. 

The business logic sits in the SegmentValidator of the TraceController, 
which checks potential segments against each segment in each of the other 
traces of the trace set. At this level the segment to segment validation 
is made by checking various orientation criteria on different selections
of 3 endpoints from the two segments. Also, a number of special cases 
when the segments are collinear and overlapping must be handled.  

Executables for Windows can be found in 
\PCB_Traces\out\build\x64-release\bin. 

As an aid to visually try out the TraceController a specially made
GUI is also provided, called PCB_Traces_GUI. It is developed within 
the Qt framework.  