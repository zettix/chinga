// card.cpp -- card implementation for chinga.
// (c) 2017 Sean Brennan
// MIT licence.

#include <vector>

#include "card.h"
#include "deck.h"
#include "game.h"

namespace com_zettix_chinga {

void Game::shuffle() {
  deck_.shuffle();
};

void Game::assemble() {
  std::vector<int> empty {};
  for (int y = 0; y < 2; y++) {
    for (int i = 1; i < 11; i++) {
      Card c {i, empty};
      deck_.add(c);
    }
  }

  for (int i = 1; i < 11; i++) {
    int link1 = ((i + 7) % 10) + 1;
    std::vector<int> single {link1};
    Card c {i, single};
    deck_.add(c);
  }

  for (int i = 1; i < 11; i++) {
    int link1 = ((i + 5) % 10) + 1;
    std::vector<int> single {link1};
    Card c {i, single};
    deck_.add(c);
  }

  for (int i = 1; i < 11; i++) {
    int link1 = ((i + 2) % 10) + 1;
    int link2 = ((i + 4) % 10) + 1;
    std::vector<int> single {link1, link2};
    Card c {i, single};
    deck_.add(c);
  }

  for (int i = 1; i < 11; i++) {
    int link1 = ((i + 3) % 10) + 1;
    int link2 = ((i + 6) % 10) + 1;
    std::vector<int> single {link1, link2};
    Card c {i, single};
    deck_.add(c);
  }

};

void Game::add(Card card) {
  deck_.add(card);
}

void Game::erase(int index) {
  if (index >= count()) {
    std::cerr << "Error: Out of bounds: " << index << std::endl;
  } else {
    deck_.erase(index);    
  }
}

Card Game::pop() {
  Card c = deck_.pop();
  return c;
}

Card Game::get(int index) {
  return deck_.get(index);
}

int Game::count() {
  return deck_.count();
}

void Game::setup(int num_players) {
  players_.clear();
  for (int i = 0; i < num_players; i++) {
    Player p;
    players_.push_back(p);
  }
  assemble();
  shuffle();
  up_card = deck_.pop();
}

void Game::deal(int cards) {
  for (int p = 0; p < players_.size(); p++) {
    for (int i = 0; i < cards; i++) {
      Card c = pop();
      players_[p].add(c);
    }
  }
}

bool Game::move(int player) {
  bool done = false;
  bool won = false;
  bool moved = false;
  bool moved_once = false;
  while (! done) {
    std::cout << "Up card: " << up_card << std::endl;
    if (up_card.links_.size() == 0 && ! moved) {
      moved = true;
      moved_once = true;
      up_card = players_[player].hand_.pop();
      if (up_card.links_.size() == 0) {
        done = true;
      }
    } else {
      for (int j = 0; j < players_[player].hand_.count(); j++) {
        if (players_[player].hand_.get(j).can_play(up_card)) {
          up_card = players_[player].hand_.pop(j);
          moved_once = true;
          moved = true;
          if (up_card.links_.size() == 0) {
            done = true;
          }
          break;
        }
      }
      if (! moved) done = true;
      moved = false;
    }  
    if (players_[player].hand_.count() == 0) {
      std::cout << "Player " << player << " Wins!!" << std::endl;
      won = true;
      done = true;
    }
    if (! moved_once) {
      Card c = deck_.pop();
      players_[player].hand_.add(c);
    }
    
  }
  std::cout << "Player " << player << " done. hand:\n" << players_[player].hand_;
  return won;
}

void Game::play() {
  bool won = false;
  int iter = 0;
  while (! won) {
    std::cout << "Round ...... " << iter << " ===========================" << std::endl;
    for (int i = 0; i < players_.size(); i++) {
      won = move(i);
      if (won) break;
    }
    iter++;
    if (iter > 14) {
      break;
    }
  }
}
   
std::ostream & operator<<(std::ostream& os, Game &g) {
  os << "Chinga Game State:" << std::endl;
  os << "Deck: " << g.count() << " cards." <<  std::endl;
  os << g.deck_ << std::endl;
  os << "Players: " << g.players_.size() << std::endl;
  for (int i = 0; i < g.players_.size(); i++) {
    os << "Player: " << i << std::endl;
    os << g.players_[i] << std::endl;
  }
  return os;
}

} // namespace

