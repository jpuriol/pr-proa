all: test

alumno.o: alumno.h alumno.cpp
	g++ -std=c++11 -Wall -O2 -c alumno.cpp

tabla.o: tabla.h alumno.h tabla.cpp
	g++ -std=c++11 -Wall -O2 -c tabla.cpp

test.o: test.cpp tabla_t.h alumno.h
	g++ -std=c++11 -Wall -O2 -c test_tabla.cpp

test: alumno.o test.o
	g++ -std=c++11 -Wall -O2 alumno.o test_tabla.o -o test_tabla.out

clean:
	rm -f  *.o test_tabla.out