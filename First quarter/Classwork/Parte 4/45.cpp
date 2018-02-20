#include <iostream>
#include <vector>
using namespace std;

int main(){
    int totalnumeros;

    cout <<"Introduce el número natural hasta el cual se comprobarán los primos que hay: ";
    cin >>totalnumeros;
    
    vector<bool> v(totalnumeros, true);

    for (int i=0; i<v.size(); i++){
        if (i>1 && v[i]==true){
            for (int j=i+i; j<v.size(); j=j+i)
                v[j]=false;

        }
    }

    for (int i=0; i<v.size(); i++)
        if (v[i]==true && i>0)
            cout <<i<<" ";
}