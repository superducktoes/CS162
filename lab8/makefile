program_name = lab_8
object_files = main.o menu.o

lab_6: $(object_files)
	g++ -std=c++11 $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp
	g++ -std=c++11 -c menu.cpp

clean:
	rm *.o

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)

run:
	./$(program_name)
