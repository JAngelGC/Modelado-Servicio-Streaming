#include "pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula(string id, string nombre,string duracion,string genero, double calificacion)
{
    m_id = id;
    m_nombre = nombre;
    m_duracion = duracion;
    m_genero = genero;
    m_calificacion = calificacion;
}

string Pelicula::muestraDatos()
{
    string str = "Pelicula: " + m_nombre + ", " + "Duracion: " + m_duracion + " minutos, " + "Genero: " + m_genero + ", " + "Calificacion: " + to_string(m_calificacion) + "\n";
    return str;
}