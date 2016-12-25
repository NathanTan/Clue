/*player.cpp*/
#include "card.h"
#include "player.h"
#include "info.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Error_Handling.cpp"

using namespace std;

player::player(){

   this->current_room = "NULL";
   this->hand = NULL;

   this->hand_length = 0;

   this->current_room = "None";
}
player::~player(){
   delete [] hand;
}


void player::operator=(player &p){
   cout << "in overload" << endl;
//   delete [] hand;
//   delete [] game_sheet;
      this->hand = p.getHand();
   this->game_sheet = p.getGame_sheet();
}

//player::player(player &p){
//   cout << "in player copy constructor" << endl;
//   this->hand = p.getHand();
//   this->game_sheet = p.getGame_sheet();
//}

card* player::getHand(){
   return this->hand;
}

void player::setHand(card* h){
   this->hand = h;
}

info* player::getGame_sheet(){
   return this->game_sheet;
}

void player::addCardToHand(card c){
   card* temp = new card[hand_length + 1];
   if(hand != NULL){
      for(int i=0; i< hand_length; i++)
	 temp[i] = hand[i];
   delete [] hand;
   }

   hand = temp;
      hand_length++;
      hand[hand_length-1] = c;
}



void player::printHand(){
   cout << "Hand: \n" << endl;
   for(int i=0; i<hand_length; i++){
      cout << hand[i].name << endl;
   }
   cout << endl;
   return;
}

bool player::turn(game_state gs){
   srand(time(NULL));
   bool dice_rolled = false;
   bool turn_is_over = false;
   bool player_moved = false;
   int user_choice;
   int dice_roll = 0;
   int guess; // TODO rename and repurpose

   while(!turn_is_over){
      cout << "What would you like to do? " << endl;
      print_turn_options(dice_rolled, player_moved);
      cin >> user_choice;

      if(user_choice == 4){
	 return guess;
      }
      guess = execute_turn(gs, user_choice, &dice_rolled, &dice_roll, &player_moved);

   }
   return guess;
}

int player::roll_dice(){
   int num = (rand() % 12) + 1;
   return num;
}


//TODO: make sure incoming user choice is valid and not an char
bool player::execute_turn(game_state gs, int user_choice, bool* dice_rolled, int* dice_roll, bool * player_moved ){

   cout << "Executing turn" << endl;
   switch(user_choice){
      case 1: 
	 cout << "case 1" << endl;
	 if(*dice_rolled == false){
	    cout << "Rolling dice" << endl;
	    *dice_roll = roll_dice();
	    cout << "Number rolled: " << *dice_roll << endl;

	    *dice_roll %= 12;
	    *dice_roll++;
	    *dice_rolled = true;
	 }
	 return false;
      case 2:

	 cout << "case 2" << endl;

	 if(!(*player_moved)){
	    cout << "Moving character" << endl;
	    move_character(*dice_roll, *dice_rolled, gs);
	 
	    *player_moved = true;
	 }
	 return false;
	 case 3:
	 cout << "Guessing confidential" << endl;
	 return true;
      default: 
	 cout << "Default Error" << endl;
	 return false;
   }
   return false;
}

void player::print_turn_options(bool dice_rolled, bool player_moved){
   if(!dice_rolled)
      cout << "1) Roll Dice" << endl;
   if(!player_moved)
   cout << "2) Move Character" << endl;
   cout << "3) Guess Confidential File" << endl;
   cout << "4) End Turn" << endl;
}

void player::move_character(int roll, bool dice_rolled, game_state gs){
   string userChoice;
   bool userC;

   //TODO: fix the logic here to allow for both options (if valid)
   if(dice_rolled)
   {
      cout << "time to move your character" << endl;
      print_available_rooms(roll, gs);

      cout << "Current Room: " << current_room << endl;
   }
   else if(current_room == "conservatory" || current_room == "study" ||
	 current_room == "kitchen" || current_room == "lounge")
   {
      cout << "Would you like to use the secert passage way and travel to the " << current_room << "? " << endl;
      cin >> userChoice;
      userC = answer_to_bool(userChoice);
      if(current_room == "conservatory")
	 current_room = "lounge";
      else if(current_room == "study")
	 current_room = "kitchen";
      else if(current_room == "lounge")
	 current_room == "conservatory";
      else if(current_room == "kitchen")
	 current_room = "study";
      cout << "Current Room: " << current_room << endl;
   }
   else
   {
      cout << "You haven't rolled the dice yet" << endl;
   }

   return;
}

