CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o MAP.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
MAP.o: MAP.cpp MAP.h
	$(CXX) $(CXXFLAGS) MAP.cpp 
clean:
	rm -f $(TARGET) $(OBJECTS)
