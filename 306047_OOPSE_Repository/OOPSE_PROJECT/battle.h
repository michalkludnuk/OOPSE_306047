#ifndef battle_H
#define battle_H
#include "lib.h"
#include "character.h"
#include "monster.h"
using namespace std;
extern int wand;
extern int shield;
extern int sword;
extern int result;
template <class T>

class Battle {
public:
    void menu(){
        cout<<endl;
        Character h1;
        h1.load();
        cout<<endl;
        Character h2;
        h2.load();
        fight(h1, h2);
    }

    void fight(Character &h1, Character &h2){
        int x;
        if (h1.profession=="mage")
        {x=1;}
        if (h1.profession=="berserker")
        {x=2;}
        if (h1.profession=="warrior")
        {x=3;}
        if (h1.profession=="thief")
        {x=4;}

        switch (x) {
            case 1:
                if(h1.intelligence>=h2.intelligence)
                {
                    result=1;
                    int increase=h1.exp+h2.exp;
                    while(increase>100)
                    {
                        h1.lvl++;
                        increase=increase-100;
                    }
                    h1.exp=increase;
                }
                else
                {
                    result=0;
                    int rest=h1.exp-h2.exp;
                    while (rest<0)
                    {
                        h1.lvl--;
                        rest=rest+100;
                    }
                    h1.exp=rest;
                    if(h1.lvl<1)
                    {
                        h1.lvl=1;
                        h1.exp=0;
                    }
                }
                break;
            case 2:
                if(h1.strength>=h2.strength)
                {result=1;
                    int increase=h1.exp+h2.exp;
                    while(increase>100)
                    {
                        h1.lvl++;
                        increase=increase-100;
                    }
                    h1.exp=increase;
                }
                else
                {result=0;
                    int rest=h1.exp-h2.exp;
                    while (rest<0)
                    {
                        h1.lvl--;
                        rest=rest+100;
                    }
                    h1.exp=rest;
                    if(h1.lvl<1)
                    {
                        h1.lvl=1;
                        h1.exp=0;
                    }
                }
                break;
            case 3:
                if(h1.endurance>=h2.endurance)
                {result=1;
                    int increase=h1.exp+h2.exp;
                    while(increase>100)
                    {
                        h1.lvl++;
                        increase=increase-100;
                    }
                    h1.exp=increase;
                }
                else
                {result=0;
                    int rest=h1.exp-h2.exp;
                    while (rest<0)
                    {
                        h1.lvl--;
                        rest=rest+100;
                    }
                    h1.exp=rest;
                    if(h1.lvl<1)
                    {
                        h1.lvl=1;
                        h1.exp=0;
                    }
                }
                break;
            case 4:
                if(h1.dexterity>=h2.dexterity)
                {result=1;
                    int increase=h1.exp+h2.exp;
                    while(increase>100)
                    {
                        h1.lvl++;
                        increase=increase-100;
                    }
                    h1.exp=increase;
                }
                else
                {result=0;
                    int rest=h1.exp-h2.exp;
                    while (rest<0)
                    {
                        h1.lvl--;
                        rest=rest+100;
                    }
                    h1.exp=rest;
                    if(h1.lvl<1)
                    {
                        h1.lvl=1;
                        h1.exp=0;
                    }
                }
                break;
        }
        if(result==1)
        {
            if (wand==1)
            {
                h1.intelligence=h1.intelligence-2;
            }
            if (shield == 1)
            {
                h1.endurance=h1.endurance-2;
            }
            if (sword == 1)
            {
                h1.intelligence=h1.intelligence-4;
                h1.strength=h1.strength-4;
                h1.dexterity=h1.dexterity-4;
                h1.endurance=h1.endurance-4;
                h1.charisma=h1.charisma-4;
            }
            h1.hist.reverse();
            h1.hist.pop_front();
            h1.hist.reverse();
            h1.hist.push_front("win");

        }
        else
        {
            if (wand == 1)
            {
                h1.intelligence=h1.intelligence-2;
				h1.dexterity=h1.dexterity-2;
            }
            if (shield == 1)
            {
                h1.endurance=h1.endurance-2;
				h1.strength=h1.strength-2;
            }
            if (sword == 1)
            {
                h1.strength=h1.strength-2;
                h1.dexterity=h1.dexterity-2;
            }
            h1.hist.reverse();
            h1.hist.pop_front();
            h1.hist.reverse();
            h1.hist.push_front("loss");
        }
        h1.save();
    }
};
#endif //battle_H
