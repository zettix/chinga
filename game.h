// game.h -- game interface for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#ifndef __COM_ZETTIX_CHINGA_GAME_H__
#define __COM_ZETTIX_CHINGA_GAME_H__

#include <iostream>
#include <vector>

#include "card.h"
#include "deck.h"
#include "player.h"

namespace com_zettix_chinga {

class Game {
 public:
  Game() {}
  ~Game() {}

  void setup(int num_players);
  bool move(int player);
  void play();
  void add(Card card);
  void deal(int cards);
  Card get(int index);
  void erase(int index);
  Card pop();
  int count();
  friend std::ostream & operator<<(std::ostream& os, Game &g);

 private:
  Deck deck_;
  std::vector<Player> players_;
  void shuffle();
  void assemble();
  Card up_card {0, std::vector<int>()};
};

std::ostream & operator<<(std::ostream& os, Game &g);

} // namespace


#endif
