#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string cad1, cad2;
    cout <<"Introduce valores para los dos strings. cad1: ";
    getline(cin, cad1);
    cout <<"Cad2: " ;
    getline (cin, cad2);

    if (cad1<cad2)
        cout <<"\n"<<cad1;
    else       
        cout <<"\n"<<cad2;

}