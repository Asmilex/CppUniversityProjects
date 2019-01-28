#include <iostream>
#include <stack>

using namespace std;

void flota_pares( stack<int> & p ) {
    stack<int> pares, impares;
    int elemento;

    while ( !p.empty() ) {
        elemento = p.top();

        if ( elemento % 2 == 0 )
            pares.push(elemento);
        else
            impares.push(elemento);    

        p.pop();
    }

    while ( !pares.empty() ) {
        p.push( pares.top() );
        pares.pop();
    }
    
    while ( !impares.empty() ) {
        p.push( impares.top() );
        impares.pop();
    }
}

int main() {
    stack<int> p;

    p.push(4);
    p.push(17);
    p.push(9);
    p.push(7);
    p.push(4);
    p.push(2);
    p.push(0);
    p.push(9);
    p.push(2);
    p.push(15);

    cout << "\n\n";

    flota_pares(p);

    while ( !p.empty() ) {
        cout << p.top() << " ";
        p.pop();
    }

    return 0;
}