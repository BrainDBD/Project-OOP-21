mkdir obj
g++ -c -o obj/Card.o src/Card.cpp
g++ -c -o obj/Deck.o src/Deck.cpp
g++ -c -o obj/Player.o src/Player.cpp 
g++ -c -o obj/Game.o src/Game.cpp
g++ -c -o obj/main.o main.cpp
g++ -o main obj/main.o obj/Card.o obj/Deck.o obj/Player.o obj/Game.o
main.exe
cd obj 
del Card.o
del Deck.o 
del Game.o 
del main.o 
del Player.o 
cd .. 
rmdir obj
