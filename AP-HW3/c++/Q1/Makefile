CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o maxHeap.o 
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Truckload.o: maxHeap.h maxHeap.cpp
	$(CXX) $(CXXFLAGS) maxHeap.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
