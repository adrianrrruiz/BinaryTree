#ifndef NODOBINARIO
#define NODOBINARIO

template<class T>
class NodoBinario {
    protected:
        T dato;
        NodoBinario<T>* hijoIzq;
        NodoBinario<T>* hijoDer;
    public:
        NodoBinario();
        NodoBinario(T val);
        ~NodoBinario();
        T obtenerDato();
        void fijarDato(T val);
        NodoBinario<T>* obtenerHijoIzq();
        NodoBinario<T>* obtenerHijoDer();
        void fijarHijoIzq(NodoBinario<T>* izq);
        void fijarHijoDer(NodoBinario<T>* der);
        bool esHoja();
        int altura();
        void inOrden();
        void preOrden();
        void posOrden();
};

#include "NodoBinario.cpp"


#endif  // NODOBINARIO
