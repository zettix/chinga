// card.cpp -- card implementation for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#include <algorithm>
#include <iostream>

#include "card.h"
#include "deck.h"

namespace com_zettix_chinga {

void Deck::add(Card card) {
  cards_.push_back(card);
}

void Deck::shuffle() {
   std::random_shuffle(cards_.begin(), cards_.end());
}

void Deck::erase(int index) {
  if (index >= count()) {
    std::cerr << " ERROR!! Out of bounds: " << index << std::endl;
  } else {
    cards_.erase(cards_.begin() + index);
  }
}

Card Deck::pop(int i) {
  Card c = get(i);
  cards_.erase(cards_.begin() + i);
  return c;
}

Card Deck::pop() {
  if (0 >= count()) {
    std::cerr << " ERROR!! Empty deck, returning 0<0>" << std::endl;
    return Card{0, std::vector<int>()};
  }
  Card c = cards_.front();
  cards_.erase(cards_.begin());
  return c;
}

Card Deck::get(int index) {
  if (index >= count()) {
    std::cerr << " ERROR!! Past end  returning 0<0>" << std::endl;
    return Card{0, std::vector<int>()};
  }
  return cards_[index];
}

int Deck::count() {
  return cards_.size();
}

std::ostream & operator<<(std::ostream& os, Deck &d) {
  for (int i=0; i < d.cards_.size(); i++) {
      os << d.cards_[i] << std::endl;
  }
  return os;
}

} // namespace
