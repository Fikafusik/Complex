
objects = main.o complex.o mathematic.o
executable = complex_test
compiler = g++

all: $(objects)
	$(compiler) -o $(executable) $(objects)

main.o: main.cpp complex.hpp mathematic.hpp
	$(compiler) -c main.cpp

complex.o: complex.cpp
	$(compiler) -c complex.cpp

mathematic.o: mathematic.cpp
	$(compiler) -c mathematic.cpp

clean:
	rm $(objects)