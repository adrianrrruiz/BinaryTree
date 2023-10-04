#include "Elfo.hpp"

string Elfo::getNombre()
{
    return this->nombre;
}

void Elfo::setNombre(string nombre)
{
    this->nombre = nombre;
}

int Elfo::getPoder()
{
    return this->poder;
}

void Elfo::setPoder(int poder)
{
    this->poder = poder;
}

vector<string> Elfo::getHabilidadesEspeciales()
{
    return this->habilidadesEspeciales;
}

void Elfo::setHabilidadesEspeciales(vector<string> habilidadesEspeciales)
{
    this->habilidadesEspeciales = habilidadesEspeciales;
}
