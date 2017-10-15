
objects = main.o complex.o mathematic.o algorithms.o
executable = complex_test
compiler = g++

all: $(objects)
	$(compiler) -o $(executable) $(objects)

main.o: main.cpp complex.hpp mathematic.hpp algorithms.hpp
	$(compiler) -c main.cpp

complex.o: complex.cpp
	$(compiler) -c complex.cpp

mathematic.o: mathematic.cpp algorithms.hpp
	$(compiler) -c mathematic.cpp

algorithms.o: algorithms.cpp 
	$(compiler) -c algorithms.cpp

clean:
	rm $(objects)