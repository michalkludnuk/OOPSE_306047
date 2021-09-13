#include <iostream>
int fact(int);
//function that calculates factorial of a givennumber
int main(){
    int n, result;
    std::cout << "Enter a non-negative number: ";
    std::cin >> n;
    result = fact(n);
    std::cout << "Factorial of " << n << " = " << result;
    return 0;
    
}
int fact(int n){
    if (n > 1) {
        return n * fact(n - 1);
        
    } else {
        return 1;
        
    }
    
}
