/*game_state.h*/
#include <string>
#include "card.h"
#include "room.h"

#pragma once

using namespace std;

class game_state{

   private:
      int num_of_players;
      string* rooms;
      string* weapons;
      string* suspects;

      string list_of_rooms[9];
      string list_of_suspects[6];
      string list_of_weapson[6];

      card deck[21];
      card confidential[3];

      //TODO keep these in an array instead
      room study;
      room hall;
      room lounge;
      room library;
      room dining_room;
      room billiard_room;
      room conservatory;
      room ballroom;
      room kitchen;

      //treating the player's start position as a room
      room scarlet_start;
      room mustard_start;
      room green_start;
      room white_start;
      room peacock_start;
      room plum_start;

   public:
      game_state(int n);
      string* getRooms();
      string* getSuspects();
      string* getWeapons();

      card* getConfidential();
      card getConfidentialAt(int);
      void setConfidentialAt(card, int);



      void printConfidential();


      int getNumberOfPlayers();
      void setNumberOfPlayers(int);

      ac getAdjacentRooms(string);

      room getStudy();
      room getHall();
      room getLounge();
      room getLibrary();
      room getDining_room();
      room getBilliard_room();
      room getConservatory();
      room getBallroom();
      room getKitchen();

      room getScarlet_start();
      room getMustard_start();
      room getGreen_start();
      room getWhite_start();
      room getPeacock_start();
      room getPlum_start();

      string get_list_of_rooms();
      string get_list_of_suspects();
      string get_list_of_weapons();

      void print_availble_rooms(int, game_state);


};