void player::print_available_rooms(int roll, game_state gs){

   cout << "Current Room: " << current_room << endl;
   cout << "Please select the room which you would like to enter" << endl;




   //If the roll is less not high enough, cut straight to the else
   //unless they can use a secert passage
   if(current_room == "study" && roll >= 4){
      if(gs.getStudy().access.adjacent1.distance <= roll){//4
	 cout << " - Hall" << endl;
      }
      if(gs.getStudy().access.adjacent2.distance <= roll)//7
	 cout << " - Library" << endl;
   }
   else if(current_room == "hall" && roll >= 4)
   {
      if(gs.getHall().access.adjacent1.distance <= roll)//4
	 cout << " - Study" << endl;
      if(gs.getHall().access.adjacent2.distance <= roll)//8
	 cout << " - Lounge" << endl;
      if(gs.getHall().access.corner1.distance <= roll)//7
	 cout << " - Library" << endl;
      if(gs.getHall().access.corner2.distance <= roll)//8
	 cout << " - Dining Room" << endl;
   }
   else if(current_room == "lounge") //will always have the option of secert_passage
   {
      if(gs.getLounge().access.adjacent1.distance <= roll)//8
	 cout << " - Hall" << endl;
      if(gs.getLounge().access.adjacent2.distance <= roll)//4
	 cout << " - Dining Room" << endl;
      cout << " - Conservatory" << endl;//secret_passage
   }
   else if(current_room == "dining_room" && roll >= 4)
   {
      if(gs.getDining_room().access.adjacent1.distance <= roll)//4
	 cout << " - Lounge" << endl;
      if(gs.getDining_room().access.adjacent2.distance <= roll)//11
	 cout << " - Kitchen" << endl;
      if(gs.getDining_room().access.corner1.distance <= roll)//8
	 cout << " - Hall" << endl;
      if(gs.getDining_room().access.corner2.distance <= roll)//7
	 cout << " - Ballroom" << endl;
   }
   else if(current_room == "kitchen") //will always have the option of secert_passage
   {
      if(gs.getKitchen().access.adjacent1.distance <= roll)//11
	 cout << " - Dining Room" << endl;
      if(gs.getKitchen().access.adjacent2.distance <= roll)//7
	 cout << " - Kitchen" << endl;
	 
      cout << " - Study" << endl;//seceret_pasage
   }
   else if(current_room == "ballroom" && roll <= 4)
   {
      if(gs.getBallroom().access.adjacent1.distance <= roll)//7
	 cout << " - Kitchen" << endl;
      if(gs.getBallroom().access.adjacent2.distance <= roll)//4
	 cout << " - Conservatory" << endl;
      if(gs.getBallroom().access.corner1.distance <= roll)//7
	 cout << " - Dining Room" << endl;
      if(gs.getBallroom().access.corner2.distance <= roll)//6
	 cout << " - Billiard Room" << endl;
   }
   else if(current_room == "conservatory") //will always have the option of secert_passage
   {
      if(gs.getConservatory().access.adjacent1.distance <= roll)//4
	 cout << " - Ballroom" << endl;
      if(gs.getConservatory().access.adjacent2.distance <= roll)//7
	 cout << " - Billiard Room" << endl;
	 cout << " - Lounge" << endl;//seceret_passage
   }
   else if(current_room == "billiard_room" && roll >= 4)
   {
      if(gs.getBilliard_room().access.adjacent1.distance <= roll)//7
	 cout << " - Conservatory" << endl;
      if(gs.getBilliard_room().access.adjacent2.distance <= roll)//4
	 cout << " - Library" << endl;
      if(gs.getBilliard_room().access.corner1.distance <= roll)//6
	 cout << " - Ballroom" << endl;
   }
   else if(current_room == "library" && roll >= 4)
   {
      if(gs.getLibrary().access.adjacent1.distance <= roll)//4
	 cout << " - Billiard Room" << endl;
      if(gs.getLibrary().access.adjacent2.distance <= roll)//7
	 cout << " - Study" << endl;
      if(gs.getLibrary().access.corner1.distance <= roll)//7
	 cout << " - Hall" << endl;
   }
   else if(current_room == "scarlet_start" && roll >= 8)
   {
      if(gs.getScarlet_start().access.adjacent1.distance <= roll)//8
	 cout << " - Lounge" << endl;
      if(gs.getScarlet_start().access.adjacent2.distance <= roll)//12
	 cout << " - Hall" << endl;
      if(gs.getScarlet_start().access.corner1.distance <= roll)//10
	 cout << " - Dining Room" << endl;
   }

   else if(current_room == "mustard_start" && roll >= 8)
   {
      if(gs.getMustard_start().access.adjacent1.distance <= roll)//8
	 cout << " - Lounge" << endl;
      if(gs.getMustard_start().access.adjacent2.distance <= roll)//8
	 cout << " - Hall" << endl;
      if(gs.getMustard_start().access.corner1.distance <= roll)//12
	 cout << " - Dining Room" << endl;
   }

   else if(current_room == "green_start" && roll >= 8)
   {
      if(gs.getGreen_start().access.adjacent1.distance <= roll)//8
	 cout << " - Lounge" << endl;
      if(gs.getGreen_start().access.adjacent2.distance <= roll)//10
	 cout << " - Hall" << endl;
      if(gs.getGreen_start().access.corner1.distance <= roll)//13
	 cout << " - Dining Room" << endl;
   }

   else if(current_room == "white_start" && roll >= 8)
   {
      if(gs.getWhite_start().access.adjacent1.distance <= roll)//8
	 cout << " - Lounge" << endl;
      if(gs.getWhite_start().access.adjacent2.distance <= roll)//13
	 cout << " - Hall" << endl;
      if(gs.getWhite_start().access.corner1.distance <= roll)//16
	 cout << " - Dining Room" << endl;
   }

   else if(current_room == "peacock_start" && roll >= 7)
   {
      if(gs.getPeacock_start().access.adjacent1.distance <= roll)//7
	 cout << " - Lounge" << endl;
      if(gs.getPeacock_start().access.adjacent2.distance <= roll)//10
	 cout << " - Hall" << endl;
      if(gs.getPeacock_start().access.corner1.distance <= roll)//9
	 cout << " - Dining Room" << endl;
   }

   else if(current_room == "plum_start" && roll >= 7)
   {
      if(gs.getPlum_start().access.adjacent1.distance <= roll)//ll
	 cout << " - Lounge" << endl;
      if(gs.getPlum_start().access.adjacent2.distance <= roll)//8
	 cout << " - Hall" << endl;
      if(gs.getPlum_start().access.corner1.distance <= roll)//10
	 cout << " - Dining Room" << endl;
   }

   else
      cout << "There are currently no rooms in range. Try again next turn." << endl;

   //maybe have this function return a tuple of options
   return;
}

