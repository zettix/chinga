ALL: game

game:	card.o deck.o game.o main.o player.o
	g++ -std=c++11 -g -o game game.o card.o deck.o main.o player.o

main.o:	main.cc player.h game.h
	g++ -std=c++11 -g -c main.cc

player.o:	player.cc player.h
	g++ -std=c++11 -g -c player.cc

card.o:	card.h card.cc
	g++ -std=c++11 -g -c card.cc

deck.o:	deck.h deck.cc
	g++ -std=c++11 -g -c deck.cc

game.o:	game.h game.cc
	g++ -std=c++11 -g -c game.cc

clean:
	@rm *.o game
