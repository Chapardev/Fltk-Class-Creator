CC=g++
OBJS = ./*.o

all: compile link

compile:
	$(CC) -std=c++17 -O2 ../include/precompiled.hpp -Wall -Wextra -pedantic-errors
	$(CC) -std=c++17 -O2 -c ../src/*.cpp -I ../include -Wall -pedantic-errors

link:
	$(CC) $(OBJS) -o FltkClassCreator `fltk-config --ldflags --cxxflags`