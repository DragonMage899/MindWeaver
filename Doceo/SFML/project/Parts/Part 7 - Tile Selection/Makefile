CXX = g++
CXXFLAGS = -c
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = city-builder

all: $(EXECUTABLE)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $<

$(EXECUTABLE): main.o $(OBJECTS)
	$(CXX) main.o $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)
