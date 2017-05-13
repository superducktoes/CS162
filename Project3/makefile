program_name = project_3
object_files = main.o creature.o barbarian.o vampire.o harrypotter.o bluemen.o medusa.o menu.o
test_driver_object_files = creature.o barbarian.o vampire.o harrypotter.o bluemen.o medusa.o menu.o testDriver.o

project_3: $(object_files)
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

testDriver.o: testDriver.cpp
	g++ -c -std=c++11 testDriver.cpp

test_driver: $(test_driver_object_files)
	g++ -std=c++11 $(test_driver_object_files) -o test_driver

clean:
	rm *.o
	rm *~

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)

run:
	./$(program_name)
