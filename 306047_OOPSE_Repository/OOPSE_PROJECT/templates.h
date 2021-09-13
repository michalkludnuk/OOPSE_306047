#ifndef Tempaltes_H
#define Tempaltes_H
#include "lib.h"
using namespace std;

class attributes{
public:
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    int exp;
    int lvl;
    int item;
    string name;
    string profession;

};
class profession{
public:
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    int exp;
    int lvl;
    virtual void load(string profession)=0;
};

#endif //Tempaltes_H