#include "Manager.h"
#include <string>

using namespace std;

Manager::Manager(const string &name, int regNo) : Person(name) {
  this->name = name;
  this->regNo = regNo;
}
int Manager::getRegNo() const { return this->regNo; }
