#include <iostream> 
#include <string>
using namespace std; 

int main(){
    string palindromo; 

    cout <<"Introduce la cadena de texto que quieras. Te dirá si es palíndromo o no\n";
    bool interruptor=1;
    getline(cin, palindromo);
    
    /*Líneas que he usado para comprobar manualmente si era palíndromo o no. Como no hace daño, lo dejo incluido
    for (int i=palindromo.size(); i>=0; i--)  
        cout <<palindromo[i];
    
    cout <<"\n"<<palindromo.size();
    */

    for (int i=0; palindromo[i]; i++) 
        palindromo[i]=toupper(palindromo[i]);
    
    bool comprob=false;
    int i=0;
    int j=palindromo.size()-1;
    while (i!=palindromo.size()){
        char esespacioi=palindromo[i]; //Estas dos variables comprueban si hay espacios en blanco. Si los hay, incrementa en 1 el contador
        char esespacioj=palindromo[j];

        if (isspace(esespacioi)) //Si se encuentra un espacio, aumenta el recorrido en el vector. No tiene sentido comparar un espacio, porque en la definición de palíndromo no se incluyen.
            i++;
        if (isspace(esespacioj))
            j--;
        if (palindromo[i]==palindromo[j])
            comprob=true;
      
        //Descomentar la siguiente línea activa la comprobación didáctiva visual de si es palíndromo o no. Útil para debugging
        //cout <<"\n"<<palindromo[i]<<" "<<palindromo[j]; 
        i++;
        j--;
    }
    
    
    if (comprob==false)
        cout <<"\nNo es palíndromo\n";
    else
        cout <<"\n Es un palíndromo\n";
    
    return 0;
}

//No sé cómo ignorar acentos de forma eficiente. Una forma sería poner condiciones para todas las tildes que hay en español, y convertirlas individualmente, pero no es demasiado didáctico 
/*Me han comentado que otros profesores son muy estrictos con respecto al nombre de las variables. En mi primer examen práctico, también fue una pega. ¿Cuál es su punto de vista con respecto al tema?
¿Deben de ser siempre ultraespecíficas aunque no sea necesario por el contexto? ¿Alguna recomendación en general? Muchas gracias */