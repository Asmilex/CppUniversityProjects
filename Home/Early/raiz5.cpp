#include <iostream> 
#include <cmath>
using namespace std;

int main(){
	double a,b,c;
	double sol1,sol2,soli;
	cout <<"Introduce los valores para ax²+bx+c\na:";
	cin >>a;
	cout << "\nb: " ;
	cin >>b;
	cout <<"\nc: ";
	cin >>c;
	
	if (a==0)
		if (b==0)
			sol1=c;
		else
			sol1=(-1*c)/b;	
	else
	{
		if (b==0)
		{
			sol1=sqrt((-1*c)/a);
			sol2=-sqrt((-1*c)/a);
			
		}	
		else
			if (c==0)
			{
				sol1=-b/a;
				sol2=0;
			}
			else
			{
				sol1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
				sol2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
			}


	}
		
	cout <<"Tu ecuación es:"<<a<<"x² + "<<b<<"x + "<<c<<"\nLas soluciones son: "<<sol1<<","<<sol2;
}	