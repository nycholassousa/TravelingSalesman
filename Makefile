CC = g++
FLAGS = -std=c++11

.PHONY: salesman

program: main.cpp src/*.cpp Makefile
	$(CC) $(FLAGS) main.cpp src/*.cpp -o salesman
	
clean:
	rm -rf *.o salesman
