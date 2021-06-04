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

//Sobre carga de operadores para comparar Videos
bool operator>(const Video &v1, const Video &v2)
{
    return (stod(v1.m_calificacion) > stod(v2.m_calificacion));
}

bool cmpVideos(const Video *v1, const Video *v2)
{
    return *v1 > *v2;
}

void Video::setCalificacion(string calificacion)
{
    m_calificacion = calificacion;
}
