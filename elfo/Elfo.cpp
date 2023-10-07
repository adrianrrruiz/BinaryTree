#include "Elfo.hpp"

Elfo::Elfo() {}

Elfo::Elfo(const std::string& nombre, int poder, const std::vector<std::string>& habilidadesEspeciales)
    : nombre(nombre), poder(poder), habilidadesEspeciales(habilidadesEspeciales) {}

string Elfo::getNombre() const 
{
    return nombre;
}

void Elfo::setNombre(string nombre)
{
    this->nombre = nombre;
}

int Elfo::getPoder() const 
{ 
    return poder;
}

void Elfo::setPoder(int poder)
{
    this->poder = poder;
}

vector<string> Elfo::getHabilidadesEspeciales() const
{
    return this->habilidadesEspeciales;
}

void Elfo::setHabilidadesEspeciales(vector<string> habilidadesEspeciales)
{
    this->habilidadesEspeciales = habilidadesEspeciales;
}
void Elfo::setComunidad(const std::string& comunidad) {
    this->comunidad = comunidad;
}

string Elfo::getComunidad() const {
    return comunidad;
}
