// deck.h -- deck interface for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#ifndef __COM_ZETTIX_CHINGA_DECK_H__
#define __COM_ZETTIX_CHINGA_DECK_H__

#include <iostream>
#include <vector>

#include "card.h"

namespace com_zettix_chinga {

class Deck {
 public:
  Deck() {}
  ~Deck() {}

  void add(Card card);
  void erase(int index);
  void shuffle();
  Card get(int index);
  Card pop();
  Card pop(int i);
  int count();

  friend std::ostream & operator<<(std::ostream& os, Deck &d);

 private:
  std::vector<Card> cards_;
};

std::ostream & operator<<(std::ostream& os, Deck &d);

} // namespace
#endif
