default:
	g++ -std=c++17 -O2 -c ../src/*.cpp -I ../include -Wall -Wextra -pedantic-errors
	g++ ./*.o -o FltkClassCreator `fltk-config --ldflags --cxxflags` -Wl,-subsystem,windows