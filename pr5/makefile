todo: test_tabla

clase.o: clase.h clase.cpp
	g++ -std=c++11 -Wall -o -O2

main.o: main.cpp clase.h
	g++ -std=c++11 -Wall -o -O2

main: main.o clase.o
	g++ -std=c++11 -Wall main.o clase.o -o main -O2
	
clean:
	rm  *.o
