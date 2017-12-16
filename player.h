// player.h -- player interface for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#ifndef __COM_ZETTIX_CHINGA_PLAYER_H__
#define __COM_ZETTIX_CHINGA_PLAYER_H__

#include <iostream>
#include <vector>
#include "deck.h"

namespace com_zettix_chinga {

class Player {
 public:
  Player();
  ~Player(){}
  void add(Card c);
  bool operator==(Player &o) { return o.serial == serial;}
  friend std::ostream& operator<<(std::ostream &os, Player &p);
  Deck hand_;

 private:
  int serial;
};

std::ostream& operator<<(std::ostream &os, Player &p);

} // namespace
#endif
