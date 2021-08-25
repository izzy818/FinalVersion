// replace my comments with your own
// except: you can use my comment about one-word lookahead

// you may modify the code that I have supplied if you wish

#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

string removePunct(string word)
{ // should return a copy of the word with all leading and trailing punctuation
  // removed
  // punctuation elsewhere in the word should not be removed
  // note that a word could havce more than one leading/trailing punctuation symbols
  // you need to write this
  for (auto it = begin(word); ispunct(*it);)
  {
    it = word.erase(it);
  }
  for (auto it = prev(end(word)); ispunct(*it); --it)
  {
    it = word.erase(it);
  }
  return word;
}

ReadWords::ReadWords(const char *fname)
{
  wordfile.open(fname); //open file
  if (!wordfile)
  {
    cout << "Failed to open " << fname << endl;
    exit(1);
  }
  wordfile >> nextword;
  eoffound = false;
}

string ReadWords::getNextWord()
{ // should return next word in file, converted to lower case
  // empty string should be returned if next word contains no letters

  // uses a one-word lookahead to avoid any problems relating to when if end-of-file
  // is detected due to absence/presence of newline at end of file

  // incomplete

  string word = nextword;
  wordfile >> nextword;

  if (wordfile.eof())
    eoffound = true;

  word = removePunct(word);

  // need to check that word contains a letter, and if not return an empty string;

  // also need to convert to lower case before returning

  // this is a temp fix use for_each in final version
  transform(word.begin(), word.end(), word.begin(), ::tolower);

  //cout << word << " ";
  return word;
}

bool ReadWords::isNextWord()
{
  return !eoffound;
}

bool ReadWords::getPhrases()
{ // you must write this
  
  cout << "hello -------------------------------------------" << endl;

 // reset file position
  wordfile.seekg(0, wordfile.beg);
  eoffound = false;
  //ifstream phrase_file;
  //phrase_file.open("sample.txt");

  //cout << phrase_file << endl;
  //cout << nextword << endl;
    
  string phrase;
  bool found;

  for (int i = 0; i < 10; i++)
  {
    cout << "Word in array " << words[i] << endl;
    found = false;
    if (isNextWord())
    {
      string word = getNextWord();
      cout << word << "+";
      if (word != "")
      {
        cout << word << "|";
        /*
        phrase += word;
        if (word == words[i]){
          found = true;
        }
        if (word == "."){
          if (found == true){
            cout << phrase << " contains " << words[i] << endl;
            //phrases
            break;
          }
        }
        */
      }
    }
    // reset file position
    wordfile.seekg(0, wordfile.beg);
  }
  //wibble.close();
  return 0;
}

//void ReadWords::getWords()
//{ // you must write this
//}

bool ReadWords::getWords() //declare as bool in readwords.h
{
  //set here as temporary measure
  int minlen = 6;
  int maxlen = 10;

  // Populate a set of all words
  set<string> allwords;
  while (isNextWord())
  {
    string word = getNextWord();
    if (word != "")
    {
      if (word.length() >= minlen && word.length() <= maxlen)
      {
        allwords.insert(word);
      }
    }
  }

  // select 10 words randomly
  for (int i = 0; i < 10; i++)
  {
    int randNum = rand() % allwords.size();
    auto it = begin(allwords);
    advance(it, randNum);
    words[i] = *it;
  }

  // reset file position
  wordfile.seekg(0, wordfile.beg);

  // print out 10 words selected
  ofstream words_file;
  words_file.open("words_file.txt", ios::out);
  if (words_file.is_open())
  {
    for (int i = 0; i < 10; i++){
      words_file << words[i] << endl;
      cout << "New word " << words[i] << " saved to file" << endl;
    }
    words_file.close();
  }
  return 0;
}

void ReadWords::close()
{ // you must write this
  if (wordfile.is_open())
  {
    wordfile.close();
  }
}