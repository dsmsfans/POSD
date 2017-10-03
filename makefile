all: hw2

hw2: utTerm

utTerm: mainTerm.o
	g++ -o utTerm mainTerm.o -lgtest -lpthread
mainTerm.o: Interface.h mainTerm.cpp utTerm.h Number.h Atom.h Variable.h
	g++ -std=c++11 -c mainTerm.cpp

clean:
	rm -f *.o utTerm
stat:
	wc *.h *.cpp
