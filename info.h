/*info.h*/
#include <string>

#pragma once

using namespace std;

class info{
	private:
		string* rooms;
		string* suspects;
		string* weapsons;
		bool* roomsSeen;
		bool* suspectsSeen;
		bool* weaponsSeen;
	public:
		info();
		~info();
		void printCardsSeen();
		


};
