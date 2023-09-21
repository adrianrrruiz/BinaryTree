#include "NodoBinario.h"

template <class T>
NodoBinario<T>::NodoBinario()
{
}

template <class T>
NodoBinario<T>::NodoBinario(T val)
{
}

template <class T>
NodoBinario<T>::~NodoBinario()
{
}

template <class T>
T NodoBinario<T>::obtenerDato()
{
    return T();
}

template <class T>
void NodoBinario<T>::fijarDato(T val)
{
}

template <class T>
NodoBinario<T> *NodoBinario<T>::obtenerHijoIzq()
{
    return nullptr;
}

template <class T>
NodoBinario<T> *NodoBinario<T>::obtenerHijoDer()
{
    return nullptr;
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq)
{
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der)
{
}

template <class T>
bool NodoBinario<T>::esHoja()
{
    return false;
}

template <class T>
int NodoBinario<T>::altura()
{
    int valt; //Valor altura

    if(nodo->esHoja()){
        valt = 0; //Solo es un nodo
    } else{
        int valt_izq = -1;
        int valt_der = -1;
        if(this->hijoIzq != NULL){
            valt_izq = (this->hijoIzq)->altura();
        }
        if(this->hijoDer != NULL){
            valt_der = (this->hijoDer)->altura();
        }
        if(valt_izq > valt_der){
            valt = valt_izq + 1;
        }else {
            valt = valt_der + 1;
        }
    }
    return valt;
}
