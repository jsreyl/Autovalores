CXX = g++
CXXFLAGS = -I
LIB = ~/local/include
SOURCES = EigenValuesR.cpp

autov.x:
	$(CXX) $(SOURCES) $(CXXFLAGS) $(LIB) -o $@ 
