program_name = lab_6
object_files = main.o dll.o menu.o

lab_6: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

dll.o: dll.cpp
	g++ -c dll.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm *.o

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)
run:
	./$(program_name)
