#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector < int > container( 10, 0 );
    container.insert( container.begin(), 1 );
    container.insert( container.end(), 3, 6 );
    container.insert( container.begin() + 3, 2 );
    for( int i = 0; i < container.size(); ++i )
        cout << container[ i ] << ’ ’;
    cout <<endl;
    container.erase( container.begin() );
    container.erase( container.begin() + 2, container.begin() + 4 );
    container.erase( container.begin() + 4, container.end() );
    vector<int>::iterator it;
    for( it=container.begin(); it!=container.end(); ++it ){
        cout<< *it << ’ ’;
        
    }
    cout<<endl;
    return 0;
    
}
