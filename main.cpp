#include <iostream>
#include <fstream>
#include <map>
#include "binary_tree/BinaryTree.hpp"
#include "elfo/Elfo.hpp"

int main()
{
    int opcion, dato;
    BinaryTree<int> arbol = BinaryTree<int>();
    map<string, BinaryTree<Elfo>> universoElfico;
    //Para leer los elfos del archivo "elfos.txt"
    vector<Elfo> listaElfos;
    leerElfos("archivo.txt", listaElfos);

    do{
        cout << "ARBOL BINARIO AVL\n";
        cout << "1. Ingresar un dato\n";
        cout << "2. Mostrar arbol con preorden\n";
        cout << "3. Mostrar arbol con inorden\n";
        cout << "4. Mostrar arbol con posorden\n";
        cout << "5. Eliminar un dato\n";
        cout << "6. Altura del arbol\n";
        cout << "7. Salir\n";
        cout << "Ingrese una opcion: "; cin >> opcion;
        
        switch (opcion)
        {
            case 1:
                cout << "Ingrese el numero que quiera insertar al arbol: ";
                cin >> dato;
                arbol.addNode(dato);
                system("pause");
                break;
            case 2:{
                cout << "PREORDEN\n";
                list<int> myList = arbol.preOrder();
                for (auto it = myList.begin(); it != myList.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 3:{
                cout << "INORDEN\n";
                list<int> myList = arbol.inOrder();
                for (auto it = myList.begin(); it != myList.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 4:{
                cout << "POSORDEN\n";
                list<int> myList = arbol.postOrder();
                for (auto it = myList.begin(); it != myList.end(); it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 5: 
                cout << "Ingrese el numero que quiera eliminar al arbol: ";
                cin >> dato;
                arbol.deleteNode(dato);
                break;
            case 6:{
                BinaryNode<int>* nodoAux = arbol.getRootNode(); //Se le pide la raiz del arbol
                int altura = arbol.alturaNodo(nodoAux); //Se pasa por parametro para saber la altura
                cout << "La altura del arbol es: " << altura << endl;
                system("pause");
                break;
            }
            case 7:
                cout << "Muchas gracias por usar el sistema :)\n";
                system("pause");
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 7);

    return 0;
}

void leerElfos(string rutaArchivo, vector<Elfo>& listaElfos) {
    ifstream archivo(rutaArchivo);

    if (!archivo) {
        cout << "No se puede abrir el archivo" << endl;
        return;
    }

    string linea;
    string nombre;
    string poder;
    vector<string> habilidadesEspeciales;

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            if (linea.find("Poder:") != string::npos) { //.find - Si no encuentra la subcadena, devuelve string::npos 
                // Línea que contiene el poder del elfo
                poder = linea.substr(linea.find(":") + 2); // +2 para omitir ": "
            }
            else if (linea.find("Habilidades Especiales:") != string::npos) {
                 // Línea que contiene las habilidades especiales del elfo
                habilidadesEspeciales.clear(); //Vaciar lista antes de llenarla
                getline(archivo, linea); // Leer la línea de habilidades
                // Separar las habilidades por comas y agregarlas al vector
                unsigned int pos = 0;
                while ((pos = linea.find(',')) != string::npos) {
                    string habilidad = linea.substr(0, pos);
                    habilidadesEspeciales.push_back(habilidad);
                    linea.erase(0, pos + 1);
                }
                habilidadesEspeciales.push_back(linea); // Agregar la última habilidad
            }
            else {
                // Línea que contiene el nombre del elfo
                nombre = linea;
            }
        }
        else {
            // Fin de un elfo, crea el objeto Elfo y lo agregarlo a la lista
            Elfo nuevoElfo;
            nuevoElfo.setNombre(nombre);
            nuevoElfo.setPoder(stoi(poder)); //Pasarlo de string a entero
            nuevoElfo.setHabilidadesEspeciales(habilidadesEspeciales);
            listaElfos.push_back(nuevoElfo);
        }
    }

    archivo.close();
    
}

