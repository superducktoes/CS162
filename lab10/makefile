program_name = lab_10
object_files = main.o FibonacciR.o FibonacciNR.o

lab_10: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

FibonacciNR.o: FibonacciNR.cpp
	g++ -c FibonacciNR.cpp

FibonacciR.o: FibonacciR.cpp
	g++ -c FibonacciR.cpp

clean:
	rm *.o

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)

run:
	./$(program_name)
