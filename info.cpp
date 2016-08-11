/*info.cpp*/
#include <string>
#include <iostream>
#include "info.h"

using namespace std;

info::info(){

	this->rooms = {"Hall", "Lounge", "Dining Room", "Kitchen", "Ball Room", "Conservatory",
	   		"Billiard Room", "Library", "Study"};
	this->suspects = {"Miss Scarlet", "Colonel Mustard", "Mrs. White", "Mr. Green", "Mrs.Peacock",
	   		"Professor Plum"};
	this->weapons = {"Knife", "Candlestick", "Revolver", "Rope", "Lead Pipe", "Wrench" };
}

info::~info(){
	delete [] rooms;
	delete [] suspects;
	delete [] weapons;
}

void info::printCardsSeen(){
	cout << "Cards seen -" << endl;
	cout <<　"Rooms: " << endl;
	for(int i=0; i<8; i++){
		if(roomsSeen[i])
			cout << "   - " << rooms[i] << endl;
		}
	cout << "Suspects: " << endl;
	for(int i=0; i<5; i++)
		if(suspectsSeen[i])
			cout << "   - " << suspects[i] << endl;
	for(int i=0; i<5; i++)
		if(weaponsSeen[i])
			cout << "   - " << weapons[i] << endl;



}
