#include <iostream>
namespace conversion{
double div=0.39370;
template <typename T> T cmToInch(T a){
    return(a*div);
    
}
template <typename T> T inchToCm(T a){
    return(a/div);
    
}

}
void disp(std::string a){
    std::cout<<"Disp function operational! "<< a <<std::endl;
    
}
namespace display{
using namespace std;
void disp(string a);

}
int main(){
    int a=20, b=0 ;27float f = 6.5, c=0, d=0;
    b=conversion::cmToInch(a);
    std::cout<<"Converting a to inch: "<< b <<std::endl;
    {
        using namespace conversion;
        c=cmToInch(a);
        std::cout<<"Converting a againt to inch: "<< c <<std::endl;
        
    }
    d=conversion::inchToCm(f);
    std::cout<<"Converting f to cm: "<< d <<std::endl;
    display::disp("Let’s display all conversions!");
    std::cout<<std::endl<<"a = "<<a<<std::endl<<"b ="<<b<<std::endl<<"c = "<<c<<std::endl<<"d = "<<d<<std::endl;
    disp("non namespace function");
    display::disp("namespace disp function");
    
    using namespace display;
    display::disp("now a cover of the function"); //if the name of the namespace is not added generates an error due to thefunction overloading principles
    return 0;
    
}
void display::disp(string a){
    cout << a << endl;
    
}
