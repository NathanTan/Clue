/*Clue.h*/
#include <string>
#include "card.h"
#include "player.h"
#include "game_state.h"

using namespace std;


void print_string_array(string*, int);
void dealcards(string*, string*, string*, int, player*);
void game(game_state, player*);
void shuffle_deck(card*);
void print_cards(card*);
