langtons_ant: main.o board.o menu.o ant.o
	g++ main.o board.o menu.o ant.o -o langtons_ant

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp board.hpp
	g++ -c board.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

clean:
	rm *.o
