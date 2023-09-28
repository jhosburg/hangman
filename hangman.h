#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cctype>
#include <ctime> 
#include <cstdlib>
using namespace std;

class Hangman
{
private:
	int attempts; //Variable attempts is used to keep track of the number of times the user has missed guessing the correct
	//character
	vector<string> wordList; //Vector wordList is used to store all the words read from the file
	string secretWord; //Variable secretWord is used to store the random word extracted from the vector wordList which would be the
	//word that the user has to guess
	int wordLength; //Variable wordLength is used to store the length of the variable secretWord (this variable is optional)

	const string filename = "base.txt"; //text file filled with words
	void selectRandomWord();	//function grabs a word at random
	void printHangman(int step); //prints image
	const string empty[8] = 
	{ "    +-----+",
	  "    |     |",
	            "|",
		        "|",
		        "|",
		        "|",
		        "|",
	"=============" };
	const string image[5] = 
	{ "   ___    ",
	  " / * * \\  ",
	  "(   o   ) ",
	  " \\ ___ /  ",
	  "    |     " };
	const string space = "          ";
public:
	Hangman();
	void playGame(); //This function creates an empty string variable (let’s call it blanks) to keep track of the correct characters (in
	//appropriate places) entered by the user
	void enterNewWords(); // Instead of displaying the contents of the file, the
	//function inserts the contents into the vector named wordlist
	bool isWin(string word); //checks if the test string matches with the secretWord or not
	void convertToUpper(); // This function is used to
	//convert all the characters in the variable secretWord to uppercase
	void readFromFile(); //also selects a random word
	//from the vector wordlist which is stored in the variable secretWord
	void setSecretWord(string word); //set the values of member variable secretWord
	string getSecretWord(); //get the values of member variable secretWord
	void setWordLength(int length); //set the values of member variable wordLength
	int getWordLength(); //get the values of member variable wordLength
	void displayMenu(); //displayMenu()is used to display menu with following options: Play, Enter New Words, Quit
};
