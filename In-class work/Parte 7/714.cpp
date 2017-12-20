#include <iostream>
#include <vector>
using namespace std;

void VaciarTablero(vector<vector<char>> & tab){
    for (int i=0; i<tab.size(); i++){
        for (int j=0; j<tab[i].size(); j++){
            tab[i][j]=' ';
        }
    }
}

void VisualizarTablero(const vector<vector<char>> & tab){
    cout <<"-------------\n";
    for (int i=0; i<tab.size(); i++){
        for (int j=0; j<tab[i].size(); j++){
            cout <<tab[i][j]<<" ";
        }
        cout <<endl;
    }
    cout <<"-------------\n";
}

void PedirJugada(int turno,const vector<vector<char>> & tab, int & f, int & c){
    cout <<"Te toca, jugador "<<turno;
    cout <<". ¿Dónde quieres colocar la ficha?(fila, columna)\n";
    cin >>f>>c;

    while (f-1>2 || c-1>2){
        cout <<"\n¿Dónde vas, colgao? Que te has pasado del tablero. Ponlo bien, anda\n";
        cin >>f>>c;
    }

    while (tab[f][c]!=' '){
        cout <<"A ver, estaría guapo pisotear las fichas de tu colega, pero me da a mí que no te voy a dejar. Anda, pon otra casilla\n";
        cin >>f>>c;
    }
}

void PonerFicha (int turno, vector<vector<char>> & tab, int f, int  c){
    if (turno==0)
        tab[f][c]='O';
    if (turno==1)
        tab[f][c]='X';
}

/**
 * @brief: muestra el resultado de la partida
 * @return estado: Devuelve 0 si ha ganado el primer jugador (O); 1 si ha ganado el segundo jugador (X); 2 si ha habido empate y 3 si se sigue jugando
 */
int ComprobarEstado(vector<vector<char>> & tab){  
    for (int f=0; f<tab.size(); f++){ //Por filas
        if (tab[f][0]==tab[f][1] && tab[f][1]==tab[f][2]){
            if (tab[f][0]=='O')
                return 0;
            if (tab[f][0]=='X')
                return 1;
        }
    }
    
    for (int c=0; c<tab.size(); c++){ //Por columnas
        if (tab[0][c]==tab[1][c] && tab[0][c]==tab[2][c]){
            if (tab[0][c]=='O')
                return 0;
            if (tab[0][c]=='X')
                return 1;
        }
    }

    if (tab[0][0]==tab[1][1] && tab[0][0]==tab[2][2]){ //Diagonal 1
        if (tab[0][0]=='O')
            return 0;
        if (tab[0][0]=='X')
            return 1;
    }
    
    if (tab[0][2]==tab[1][1] && tab[0][2]==tab[2][0]){ //Diagonal 2
        if (tab[0][2]=='O')
            return 0;
        if (tab[0][2]=='X')
            return 1;
    }
    
    for (int f=0; f<tab.size(); f++) //Si hay espacios en blanco, se sigue jugando 
        for (int c=0; c<tab.size(); c++)
            if (tab[f][c]==' ')
                return 3;


    return 2;
}

void MostrarGanador(int estado){
    if (estado==0)
        cout <<"Illo, jugador 1, lo has petado. ¡Enhorabuena!";
    if (estado==1)
        cout <<"Te la has sacado, jugador 2. Vaya paliza";
    if (estado==2)
        cout <<"Vaya mataos que sois. Jugáis 1v1 y no gana ninguno de los dos";
}


bool Sigue(){
    cout <<"¿Te hace otra partida?\n";
    cout <<"1) Aro!\n2) Nah\n";

    int decision;
    cin >>decision;

    if (decision==1)
        return true;
    else    
        return false;

}

int main(){
    vector<vector<char>> tab(3,vector<char>(3)); //Casillas en blanco: ' '; resto de casillas: 'X','O'
    int turno=0, estado, f, c;


    do {
        cout <<"Empieza la partida\n";
        VaciarTablero(tab);
        VisualizarTablero(tab);
       
        do {
            turno=(turno+1)%2;              //Avanzar turno
            PedirJugada(turno, tab, f, c);  //Pregunta dónde poner cada ficha
            PonerFicha(turno, tab, f, c);   //Poner ficha en el tablero
            VisualizarTablero(tab);         //Mostrar tablero
            estado=ComprobarEstado(tab);    //Gana, empate, nada

            } while (estado==3);
        
        MostrarGanador(estado);             //Mostrar resultado
    } while (Sigue());

    return 0;
}