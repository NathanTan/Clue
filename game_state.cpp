/*game_state.cpp*/
#include <string>
#include <iostream>
#include <stdlib.h>
#include "game_state.h"
#include "room.h"

using namespace std;


game_state::game_state(int n){
   num_of_players = n;

   deck[0].name = "Hall";
   deck[1].name = "Lounge";
   deck[2].name = "Dining Room";
   deck[3].name = "Kitchen";
   deck[4].name = "Ball Room";
   deck[5].name = "Conservatory";
   deck[6].name = "Billiard Room";
   deck[7].name = "Library";
   deck[8].name = "Study";
   
   deck[0].type = "room";
   deck[1].type = "room";
   deck[2].type = "room";
   deck[3].type = "room";
   deck[4].type = "room";
   deck[5].type = "room";
   deck[6].type = "room";
   deck[7].type = "room";
   deck[8].type = "room";

   deck[9].name = "Miss Scarlet";
   deck[10].name = "Colonel Mustard";
   deck[11].name = "Mrs. White";
   deck[12].name = "Mr. Green";
   deck[13].name = "Mrs.Peacock";
   deck[14].name = "Professor Plum";


   deck[9].type = "suspect";
   deck[10].type = "suspect";
   deck[11].type = "suspect";
   deck[12].type = "suspect";
   deck[13].type = "suspect";
   deck[14].type = "suspect";

   deck[15].name = "Knife";
   deck[16].name = "Candlestick";
   deck[17].name = "Revolver";
   deck[18].name = "Rope";
   deck[19].name = "Lead Pipe";
   deck[20].name = "Wrench";

   deck[15].type = "Knife";
   deck[16].type = "Candlestick";
   deck[17].type = "Revolver";
   deck[18].type = "Rope";
   deck[19].type = "Lead Pipe";
   deck[20].type = "Wrench";

   for(int i = 0; i < 9; i++){
         list_of_rooms[i] = deck[i].name;
   }
   for(int i = 0; i < 6; i++){
         list_of_suspects[i] = deck[i + 9].name;
   }
   for(int i = 0; i < 6; i++){
         list_of_weapson[i] = deck[i + 15].name;
   }



   study.name = "Study";
   study.access.adjacent1.name = "hall";
   study.access.adjacent1.distance = 4;
   study.access.adjacent2.name = "library";
   study.access.adjacent2.distance = 7;
   study.access.secret_passage.name = "kitchen";
   study.access.secret_passage.distance = 0;
   study.access.corner1.name = "NULL";
   study.access.corner2.name = "NULL";

   hall.name = "Hall";
   hall.access.adjacent1.name = "study";
   hall.access.adjacent1.distance = 4;
   hall.access.adjacent2.name = "lounge";
   hall.access.adjacent2.distance = 8;
   hall.access.secret_passage.name = "NULL";
   hall.access.corner1.name = "library";
   hall.access.corner1.distance = 7;
   hall.access.corner2.name = "dining_room";
   hall.access.corner2.distance = 8;

   lounge.name = "Lounge";
   lounge.access.adjacent1.name = "hall";
   lounge.access.adjacent1.distance = 8;
   lounge.access.adjacent2.name = "dining_room";
   lounge.access.adjacent2.distance = 4;
   lounge.access.secret_passage.name = "conservatory";
   lounge.access.secret_passage.distance = 0;
   lounge.access.corner1.name = "NULL";
   lounge.access.corner2.name = "NULL";

   dining_room.name = "Dining Room";
   dining_room.access.adjacent1.name = "lounge";
   dining_room.access.adjacent1.distance = 4;
   dining_room.access.adjacent2.name = "kitchen";
   dining_room.access.adjacent2.distance = 11;
   dining_room.access.secret_passage.name = "NULL";
   dining_room.access.secret_passage.distance = 0;
   dining_room.access.corner1.name = "hall";
   dining_room.access.corner1.distance = 8;
   dining_room.access.corner2.name = "ballroom";
   dining_room.access.corner2.distance = 7;

   kitchen.name = "Kitchen";
   kitchen.access.adjacent1.name = "dining_room";
   kitchen.access.adjacent1.distance = 11;
   kitchen.access.adjacent2.name = "ballroom";
   kitchen.access.adjacent2.distance = 7;
   kitchen.access.secret_passage.name = "study";
   kitchen.access.secret_passage.distance = 0;
   kitchen.access.corner1.name = "NULL";
   kitchen.access.corner2.name = "NULL";

   ballroom.name = "Ballroom";
   ballroom.access.adjacent1.name = "kitchen";
   ballroom.access.adjacent1.distance = 7;
   ballroom.access.adjacent2.name = "conservatory";
   ballroom.access.adjacent2.distance = 4;
   ballroom.access.secret_passage.name = "NULL";
   ballroom.access.corner1.name = "dining_room";
   ballroom.access.corner1.distance = 7;
   ballroom.access.corner2.name = "billiard_room";
   ballroom.access.corner2.distance = 6;

   conservatory.name = "Conservatory";
   conservatory.access.adjacent1.name = "ballroom";
   conservatory.access.adjacent1.distance = 4;
   conservatory.access.adjacent2.name = "billiard_room";
   conservatory.access.adjacent2.distance = 7;
   conservatory.access.secret_passage.name = "lounge";
   conservatory.access.secret_passage.distance = 0;
   conservatory.access.corner1.name = "NULL";
   conservatory.access.corner2.name = "NULL";

   billiard_room.name = "Billiard Room";
   billiard_room.access.adjacent1.name = "conservatory";
   billiard_room.access.adjacent1.distance = 7;
   billiard_room.access.adjacent2.name = "library";
   billiard_room.access.adjacent2.distance = 4;
   billiard_room.access.secret_passage.name = "NULL";
   billiard_room.access.corner1.name = "ballroom";
   billiard_room.access.corner1.distance = 6;
   billiard_room.access.corner2.name = "NULL";

   library.name = "Library";
   library.access.adjacent1.name = "billiard_room";
   library.access.adjacent1.distance = 4;
   library.access.adjacent2.name = "study";
   library.access.adjacent2.distance = 7;
   library.access.secret_passage.name = "NULL";
   library.access.corner1.name = "hall";
   library.access.corner1.distance = 7;
   library.access.corner2.name = "NULL";

   scarlet_start.access.adjacent1.name = "lounge";
   scarlet_start.access.adjacent1.distance = 8;
   scarlet_start.access.adjacent2.name = "hall";
   scarlet_start.access.adjacent2.distance = 12;
   scarlet_start.access.secret_passage.name = "NULL";
   scarlet_start.access.corner1.name = "dining_room";
   scarlet_start.access.corner1.distance = 10;
   scarlet_start.access.corner2.name = "NULL";
 
   mustard_start.access.adjacent1.name = "lounge";
   mustard_start.access.adjacent1.distance = 8;
   mustard_start.access.adjacent2.name = "dining_room";
   mustard_start.access.adjacent2.distance = 8;
   mustard_start.access.secret_passage.name = "NULL";
   mustard_start.access.corner1.name = "hall";
   mustard_start.access.corner1.distance = 12;
   mustard_start.access.corner2.name = "NULL";
 
   green_start.access.adjacent1.name = "ballroom";
   green_start.access.adjacent1.distance = 8;
   green_start.access.adjacent2.name = "conservatory";
   green_start.access.adjacent2.distance = 10;
   green_start.access.secret_passage.name = "NULL";
   green_start.access.corner1.name = "billiard_room";
   green_start.access.corner1.distance = 13;
   green_start.access.corner2.name = "NULL";
   
   white_start.access.adjacent1.name = "ballroom";
   white_start.access.adjacent1.distance = 8;
   white_start.access.adjacent2.name = "kitchen";
   white_start.access.adjacent2.distance = 13;
   white_start.access.secret_passage.name = "NULL";
   white_start.access.corner1.name = "dining_room";
   white_start.access.corner1.distance = 16;
   white_start.access.corner2.name = "NULL";
   
   peacock_start.access.adjacent1.name = "lounge";
   peacock_start.access.adjacent1.distance = 7;
   peacock_start.access.adjacent2.name = "billiard_room";
   peacock_start.access.adjacent2.distance = 10;
   peacock_start.access.secret_passage.name = "NULL";
   peacock_start.access.corner1.name = "ballroom";
   peacock_start.access.corner1.distance = 9;
   peacock_start.access.corner2.name = "NULL";

   plum_start.access.adjacent1.name = "library";
   plum_start.access.adjacent1.distance = 11;
   plum_start.access.adjacent2.name = "study";
   plum_start.access.adjacent2.distance = 8;
   plum_start.access.secret_passage.name = "NULL";
   plum_start.access.corner1.name = "hall";
   plum_start.access.corner1.distance = 10;
   plum_start.access.corner2.name = "NULL";

}

