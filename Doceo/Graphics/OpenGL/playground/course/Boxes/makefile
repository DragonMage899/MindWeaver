main: main.cpp
	g++ -g shader.cpp shapes.cpp main.cpp -lglfw3 -pthread -lGLEW -ldl -lGL -o main

clean:
	rm -f *.o *.txt main

run:
	./main

all:
	make clean
	make
	make run