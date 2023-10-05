#include "comunidadElfo.hpp"
#include <algorithm>

using namespace std;

ComunidadElfos::ComunidadElfos() {}

ComunidadElfos::ComunidadElfos(const string& nombreComunidad, const string& lider, int poblacion, const string& habilidadesEspeciales)
    : nombreComunidad(nombreComunidad), lider(lider), poblacion(poblacion), habilidadesEspeciales(habilidadesEspeciales) {}

void ComunidadElfos::setNombreComunidad(const string& nombre) {
    nombreComunidad = nombre;
}

void ComunidadElfos::setLider(const string& lider) {
    this->lider = lider;
}

void ComunidadElfos::setPoblacion(int poblacion) {
    this->poblacion = poblacion;
}

void ComunidadElfos::sethabilidadesEspeciales(const string& habilidadesEspeciales) {
    this->habilidadesEspeciales = habilidadesEspeciales;
}

void ComunidadElfos::setElfosAsignados(const vector<Elfo>& elfos) {
    elfosAsignados = elfos;
}

string ComunidadElfos::getNombreComunidad() const {
    return nombreComunidad;
}

string ComunidadElfos::getLider() const {
    return lider;
}

int ComunidadElfos::getPoblacion() const {
    return poblacion;
}

string ComunidadElfos::gethabilidadesEspeciales() const {
    return habilidadesEspeciales;
}

vector<Elfo> ComunidadElfos::getElfosAsignados() const {
    return elfosAsignados;
}
double ComunidadElfos::promedioPoderMagicoComunidad() const {
    double sumaPoderMagico = 0.0;

    for (const Elfo& elfo : elfosAsignados) {
        sumaPoderMagico += static_cast<double>(elfo.getPoder());
    }

    if (elfosAsignados.size() > 0) {
        return sumaPoderMagico / elfosAsignados.size();
    } else {
        return 0.0; // Si no hay elfos asignados, el promedio es 0.
    }
}

string ComunidadElfos::getDescripcion() const {
    std::string descripcion = "Comunidad: " + nombreComunidad + ", Líder: " + lider;
    descripcion += ", Población: " + to_string(poblacion);
    descripcion += ", Características Especiales: " + habilidadesEspeciales;
    return descripcion;
}

vector<pair<Elfo, string>> ComunidadElfos::buscarElfosPorHabilidades(const vector<string>& habilidades) const {
    vector<pair<Elfo, string>> elfosEncontrados;

    for (const Elfo& elfo : elfosAsignados) {
        const vector<string>& habilidadesEspeciales = elfo.getHabilidadesEspeciales();

        // Comprobar si el elfo tiene al menos una de las habilidades buscadas
        for (const string& habilidad : habilidades) {
            if (find(habilidadesEspeciales.begin(), habilidadesEspeciales.end(), habilidad) != habilidadesEspeciales.end()) {
                // El elfo tiene la habilidad, agregarlo a la lista con el nombre de la comunidad
                elfosEncontrados.push_back(make_pair(elfo, nombreComunidad));
                break; // No es necesario seguir buscando más habilidades para este elfo
            }
        }
    }

    return elfosEncontrados;
}