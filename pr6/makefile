todo: test

alumno.o:alumno.h alumno.cpp
	g++ -std=c++11 -Wall -O2 -c alumno.cpp
	
test.o: test.cpp tabla.h alumno.h lista.h
	g++ -std=c++11 -Wall -O2 -c test.cpp
	
test: alumno.o test.o
	g++ -std=c++11 -Wall -O2 alumno.o test.o -o test.out 
	
clean:
	rm -f *.o test.out
