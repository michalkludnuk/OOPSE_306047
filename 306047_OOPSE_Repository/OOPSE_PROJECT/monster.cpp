#include "monster.h"

void monster::generate_monsters() {
    cout<<"input name: ";
    cin>>name;
    profession="monster";
    strength = rand()%20;
    dexterity =rand()%20;
    endurance =rand()%20;
    intelligence = rand()%20;
    charisma =rand()%20;
    exp=rand()%20;
    lvl=0;
    item=rand()%20;
}

void monster::save_monsters() {
    string path=name+"_monster.txt";
    ofstream file(path.c_str());
    file<<name<<endl;
    file<<profession<<endl;
    file<<strength<<endl;
    file<<dexterity<<endl;
    file<<endurance<<endl;
    file<<intelligence<<endl;
    file<<charisma<<endl;
    file<<exp<<endl;
    file<<lvl<<endl;
    file<<name<<endl;
    file.close();
}
