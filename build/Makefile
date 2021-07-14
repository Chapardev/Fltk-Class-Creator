CC=g++
OBJS = ./*.o

default:
	$(CC) -std=c++17 -O2 -c ../src/*.cpp -I ../include -Wall -pedantic-errors
	$(CC) $(OBJS) -o FltkClassCreator `fltk-config --ldflags --cxxflags`