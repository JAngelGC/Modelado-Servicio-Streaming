#include "video.h"
#include <iostream>

using namespace std;

string Video::getID()
{
    return m_id;
}


string Video::getNombre()
{
    return m_nombre;
}

string Video::getDuracion()
{
    return m_duracion;
}

string Video::getGenero()
{
    return m_genero;
}

string Video::getCalificacion()
{
    return m_calificacion;
}

void Video::setCalificacion(string calificacion)
{
    m_calificacion = calificacion;
}

