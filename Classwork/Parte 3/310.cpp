#include <iostream>
using namespace std;

int main(){
	int x=2;
	while (!((x%3 ==  0) || (x <= 0 && x%2 != 0 ))){
		cout <<"Loco, dame un numeraco\t";
		cin >>x;
	}
	cout <<"Illo la has cagado";
}


