#include <iostream>
#include "NodoBinario.h"
#include "ArbolBinarioOrd.h"

using namespace std;

int main(){
    int opcion;
    ArbolBinarioOrd<int> arbol = new ArbolBinarioOrd();
    do {
        cout << "BIENVENIDO AL ARBOL BINARIO\n";
        cout << "1. Ingresar numero al arbol\n";
        cout << "2. Eliminar numero del arbol\n";
        cout << "3. Ordenar\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:{
                int num;
                cout << "Ingrese el numero: ";
                cin >> num;
                
                break;
            }
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida\n";
        }
    }while(opcion != 4);
    
    
    return 0;
}