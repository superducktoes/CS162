program_name = dice_game
object_files = main.o game.o dice.o loadedDie.o menu.o
dice_game: $(object_files)
	g++ $(object_files) -o $(program_name)

main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

dice.o: dice.cpp
	g++ -c dice.cpp

loadedDie.o: loadedDie.cpp
	g++ -c loadedDie.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm *.o

run:
	./$(program_name)
