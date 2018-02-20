#include <iostream>
using namespace std;

int convmin(char a){
    char b;
    b=a+32;
    return b;
}


int main(){
    char caractermin, caractermay;
    
    cout <<"Dame una letra\n";
    cin >>caractermay;

    if (caractermay < 65 || caractermay > 90){
        cout <<"No has introducido una letra mayúscula";
        
    } 
    else{
        caractermin=convmin(caractermay);
        cout <<"La letra minúscula es "<<caractermin<<"\n";
    }
        
    


}