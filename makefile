all: hw5

hw5: mainTerm.o

ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainTerm.o -lgtest
else
	g++ -o hw5 mainTerm.o -lgtest -lpthread
endif

mainTerm.o: term.h mainTerm.cpp number.h atom.h variable.h struct.h list.h utList.h scanner.h utScanner.h global.h parser.h utParser.h
	g++ -std=gnu++0x -c mainTerm.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw5
endif
