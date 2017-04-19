program_name = dice_game

dice_game: main.o
	g++ main.o

main.o: main.cpp
	g++ -c main.cpp -o dice_game

clean:
	rm *.o
