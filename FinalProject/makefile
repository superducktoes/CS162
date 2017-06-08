program_name = final_project
object_files = main.o bossoffice.o breakroom.o darkhallway.o defaultRoom.o gameplay.o mainLobby.o parkingLot.o reception.o yourdesk.o

final_project: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

bossoffice.o: bossoffice.cpp
	g++ -c bossoffice.cpp

breakroom.o: breakroom.cpp
	g++ -c breakroom.cpp

darkhallway.o: darkhallway.cpp
	g++ -c darkhallway.cpp

defaultRoom.o: defaultRoom.cpp
	g++ -c defaultRoom.cpp

gameplay.o: gameplay.cpp
	g++ -c gameplay.cpp

mainLobby.o: mainLobby.cpp
	g++ -c mainLobby.cpp

parkingLot.o: parkingLot.cpp
	g++ -c parkingLot.cpp

reception.o: reception.cpp
	g++ -c reception.cpp

yourdesk.o: yourdesk.cpp
	g++ -c yourdesk.cpp
	
clean:
	rm *.o

valgrind:
	valgrind ./$(program_name)

gdb:
	gdb ./$(program_name)

run:
	./$(program_name)
