main: main.cpp
	g++ -g $(files) main.cpp shader.cpp -lglfw -pthread -lGLEW -ldl -lGL -o main


window: window.cpp 
	g++ -g $(files) window.cpp -lglfw -pthread -lGLEW -ldl -lGL -o window

clean:
	rm -f *.o main window triangle rectangle draws test

run:
	./main

all:
	make clean
	make
	make run