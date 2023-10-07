#ifndef ELFO_HPP
#define	ELFO_HPP

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Elfo{
    protected:
        string nombre;
        int poder;
        vector<string> habilidadesEspeciales;
        string comunidad;
    public:
        //Getters y Setters
        std::string getNombre() const;
        void setNombre(string nombre);
        int getPoder() const; 
        void setPoder(int poder);
        vector<string> getHabilidadesEspeciales() const;
        void setHabilidadesEspeciales(vector<string> habilidadesEspeciales);
        void setComunidad(const std::string& comunidad);
        string getComunidad() const;
        Elfo();
        Elfo(const std::string& nombre, int poder, const std::vector<std::string>& habilidadesEspeciales);

};

#include "Elfo.cpp"

#endif //ELFO_HPP