#include "Gamer.h"
#include "Manager.h"
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

            Manager g = Manager(full_name, regNo);
            managers.push_back(g);
        }
        managers_file.close();
    }

    return managers;
}

/*int gamer() {
  // load gamers from file.
  list<Gamer> gamers = load_gamers();

  // temporary to show we've loaded them properly.
  {
    list<Gamer>::iterator it;
    for (it = gamers.begin(); it != gamers.end(); it++) {
      cout << it->getRegNo() << " ... " << it->getName() << endl;
    }
  }

  cout << "Enter your full name:" << endl;

  string full_name;
  cin.ignore();
  getline(cin, full_name);

  // try to find the right gamer
  Gamer g("", 0);

  list<Gamer>::iterator it;
  for (it = gamers.begin(); it != gamers.end(); it++) {
    cout << it->getRegNo() << " ... " << it->getName() << endl;
    if (it->getName() == full_name) {
      g = Gamer(it->getName(), it->getRegNo());
        cout << "Found ..." << full_name << endl;
    }
  }

  cout << "got it " << g.getName() << " and reg no " << g.getRegNo() << endl;
  //if validation fails (regno = 0), create new gamer profile

  cout << "1) Play game" << endl;
  cout << "2) Your statistics" << endl;
  cout << "3) Display top 10" << endl;
  cout << "4) Exit game" << endl;

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
  default:
    cout << "Invalid option: " << option << endl;
    return -1;
  }

  return 0;
}*/

//error handling TODO

/*int manager() {
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
    //Manager m;

    list<Manager>::iterator it;
    for (it = managers.begin(); it != managers.end(); it++) {
        cout << it->getRegNo() << " ... " << it->getName() << endl;
        if (it->getName() == full_name) {
            //m = manager(it->getName(), it->getRegNo());
            cout << "Found " << full_name << endl;
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
    }*/

int main() {
    // load gamers from file.
    list<Gamer> gamers = load_gamers();
    //load managers from file
    list<Manager> managers = load_managers();


  cout << "Enter your full name: " << endl;

  string full_name;
  //cin.ignore();
  getline(cin, full_name);

  // try to find a manager
  Manager m("", 0);
  //try to find a gamer
  Gamer g("", 0);



  list<Manager>::iterator it;
  for (it = managers.begin(); it != managers.end(); it++) {
      //cout << it->getRegNo() << " ... " << it->getName() << endl;
      if (it->getName() == full_name) {
          m = Manager(it->getName(), it->getRegNo());
          cout << "Found ... " << full_name << endl;
      }
  }

list<Gamer>::iterator it;
  // try to find the right gamer
  for (it = gamers.begin(); it != gamers.end(); it++) {
      //cout << it->getRegNo() << " ... " << it->getName() << endl;
      if (it->getName() == full_name) {
          g = Gamer(it->getName(), it->getRegNo());
          cout << "Found ... " << full_name << endl;
      }
  }

  //cout << "Welcome " << g.getName() << ", reg no " << g.getRegNo() << endl;
  //cout << "Welcome " << full_name << endl;

  /*char mode;
  cin >> mode;

  switch (mode) {
  case '1':
    return gamer();
  case '2':
    return manager();
  default:
    cout << "Invalid option: " << mode << endl;
    return -1;
  }*/
}
