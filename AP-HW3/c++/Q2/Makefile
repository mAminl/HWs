CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o my_vector.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
my_vector.o: my_vector.cpp my_vector.h
	$(CXX) $(CXXFLAGS) my_vector.cpp 
clean:
	rm -f $(TARGET) $(OBJECTS)
