#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include "Clue.h"
#include "card.h"
#include "game_state.h"
#include "player.h"



/*
 * current issue: IF you don't roll a high enough number, you don't get any option (rooms to approach)
 * Also! once the dice is rolled for player 1 it can't be rolled for player 2 TODO fix
*/

using namespace std;

int main(){
   srand(time(NULL));
   card confidential_file[3];
   int conf[3];

   conf[0] = rand() % 9;
   conf[1] = rand() % 6;
   conf[2] = rand() % 6;

   string rooms[9] = {"Hall", "Lounge", "Dining Room", "Kitchen", "Ball Room", "Conservatory",
      "Billiard Room", "Library", "Study"};
   string suspects[6] = {"Miss Scarlet", "Colonel Mustard", "Mrs. White", "Mr. Green", "Mrs. Peacock",
      "Professor Plum"};
   string weapons[6] = {"Knife", "Candlestick", "Revolver", "Rope", "Lead Pipe", "Wrench" };

   //taking the cards from the "deck" and putting them into the confidential file

   confidential_file[0].name = rooms[conf[0]];
   confidential_file[0].type = "room";
   confidential_file[1].name = suspects[conf[1]];
   confidential_file[1].type = "suspect";
   confidential_file[2].name = weapons[conf[2]];
   confidential_file[2].type = "weapon";


   int num_of_players = 2;
   cout << "Welcome to Clue!" << endl;
   while(num_of_players > 6 || num_of_players <= 0){
      cout << "Please enter a number of players(2-6)" << endl;
      //TODO	getline(cin,num_of_players);
      cout << "2" << endl;
   }
   game_state clue(num_of_players);


   clue.setConfidentialAt(confidential_file[0], 0);
   clue.setConfidentialAt(confidential_file[1], 1);
   clue.setConfidentialAt(confidential_file[2], 2);

   player* players;
   players = new player[num_of_players];
   dealcards(rooms, suspects, weapons,num_of_players, players);

   for(int i=0; i< num_of_players; i++){

      int temp_character = 0;
      cout << "Player " << i+1<< endl;
      cout << "\nPick your character" << endl;

      print_string_array(suspects, 6);
      //TODO make sure is valid
      //TODO make it so 2 players cannot occupie the same character
      cin >> temp_character;
      players[i].setCharacter(suspects[temp_character - 1]);
      players[i].setCurrent_room(suspects[temp_character - 1]);
   
      players[i].setStart_room();
   }

   for(int i=0; i< num_of_players; i++){
      cout << "\nPlayer " << i+1 << "'s ";
      players[i].printHand();

      cout << "Character: " << players[i].getCharacter()<< endl;
   }

   game(clue, players);
   clue.printConfidential();	

   delete [] players;
   return 0;
}


void dealcards(string* rooms, string* suspects, string* weapons, int num, player* players){


   card deck[22];
   deck[21].name = "NULL";
   //put room cards in deck
   for(int i=0; i<9; i++){
      deck[i].name = rooms[i]; 
      deck[i].type = "room";
   } 
   //put suspect cards in deck
   for(int i=0; i<6; i++){
      deck[i+9].name = suspects[i];
      deck[i+9].type = "suspect";
   }
   //put weapons cards in deck
   for(int i=0; i<6; i++){
      deck[i+15].name = weapons[i];
      deck[i+15].type = "weapon";
   }
   //shuffle deck
   shuffle_deck(deck);

   print_cards(deck);

   for(int i=0; i<18; i++){
      if(deck[i].name != "X"){
	 players[i % num].addCardToHand(deck[i]);
      }
   }
   return;
}


void game(game_state gs, player* players){
   bool win;
   for(int i=0;;i++){
      i %= gs.getNumberOfPlayers();
      cout << "Player " << i+1 << "'s turn" << endl;
      win = players[i].turn(gs);
      cout << "Ending turn\n" << endl;
      if(win){
	 break;
      }
   }
   //turn 
   //make turn return a bool if the player guessed correctly

   cout << "ending game" << endl;
   return;
}

void shuffle_deck(card* d){
   int r = rand() % 17;
   card temp;
   for(int i=0; i<50; i++){
      for(int j=0; j<18; j++){
	 r = rand() % 17;
	 temp = d[j];
	 d[j] = d[r];
	 d[r] = temp;
      }
   }
   return;
}

void print_cards(card* d){
   for(int i=0; i< 55;i++){
      if(d[i].name != "NULL"){
	 cout << "card: " << d[i].name << endl;
      }
      else
	 return;
   }
   return;
}


void print_string_array(string * ar, int length){
   for(int i=0; i < length; i++)
      cout << "   " << i+1 << ") " << ar[i];
   cout << endl;
   return;
}


