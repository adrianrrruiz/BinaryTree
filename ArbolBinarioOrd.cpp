#include "ArbolBinarioOrd.h"

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
    return 0;
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(T val)
{
    return false;
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T val)
{
    return false;
}

template <class T>
bool ArbolBinarioOrd<T>::buscar(T val)
{
    return false;
}

template <class T>
void ArbolBinarioOrd<T>::preOrden()
{
}

template <class T>
void ArbolBinarioOrd<T>::inOrden()
{
}

template <class T>
void ArbolBinarioOrd<T>::posOrden()
{
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden()
{
}
