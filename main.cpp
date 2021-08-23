#include "Gamer.h"
#include "Manager.h"
#include "ReadWords.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

using namespace std;

list<Gamer> load_gamers()
{
  ifstream gamers_file;
  gamers_file.open("gamers.txt");

  list<Gamer> gamers;

  string line;
  if (gamers_file.is_open())
  {
    while (getline(gamers_file, line))
    {

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

int playgame() {
  ReadWords maingame("sample.txt");

  maingame.close();
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

  int highRegNum (0);

  list<Gamer>::iterator it;
  for (it = gamers.begin(); it != gamers.end(); it++)
  {
    cout << it->getRegNo() << " ... " << it->getName() << endl;
    if (it->getName() == full_name)
    {
      g = Gamer(it->getName(), it->getRegNo());
      // temporary output to confirm found
      cout << "Found ..." << full_name << endl;
    }
    if (it->getRegNo() > highRegNum)
    {
      highRegNum = it->getRegNo();
    }
  }

  //cout << "Highest reg num " << highRegNum << endl;
  //cout << "got it " << g.getName() << " and reg no " << g.getRegNo() << endl;
  
  //if validation fails (regno = 0), create new gamer profile
  if (g.getRegNo() == 0 )
  {
    //set new reg no
    highRegNum++;
    Gamer g =  Gamer(full_name, highRegNum);
    gamers.push_back(g);
    cout << g.getName() << " you are a new gamer, your reg number is " << g.getRegNo() << endl;
  }

  // temporary to show we've loaded them properly.
  {
    list<Gamer>::iterator it;
    for (it = gamers.begin(); it != gamers.end(); it++)
    {
      cout << it->getRegNo() << " ... " << it->getName() << endl;
    }
  }

  do 
  {
      cout << "1) Play game" << endl;
      cout << "2) Your statistics" << endl;
      cout << "3) Display top 10" << endl;
      cout << "4) Exit game" << endl;

      char option;
      cin >> option;

      switch (option)
      {
      case '1':
        // TODO:
        playgame();
        gamer();
      case '2':
        // TODO:
        break;
      case '3':
        // TODO:
        break;
      case '4':
        // TODO:
        return -1;
      default:
        cout << "Invalid option: " << option << endl;
        return -1;
      }
  }
  while (1);
  return 0;
}

//error handling TODO

int addManager(int newRegNum, list<Manager> managers) {
  cout << "Adding manager (first name and last name):" << endl;
  string newManager;
  cin.ignore();
  getline(cin, newManager);
  
  //cout << "highest reg number:" << newRegNum << endl;
  string newReg(4,'0');
  newRegNum++;
  newReg = newReg + to_string(newRegNum);
  newReg = newReg.substr(newReg.size() - 4);
  cout << "formatted new reg: " << newReg << endl;

  Manager nm = Manager(newManager, newRegNum);
  managers.push_back(nm);
  cout << nm.getName() << " you are a new manager, your reg number is " << nm.getRegNo() << endl;
  ofstream managers_file;
  managers_file.open("managers.txt", ios::app);
  if (managers_file.is_open()){
    managers_file << endl << newReg << " " << newManager;
    cout << "New manager saved to file" << endl;
    managers_file.close();
  }
  else cout << "New manager not saved!";
  return 0;
}

int manager() {
    //load managers from file
    list<Manager> managers = load_managers();

    // temporary output to show they loaded 
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

    int highRegNum (0);

    list<Manager>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++) 
    {
      cout << it->getRegNo() << " ... " << it->getName() << endl;
      if (it->getName() == full_name) 
      {
          m = Manager(it->getName(), it->getRegNo());
          cout << "Found ... " << full_name << endl;
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
    cout << "5) Return to main options" << endl;

    char option;
    cin >> option;

    switch (option) {
      case '1':
        // TODO: reset the to default difficulty values
        break;
      case '2':
        // TODO: set new difficulty values
        break;
      case '3':
        // TODO: Add name to list and increment reg no by 1
        addManager (highRegNum, managers);
        break;
      case '4':
        // TODO: select the word file for the game play
          break;
      case '5':
        //TODO return to main menu
        return 0; 
      default:
        cout << "Invalid option: " << option << endl;
        return -1;
    }

    return 0;
}

int main() {
  cout << "1) Gamer" << endl;
  cout << "2) Manager" << endl;
  cout << "3) Exit Game" << endl;
  cout << "Enter choice:" << endl;

  char mode;
  cin >> mode;

  switch (mode) {
    case '1':
      return gamer();
    case '2':
      manager();
      main();
    case '3':
      return 1;
    default:
      cout << "Invalid main option: " << mode << endl;
      return -1;
  }
}
