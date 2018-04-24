#Daniel Olivas
#CS162
#final assignment

all: game

game: main.o game.o bathRoom.o bedRoom.o hall.o kitchen.o livingRoom.o outside.o player.o
	g++ main.o game.o bathRoom.o bedRoom.o hall.o kitchen.o livingRoom.o outside.o player.o -o game

main.o: main.cpp
	g++ -c main.cpp

bathRoom.o: bathRoom.cpp bathRoom.h
	g++ -c bathRoom.cpp

bedRoom.o: bedRoom.cpp bedRoom.h
	g++ -c bedRoom.cpp

hall.o: hall.cpp hall.h
	g++ -c hall.cpp

kitchen.o: kitchen.cpp kitchen.h
	g++ -c kitchen.cpp

livingRoom.o: livingRoom.cpp livingRoom.h
	g++ -c livingRoom.cpp

outside.o: outside.cpp outside.h
	g++ -c outside.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

game.o: game.cpp game.h
	g++ -c game.cpp

clean:
	rm *o game