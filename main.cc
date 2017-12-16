#include <iostream>

#include "card.h"
#include "deck.h"
#include "game.h"

using namespace std;
using namespace com_zettix_chinga;

int main(int argc, char **argv) {

  Game game;

  cout << "Welcome to Chinga. \n  How many players?" << endl;
  int num_players;
  cin >> num_players;
  cout << "Starting game with " << num_players << " players." << endl;
  game.setup(num_players);
  game.deal(7);
  cout << game << endl;
  cout << "Get ready..." << endl;
  game.play();
}
