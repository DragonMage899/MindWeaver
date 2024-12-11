CC = g++
CFLAGS = -Wall -Wextra -std=c++11
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = app
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
HDR = $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -c $<

run:
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: all run clean