bool player::guess_confidential(game_state gs){

   bool guess_is_correct = false;
   string room = 0;
   string weapon = 0;
   string suspect = 0;
   cout << "Guessing Confidential: " << endl;
   //print all cards
   //take in inputs as ints
   cout << "Please Enter the number of your guesses" << endl;

   cout << "Suspect: ";
   cin >> suspect;
   cout << "\nRoom: ";
   cin >> room;
   cout << "Weapon: ";
   cin >> weapon;

   //Instead of creating 3 card, just check against the card values
   //create_card(room, weapon, suspect);


   //TODO check to see if inputs are valid

   check_guess(gs, room, weapon, suspect);

   return false;
}

bool player::check_guess(game_state gs, string room, string weapon, string suspect){
   if(gs.getConfidentialAt(0).name == room &&
	 gs.getConfidentialAt(1).name == weapon &&
	 gs.getConfidentialAt(2).name == suspect){
      return true;
   }
   return false;
}

card * player::create_card(string name, string type){
   card new_card;
   new_card.name = name;
   new_card.type = type;
   return new_card;
}

card * player::create_card(string name, string type, game_state gs){
   card * new_card;
   new_card.type = type;

   int i = 0;
   if(type == "Suspect"){
      while(true){
	 if(name == gs.get_suspect(i)){
	    new_card->name = name;
	    new_card->type = type; 
	 }
	 i++;
      }
   }
   else if(type == "Room"){
      while(true){
	 if(name == gs.get_room(i)){
	    new_card->name = name;
	    new_card->type = type; 
	 }
	 i++;
      }
   }
   else if(type == "Weapon"){
      while(true){
	 if(name == gs.get_weapon(i)){
	    new_card->name = name;
	    new_card->type = type; 
	 }
	 i++;
      }
   }

   return new_card;
}

string player::getCharacter(){
   return character;
}

void player::setCharacter(string s){
   character = s;
}

string player::getCurrent_room(){
   return current_room;
}


void player::setCurrent_room(string s){
   current_room = s;
}

//pre-condition: player must have a valid character
void player::setStart_room(){

   if(character == "Miss Scarlet")
      current_room = "scarlet_start";
   else if(character == "Colonel Mustard")
      current_room = "mustard_start";
   else if(character == "Mrs. White")
      current_room = "white_start";
   else if(character == "Mr. Green")
      current_room = "green_start";
   else if(character == "Mrs. Peacock")
      current_room = "peacock_start";
   else if(character == "Professor Plum")
      current_room = "plum_start";

   return;
}




