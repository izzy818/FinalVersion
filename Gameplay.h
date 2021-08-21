#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

#include <string>

using namespace std;

class Gameplay
{   public:
        Gameplay(const string &score);
        string getScore() const;
    protected:
        string score;
};

#endif