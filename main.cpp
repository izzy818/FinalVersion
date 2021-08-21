#include "Gamer.h"
#include "Manager.h"
#include "Hangman.h"
//#include "ReadWords.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
using namespace std;


list<Gamer> load_gamers() {
    ifstream gamers_file;
    gamers_file.open("gamers.txt");

    list<Gamer> gamers;

    string line;
    if (gamers_file.is_open()) {
        while (getline(gamers_file, line)) {

            stringstream ss(line);

            int regNo;
            ss >> regNo;

            string first;
            ss >> first;

            string second;
            ss >> second;

            string full_name = first + " " + second;

            Gamer g = Gamer(full_name, regNo);
            gamers.push_back(g);
        }
        gamers_file.close();
    }

    return gamers;
}

list<Manager> load_managers() {
    ifstream managers_file;
    managers_file.open("managers.txt");

    list<Manager> managers;

    string line;
    if (managers_file.is_open()) {
        while (getline(managers_file, line)) {

            stringstream ss(line);

            int regNo;
            ss >> regNo;

            string first;
            ss >> first;

            string second;
            ss >> second;

            string full_name = first + " " + second;

            Manager m = Manager(full_name, regNo);
            managers.push_back(m);
        }
        managers_file.close();
    }

    return managers;
}

int gamer() {
    // load gamers from file.
    list<Gamer> gamers = load_gamers();
    do {
        cout << "Enter your full name: ";

        string full_name;
        cin.ignore();
        getline(cin, full_name);

        // try to find the right gamer
        Gamer g("", 0);

        int highRegNum (0);

        list<Gamer>::iterator it;
        for (it = gamers.begin(); it != gamers.end(); it++)
        {
            //cout << it->getRegNo() << " ... " << it->getName() << endl;
            if (it->getName() == full_name)
            {
                g = Gamer(it->getName(), it->getRegNo());
                //cout << "Found ..." << full_name << endl;
            }
            if (it->getRegNo() > highRegNum)
            {
                highRegNum = it->getRegNo();
            }
        }

        //cout << "Highest reg num " << highRegNum << endl;
        //cout << "got it " << g.getName() << " and reg no " << g.getRegNo() << endl;

        //if validation fails (regno = 0), create new gamer profile
        if (g.getRegNo() == 0)
        {
            //set new reg no
            highRegNum++;
            Gamer g = Gamer(full_name, highRegNum);
            gamers.push_back(g);
            cout << g.getName() << " you are a new gamer, your reg. no is: " << g.getRegNo() << endl;
        }

        // temporary to show we've loaded them properly.
        /* {
            list<Gamer>::iterator it;
            for (it = gamers.begin(); it != gamers.end(); it++)
            {
                cout << it->getRegNo() << " ... " << it->getName() << endl;
            }
        }*/


        cout << "Welcome " << g.getName() << ", reg. no: " << g.getRegNo() << endl;
        //if validation fails (regno = 0), create new gamer profile

        cout << "1) Play game" << endl;
        cout << "2) Your statistics" << endl;
        cout << "3) Display top 10" << endl;
        cout << "4) Exit game" << endl;

        char option;
        cin >> option;

        if (option == '1') {
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

                switch (guesses)
                {
                case 6:
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
        }
        else if (option == '2') {
            // statistics
            return 0;
        }
        else if (option == '3') {
            // display top 10
            return 0;
        }
        else if (option == '4') {
            cout << "Exiting";
            return 0;
        }
        else {
            cout << "Invalid option: " << option << endl;
            return -1;
        }
    }
    while (1);
        return 0;
    
}

//error handling TODO

int manager() {
    //load managers from file
    list<Manager> managers = load_managers();

    //show they loaded
    {
        list<Manager>::iterator it;
        for (it = managers.begin(); it != managers.end(); it++) {
            cout << it->getRegNo() << " ... " << it->getName() << endl;
        }
    }

    cout << "Enter your full name:" << endl;

    string full_name;
    cin.ignore();
    getline(cin, full_name);

    // try to find the right manager
    Manager m("", 0);

    list<Manager>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++) {
        cout << it->getRegNo() << " ... " << it->getName() << endl;
        if (it->getName() == full_name) {
            m = Manager(it->getName(), it->getRegNo());
            cout << "Found ... " << full_name << endl;
        }
    }

    //if validation fails, return to login?

    cout << "1) Reset game" << endl;
    cout << "2) Change game levels" << endl;
    cout << "3) Add another manager" << endl;
    cout << "4) Set the word file" << endl;
    cout << "5) Exit game" << endl;

    char option;
    cin >> option;

    switch (option) {
    case '1':
        // TODO:
        break;
    case '2':
        // TODO:
        break;
    case '3':
        // TODO:
        break;
    case '4':
        // TODO:
        break;
    case '5':
        //TODO
        break;
    default:
        cout << "Invalid option: " << option << endl;
        return -1;
    }

    return 0;
}

int main() {

    cout << "   Welcome to Hangman" << endl;
    cout << "        ____" << endl;
    cout << "        |  |" << endl;
    cout << "        |  O" << endl;
    cout << "        | /|\\" << endl;
    cout << "        | / \\" << endl;
    cout << "        |" << endl;
    cout << "        |______" << endl << endl;
    cout << "1) Gamer" << endl;
    cout << "2) Manager" << endl;
    cout << "Enter choice: ";

    char mode;
    cin >> mode;

    switch (mode) {
    case '1':
        return gamer();
    case '2':
        return manager();
    default:
        cout << "Invalid option: " << mode << endl;
        return -1;
    }
}
