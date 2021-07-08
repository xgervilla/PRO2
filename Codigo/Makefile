OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o idiomas.o idioma.o treecode.o frecuencia.o
	g++ -o program.exe *.o

program.o: program.cc idiomas.hh
	g++ -c program.cc $(OPCIONS) 

idiomas.o: idiomas.cc idioma.hh
	g++ -c idiomas.cc $(OPCIONS) 

idioma.o: idioma.cc treecode.hh frecuencia.hh idioma.hh BinTree.hh treecode.cc
	g++ -c idioma.cc $(OPCIONS) 

treecode.o: treecode.cc treecode.hh
	g++ -c treecode.cc $(OPCIONS) 

frecuencia.o: frecuencia.cc frecuencia.hh
	g++ -c frecuencia.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe
