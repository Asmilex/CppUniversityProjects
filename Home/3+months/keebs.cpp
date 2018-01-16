#include <iostream>
#include <vector>
using namespace std;

class Keyboard{
private:
    int layout;
    char distro;
    string mechSwitch; 
public:
    Keyboard(){
        mechSwitch = SwitchQuery();
        layout = LayoutQuery();
        distro = DistroQuery();
    }

    Keyboard(int layout_, char distro_, string mechSwitch_){
        layout = layout_;
        distro = distro_;
        mechSwitch = mechSwitch_;
    }
    
    void TypeKeeb() const{
        cout <<"Tamaño: "<<this->layout<<" % \nDistribución: ";
        if (this->distro == 'I')
            cout <<"ISO";
        if (this->distro == 'A')
            cout <<"ANSI";
        if (this->distro == 'D')
            cout <<"Dvorak";
        cout <<"\nTipo de switch: "<<this->mechSwitch;
    };

    string SwitchQuery() const{
        cout <<"¡Bienvenido a la consulta de switches! Esta guía te ayudará a elegir un tipo de interruptor\n";
        cout <<"Para empezar, ¿qué te gusta más? ¿Te gusta que la tecla vaya suave hacia abajo (lineal), que haya un pequeño impacto "; 
        cout <<"silencioso al activarse (táctil), o que ese impacto se pueda oír (clicky)? \n 1) Lineal\n 2) Táctil \n 3) Clicky\n";
        
        int selector = 0;
        string TipoSwitch;
        
        while (selector != 1 && selector != 2 && selector != 3)
            cin >> selector;
        switch (selector){
            case 1:
                cout <<"Cuánta fuerza te gusta hacer para apretar la tecla?";
                cout <<"\n 1) Poca \n 2) Fuerza media \n 3) Que esté durilla \n";
                
                selector = 0;
                while (selector != 1 && selector != 2 && selector != 3)
                    cin >> selector;
                if (selector == 1){
                    cout <<"Quizás te puedan gustar los reds";
                    TipoSwitch = "red";
                }
                if (selector == 2){
                    cout <<"Quizás te puedan gustar los blacks, pero son algo mas difíciles de encontrar";
                    TipoSwitch = "black";
                }
                if (selector == 3){
                    cout <<"Quizás te pueda gustar el tipo de switch Black Grey, pero son bastantes difíciles de encontrar";
                    TipoSwitch = "black grey";
                }
                
                break;

            case 2:
                cout <<"Cuánta fuerza te gusta hacer para apretar la tecla?";
                cout <<"\n 1) Poca \n 2) Fuerza media \n 3) Que esté durilla \n";
                
                selector = 0;
                while (selector != 1 && selector != 2 && selector != 3)
                    cin >> selector;
                if (selector == 1){
                    cout <<"Quieres lo mejor de lo mejor (1), o te vale con algo típico (2)?";
                    int aux = 0;
                    
                    while (aux != 1 && aux != 2)
                        cin >>aux;

                    if (aux == 1){
                        cout <<"Cómprate un Topre, asqueroso rico";
                        TipoSwitch = "topre";
                    }
                    if (aux == 2){
                        cout <<"Un brown te gustará";
                        TipoSwitch = "brown";
                    }                    
                }
                if (selector == 2){
                    cout <<"Quizás te puedan gustar los clear, pero son algo mas dificiles de encontrar";
                    TipoSwitch = "clear";
                }
                if (selector == 3){
                    cout <<"Quizás te pueda gustar el tipo de switch light grey, pero son bastantes difíciles de encontrar";
                    TipoSwitch = "light grey";
                }
                
                break;

            case 3:
                cout <<"Cuánta fuerza te gusta hacer para apretar la tecla?";
                cout <<"\n 1) Poca \n 2) Fuerza media \n 3) Que esté durilla \n 4) QUE HAGAN MUCHO RUIDO PACHUM PACHUM\n";
                
                selector = 0;
                while (selector != 1 && selector != 2 && selector != 3 && selector != 4)
                    cin >> selector;
                if (selector == 1){
                    cout <<"Los blues son para ti. Son mis preferidos!";
                    TipoSwitch = "blue";
                }
                if (selector == 2){
                    cout <<"A lo mejor los White Alps son para ti";
                    TipoSwitch = "white alps";
                }
                if (selector == 3){
                    cout <<"Los greens son lo tuyo";
                    TipoSwitch = "green";
                }
                if (selector == 4){
                    cout <<"PACHUM MODEL PACHUM PACHUM M PACHUUUUM";
                    TipoSwitch = "buckling spring";
                }
                
                break;
        }
        
        return TipoSwitch;
    };

