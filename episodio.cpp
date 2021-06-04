#include "episodio.h"

Episodio::Episodio(string id, string idEpisodio, string nombre, string duracion, string calificacion, int temporada)
{
    m_id = id;
    m_idEpisodio = idEpisodio;
    m_nombre = nombre;
    m_duracion = duracion;
    m_calificacion = calificacion;
    m_temporada = temporada;
}

string Episodio::getIdEpisodio()
{
    return m_idEpisodio;
}

int Episodio::getTemporada()
{
    return m_temporada;
}

void Episodio::setSerie(string serie)
{
    m_serie = serie;
}

string Episodio::getSerie()
{
    return m_serie;
}

void Episodio::setGenero(string genero)
{
    m_genero = genero;
}

string Episodio::muestraDatos()
{
    string var_mostrar = "Nombre del Episodio: " + m_nombre + ", Serie: " + m_serie + ", Temporada: " + to_string(m_temporada) + ", Duracion: " + m_duracion + " hrs, Genero: " + m_genero + ", Calificacion: " + m_calificacion + "\n";
    return var_mostrar;
}
