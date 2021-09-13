#include <iostream>
using namespace std;
const int max_urzadz = 15;
const int max_czujn = 10;
int detektor[max_urzadz][max_czujn]; // tablica na wyniki pomiarow
bool odczytaj_zdarzenie();
void analizuj_zdarzenie();
unsigned long pobierz_slowo();
int main(){
    cout << "Program analizuje dane pomiarowe" << endl;
    while (odczytaj_zdarzenie()){ //odebranie danych
        analizuj_zdarzenie();
        
    }
    cout << "Nie ma wiecej danych" << endl;
    return 0;
    
}
bool odczytaj_zdarzenie(){
    struct slowo_vxi {
        unsigned int dana  :7;
        unsigned int urzadzenie :8;
        unsigned int czujnik :6;
        unsigned int       :2;
        
    };
    //unia pozwalajaca na poszatkowanie slowa
    union {
        unsigned long cale;
        slowo_vxi    vxi;
        
    };
    cout << "Wczytywanie nastepnego zdarzenia...\n";
    //petla wczytujaca wiele slow do jednego zdarzenia
    while(1){
        cale=pobierz_slowo();
        if(!cale) return false;
        if (vxi.urzadzenie == 0xf8){
            cout<<"Koniec odczytu danych zdarzenia nr"<<vxi.dana<<endl;
            return true;
            
        } else {
            if(vxi.urzadzenie > max_urzadz || vxi.czujnik >=max_czujn){
                continue;
                
            }
            detektor[vxi.urzadzenie][vxi.czujnik]=vxi.dana;
            
        }
        
    }
    
};

void analizuj_zdarzenie(){
    cout<<"Analiza zdarzenia. Zadzialaly:"<<endl;
    for (int u = 0; u < max_urzadz; u++) {
        for (int c = 0; c < max_czujn; c++)  {
            if(detektor[u][c]){
                cout<<"\turzadzenie "<<u<<"czujnik "<<c<<", odczyt="<<detektor[u][c]<<endl;
                
            }
            
        }
        
    }
    
};

unsigned long pobierz_slowo(){
    unsigned long slowo[]={720x4060658, 0x60201ff, 0x9058c, 0xf80000,73328457, 100729404, 0xf80001,74197827, 134417127, 84087033, 50927293,7516848207, 17105686, 16847128,760xf80002,770};
    static int licznik;
    return slowo[licznik++];
    
};
