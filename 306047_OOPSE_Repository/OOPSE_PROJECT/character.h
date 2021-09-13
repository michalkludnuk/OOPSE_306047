
#ifndef character_H
#define character_H
#include "templates.h"
#include<array>


class Profession :public profession{
public:
    void load(string profession);
};
class Character :public attributes{
public:
    forward_list<string> hist;
    void load();
    void save();
    void add();
};

#endif //character_H
