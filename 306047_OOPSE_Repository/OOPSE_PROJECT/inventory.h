#ifndef Inventory_H
#define Inventory_H
#include "lib.h"
#include "character.h"
#include "monster.h"


//using namespace std;



struct statsitem
{

    int ID;
    string name;
    string name_id;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
} ;

struct node
{
    int listNum;
    int ID;
    string name;
    string name_id;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    struct node *next;
    struct node *prev;
};
extern node *start;
class equipment_DoubleLList
{
    public:
    int cnt = 0;
    void create_list(statsitem cool);
    void add_begin(statsitem cool);
    void display_dlist();
    equipment_DoubleLList() { start = NULL; }
};



void loaditems();
void namegeneration();


#endif //Inventory_H
