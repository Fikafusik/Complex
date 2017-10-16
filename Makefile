
objects = main.o complex.o mathematic.o algorithms.o combinatorics.o primes.o
executable = complex_test
compiler = g++

all: $(objects)
	$(compiler) -o $(executable) $(objects)

main.o: main.cpp complex.hpp mathematic.hpp algorithms.hpp combinatorics.hpp primes.hpp
	$(compiler) -c main.cpp

complex.o: complex.cpp
	$(compiler) -c complex.cpp

mathematic.o: mathematic.cpp algorithms.hpp
	$(compiler) -c mathematic.cpp

algorithms.o: algorithms.cpp 
	$(compiler) -c algorithms.cpp

combinatorics.o: combinatorics.cpp
	$(compiler) -c combinatorics.cpp

primes.o: primes.cpp
	$(compiler) -c primes.cpp

clean:
	rm $(objects)