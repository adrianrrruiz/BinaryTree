#ifndef COMUNIDADELFO_HPP
#define COMUNIDADELFO_HPP

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "elfo.hpp"

using namespace std;

class ComunidadElfos {
public:
    ComunidadElfos();
    ComunidadElfos(const string& nombreComunidad, const string& lider, int poblacion, const string& habilidadesEspeciales);

    void setNombreComunidad(const string& nombre);
    void setLider(const string& lider);
    void setPoblacion(int poblacion);
    void sethabilidadesEspeciales(const string& habilidadesEspeciales);
    void setElfosAsignados(const vector<Elfo>& elfos);
    double promedioPoderMagicoComunidad() const;

    string getNombreComunidad() const;
    string getLider() const;
    int getPoblacion() const;
    string gethabilidadesEspeciales() const;
    vector<Elfo> getElfosAsignados() const;
    string getDescripcion() const;
    vector<pair<Elfo, string>> buscarElfosPorHabilidades(const vector<string>& habilidades) const;

private:
    string nombreComunidad;
    string lider;
    int poblacion;
    string habilidadesEspeciales;
    vector<Elfo> elfosAsignados;
};

#include "comunidadElfo.cpp"
#endif  // COMUNIDADELFO_HPP
