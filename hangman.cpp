#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

class Hangman
{

};

int game()
{
	//start screen
	//char start{};

	/*cout << "  Hangman  " << endl;
	cout << "____" << endl;
	cout << "|  |" << endl;
	cout << "|  O" << endl;
	cout << "| /|\\" << endl;
	cout << "| / \\" << endl;
	cout << "|" << endl;
	cout << "|______" << endl;*/

	//cout << "\nPress any key then hit enter to start: ";
	//cin >> start;

	//set variables for game
	int guesses{ 6 }; //allowed guesses
	char guess;
	bool correctGuess = false;
	string word; //word to guess
	string wordList[99]; //an array of 100 strings
	char guessed[7]; //array of guesses

	guessed[0] = '\0';
	for (int i = 1; i < 6; i++)
	{
		guessed[i] = '-';
	}
	guessed[6] = '\0';


	//get random word
	srand(time(NULL)); //for obtaining a random word from the array
	ifstream randWord; //for reading in variable
	randWord.open("Words.txt");

	for (int i = 0; i < 99; i++)
	{
		randWord >> wordList[i]; //filling up array
		//cout << wordList[i] << endl; //for testing the list
	}
	int randNum = rand() % 100; //returns random value between 0-99
	word = wordList[randNum];
	//cout << word << endl; //for testing the random word
	randWord.close();

	string answer(word.length(), '_');
	//cout << answer << endl;

	while (guesses >= 0)
	{
		//reset bool
		correctGuess = false;

		//show relevant info
		cout << "\nWord to guess: ";
		cout << answer << endl;
		cout << "\nWord length: " << answer.length();
		cout << "\nGuesses remaining: " << guesses;
		if (guessed[0] == '\0')
		{
			cout << endl;
		}
		else
		{
			cout << "\nLetters guessed: " << guessed << endl;
		}
		cout << "\n\nGuess a letter: ";
		cin >> guess;

		//check matching letters
		for (int i = 0; i < answer.length(); i++)
		{
			if (word[i] == guess)
			{
				answer[i] = guess;
				correctGuess = true;
			}
		}
		if (word == answer)
		{
			cout << "\n\nWell done, you have guessed the word: " << answer << endl;
			break;
		}
		if (correctGuess == false)
		{
			guesses--;
			cout << guess << " is not a matching letter" << endl;
		}
		else
		{
			cout << guess << " is a matching letter" << endl;
		}



		if (guesses = 6)
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|______" << endl;

			break;
		}
		case 5:
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|  O" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|______" << endl;

			if (correctGuess == false)
			{
				guessed[0] = guess;
			}

			break;
		}
		case 4:
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|  O" << endl;
			cout << "|  |" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|______" << endl;

			if (correctGuess == false)
			{
				guessed[1] = guess;
			}

			break;
		}
		case 3:
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|  O" << endl;
			cout << "| /|" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|______" << endl;

			if (correctGuess == false)
			{
				guessed[2] = guess;
			}

			break;
		}
		case 2:
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|  O" << endl;
			cout << "| /|\\" << endl;
			cout << "|" << endl;
			cout << "|" << endl;
			cout << "|______" << endl;

			if (correctGuess == false)
			{
				guessed[3] = guess;
			}

			break;
		}
		case 1:
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|  O" << endl;
			cout << "| /|\\" << endl;
			cout << "| / " << endl;
			cout << "|" << endl;
			cout << "|______" << endl;

			if (correctGuess == false)
			{
				guessed[4] = guess;
			}

			break;
		}
		case 0:
		{
			cout << "____" << endl;
			cout << "|  |" << endl;
			cout << "|  O" << endl;
			cout << "| /|\\" << endl;
			cout << "| / \\" << endl;
			cout << "|" << endl;
			cout << "|______" << endl;
			cout << "\nGame over!" << endl;
			guesses = -1;
			break;
		}
		default:
			cout << "Error.";
		}
	}
	return 0;
}