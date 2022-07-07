All: all
all: main

main: main.cpp
	g++ -O0 -g3 -std=c++14 main.cpp -lncurses -o main