Chinga: A card game.

Object: Get rid of your cards.

Start: A deck of cards is shuffled and cards are dealt to players.  A single card from the deck is turned over as the "up card".

Basic rules:
A player can play a card from their hand if either the up card has links to
their card's value, or if the up card has no links listed.  If a card is played,it becomes the new up card.  A player can continue playing until from their
hand until the up card has no links to cards in their hand.

When the player can play no further cards, if they did not play a card,
they draw one from the deck, and it's the next player's turn.

Cards have an in and out, it's face value and cards that can link to it.
For example, a 5 card can have 0 or more link cards, up to two.

On the edge:
5 - value
3 - link
2 - link
So players can hold the cards and see the value and links.

That's it, when you can't go you take a card.
Terminals cards (no links) will make it more difficult to go out.

Generate cards like so:
n types.
k terminals.

Say just 10 types.
but 60 cards.
20 terminals.
Duplicates possible.  But let's avoid that.
1st, terminals:
1...10, 1...10 : 20 cards.

Singles: 20 cards.
1:4
2:5
3:6
4:7
5:8
6:9
7:10
8:1
9:2
10:3
1:6
2:7
3:8
4:9
5:10
6:1
7:2
8:3
9:4
10:5
Doubles: 20 cards:
1:3 5
2:4 6
3:5 7
4:6 8
5:7 9
6:8 10
7:9 1
8:10 2
9:1 3
10 2 4
1:4 7
2:5 8
3:6 9
4:7 10
5:8 1
6:9 2
7:10 3
8:1 4
9:2 5
10:3 6


The code here just tests out the following parameters:
Number of players.
Dumb strategy of playing first available card that will match.
At the moment, 2-6 players seem to take anyhere from 4 to 14 rounds, so not
a bad card game, quite simple.
