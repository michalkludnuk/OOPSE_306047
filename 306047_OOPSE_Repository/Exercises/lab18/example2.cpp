#include <iostream>
using namespace std;
int main(){
    int a=3, b=2, c=7;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "c= " << c << endl;
    while(c>a){
        a+=b;
        cout << "a= " << a << endl;
        if(a==c) cout << "c= " << c << endl;
        
    }
    if(a==c)cout << " after while loop c= " << c << endl;
    
}
