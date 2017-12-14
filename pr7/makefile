all: main_expresion tiempos

main_expresion:  expresion.h Eigen/Dense main_expresion.cpp
	g++ -std=c++11 main_expresion.cpp -o $@.out -O2

tiempos: expresion.h  SArray2.h Eigen/Dense tiempos.cpp
	g++ -std=c++11 tiempos.cpp -o $@.out -Wall -O2

clean:
	rm -f *.out
