all: hw7

hw7: mainTerm.o term.o struct.o list.o

ifeq (${OS}, Windows_NT)
	g++ -o hw7 mainTerm.o term.o struct.o list.o -lgtest
else
	g++ -o hw7 mainTerm.o term.o struct.o list.o -lgtest -lpthread
endif

mainTerm.o: term.o mainTerm.cpp number.h atom.h variable.h struct.o list.o iterator.h utIterator.h
	g++ -std=gnu++0x -c mainTerm.cpp
term.o: term.h term.cpp
	g++ -std=gnu++0x -c term.cpp
struct.o: struct.h struct.cpp
	g++ -std=gnu++0x -c struct.cpp
list.o: list.h list.cpp
	g++ -std=gnu++0x -c list.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw7
endif
