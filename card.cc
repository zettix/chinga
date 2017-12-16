// card.cpp -- card implementation for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#include "card.h"

namespace com_zettix_chinga {

int card_serial_next = 0;

Card::Card(int value, std::vector<int> links): value_(value), serial(card_serial_next++), links_(links) {
}

bool Card::can_play(Card &card) {
  for (int i = 0; i < card.links_.size(); i++) {
    if (card.links_[i] == value_) {
      return true;
    }
  }
  return false;
}

std::ostream & operator<<(std::ostream &os, Card &c) {
  os << "[" << c.value_ << "]<" << c.serial << ">-(";
  for (int i=0; i < c.links_.size(); i++) {
     os << c.links_[i] << ",";
  }
  os << ")";
  return os;
}

} // namespace