string* game_state::getRooms(){
   return this->rooms;
}
//setRooms(){;
string* game_state::getSuspects(){
   return this->suspects;
}
//setSuspects();
string* game_state::getWeapons(){
   return this->weapons;
}

card* game_state::getConfidential(){
   return this->confidential;
}

card game_state::getConfidentialAt(int pos){
   return this->confidential[pos];
}

void game_state::setConfidentialAt(card c, int pos){
   if(pos <= 2)
      this->confidential[pos] = c;
}

void game_state::printConfidential(){

   cout << "//////////////////////" << endl;
   cout << "/   -CONFIDENTIAL-   /" << endl;
   cout << "//////////////////////\n" << endl;

   for(int i=0; i<3; i++){
      cout << "  | " << confidential[i].name << " | " << endl;
   }

}

int game_state::getNumberOfPlayers(){
   return this->num_of_players;
}

void game_state::setNumberOfPlayers(int num){
   this->num_of_players = num;
}



ac game_state::getAdjacentRooms(string room){
   if(room == "study"){
      return study.access;
   }else if(room == "hall"){
      return hall.access;
   }else if(room == "lounge"){
      return lounge.access;
   }else if(room == "library"){
      return library.access;
   }else if(room == "dining_room"){
      return dining_room.access;
   }else if(room == "billiard_room"){
      return billiard_room.access;
   }else if(room == "conservatory"){
      return conservatory.access;
   }else if(room == "ballroom"){
      return ballroom.access;
   }else if(room == "kitchen"){
      return kitchen.access;
   }
   else{
      cout << "//////////////////////ERROR//////////////////" << endl;
   }

return NULL;
}

room game_state::getStudy(){
   return study;
}
room game_state::getHall(){
   return hall;
}
room game_state::getLounge(){
   return lounge;
}
room game_state::getLibrary(){
   return library;
}

room game_state::getDining_room(){
   return dining_room;
}
room game_state::getBilliard_room(){
   return billiard_room;
}
room game_state::getConservatory(){
   return conservatory;
}
room game_state::getBallroom(){
   return ballroom;
}
room game_state::getKitchen(){
   return kitchen;
}

room game_state::getScarlet_start(){
   return scarlet_start;
}
room game_state::getMustard_start(){
   return mustard_start;
}
room game_state::getGreen_start(){
   return green_start;
}
room game_state::getWhite_start(){
   return white_start;
}
room game_state::getPeacock_start(){
   return peacock_start;
}
room game_state::getPlum_start(){
   return plum_start;
}
string game_state::get_list_of_rooms(){
   return list_of_rooms;
}
string game_state::get_list_of_suspects(){
      return list_of_suspects;
}
string game_state::get_list_of_weapons(){
      return list_of_weapson;
}

/*
   void game_state::printAllCards(){
   cout << " 0 - " << study.name;
   }
   */






