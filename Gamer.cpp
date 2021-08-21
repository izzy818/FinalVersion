#include <string>
#include "Gamer.h"

using namespace std;

Gamer::Gamer(const string &name, int regNo) : Person(name) {
  this->name = name;
  this->regNo = regNo;
}

int Gamer::getRegNo() const { return this->regNo; }

void Gamer::addScore(float score, string difficulty) {
  this->scores.insert(pair<string, float>(difficulty, score));
}

bool Gamer::updateAccumulativeScore(string difficulty, float score)
{
  this->accumulative_scores[difficulty] += score;
  //need to add error handling to capture failure/errors and return false
  return true;
}
