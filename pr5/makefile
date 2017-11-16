todo: test_tabla 


alumno.o: alumno.h alumno.cpp
	g++ -std=c++11 -Wall -O2 -c alumno.cpp

tabla.o: tabla.h alumno.h tabla.cpp
	g++ -std=c++11 -Wall -O2 -c tabla.cpp

test_tabla: alumno.o tabla_t.h
	g++ -std=c++11 -Wall -o -O2 alumno.o test_tabla.cpp -o test_tabla.out

clean:
	rm -f  *.o test_tabla.out
