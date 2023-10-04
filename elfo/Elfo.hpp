#ifndef ELFO_HPP
#define	ELFO_HPP

#include <vector>
#include <iostream>
using namespace std;

class Elfo{
    protected:
        string nombre;
        int poder;
        vector<string> habilidadesEspeciales;
    public:
        //Getters y Setters
        string getNombre();
        void setNombre(string nombre);
        int getPoder();
        void setPoder(int poder);
        vector<string> getHabilidadesEspeciales();
        void setHabilidadesEspeciales(vector<string> habilidadesEspeciales);

};

#include "Elfo.cpp"

#endif //ELFO_HPP