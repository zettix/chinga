// player.cc -- player impl for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#include <iostream>
#include <vector>
#include "player.h"

namespace com_zettix_chinga {

int player_serial_next = 0;

Player::Player(): serial(player_serial_next++) { }

void Player::add(Card card) {
  hand_.add(card);
}

std::ostream & operator<<(std::ostream &os, Player &p) {
  os << "[ player " << p.serial << "] hand: (" << std::endl;
  os << p.hand_;
  os << ")";
  return os;
}

} // namespace
