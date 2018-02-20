#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vector1(10);
    for (int i=0; i<vector1.size(); i++)
        vector1.at(i)=i;
    for (int j=0; j<vector1.size(); j++)
        cout <<vector1[j];
}