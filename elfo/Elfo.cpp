#include "Elfo.hpp"
#include <ostream>

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

bool Elfo::operator<(Elfo const &otherElfo) const
{
    return poder < otherElfo.poder;
}

bool Elfo::operator>(Elfo const &otherElfo) const
{
    return poder > otherElfo.poder;
}

bool Elfo::operator==(Elfo const &otherElfo) const
{

    return poder == otherElfo.poder && nombre == otherElfo.nombre && habilidadesEspeciales == otherElfo.habilidadesEspeciales;
}

bool Elfo::operator!=(Elfo const &otherElfo) const
{
    return poder != otherElfo.poder || nombre != otherElfo.nombre || habilidadesEspeciales != otherElfo.habilidadesEspeciales;
}

ostream &operator<<(ostream &os, Elfo const &elfo)
{
    os << "Nombre: " << elfo.getNombre() << " - Poder: " << elfo.getPoder() << " - Habilidades: ";
    for(int i = 0; i < elfo.getHabilidadesEspeciales().size(); i++){
            os << elfo.getHabilidadesEspeciales()[i] << ", ";
    }
    
    return os;
}