main: main.cpp 
	g++ -g Shapes2D.cpp shader.cpp main.cpp -lglfw3 -pthread -lGLEW -ldl -lGL -o main

clean:
	rm -f *.o main

run:
	./main

all:
	make clean
	make
	make run