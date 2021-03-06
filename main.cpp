#include "Gamer.h"
#include "Manager.h"
#include "Hangman.h"
#include "ReadWords.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <limits>
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

int game() {
    
    int guesses{ 6 }; 
    char guess;
    bool correctGuess = false;
    string word;
    string wordList[99];
    string wordListE[99];
    string wordListM[99];
    string wordListH[99];
    int randNum(0);
    char diffMode;
    char guessed[7]; 

    ifstream difficulty;
    difficulty.open("diff.txt");

    guessed[0] = '\0';
    for (int i = 1; i < 6; i++)
    {
        guessed[i] = '-';
    }
    guessed[6] = '\0';

    //get random word
    srand(time(NULL)); 
    ifstream randWord; 
    randWord.open("Words.txt");

    for (int i = 0; i < 99; i++)
    {
        randWord >> wordList[i]; 
        //cout << wordList[i] << endl; //for testing the list
    }

    cout << "Please select a difficulty: " << endl;
    cout << "1) Easy" << endl;
    cout << "2) Medium" << endl;
    cout << "3) Hard" << endl;

    cin >> diffMode;

    if (diffMode == '1') {
        randNum = rand() % 30;
        word = wordList[randNum];
    }
    else if (diffMode == '2') {
        int randNum = rand() % 29 + 31;
        word = wordList[randNum];
    }
    else if (diffMode == '3') {
        int randNum = (rand() % 10) + 61;
        word = wordList[randNum];
    }
    else {
        cout << "error";
        int randNum = rand() % 71; 
        word = wordList[randNum];
    }
    
    //word = wordList[randNum];

    /*if (diffMode == '1') {
        word = wordListE[randNum];
    }
    else if (diffMode == '2') {
        word = wordListM[randNum];
    }
    else if (diffMode == '3') {
        word = wordListH[randNum];
    }
    else {
        cout << "Invalid option: " << diffMode;
        return 0;
    }*/

    //cout << word << endl; //for testing the random word
    randWord.close();

    string answer(word.length(), '_');
    //cout << answer << endl;

    while (guesses >= 0)
    {
        //reset bool
        correctGuess = false;

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
        cout << "\nGuess a letter: ";
        cin >> guess;

        int points;
        points = diffMode * guesses;

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
            if (diffMode == '1') {
                cout << "You have scored " << guesses << " points." << endl << endl;
            }
            else if (diffMode == '2') {
                cout << "You have scored " << guesses * 2 << " points." << endl << endl;
            }
            else if (diffMode == '3') {
                cout << "You have scored " << guesses * 3 << " points." << endl << endl;
            }
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

int playgame(int difficulty) {

    int d = difficulty;

    ReadWords maingame("sample.text");

    maingame.getWords();
    // print out 10 words selected
    maingame.getPhrases();

    maingame.close();
    return 0;
}

int gamer() {
    // load gamers from file.
    list<Gamer> gamers = load_gamers();
    cout << "Enter your full name:" << endl;

    string full_name;
    cin.ignore();
    getline(cin, full_name);

    // try to find the right gamer
    Gamer g("", 0);

    int highRegNum(0);

    list<Gamer>::iterator it;
    for (it = gamers.begin(); it != gamers.end(); it++)
    {
        //cout << it->getRegNo() << " ... " << it->getName() << endl;
        if (it->getName() == full_name)
        {
            g = Gamer(it->getName(), it->getRegNo());
            // temporary output to confiem found
            cout << "Welcome " << full_name << endl;
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
        cout << g.getName() << " you are a new gamer, your reg. no is: " << g.getRegNo() << endl <<endl;
        ofstream gamers_file;
        gamers_file.open("gamers.txt", ios::app);
        if (gamers_file.is_open()) {
            gamers_file << endl << highRegNum << " " << full_name;
            cout << "New gamer saved to file" << endl;
            gamers_file.close();
        }
        else cout << "New gamer not saved!";
    }

    // temporary to show we've loaded them properly.
    {
        list<Gamer>::iterator it;
        for (it = gamers.begin(); it != gamers.end(); it++)
        {
            //cout << "Welcome " << it->getName() << ", reg no.: " << it->getRegNo() << endl;
        }
    }
    do {

        cout << "1) Play game" << endl;
        cout << "2) Your statistics" << endl;
        cout << "3) Display top 10" << endl;
        cout << "4) Exit game" << endl;

        char option;
        cin >> option;

        if (option == '1') {
            game();
            return 0;
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
            return 0;
        }
        else {
            cout << "Invalid option: " << option << endl;
            return -1;
        }
    } while (1);
    return 0;

}

//error handling TODO

int addManager(int newRegNum, list<Manager> managers) {
    cout << "Adding manager (first name and last name):" << endl;
    string newManager;
    cin.ignore();
    getline(cin, newManager);

    //cout << "highest reg number:" << newRegNum << endl;
    string newReg(4, '0');
    newRegNum++;
    newReg = newReg + to_string(newRegNum);
    newReg = newReg.substr(newReg.size() - 4);
    cout << "formatted new reg: " << newReg << endl;

    Manager nm = Manager(newManager, newRegNum);
    managers.push_back(nm);
    cout << nm.getName() << " you are a new manager, your reg number is " << nm.getRegNo() << endl;
    ofstream managers_file;
    managers_file.open("managers.txt", ios::app);
    if (managers_file.is_open()) {
        managers_file << endl << newReg << " " << newManager;
        cout << "New manager saved to file" << endl;
        managers_file.close();
    }
    else cout << "New manager not saved!";
    return 0;
}

int changeLevels() {
    ofstream diffFile("diff.txt");

    string eMode, mMode, hMode;
    cout << "Enter the upper and lower character limits for easy mode: " << endl;
    cin.ignore();
    getline(cin, eMode);
    cout << "Enter the upper and lower character limits for medium mode: " << endl;
    getline(cin, mMode);
    cout << "Enter the lower character limit for hard mode: " << endl;
    getline(cin, hMode);

    diffFile << eMode << endl;
    diffFile << mMode << endl;
    diffFile << hMode;

    diffFile.close();

    /*cout << "Which difficulty would you like to change?" << endl;
    cout << "1) Easy mode" << endl;
    cout << "2) Medium mode" << endl;
    cout << "3) Hard mode" << endl;

    char mode;
    cin >> mode;

    switch (mode) {
    case '1':
        //TODO

    case '2':
        //TODO

    case '3':
        //TODO

    default:
        cout << "Invalid option" << mode << endl;
        return -1;
    }*/
    return 0;
}

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

    int highRegNum(0);

    list<Manager>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++)
    {
        //cout << it->getRegNo() << " ... " << it->getName() << endl;
        if (it->getName() == full_name)
        {
            m = Manager(it->getName(), it->getRegNo());
            cout << "Welcome " << full_name << endl;
        }
        if (it->getRegNo() > highRegNum)
        {
            highRegNum = it->getRegNo();
        }
    }

    //if validation fails, return to login?
    if (m.getRegNo() == 0)
    {
        cout << "No matching manager name" << endl;
        //pause;
        cin.ignore();
        return 0;
    }

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
        changeLevels();
        break;
    case '3':
        addManager(highRegNum, managers);
        break;
    case '4':
        // TODO:
        break;
    case '5':
        return -1;
    default:
        cout << "Invalid option: " << option << endl;
        return -1;
    }

    return 0;
}

int main() {
    cout << "\n   Welcome to Hangman!" << endl;
    cout << "        ____" << endl;
    cout << "        |  |" << endl;
    cout << "        |  O" << endl;
    cout << "        | /|\\" << endl;
    cout << "        | / \\" << endl;
    cout << "        |" << endl;
    cout << "        |______" << endl << endl;
    cout << "1) Sign in as Gamer" << endl;
    cout << "2) Sign in as Manager" << endl;
    cout << "3) Exit" << endl;
    cout << "Enter choice: ";

    char mode;
    cin >> mode;

    switch (mode) {
    case '1':
        gamer();
        //main();
        return 0;
    case '2':
        manager();
        main();
        return 0;
    case '3':
        
        return 0;
    default:
        cout << "Invalid option: " << mode << endl;
        return -1;
    }
}
