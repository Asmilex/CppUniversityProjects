#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v(1);
    
    cout <<"Introduce una serie de valores: \n";
    for (int i=0; i<v.size(); i++){
        v.push_back(1);
        cin >>v[i];

        if (v[i]==0){
            v.pop_back();
            v.pop_back();
        }
    
    }

    for (int i=0; i<v.size(); i++)
        cout <<v[i]<<" ";



    

}