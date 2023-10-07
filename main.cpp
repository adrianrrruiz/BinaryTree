#include <iostream>
#include <fstream>
#include <map>
#include "binary_tree/BinaryTree.hpp"
#include "elfo/Elfo.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "elfo/comunidadElfo.hpp"

void leerElfos(string rutaArchivo, vector<Elfo>& listaElfos);
void imprimirElfos(const vector<Elfo>& listaElfos);
std::map<std::string, std::vector<Elfo>> asignarComunidades(std::vector<Elfo>& elfos);
void imprimirElfosPorComunidad(const std::map<std::string, std::vector<Elfo>>& comunidades);
map<string, double> calcularPromedios(const vector<ComunidadElfos>& comunidades);
void mostrarPromedios(const map<string, double>& promediosComunidades);
vector<pair<Elfo, string>> buscarElfosPorHabilidadesEnComunidades(const vector<ComunidadElfos>& comunidades, const vector<string>& habilidadesBuscadas);
void mostrarElfosEncontrados(const vector<pair<Elfo, string>>& elfosEncontrados);
int main()
{
    int opcion, dato;
    BinaryTree<int> arbol = BinaryTree<int>();
    map<string, BinaryTree<Elfo>> universoElfico;
    vector<Elfo> listaElfos;
    //leerElfos("elfo/elfos.txt", listaElfos);
    //Para crear las comunidades y agregar los elfos
    map<string, vector<Elfo>> comunidades = asignarComunidades(listaElfos);

    //Crear mapa con los promedio por poderes de cada comunidad
    //map<std::string, double> promedios = calcularPromedios(comunidades);
    //Buscar 2 habilidades espcificas en cada comunidad
    vector<string> habilidadesBuscadas = { "Magia elemental", "Invisibilidad" };
    //Para buscar los elfos con sus comunidades por las habilidades
    //vector<pair<Elfo, std::string>> elfosEncontrados = buscarElfosPorHabilidadesEnComunidades(comunidades, habilidadesBuscadas);
    //Para leer los elfos del archivo "elfos.txt"
    
    do{
        cout << "ARBOL BINARIO AVL\n";
        cout << "0. Cargar archivo elfos\n";
        cout << "1. Ingresar un dato\n";
        cout << "2. Mostrar arbol con preorden\n";
        cout << "3. Mostrar arbol con inorden\n";
        cout << "4. Mostrar arbol con posorden\n";
        cout << "5. Eliminar un dato\n";
        cout << "6. Altura del arbol\n";
        cout << "7. Imprimir elfos con su comunidad\n";
        cout << "9. Salir\n";
        cout << "Ingrese una opcion: "; cin >> opcion;
        
        switch (opcion)
        {
            case 0:
                leerElfos("elfo/elfos.txt", listaElfos);
                imprimirElfos(listaElfos);

                system("pause");
                break;
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
            case 7:{
                std::map<std::string, std::vector<Elfo>> comunidades = asignarComunidades(listaElfos);
                cout << "Se asignaron correctamente" << endl;
                for (const Elfo& elfo : listaElfos) {
                std::cout << "Nombre: " << elfo.getNombre() << ", Comunidad: " << elfo.getComunidad() << std::endl;
                }

                system("pause");
                break;
            }
            case 9:
                cout << "Muchas gracias por usar el sistema :)\n";
                system("pause");
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 9);

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
        if (linea != "") {
            if (linea.find("Poder:") != string::npos) { //.find - Si no encuentra la subcadena, devuelve string::npos 
                // Línea que contiene el poder del elfo
                poder = linea.substr(linea.find(":") + 2); // +2 para omitir ": "
            }
            else if (linea.find("Habilidades Especiales:") != string::npos) {
                 // Línea que contiene las habilidades especiales del elfo
                habilidadesEspeciales.clear(); //Vaciar lista antes de llenarla
                // Separar las habilidades por comas y agregarlas al vector
                unsigned int pos = linea.find(':');
                linea.erase(0, pos + 1); // Eliminar habilidades especiales
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

void imprimirElfos(const vector<Elfo>& listaElfos) {
    for (const Elfo& elfo : listaElfos) {
        cout << "Dentro del bucle for" << endl; // Agrega esta línea
        cout << "Nombre: " << elfo.getNombre() << endl;
        cout << "Poder: " << elfo.getPoder() << endl;
        cout << "Habilidades Especiales:";
        const vector<string>& habilidades = elfo.getHabilidadesEspeciales();
        for (const string& habilidad : habilidades) {
            cout << " " << habilidad;
        }
        cout << endl;
        cout << "---------------------------" << endl;
    }
}


std::map<std::string, std::vector<Elfo>> asignarComunidades(std::vector<Elfo>& elfos) {
    std::map<std::string, std::vector<Elfo>> comunidades;

    srand(time(0)); // Inicializa la semilla para números aleatorios

    for (Elfo& elfo : elfos) {
        int random = rand() % 3; // Genera un número aleatorio entre 0 y 2
        if (random == 0) {
            elfo.setComunidad("Elfolandia");
        } else if (random == 1) {
            elfo.setComunidad("Rivendel");
        } else {
            elfo.setComunidad("Arvandor");
        }

        // Agregar el elfo a su comunidad correspondiente en el mapa
        comunidades[elfo.getComunidad()].push_back(elfo);
    }

    return comunidades;
}


// Función para calcular el promedio de poder mágico de las comunidades
map<string, double> calcularPromedios(const vector<ComunidadElfos>& comunidades) {
    map<std::string, double> promediosComunidades;

    for (const ComunidadElfos& comunidad : comunidades) {
        double promedio = comunidad.promedioPoderMagicoComunidad();
        promediosComunidades[comunidad.getNombreComunidad()] = promedio;
    }

    return promediosComunidades;
}

void mostrarPromedios(const map<string, double>& promediosComunidades) {
    cout << "Promedios de Poder Magico por Comunidad:" << endl;
    
    for (const auto& pareja : promediosComunidades) {
        cout << pareja.first << ": " << pareja.second << endl;
    }
}

vector<pair<Elfo, string>> buscarElfosPorHabilidadesEnComunidades(
    const vector<ComunidadElfos>& comunidades,
    const vector<string>& habilidadesBuscadas) {
    
    vector<pair<Elfo, string>> elfosEncontrados;

    for (const ComunidadElfos& comunidad : comunidades) {
        vector<pair<Elfo, string>> elfosEnComunidad = comunidad.buscarElfosPorHabilidades(habilidadesBuscadas);
        elfosEncontrados.insert(elfosEncontrados.end(), elfosEnComunidad.begin(), elfosEnComunidad.end());
    }

    return elfosEncontrados;
    
}

void mostrarElfosEncontrados(const vector<pair<Elfo, string>>& elfosEncontrados) {
    cout << "Elfos con habilidades especiales:" << endl;
    for (const auto& pareja : elfosEncontrados) {
        cout << "Comunidad: " << pareja.second << ", Elfo: " << pareja.first.getNombre() << endl;
    }
}
