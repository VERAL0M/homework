#ifndef PLAY_H
#define PLAY_H

#include "deck.h"
#include <string>

using namespace std;


void push_back(Deck& deck, int value);


bool pop_front(Deck& deck, int& out_value);


void clear_deck(Deck& deck);


void show_deck(const Deck& deck, const string& name);

bool isWin(int c1, int c2);


bool readCards(Deck& deck);


void playDurachok();


void showMenu();


void showRules();

#endif