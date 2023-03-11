CXX = g++
CXXFLAGS = -Wall

InfiniteInt: demo.cpp InfiniteInt.cpp
	$(CXX) $(CXXFLAGS) -o InfiniteInt demo.cpp InfiniteInt.cpp

clean:
	-rm InfiniteInt

