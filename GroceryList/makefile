program_name = grocery_list
object_files = main.o Item.o

grocery_list: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

clean:
	rm *.o

run:
	./$(program_name)
