#include <iostream>
#include <fstream>
#include <map>
#include "binary_tree/BinaryTree.hpp"
#include "elfo/Elfo.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include "elfo/comunidadElfo.hpp"

void leerElfos(string rutaArchivo, vector<Elfo>& listaElfos);
vector<ComunidadElfos> crearComunidadesYAsignarElfos(const std::string& rutaArchivo);
void imprimirComunidades(const vector<ComunidadElfos>& comunidades);
map<string, double> calcularPromedios(const vector<ComunidadElfos>& comunidades);
void mostrarPromedios(const map<string, double>& promediosComunidades);
vector<pair<Elfo, string>> buscarElfosPorHabilidadesEnComunidades(const vector<ComunidadElfos>& comunidades, const vector<string>& habilidadesBuscadas);
void mostrarElfosEncontrados(const vector<pair<Elfo, string>>& elfosEncontrados);
int main()
{
    int opcion, dato;
    BinaryTree<int> arbol = BinaryTree<int>();
    map<string, BinaryTree<Elfo>> universoElfico;
    //Para crear las comunidades y agregar los elfos
    vector<ComunidadElfos> comunidades = crearComunidadesYAsignarElfos("elfo/elfos.txt");
    //Crear mapa con los promedio por poderes de cada comunidad
    map<std::string, double> promedios = calcularPromedios(comunidades);
    //Buscar 2 habilidades espcificas en cada comunidad
    vector<string> habilidadesBuscadas = { "Magia elemental", "Invisibilidad" };
    //Para buscar los elfos con sus comunidades por las habilidades
    vector<pair<Elfo, std::string>> elfosEncontrados = buscarElfosPorHabilidadesEnComunidades(comunidades, habilidadesBuscadas);
    //Para leer los elfos del archivo "elfos.txt"
    vector<Elfo> listaElfos;
    leerElfos("elfo/elfos.txt", listaElfos);

    do{
        cout << "ARBOL BINARIO AVL\n";
        cout << "1. Ingresar un dato\n";
        cout << "2. Mostrar arbol con preorden\n";
        cout << "3. Mostrar arbol con inorden\n";
        cout << "4. Mostrar arbol con posorden\n";
        cout << "5. Eliminar un dato\n";
        cout << "6. Altura del arbol\n";
        cout << "7. Mostrar Elfo encontrados por habilidades especiales\n";
        cout << "8. Mostrar promedio de poderes Elfos\n";
        cout << "9. Salir\n";
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
            case 7:{
                mostrarElfosEncontrados(elfosEncontrados);
                break;
            }
            case 8:{
                mostrarPromedios(promedios);
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

// Función para crear comunidades y asignar elfos
vector<ComunidadElfos> crearComunidadesYAsignarElfos(const std::string& rutaArchivo) {
    vector<ComunidadElfos> comunidades;
    vector<Elfo> listaElfos;

    // Llamar a la función para cargar elfos desde el archivo en listaElfos
    leerElfos(rutaArchivo, listaElfos);

    // Crear tres comunidades de elfos
    ComunidadElfos elfolandia;
    elfolandia.setNombreComunidad("Elfolandia");
    elfolandia.setLider("Finarfin");
    elfolandia.setPoblacion(500);
    elfolandia.sethabilidadesEspeciales("Manipulación de la flora, crecimiento acelerado de plantas, sanación a través de plantas");

    ComunidadElfos rivendel;
    rivendel.setNombreComunidad("Rivendel");
    rivendel.setLider("Elrond");
    rivendel.setPoblacion(300);
    rivendel.sethabilidadesEspeciales("Sanación avanzada, detener el envejecimiento, protección mágica");

    ComunidadElfos arvandor;
    arvandor.setNombreComunidad("Arvandor");
    arvandor.setLider("Thranduil");
    arvandor.setPoblacion(700);
    arvandor.sethabilidadesEspeciales("Cambio de forma en un animal, habilidades animales");

    // Asignar elfos a cada comunidad (suponiendo que hay suficientes elfos en listaElfos)
    if (listaElfos.size() >= 3) {
        elfolandia.setElfosAsignados({ listaElfos[0], listaElfos[1] });
        rivendel.setElfosAsignados({ listaElfos[2] });
    }

    // Agregar las comunidades a la lista de comunidades
    comunidades.push_back(elfolandia);
    comunidades.push_back(rivendel);
    comunidades.push_back(arvandor);

    return comunidades;
}

void imprimirComunidades(const vector<ComunidadElfos>& comunidades) {
    for (const ComunidadElfos& comunidad : comunidades) {
        cout << "Comunidad: " << comunidad.getNombreComunidad() << endl;
        cout << "Líder: " << comunidad.getLider() << std::endl;
        cout << "Población: " << comunidad.getPoblacion() << endl;
        cout << "Características Especiales: " << comunidad.gethabilidadesEspeciales() << endl;

        cout << "Elfos Asignados:" << std::endl;
        for (const Elfo& elfo : comunidad.getElfosAsignados()) {
            cout << "  - " << elfo.getNombre() << std::endl;
        }

        std::cout << "---------------------------" << std::endl;
    }
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
    cout << "Promedios de Poder Mágico por Comunidad:" << endl;
    
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
