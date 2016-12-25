/*player.h*/
#include "card.h"
#include "info.h"
#include "game_state.h"
#include <string>

#pragma once
//using namespace std;

class player{

   private:

      int hand_length;
      card* hand;
      string current_room;
      info* game_sheet; //just a pointer, not an array
      string name;
      string character;
   public:
      player();
      ~player();
      void operator=(player&);
      //		player(player&);
      card* getHand();
      void setHand(card*);
      info* getGame_sheet();
      void setGame_sheet(info*);
      void addCardToHand(card);

      bool turn(game_state);
      void printHand();
      int roll_dice();
      bool execute_turn(game_state, int , bool* , int*, bool *);
      void print_turn_options(bool, bool);
      void move_character(int, bool, game_state);
      card * create_card(string, string);
      card * create_card(int, string, game_state);

      void print_available_rooms(int, game_state);

      bool guess_confidential(game_state);
      bool check_guess(game_state, string, string, string);

      string getCharacter();
      void setCharacter(string);

      string getCurrent_room();
      void setCurrent_room(string);

      void setStart_room();
};
