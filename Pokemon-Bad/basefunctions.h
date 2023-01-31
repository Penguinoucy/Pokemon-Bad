/**
* @author JonnyT-chocomint, yujiroo & Penguinoucy
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <functional>
#include <array>
#include <set>
#include <map>
#include <ctime>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <fstream>
using namespace std;

/**
 * Takes a word and capitalizes it by changing the first letter to upper case and changing the rest to lower case.
 *
 * @param word a string of letters
 * @return the capitalized version of the word
 */
string capitalize(string word) {
	word[0] = toupper(word[0]);
  int length = sizeof(word)/sizeof(word[0]);
  for (int i = 1; i < length; i++) {
    word[i] = tolower(word[i]);      
    }
  return word;
}

/**
 * Takes an integer value and measures it in milliseconds. Delays the program for inserted amount of seconds.
 */
void sleep(int ms) {
  this_thread::sleep_for(chrono::milliseconds(ms));
}


/**
 * Takes a string and prints the string out in a typing animation.
 */
void typeOut(string sen) {
  for (int i = 0; sen[i] != '\0'; i++ ) {
  	   cout << sen[i] << flush; //print each index one at a time after each is flushed and slept for specified time
      sleep(20); //20
  	 if (sen[i] == ' ')
      {
  	   sleep(1); //1
      }
  }
}

/**
 * Takes a string and prints the string out in a typing animation fast.
 */
void typeOutFast(string sen) {
  for (int i = 0; sen[i] != '\0'; i++ ) {
  	   cout << sen[i] << flush;
      sleep(10);
  	 if (sen[i] == ' ')
      {
  	   sleep(1);
      }
  }
}
