all: hw3

hw3: mainTerm.o

ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainTerm.o -lgtest
else
	g++ -o hw3 mainTerm.o -lgtest -lpthread
endif

mainTerm.o: term.h mainTerm.cpp number.h atom.h variable.h utVariable.h utStruct.h struct.h
	g++ -std=gnu++0x -c mainTerm.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw3
endif
