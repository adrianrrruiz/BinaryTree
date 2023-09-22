#include "ArbolBinarioOrd.h"
# include <queue>
template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
    this->raiz = NULL;
}

template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
    if(this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    }
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio()
{
    return this->raiz == NULL;
}

template <class T>
T ArbolBinarioOrd<T>::datoRaiz()
{
    return (this->raiz)->obtenerDato();
}

template <class T>
int ArbolBinarioOrd<T>::altura()
{
    if(this->esVacio()){
        return -1;
    }else{
        return (this->raiz)->altura();
    }
}

template <class T>
int ArbolBinarioOrd<T>::tamano()
{
    if(this->esVacio()){
        return -1;
    }else{
        return (this->raiz)->tamano();
    }
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(T val)
{
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while (nodo != NULL){
        padre = nodo;
        if(val<nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        } else {
            duplicado = true;
            break;
        }
    }
    if (!duplicado){
        NodoBinario<T>* nuevo = new NodoBinario<T>(val);
        if (nuevo != NULL){
            if (val<padre->obtenerDato())
                padre->fijarHijoIzq(nuevo);
            else 
                padre->fijarHijoDer(nuevo);
        }
        insertado = true;
    }
    return insertado;
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val) {
    NodoBinario<T>* padre = NULL; // Nodo padre del nodo que vamos a eliminar
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    // Buscar el nodo a eliminar y su padre
    while (nodo != NULL) {
        if (val == nodo->obtenerDato()) {
            encontrado = true;
            break; // Encontramos el nodo a eliminar
        }
        padre = nodo;

        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else {
            nodo = nodo->obtenerHijoDer();
        }
    }

    if (!encontrado) {
        return false; // No se encontró el valor a eliminar
    }

    // Caso 1: Nodo hoja
    if (nodo->esHoja()) {
        if (padre == NULL) {
            // El nodo raíz es el único nodo en el árbol
            delete this->raiz;
            this->raiz = NULL;
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHijoIzq(NULL);
        } else {
            padre->fijarHijoDer(NULL);
        }
        delete nodo;
    }
    // Caso 2: Nodo con un solo hijo
    else if (nodo->tieneUnHijo()) {
        NodoBinario<T>* hijo = (nodo->obtenerHijoIzq() != NULL) ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();
        if (padre == NULL) {
            // El nodo a eliminar es la raíz del árbol
            delete this->raiz;
            this->raiz = hijo;
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHijoIzq(hijo);
        } else {
            padre->fijarHijoDer(hijo);
        }
        delete nodo;
    }
    // Caso 3: Nodo con dos hijos
    else {
        NodoBinario<T>* sucesor = encontrarSucesor(nodo->obtenerHijoDer());
        T valorSucesor = sucesor->obtenerDato();
        eliminar(valorSucesor); // Eliminar el sucesor en el subárbol derecho
        nodo->fijarDato(valorSucesor);
    }
    return true; // Nodo eliminado 
}

template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::encontrarSucesor(NodoBinario<T>* nodo) {
    while (nodo->obtenerHijoIzq() != NULL) {
        nodo = nodo->obtenerHijoIzq();
    }
    return nodo;
}


template <class T>
bool ArbolBinarioOrd<T>::buscar(T val)
{
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado=false;
    while (nodo != NULL && !encontrado){
        if(val<nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        } else {
            encontrado = true;
        }
    }
    return encontrado;
}

template <class T>
void ArbolBinarioOrd<T>::preOrden()
{
    if(!this->esVacio())
        (this->raiz)->preOrden();
}

template <class T>
void ArbolBinarioOrd<T>::inOrden()
{
    if(!this->esVacio())
        (this->raiz)->inOrden();
}

template <class T>
void ArbolBinarioOrd<T>::posOrden()
{
    if(!this->esVacio())
        (this->raiz)->posOrden();
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden()
{
    if(!this->esVacio()){
        std::queue < NodoBinario<T>* > cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;
        while (!cola.empty()){
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->obtenerDato() << " ";
            if (nodo->obtenerHijoIzq() != NULL)
                cola.push(nodo->obtenerHijoIzq());
            if (nodo->obtenerHijoDer() != NULL)
                cola.push(nodo->obtenerHijoDer());
        }
    }
}
