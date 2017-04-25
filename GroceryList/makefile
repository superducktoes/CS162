program_name = grocery_list
object_files = main.o Item.o List.o menu.o

grocery_list: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

List.o: List.cpp
	g++ -c List.cpp

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
