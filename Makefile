
objects = main.o complex.o mathematics.o algorithms.o combinatorics.o primes.o matrix.o array.o
executable = FTkL
compiler = g++

all: $(objects)
	$(compiler) -o $(executable) $(objects)

main.o: main.cpp
	$(compiler) -c main.cpp

complex.o: complex.cpp complex.hpp
	$(compiler) -c complex.cpp

mathematics.o: mathematics.cpp mathematics.hpp
	$(compiler) -c mathematics.cpp

algorithms.o: algorithms.cpp algorithms.hpp
	$(compiler) -c algorithms.cpp

combinatorics.o: combinatorics.cpp combinatorics.hpp
	$(compiler) -c combinatorics.cpp

primes.o: primes.cpp primes.hpp
	$(compiler) -c primes.cpp

matrix.o: matrix.cpp matrix.hpp
	$(compiler) -c matrix.cpp

array.o: array.cpp array.hpp
	$(compiler) -c array.cpp
	
clean:
	rm $(objects)