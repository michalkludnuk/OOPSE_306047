#include <iostream>
using namespace std;
template <typename T>
void print(T a){
    cout << a << endl;
    
}
template <typename T>
void square(T a){
    print(a*a);
    
}
int main(){
    int first = 4;
    float second = 2.8;
    cout << "\t\t\tProgram calculates square of 4 (int) and 2.8(float) numbers with same function\n";
    square(first);
    square(second);
    return 0;
    
}
