/*Error Handling*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>


using namespace std;


/***********************************
 * Function: answer to bool
 * Description: takes in a string
 * and ture true if yes
 * Parameter: none
 * Pre-condition: a prompt was 
 * printed
 * Post-conditions: a bool is 
 * returned
 * *******************************/


bool answer_to_bool(string s){
   if(s == "y" || s=="yes" || s == "1" || s== "Yes" || s=="Y" || s=="yeah" || s=="Yeah"){
      return true;
   }else if(s == "n" || s=="no" || s == "0" || s== "No" || s=="N" || s=="nope" || s=="Nope"){
      return false;
   }else{
      cout << "Your answer is not understood" << endl;
      cout << "Please re-enter: ";
      cin >> s;
      return answer_to_bool(s);
   }
}

int string_to_int(){
   string s;
   cin >> s;
   bool x;

   int len = s.length();
   for(int i=0; i< len;i++){
      if(s.at(i) >= 48 && s.at(i) <= 57)
	 x = true;
      else {
	 x = false;
	 break;
      }
   }
   if(x == true){
      return atoi(s.c_str());
   }else{
      cout << "Please re-enter: ";
      return string_to_int();
   }

}


