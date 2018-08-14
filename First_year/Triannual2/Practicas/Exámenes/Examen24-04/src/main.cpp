/**
 * @file main.cpp
 * @brief Examen de laboratorio 
 * Universidad de Granada
 * Metodología de la Programación 
 * @nombre_del_alumno: Asmilex
*/
#include <iostream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
*/
void imprimirVector(const string *v, const int n)  {
    if (v != NULL && n > 0)  {
        cout << n << " elementos" << endl;
        for (int i=0; i<n; i++)
                cout << "["<<i<<"] = " << v[i] << endl;
    }
    else
        cerr << "ERROR: Vector de datos vacío" << endl;
}

/**
 * @brief Implementa la función del enunciado 
 * @param v1 Primer vector
 * @param nv1 Número de elementos de @a v1
 * @param v2 Segundo vector
 * @param nv2 Número de elementos de @a v2
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * &v3, int &nv3)  {
    //Concatenación de v1 y v2
    string * concatenacion = new string [nv1+nv2];
    int dim_temp = 0;
    
    for (unsigned int i=0; i<nv1; i++){
        concatenacion[dim_temp] = v1[i];
        dim_temp++;
    }
        
    for (unsigned int j=0; j<nv2; j++){
        concatenacion[dim_temp] = v2[j];
        dim_temp++;
    }
       
    string * ordenado = new string [nv1+nv2];
    bool no_repetido;
    
    //Copia a otro vector, sin repetir elementos
    for (int i=0; i<dim_temp; i++){
        no_repetido = true;
        if (nv3 == 0){
            ordenado[nv3] = concatenacion[0];
            nv3++;
        }
        else{
            for (unsigned int j=0; j<nv3; j++)
                if (concatenacion[i] == ordenado[j])
                    no_repetido=false;
                
            if (no_repetido){
                ordenado[nv3] = concatenacion[i];
                nv3++;
            }
        }
    }
    
    //Copia de ordenado a v3
    v3 = new string [nv3];
    for (unsigned int i=0; i<nv3; i++)
        v3[i] = ordenado[i];
    
    delete [] concatenacion;
    delete [] ordenado;
}
    



int main()  {
    int nv1=0, nv2=0, nv3=0;
    string *v1=NULL, *v2=NULL, *v3=NULL;

    cout <<"Introduce la dimensión del primer vector: \n";
    cin >>nv1;
    
    // Examen: Leer vector v1
    cout <<"Ahora los bigramas que quieras que te opere: \n";
    v1 = new string[nv1];
    for (unsigned int i=0; i<nv1; i++){
        cin >>v1[i];
    }
    imprimirVector(v1, nv1);

    // Examen: Leer vector B
    cout <<"Pues a por otro ahora. ¿Cuál es su dimensión? \n";
    cin >>nv2;
    
    cout <<"¿Y sus elementos?\n";
    v2 = new string [nv2];
    for (unsigned int i=0; i<nv2; i++){
        cin >>v2[i];
    }
    
    imprimirVector(v2, nv2);
    
    cout <<"Lectura de bigramas finalizada\n";
    // Examen: Calcular resultado
    funcion(v1, nv1, v2, nv2, v3, nv3);
    
    // Examen: Mostrar resultado
    imprimirVector(v3, nv3);

    // Examen: Terminación del programa
    delete [] v1;
    delete [] v2;
    delete [] v3;
    
    return 0;
}
