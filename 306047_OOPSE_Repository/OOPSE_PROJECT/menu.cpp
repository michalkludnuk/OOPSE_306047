#include "character.cpp"
#include "battle.cpp"
#include "inventory.cpp"
#include "search.cpp"
#include "monster.cpp"
#include "templates.cpp"

using namespace std;
vector<string> itemNM;
int id[3];
string item[3];
int checker = 0;
int wand = 0;
int shield = 0;
int sword = 0;
int searching;
int result;
statsitem thisitem;
node *start;
bool on = true;
int main() {
    extern string itemSearchName;
    srand((unsigned) time(0));
    equipment_DoubleLList lists;
    loaditems();
    vector<int> itemID;

    while (on==true) {
        int choice;
        cout << "1.Load character \n" << endl;
        cout << "2.Create character \n" << endl;
        cout << "3.Generate Monsters \n" << endl;
        cout << "4.Fight \n" << endl;
        cout << "5.Display inventory \n" << endl;
        cout << "6.Equip item \n" << endl;
        cout << "7.Search for item \n" << endl;
		cout << "8.Turn off \n" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                Character hero;
                hero.load();
                cout << endl;
            }
                break;
            case 2: {
                Character hero;
                hero.add();
                hero.save();
                cout << endl;
            }
                break;
            case 3: {
                array<monster, 5> h;
                for (auto &i :h) {
                    i.generate_monsters();
                    i.save_monsters();
                }
            }
                break;

            case 4: {
                Battle<int> battle;
                battle.menu();
                if(result==1)
                {
                    namegeneration();
                    if (lists.cnt == 0) {
                        if (std::find(itemID.begin(), itemID.end(), thisitem.ID) != itemID.end()) {
                        } else
                            lists.create_list(thisitem);
                        itemID.push_back(thisitem.ID);
                        itemNM.push_back(thisitem.name_id);
                    }
                    else if (std::find(itemID.begin(), itemID.end(), thisitem.ID) != itemID.end()) {
                    }
                    else {
                        lists.add_begin(thisitem);
                        itemID.push_back(thisitem.ID);
                        itemNM.push_back(thisitem.name_id);
                    }
                }
                }
                break;
            case 5: {
                lists.display_dlist();
            }
                break;
            case 6: {
                int good = 0;
                int itemchoice;
                lists.display_dlist();
                if (checker == 1) {
                    break;
                }
                cout << endl;
                cout << "Choose ID of item: " << endl << endl;
                cin >> itemchoice;
                if (itemchoice == 1) {
                    for (int x : itemID) {
                        if (std::find(itemID.begin(), itemID.end(), 1) != itemID.end()) {
                            good = 1;
                            cout << endl;
                        } else {
                            cout << endl;
                            cout << "No such item in inventory." << endl << endl;
                        }
                    }
                    if (good == 1) {
                        cout << endl << endl;
                        Character hero;
                        cout << "Choose Hero:" << endl << endl;
						wand = 1;
                        hero.load();
                    }

                } else if (itemchoice == 2) {
                    {
                        if (std::find(itemID.begin(), itemID.end(), 2) != itemID.end()) {
                            good = 1;
                            cout << endl;
                        } else {
                            cout << endl;
                            cout << "No such item in inventory." << endl << endl;
                        }
                    }
                    if (good == 1) {
                        cout << endl << endl;
                        Character h1;
                        cout << "Choose Hero:" << endl << endl;
						shield = 1;
                        h1.load();
                    }
                } else if (itemchoice == 3) {
                    {
                        if (std::find(itemID.begin(), itemID.end(), 3) != itemID.end()) {
                            good = 1;
                            cout << endl;
                        } else {
                            cout << endl;
                            cout << "No such item in inventory." << endl << endl;
                        }
                    }
                    if (good == 1) {
                        cout << endl << endl;
                        Character h1;
                        cout << "Choose Hero:" << endl << endl;
						sword = 1;
                        h1.load();
                    }
                }

            }
                break;

            case 7: {
                searching=search();
                if (searching == 1)
                {
                    cout <<"Wand_of_Magic"<< endl;
                    cout << "\tItem ID: \t" <<"0"<< endl;
                    cout << "\tStrength: \t" <<"0"<< endl;
                    cout << "\tDexterity: \t" <<"2"<< endl;
                    cout << "\tEndurance: \t" <<"0"<< endl;
                    cout << "\tIntelligence: \t" <<"2"<< endl;
                    cout << "\tCharisma: \t" <<"0"<< endl<<endl;
                }
                else if (searching == 2)
                {
                    cout <<"Shield_of_Defence"<< endl;
                    cout << "\tItem ID: \t" <<"0"<< endl;
                    cout << "\tStrength: \t" <<"2"<< endl;
                    cout << "\tDexterity: \t" <<"0"<< endl;
                    cout << "\tEndurance: \t" <<"2"<< endl;
                    cout << "\tIntelligence: \t" <<"0"<< endl;
                    cout << "\tCharisma: \t" <<"0"<< endl<<endl;
                }
                else if (searching == 3)
                {
                    cout <<"Sword_of_Offence"<< endl;
                    cout << "\tItem ID: \t" <<"0"<< endl;
                    cout << "\tStrength: \t" <<"2"<< endl;
                    cout << "\tDexterity: \t" <<"2"<< endl;
                    cout << "\tEndurance: \t" <<"0"<< endl;
                    cout << "\tIntelligence: \t" <<"0"<< endl;
                    cout << "\tCharisma: \t" <<"0"<< endl<<endl;
                }
                else {
                    cout<<"No such item in inventory."<<endl<<endl;
                }
            }
                break;
				case 8: 
				on = false;
                break;
        }

    }

    return 0;
}
