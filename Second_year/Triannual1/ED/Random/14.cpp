#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool anagrama ( list< int >& l1, list < int >& l2 ) {
    for ( auto num: l1 ) {
        if ( find( l2.begin(), l2.end(), num) == l2.end() )
            return false;
        
        if (   count( l1.begin(), l1.end(), num ) 
            != count( l2.begin(), l2.end(), num ) )

            return false;
    }

    return true;
}

int main() {
    list<int> l1 = {1, 23, 21, 4, 2, 3, 0};
    list<int> l2 = {21, 1, 3, 2, 4, 3, 0};

    cout << "¿Anagrama? " << anagrama(l1, l2) << endl;
}