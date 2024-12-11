# Compiler and flags
CXX = g++
CXXFLAGS = -c
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Automatically detect all .cpp files, excluding main.cpp
SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = sfml-app

# Default target
all: $(EXECUTABLE)

# Compile main.o separately
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

# Compile other object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $<

# Link object files into the final executable
$(EXECUTABLE): main.o $(OBJECTS)
	$(CXX) main.o $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

# Run the application
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean the build files
clean:
	rm -f *.o $(EXECUTABLE)
