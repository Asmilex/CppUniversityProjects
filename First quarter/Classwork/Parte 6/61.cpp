#include <iostream>
using namespace std;

int contdivisores(int num){
    int contdiv=0;
        
    for (int i = 1; i <= num; i++){
        if (num%i == 0)
            contdiv++;
    }    
    return contdiv;
}

int main(){
    int num, contdiv;
    cout <<"Dame un número\n";
    cin >>num;

    if (num < 1 ){
        cout <<"El número debe ser positivo\n";
        contdiv=0;
    } else
        contdiv=contdivisores(num);    

    cout <<"Los divisores de "<<num<<" son "<<contdiv;
}

