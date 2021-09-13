#include "search.h"
extern vector<string> itemNM;
string itemSearchName;
int search() {
        cout<<endl;
        cout<<"Searched item name: "<<endl<<endl;
        cin>>itemSearchName;
        cout<<endl<<endl;
    if (std::find(itemNM.begin(), itemNM.end(), itemSearchName) != itemNM.end())
    {
        if (itemSearchName == "Wand_of_Magic")
        {
            return  1;
        }
        else if(itemSearchName == "Shield_of_Defence")
        {
            return 2;
        }
        else if(itemSearchName == "Sword_of_Offence")
        {
            return 3;
        }
    }
    else
    {
        return 0;
    }

}
