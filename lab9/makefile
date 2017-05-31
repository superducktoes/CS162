program_name = lab_9
object_files = main.o stack.o queueBuffer.o

lab_8: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

queueBuffer.o: queueBuffer.cpp
	g++ -c queueBuffer.cpp

clean:
	rm *.o

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)

run:
	./$(program_name)
