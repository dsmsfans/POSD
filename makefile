all: hw2

hw2: mainTerm.o

ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o -lgtest
else
	g++ -o hw2 mainTerm.o -lgtest -lpthread
endif

mainTerm.o: interface.h mainTerm.cpp utTerm.h number.h atom.h variable.h
	g++ -std=c++11 -c mainTerm.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
