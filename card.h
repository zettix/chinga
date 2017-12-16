// card.h -- card interface for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#ifndef __COM_ZETTIX_CHINGA_CARD_H__
#define __COM_ZETTIX_CHINGA_CARD_H__

#include <iostream>
#include <vector>

namespace com_zettix_chinga {

class Card {
 public:
  Card(int value, std::vector<int> linkypoos);
  ~Card(){}
  int get_value() {return value_;}
  bool can_play(Card &card);
  bool operator==(Card &o) { return o.serial == serial;}
  std::vector<int> links_;

  friend std::ostream& operator<<(std::ostream &os, Card &c);

 private:
  int serial;
  int value_;
};

std::ostream& operator<<(std::ostream &os, Card &c);

} // namespace
#endif
