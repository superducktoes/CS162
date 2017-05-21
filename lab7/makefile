program_name = lab_7
object_files = main.o queuenode.o

lab_7: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

queuenode.o: queuenode.cpp
	g++ -c queuenode.cpp

clean:
	rm *.o

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)
run:
	./$(program_name)
