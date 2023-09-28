#include "hangman.h"

//Constructor will initialize all the variables except the 
//vector with corresponding null values.
Hangman::Hangman()
{
	attempts = 0;
	secretWord = "";
	wordLength = 0;
	srand((unsigned)time(0));
}
void Hangman::playGame() //sets up game
{
	selectRandomWord();	//calls selectRandomWord() function
	string blanks = "";
	for (int i= 0; i < getWordLength(); i++) //grabs word length
	{
		blanks += "_"; // adds blanks per word length 5-6
	}
	string guessed = "";
	attempts = 0;	
	bool gameOver = false;
	while (!gameOver)
	{
		printHangman(attempts);
		cout << endl;
		cout << "Already guessed: "; //prints Already guessed
		for (unsigned int i = 0; i < guessed.length(); i++)
		{
			cout << guessed[i] << " ";
		}
		cout << endl << endl;
		cout << "Secret word: "; //prints Secret Word
		for (int i = 0; i < getWordLength(); i++)
		{
			cout << blanks[i] << " ";
		}
		cout << endl << endl;
		if (isWin(blanks))
		{
			cout << "You Won! Congratulations!" << endl; //prints You Won! Congratulations!
			gameOver = true; // ends the game if true
		}
		else if (attempts == 5) //if user passes 5 attempts, game ends
		{
			cout << "You Lost ...Game Over!" << endl; //prints You Lost ...Game Over!
			cout << "Correct word was: " << secretWord<<endl; //prints Correct word was:
			gameOver = true; // ends the game if true
		}
		if (!gameOver)
		{
			char letter;
			cout << "Enter a letter to guess: "; //prints Enter a letter to guess:
			cin >> letter; //user inputs letter
			letter = toupper(letter); //converts to uppercase
			while (guessed.find(letter) != string::npos || letter<65 || letter>95)
			{
				if (letter<65 || letter>95) // user inputs a value/letter
				{
					cout << "ONLY letters are allowed!" << endl; //prints ONLY letters are allowed!
				}
				else
				{
					cout << "This letter is already guessed earlier!" << endl; //prints This letter is already guessed earlier!
				}

				cout << "Enter a letter to guess: "; //prints Enter a letter to guess:
				cin >> letter; //user inputs letter
				letter = toupper(letter); //converts to uppercase
			}
			guessed += letter;
			if (secretWord.find(letter) != string::npos)
			{
				cout << "CORRECT!" << endl; //prints CORRECT!
				for (int i = 0; i < getWordLength(); i++)
				{
					if (secretWord[i] == letter)
					{
						blanks[i] = letter; //fills in blank
					}

				}
			}
			else
			{
				cout << "WRONG!" << endl; //prints WRONG!
				attempts++; // increments attempts by 1
			}
		}	
		
	}
	cout << endl;
}

void Hangman::printHangman(int step) //creates hangman image
{	
	cout << endl;
	int line = 0;
	cout << empty[line]<<endl;
	line++;
	cout << empty[line] << endl;
	for (int i = 0; i < step; i++)
	{
		line++;
		cout << image[i]<< empty[line] << endl;
	}
	for (int i = step; i < 5; i++)
	{
		line++;
		cout << space << empty[line] << endl;
	}
	line++;
	cout << empty[line] << endl;
}
void Hangman::enterNewWords() //add word to list
{
	cout << "Enter new single word to be added to word list file: "; //prints Enter new single word to be added to word list file:
	string word;
	cin >> word; //user inputs word
	
	while (word.length() < 5) //word needs to be 5 or more letters
	{
		cout << "Word length must be 5 or more!" << endl; //print Word length must be 5 or more!
		cout << "Enter new single word to be added to word list file: "; //prints Enter new single word to be added to word list file:
		cin >> word; //user inputs word
	}
	ofstream outputFile;
	outputFile.open(filename.c_str(), ios_base::app); //adds word to base file
	outputFile << word<< endl;
	cout << word<<" has been added to word list file"<<endl; //prints "input" has been added to word list file
	
}
//Function isWin() checks if the test string matches with the secretWord or not.
bool Hangman::isWin(string word) 
{
	return word == secretWord; //displays word
}

//Function convertToUpper() uses the toupper() function from the cctype library. 
//This function is used to convert all the characters in the variable
//secretWord to uppercase.
void Hangman::convertToUpper() 
{	
	for (int i = 0; i < getWordLength(); i++)
	{
		secretWord.at(i) = toupper(secretWord[i]);
	}	
}

//function inserts the contents into the vector named wordlist
void Hangman::readFromFile() 
{
	ifstream inputFile;
	inputFile.open(filename.c_str());
	if (inputFile)
	{
		string word;
		while (inputFile >> word)
		{
			wordList.push_back(word);
		}
	}
	else
	{
		cout << "File " << filename<<" could not be opened for reading..." << endl; //if base file fails, use these words
		cout << "Adding sample test words to word list" << endl;
		wordList.push_back("zebra");
		wordList.push_back("elephant");
		wordList.push_back("mouse");
	}
}

void Hangman::setSecretWord(string word) //sets the secretword
{
	secretWord = word;
	setWordLength(secretWord.length());
	convertToUpper();
}
string Hangman::getSecretWord() //returns word
{
	return secretWord;
}
void Hangman::setWordLength(int length) //sets the word length 5-6 letters
{
	wordLength = length;
}
int Hangman::getWordLength() //returns word length 5-6
{
	return wordLength;
}
//Function displayMenu() is used to display menu with following 
//options: Play, Enter New Words, Quit.
void Hangman::displayMenu() 
{
	cout << "1. Play"<<endl; //prints 1. Play
	cout << "2. Enter New Words" << endl; //prints 2. Enter New Words
	cout << "3. Quit" << endl; //prints 3. Quit
}

void Hangman::selectRandomWord() //picks a random word from base file
{	
	setSecretWord(wordList.at(rand() % wordList.size()));
}