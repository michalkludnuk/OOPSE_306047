#include "character.h"
extern int wand;
extern int shield;
extern int sword;



void Character::load() {
    string input_name;
    cout<<"Input name: ";
    cin>>input_name;
    string path=input_name+".txt";
    fstream file;
    string line;
    file.open(path.c_str(),ios::in | ios::out);

    getline(file,line);
    file>> profession;
    file>> strength;
    file>> dexterity;
    file>> endurance;
    file>> intelligence;
    file>> charisma;
    file>> exp;
    file>> lvl;
    file>> name;
    file>> line;
    if(file.eof())
    {
        for(int i=0; i<10; i++)
        {
            hist.push_front("noRecord");

        }
    }

    else
    {
        hist.push_front(line);
        cout<<"battle: "<<line<<endl;
        for(int i=0; i<9; i++)
        {

            file>>line;
            hist.push_front(line);
            cout<<"battle: "<<line<<endl;

        }
    }
    hist.reverse();
    file.close();



   if (wand == 1)
        {
        intelligence=intelligence+2;
		dexterity=dexterity+2;
        }
    if (shield == 1)
        {
        endurance=endurance+2;
		strength=strength+2;
        }
     if (sword == 1)
        {
        strength=strength+2;
        dexterity=dexterity+2;
        }

    cout<<endl;
    cout<<"profession: "<<profession<<endl;
    cout<<"strength: "<<strength<<endl;
    cout<<"dexterity: "<<dexterity<<endl;
    cout<<"endurance: "<<endurance<<endl;
    cout<<"intelligence: "<<intelligence<<endl;
    cout<<"charisma: "<<charisma<<endl;
    cout<<"level: "<<lvl<<endl;
    cout<<"exp: "<<exp<<endl;
}

void Character::save() {
    string path=name+".txt";
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

    for(auto &i : hist)
    {
        file<<i<<endl;
    }

    file.close();
}


void Character::add() {
    cout<<"name: ";
    cin>>name;
    cout<<"profession: ";
    cin>>profession;

    cout<<"strength: ";
    cin>>strength;
    cout<<"dexterity: ";
    cin>>dexterity;
    cout<<"endurance: ";
    cin>>endurance;
    cout<<"intelligence: ";
    cin>>intelligence;
    cout<<"charisma: ";
    cin>>charisma;


    lvl=1;
    exp=0;


    Profession hw;
    hw.load(profession);
    intelligence=intelligence+hw.intelligence;
    strength=strength+hw.strength;
    dexterity=dexterity+hw.dexterity;
    endurance=endurance+hw.endurance;
    charisma=charisma+hw.charisma;
}

void Profession::load(string profession) {
string path_prof = profession + ".txt";


    ifstream file (path_prof.c_str());
    file>>strength;
    file>>dexterity;
    file>>endurance;
    file>>intelligence;
    file>>charisma;
    file>>exp;
    file>>lvl;
    file.close();

}
