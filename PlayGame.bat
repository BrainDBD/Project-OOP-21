@echo off
mkdir obj
g++ -c -o obj/NumCard.o src/NumCard.cpp
g++ -c -o obj/ClassicCard.o src/ClassicCard.cpp
g++ -c -o obj/TrumpCard.o src/TrumpCard.cpp
g++ -c -o obj/BasicCardContainer.o src/BasicCardContainer.cpp
g++ -c -o obj/NumCardContainer.o src/NumCardContainer.cpp
g++ -c -o obj/ClassicCardContainer.o src/ClassicCardContainer.cpp
g++ -c -o obj/TrumpCardContainer.o src/TrumpCardContainer.cpp
g++ -c -o obj/NumDeck.o src/NumDeck.cpp
g++ -c -o obj/ClassicDeck.o src/ClassicDeck.cpp
g++ -c -o obj/TrumpDeck.o src/TrumpDeck.cpp
g++ -c -o obj/NumHand.o src/NumHand.cpp
g++ -c -o obj/ClassicHand.o src/ClassicHand.cpp
g++ -c -o obj/TrumpHand.o src/TrumpHand.cpp
g++ -c -o obj/StarterPlayer.o src/StarterPlayer.cpp
g++ -c -o obj/NumPlayer.o src/NumPlayer.cpp
g++ -c -o obj/ClassicPlayer.o src/ClassicPlayer.cpp
g++ -c -o obj/TrumpPlayer.o src/TrumpPlayer.cpp
g++ -c -o obj/NumGame.o src/NumGame.cpp
g++ -c -o obj/ClassicGame.o src/ClassicGame.cpp
g++ -c -o obj/TrumpGame.o src/TrumpGame.cpp
g++ -c -o obj/main.o main.cpp
g++ -o main obj/main.o obj/NumCard.o obj/ClassicCard.o obj/TrumpCard.o obj/BasicCardContainer.o obj/NumCardContainer.o obj/ClassicCardContainer.o obj/TrumpCardContainer.o obj/NumDeck.o obj/ClassicDeck.o obj/TrumpDeck.o obj/NumHand.o obj/ClassicHand.o obj/TrumpHand.o obj/StarterPlayer.o obj/NumPlayer.o obj/ClassicPlayer.o obj/TrumpPlayer.o obj/NumGame.o obj/ClassicGame.o obj/TrumpGame.o
main.exe
cd obj 
del NumCard.o
del ClassicCard.o
del TrumpCard.o
del BasicCardContainer.o
del NumCardContainer.o
del ClassicCardContainer.o
del TrumpCardContainer.o
del NumDeck.o
del ClassicDeck.o
del TrumpDeck.o
del NumHand.o
del ClassicHand.o
del TrumpHand.o
del StarterPlayer.o
del NumPlayer.o
del ClassicPlayer.o
del TrumpPlayer.o
del NumGame.o
del ClassicGame.o
del TrumpGame.o
del main.o
cd .. 
rmdir obj
@echo on 