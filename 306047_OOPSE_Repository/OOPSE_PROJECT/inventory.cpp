#include "inventory.h"

extern string item[3];
extern int id[3];
void loaditems() {
string Path = "items.txt";
    fstream file;
    string line;
    file.open(Path);
    while(!file.eof())
    {
        for(int i=0;i<3;i++)
        {
            file>>item[i];
			file>>id[i];
        }
    };
    file.close();
}

void namegeneration() {
    int randomnes = rand()%6 + 1;
    extern statsitem thisitem;
    switch (randomnes) {
        case 1: {
            thisitem.name = "Wand of Magic";
            thisitem.name_id = item[randomnes-1];
            thisitem.ID = id[randomnes-1];
            thisitem.strength = 0;
            thisitem.dexterity = 2;
            thisitem.endurance = 0;
            thisitem.intelligence = 2;
            thisitem.charisma = 0;
            cout<<"You dropped:"<<thisitem.name<<endl<<endl;
        }
            break;
        case 2: {
            thisitem.name = "Shield of Defence";
            thisitem.name_id = item[randomnes-1];
            thisitem.ID = id[randomnes-1];
            thisitem.strength = 2;
            thisitem.dexterity = 0;
            thisitem.endurance = 2;
            thisitem.intelligence = 0;
            thisitem.charisma = 0;
            cout<<"You dropped:"<<thisitem.name<<endl<<endl;
        }
            break;
        case 3: {
            thisitem.name = "Sword of Offence";
            thisitem.name_id = item[randomnes-1];
            thisitem.ID = id[randomnes-1];
            thisitem.strength = 2;
            thisitem.dexterity = 2;
            thisitem.endurance = 0;
            thisitem.intelligence = 0;
            thisitem.charisma = 0;
            cout<<"You dropped:"<<thisitem.name<<endl<<endl;
        }
            break;

        default: {
            cout<<"No loot"<<endl;
        }
            break;
    }
}

void equipment_DoubleLList::create_list(statsitem ekwip) {
    struct node *s, *temp;
    temp = new (struct node);

    temp->listNum = cnt;
    temp->ID = ekwip.ID;
    temp->name_id = ekwip.name_id;
    temp->name = ekwip.name;
    temp->strength = ekwip.strength;
    temp->dexterity = ekwip.dexterity;
    temp->endurance = ekwip.endurance;
    temp->intelligence = ekwip.intelligence;
    temp->charisma = ekwip.charisma;

    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }

    cnt++;
}

void equipment_DoubleLList::add_begin(statsitem ekwip) {
    struct node *temp;
    temp = new (struct node);
    temp->prev = NULL;

    temp->listNum = cnt;
    temp->ID = ekwip.ID;
    temp->name_id = ekwip.name_id;
    temp->name = ekwip.name;
    temp->strength = ekwip.strength;
    temp->dexterity = ekwip.dexterity;
    temp->endurance = ekwip.endurance;
    temp->intelligence = ekwip.intelligence;
    temp->charisma = ekwip.charisma;

    temp->next = start;
    start->prev = temp;
    start = temp;
    cnt++;
}

void equipment_DoubleLList::display_dlist() {
    extern int checker;
    struct node *q;
    if (start == NULL)
    {
        cout<<endl;
        cout << "No items in inventory." << endl<<endl;
        checker = 1;
        return;
    }
    q = start;
    cout<<endl;
    cout << "Inventory:" << endl<<endl;
    checker = 0;
    while (q != NULL)
    {
        cout << q->name << endl;
        cout << "\tItem ID: \t" << q->ID << endl;
        cout << "\tStrength: \t" << q->strength << endl;
        cout << "\tDexterity: \t" << q->dexterity << endl;
        cout << "\tEndurance: \t" << q->endurance << endl;
        cout << "\tIntelligence: \t" << q->intelligence << endl;
        cout << "\tCharisma: \t" << q->charisma << endl;
        q = q->next;
    }
    cout << endl;
}
