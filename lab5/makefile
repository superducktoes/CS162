program_name = lab_5
object_files = main.o labFunctions.o menu.o

lab_4: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

labFunctions.o: labFunctions.cpp
	g++ -c labFunctions.cpp

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
