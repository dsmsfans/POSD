all: hw2

hw2: mainTerm.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o -lgtest
else
	g++ -o hw2 mainTerm.o -lgtest -pthread
endif

# utTerm: mainTerm.o
# 	g++ -o utTerm mainTerm.o -lgtest -lpthread
mainTerm.o: Interface.h mainTerm.cpp utTerm.h Number.h Atom.h Variable.h
	g++ -std=c++11 -c mainTerm.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
