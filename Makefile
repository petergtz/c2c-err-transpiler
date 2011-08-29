CXXFLAGS = -g -I /usr/include/c++/4.5 -I /usr/include/c++/4.5/x86_64-linux-gnu
CFLAGS = -g
CXX = clang++

c2c: lex.yy.o c2c.tab.o
	$(CXX) -g lex.yy.o c2c.tab.o -o c2c
	
lex.yy.o: lex.yy.c
	$(CXX) -c $(CXXFLAGS) lex.yy.c
	
#c2c.tab.o: c2c.tab.cpp c2c.tab.hpp
#	g++ -g -c c2c.tab.cpp
	
c2c.tab.cpp c2c.tab.hpp: c2c.ypp structs.h
	bison --verbose --debug -d c2c.ypp
	
lex.yy.c: c2c.l c2c.tab.hpp
	lex c2c.l
	
.PHONY : clean
clean:
	-rm -f c2c c2c.tab.c* c2c.tab.h* lex.yy.c* c2c.output *.o
	
