program_name = project_4
object_files = main.o creature.o barbarian.o vampire.o harrypotter.o bluemen.o medusa.o menu.o monstersqueue.o monsterstack.o gameplay.o

project_4: $(object_files)
	g++ -std=c++11 $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

creature.o: creature.cpp
	g++ -c -std=c++11 creature.cpp

barbarian.o: barbarian.cpp
	g++ -c -std=c++11 barbarian.cpp

vampire.o: vampire.cpp
	g++ -c -std=c++11 vampire.cpp

harrypotter.o: harrypotter.cpp
	g++ -c -std=c++11 harrypotter.cpp

bluemen.o: bluemen.cpp
	g++ -c -std=c++11 bluemen.cpp

medusa.o: medusa.cpp
	g++ -c -std=c++11 medusa.cpp

menu.o: menu.cpp
	g++ -c -std=c++11 menu.cpp

monstersqueue.o: monstersqueue.cpp
	g++ -c -std=c++11 monstersqueue.cpp

monsterstack.o: monsterstack.cpp
	g++ -c -std=c++11 monsterstack.cpp

gameplay.o: gameplay.cpp
	g++ -c -std=c++11 gameplay.cpp

clean:
	rm *.o
	rm *~

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)

run:
	./$(program_name)
