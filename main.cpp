#include "hangman.h"

int getMenu(Hangman &hangman)
{
	hangman.displayMenu(); //displays start menu
	int choice;
	cout << "? ";
	cin >> choice;
	while (choice < 1 || choice>3) //if user input is not 1,2, or 3 display message
	{
		cout << "Invalid choice !" << endl;
		cout << "? ";
		cin >> choice; //user input
	}
	return choice;
}
int main()
{
	Hangman hangman;
	hangman.readFromFile(); //selects random word
	int choice = getMenu(hangman); //assigns users choice
	while (choice != 3) //options 3, quit
	{
		switch (choice)
		{
			case 1: hangman.playGame(); //option 1, play
				break;
			case 2: hangman.enterNewWords(); //option 2, enter new words
				break;
		}
		choice = getMenu(hangman);

	}
	cout << "Thanks for playing !" << endl;
}