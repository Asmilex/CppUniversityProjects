#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v(20);
    for (int i=0; i<v.size(); i++){
        cin >>v[i];
    }

    cout <<v.size()<<"\n";
    
    for (int i=0; i<v.size();){
        while (v[i]%2==0){
            int valortemporal=v[v.size()-1];
            v[v.size()-1]=v[i];
            v[i]=valortemporal;

            v.pop_back();

        }
        if (v[i]%2 != 0)
            i++;
    }
        
    for (int i=0; i<v.size(); i++)
        cout <<v[i]<<" ";
    

    

}