    int LayoutQuery() const{
        cout <<"\nVamos a ver qué tamaño de teclado es el tuyo\n¿Usas el pad numérico? (Y/n)\n";
        
        int TamanoLayout;
        char selector = '0';
        while (selector != 'Y' && selector != 'y' && selector != 'N' && selector !='n')
            cin >>selector;

        if (selector == 'Y' || selector == 'y'){
            cout <<"Tienes dos opciones: o comprarte uno típico (Full size, a.k.a. 100%) o un pad numérico y usar otro teclado a la vez.";
            cout <<"¿Quieres hacer lo primero? (Y/n)\n";
                    
            selector = '0';
            
            while (selector != 'Y' && selector != 'y' && selector != 'N' && selector !='n')
                cin >>selector;
            
            if (selector == 'Y' || selector == 'y'){
                TamanoLayout = 100;
                selector = 0;
            }

        }
        if (selector == 'N' || selector == 'n'){
            cout <<"\n¿Te gusta usar combinaciones de teclas, o te gusta tener todas las teclas a mano?\n";
            cout <<" Y) Combinaciones \n N) Que las tenga todas al alcance\n";
            selector = '0';
            while (selector != 'Y' && selector != 'y' && selector != 'N'&& selector != 'n')
                cin >>selector;
            
            if (selector == 'N' || selector == 'n'){
                cout <<"¿Compacto o extendido? \n 1) Compacto \n 2) Extendido ";
                
                selector = '0';
                while (selector != '1' && selector != '2')
                    cin >>selector;
                if (selector == '1')
                    TamanoLayout = 75;
                if (selector == '2')
                    TamanoLayout = 80;
            }

            if (selector == 'Y'|| selector == 'y'){
                cout <<"Quieres usar las teclas de dirección con Fn + WASD (1) o tenerlas físicamente en el teclado (2)?\n";
                
                selector = '0';
                while (selector != '1' && selector != '2')
                    cin >>selector;
                if (selector == '1')
                    TamanoLayout = 60;
                if (selector == '2')
                    TamanoLayout = 65;
            }
            
        }             
        
        cout <<"El tamaño del teclado que te gustará será un "<<TamanoLayout;
        return TamanoLayout;
    };

    char DistroQuery() const{
        cout <<"\n¿Eres de Europa, EEUU o un extraño que usa Dvorak?\n";
        cout <<" 1) Europa \n 2) EEUU \n 3) No me llames raro mamón, que el Dvorak mola\n";

        char distro;
        int selector = 0;
        while (selector != 1 && selector != 2 && selector != 3)
            cin >>selector;
        if (selector == 1)
            distro = 'I';
        if (selector == 2)
            distro = 'A';
        if (selector == 3)
            distro = 'D';

        return distro;
    };
};

    
int main(){
    cout <<"¡Sé bienvenido a la cutre-guía de teclados mecánicos que no tiene ni GUI! Te ayudaré a elegir un teclado a tu medida";
    cout <<"Si tienes idea de cómo va la cosa más o menos, puedes especificar tu teclado directamente. Si no, te mostaré una ayuda";
    cout <<"\n¿Quieres construir tu teclado directamente? (Y/n)\n";

    char selector = '0';
    while (selector != 'Y' && selector != 'y' && selector != 'N' && selector != 'n'){
        cin >>selector;
    }
    
    if (selector == 'N' || selector == 'n'){
        Keyboard MiTeclado;
        MiTeclado.TypeKeeb();
    }

    else{
        cout <<"¿Tipo de switch?";
        string TipoSwitch;
        getline (cin, TipoSwitch);
        
        cout <<"¿Tamaño?";
        int TamanoLayout;
        cin >>TamanoLayout;
        while (TamanoLayout < 40 || TamanoLayout > 110){
            cout <<"Me da a mí que ese layout no existe. O no lo conozco. Ponlo de nuevo: \n";
            cin >>TamanoLayout;
        }

        cout <<"¿Distribución? (1: ISO. 2: ANSI. 3: Dvorak)";
        char distro;
        int selector_;
        if (selector_ == 1)
            distro = 'I';
        if (selector_ == 2)
            distro = 'A';
        if (selector_ == 3)
            distro = 'D';
        
        Keyboard MiTeclado(TamanoLayout, distro, TipoSwitch);
        MiTeclado.TypeKeeb();
    }
}