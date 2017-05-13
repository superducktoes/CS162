program_name = rock_paper_scissors
object_files = main.o tool.o rock.o paper.o scissors.o

rock_paper_scissors: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

tool.o: tool.cpp
	g++ -c tool.cpp

rock.o: rock.cpp
	g++ -c rock.cpp

paper.o: paper.cpp
	g++ -c paper.cpp

scissors.o: scissors.cpp
	g++ -c scissors.cpp

run:
	./$(program_name)
	
clean:
	rm *.o
