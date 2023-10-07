#include <iostream>
#include <fstream>
#include <map>
#include "binary_tree/BinaryTree.hpp"
#include "elfo/Elfo.hpp"
#include <vector>
#include <string>
#include <algorithm>

void leerElfos(string rutaArchivo, vector<Elfo>& listaElfos);
void mostrarPromedios(const map<string, double>& promediosComunidades);
void crearComunidad(string nombreComunidad, int cantElfos, map<string, BinaryTree<Elfo>> &comunidadElfica, vector<Elfo>& listaElfos, BinaryTree<Elfo> &arbolComunidad);
void crearArbolConElfos(int cantidadElfos, vector<Elfo>& listaElfos, BinaryTree<Elfo> &arbolMagico);
map<string, double> operacion1(map<string, BinaryTree<Elfo>> &comunidadElfica);
double promedioElfos(list<Elfo> elfos);
void imprimirPromedios(map<string, double> promediosYComunidad);
void mostrarElfosLista(const vector<Elfo> &listaElfos);
void mostrarElfosComunidad(map<string, BinaryTree<Elfo>> &comunidadElfica);
void mostrarRaizArbol(string nombreComunidad, map<string, BinaryTree<Elfo>> &comunidadElfica);
list<Elfo> operacion2(list<string> &habilidades, map<string, BinaryTree<Elfo>> &comunidadElfica);
void buscarEnArbolHabilidad(list<Elfo> elfos, list<string> &habilidades, list<Elfo> &elfosConHabilidad);
bool encontroHabilidad(list<string> &habilidades, Elfo elfo);
void mostrarElfosEncontrados(list<Elfo> &elfos);
int main()
{
    int opcion, dato;
    string nombreComunidad = "";
    BinaryTree<int> arbol = BinaryTree<int>();
    BinaryTree<Elfo> arbolArvandor = BinaryTree<Elfo>();
    BinaryTree<Elfo> arbolElfolandia = BinaryTree<Elfo>();
    BinaryTree<Elfo> arbolRivendel = BinaryTree<Elfo>();
    map<string, BinaryTree<Elfo>> universoElfico;
    vector<Elfo> listaElfos;
    leerElfos("elfo/elfos.txt", listaElfos);
    cout << "Cargando elfos...\n";
    system("pause");
    system("cls");
    mostrarElfosLista(listaElfos); //Para probar que se estan leyendo todos los elfos
    system("pause");
    system("cls");
    //CREANDO COMUNIDADES
    crearComunidad("Arvandor", 4, universoElfico, listaElfos, arbolArvandor); //Crear comunidad Arvandor
    crearComunidad("Elfolandia", 4, universoElfico, listaElfos, arbolElfolandia); //Crear comunidad Arvandor
    crearComunidad("Rivendel", 5, universoElfico, listaElfos, arbolRivendel); //Crear comunidad Arvandor
    system("pause");
    system("cls");
    //mostrarElfosComunidad(universoElfico); //Para probar la creacion de las comunidades
    //MOSTRAR RAICES EN MAPA
    cout << "Observemos las raices de cada arbol magico: \n\n";
    mostrarRaizArbol("Arvandor",universoElfico);
    mostrarRaizArbol("Elfolandia",universoElfico);
    mostrarRaizArbol("Rivendel",universoElfico);
    system("pause");
    system("cls");

    do{
        cout << "ARBOL MAGICO ELFOS\n";
        cout << "1. Mostrar arbol con preorden\n";
        cout << "2. Mostrar arbol con inorden\n";
        cout << "3. Mostrar arbol con posorden\n";
        cout << "4. Buscar elfos con habilidades (operacion 2)\n";
        cout << "5. Mostrar promedio de poderes elfos por comunidad (operacion 1)\n";
        cout << "6. Imprimir arbol (printTree)\n";
        cout << "7. Salir\n";
        cout << "Ingrese una opcion: "; cin >> opcion;
        
        switch (opcion)
        {
            case 1:{
                cout << "PREORDEN\n";
                cout << "Ingrese el nombre de la comunidad que quiere ver: (Elfolandia - Rivendel - Arvandor)"<< endl;
                cin >> nombreComunidad;
                list<Elfo> myList = universoElfico[nombreComunidad].preOrder();
                for(Elfo elfo : myList){
                    cout <<"- "<<elfo.getNombre()<<", ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 2:{
                cout << "INORDEN\n";
                cout << "Ingrese el nombre de la comunidad que quiere ver: (Elfolandia - Rivendel - Arvandor)"<< endl;
                cin >> nombreComunidad;
                list<Elfo> myList = universoElfico[nombreComunidad].inOrder();
                for(Elfo elfo : myList){
                    cout <<"- "<<elfo.getNombre()<<", ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 3:{
                cout << "POSORDEN\n";
                cout << "Ingrese el nombre de la comunidad que quiere ver: (Elfolandia - Rivendel - Arvandor)"<< endl;
                cin >> nombreComunidad;
                list<Elfo> myList = universoElfico[nombreComunidad].postOrder();
                for(Elfo elfo : myList){
                    cout <<"- "<<elfo.getNombre()<<", ";
                }
                cout << endl;
                system("pause");
                break;
            }
            case 4:{
                list<string> habilidadesABuscar;
                int cantHabilidades;
                string habilidad;
                cout << "Cuantas habilidades desea buscar: ";
                cin >> cantHabilidades;
                for(int i = 0; i < cantHabilidades; i++){
                    cout << "Ingrese la habilidad #" << i+1 << ": ";
                    cin >> habilidad;
                    habilidadesABuscar.push_back(habilidad);
                }
                list<Elfo> elfosEncontrados = operacion2(habilidadesABuscar, universoElfico);
                mostrarElfosEncontrados(elfosEncontrados);
                system("pause");
                break;
            }
            case 5:{
                map<string, double> promediosYComunidad = operacion1(universoElfico);
                imprimirPromedios(promediosYComunidad);
                system("pause");
                break;
            }
            case 6:
                cout << "Muchas gracias por usar el sistema :)\n";
                system("pause");
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 6);

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

map<string, double> operacion1(map<string, BinaryTree<Elfo>> &comunidadElfica){
    map<string, double> promediosYComunidad;
    list<Elfo> elfosArvandor = comunidadElfica["Arvandor"].preOrder();
    list<Elfo> elfosElfolandia = comunidadElfica["Elfolandia"].preOrder();
    list<Elfo> elfosRivendel = comunidadElfica["Rivendel"].preOrder();
    double promedioArvandor = promedioElfos(elfosArvandor);
    double promedioElfolandia = promedioElfos(elfosElfolandia);
    double promedioRivendel = promedioElfos(elfosRivendel);

    promediosYComunidad["Arvandor"] = promedioArvandor;
    promediosYComunidad["Elfolandia"] = promedioElfolandia;
    promediosYComunidad["Rivendel"] = promedioRivendel;

    return promediosYComunidad;
}

double promedioElfos(list<Elfo> elfos){
    double total = 0;
    for(Elfo elfo : elfos){
        total += elfo.getPoder();
    }
    return total/elfos.size();
}

void imprimirPromedios(map<string, double> promediosYComunidad){
    for (const auto& par : promediosYComunidad) {
        cout <<"Comunidad: " << par.first << " - Promedio: " << par.second << endl;
    }
}

list<Elfo> operacion2(list<string> &habilidades, map<string, BinaryTree<Elfo>> &comunidadElfica){
    list<Elfo> elfosArvandor = comunidadElfica["Arvandor"].preOrder();
    list<Elfo> elfosElfolandia = comunidadElfica["Elfolandia"].preOrder();
    list<Elfo> elfosRivendel = comunidadElfica["Rivendel"].preOrder();
    
    list<Elfo> elfosConHabilidadArvandor, elfosConHabilidadElfolandia, elfosConHabilidadRivendel, elfosConHabilidades;
    buscarEnArbolHabilidad(elfosArvandor, habilidades, elfosConHabilidadArvandor);
    buscarEnArbolHabilidad(elfosElfolandia, habilidades, elfosConHabilidadElfolandia);
    buscarEnArbolHabilidad(elfosRivendel, habilidades, elfosConHabilidadRivendel);

    //Para unir lo de todas la listas en una sola y retornarla
    elfosConHabilidades.insert(elfosConHabilidades.end(), elfosConHabilidadArvandor.begin(), elfosConHabilidadArvandor.end());
    elfosConHabilidades.insert(elfosConHabilidades.end(), elfosConHabilidadElfolandia.begin(), elfosConHabilidadElfolandia.end());
    elfosConHabilidades.insert(elfosConHabilidades.end(), elfosConHabilidadRivendel.begin(), elfosConHabilidadRivendel.end());

    return elfosConHabilidades;
}

void buscarEnArbolHabilidad(list<Elfo> elfos, list<string> &habilidades, list<Elfo> &elfosConHabilidad){
    for(Elfo elfo: elfos){
        if(encontroHabilidad(habilidades, elfo)){
            elfosConHabilidad.push_back(elfo);
        }
    }
}

bool encontroHabilidad(list<string> &habilidades, Elfo elfo){
    for(string habilidadElfo : elfo.getHabilidadesEspeciales()){
        for(string habilidad : habilidades){
            if(habilidad == habilidadElfo){
                return true;
            }
        }
    }
    return false;
}

void mostrarElfosEncontrados(list<Elfo> &elfos) {
    cout << "ELFOS ENCONTRADOS\n";
    for(Elfo elfo: elfos){
        cout << elfo << endl;
    }
}

void crearComunidad(string nombreComunidad, int cantElfos, map<string, BinaryTree<Elfo>> &comunidadElfica, vector<Elfo>& listaElfos, BinaryTree<Elfo> &arbolComunidad){
    cout << "CREANDO " << nombreComunidad << endl;
    crearArbolConElfos(cantElfos, listaElfos, arbolComunidad);
    comunidadElfica[nombreComunidad] = arbolComunidad;
}

void crearArbolConElfos(int cantidadElfos, vector<Elfo>& listaElfos, BinaryTree<Elfo> &arbolMagico){
    for(int i = 0; i < cantidadElfos; i++){
        if(listaElfos.size() == 0){
            break; //No hay mas elfos
        }
        cout << "Elfo insertado -> " << listaElfos.back() << endl;
        arbolMagico.addNode(listaElfos.back());
        listaElfos.pop_back();
    }
    cout << endl;
}

void mostrarPromedios(const map<string, double>& promediosComunidades) {
    cout << "Promedios de Poder Magico por Comunidad:" << endl;
    
    for (const auto& pareja : promediosComunidades) {
        cout << pareja.first << ": " << pareja.second << endl;
    }
}

void mostrarElfosLista(const vector<Elfo> &listaElfos) {
    cout << "LISTA DE ELFOS\n";
    for(Elfo elfo: listaElfos){
        cout << elfo << endl;
    }
}

void mostrarElfosComunidad(map<string, BinaryTree<Elfo>> &comunidadElfica)
{
    int cont = 1;
    for (auto const comunidad : comunidadElfica){
        cout<< comunidad.first << " - Contador: " << cont << endl;
        cont++;
    }
}

void mostrarRaizArbol(string nombreComunidad, map<string, BinaryTree<Elfo>> &comunidadElfica)
{
    cout << "Raiz de " << nombreComunidad << ": " << comunidadElfica[nombreComunidad].getRootNode()->getData().getNombre()<< endl;
}
