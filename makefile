all: hw3 hw4

hw3: mainTerm.o

ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainTerm.o -lgtest
else
	g++ -o hw3 mainTerm.o -lgtest -lpthread
endif

hw4: mainTerm.o

ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainTerm.o -lgtest
else
	g++ -o hw4 mainTerm.o -lgtest -lpthread
endif

mainTerm.o: term.h mainTerm.cpp number.h atom.h variable.h struct.h list.h utList.h
	g++ -std=gnu++0x -c mainTerm.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o ut*[!.h] hw*
endif
