# Proiect POO: Game of 21/Blackjack

For the OOP project, I chose to make a modified game of Blackjack/21, based on the Resident Evil 7 incarnation. This program utilizes base OOP notions like classes and objects.

## Rules

#### Cards and Decks

- Normal cards are numbered, 1 to 11. When a player has a card drawn, its number is added to their score.
- A normal deck is made out of 11 cards, each with a different number. Both players share this deck, so if a player has drawn the 1 Card, then other players can't draw it for that round.

#### Gameplay

- Each match of 21 takes place over multiple rounds.
- Each round, players draw cards from a shared deck in an attempt to get as much as 21 points, without going over.
- On their turn, a player can choose to stay or hit. If they hit, they'll be dealt a random card from the deck. Staying ends the round without drawing a card. Trying to hit while the deck is empty also counts as staying.
- Additionally, a player can choose to view the current state of the table, seeing each player's hand.
- A round ends when both players choose to stay, one after another.
- At the end of the round, the winner is determined this way: First, if one player is above 21 and the other isn't, the former wins. Otherwise, the player closest to 21 wins.
- Decks are remade and shuffled between rounds.
- When a player loses a round, they lose Health (1 by default). When a player reaches 0 Health, they lose the match.

## How to play

- Clone the repository and run the program using the build.bat file using the following commands: 'build', then 'main.exe' with CMD.

## Explaining the Code

-Card.cpp is used in initialising, copying and showing cards.
-Deck.cpp is used to create decks, shuffle them, add or remove cards from them and show them.
-Player.cpp manages a player's health, hand and score.
-Game.cpp contains the Match function, that acts as the main game. It uses concepts from the other classes.
-main.cpp has the newMatch function, which create a set of players and rules for the purposes of a 21 match.

## Not yet implemented
- [ ] Trump Cards.
- [ ] Different game modes.
- [ ] AI for computer dealer, used for future singleplayer based modes.
