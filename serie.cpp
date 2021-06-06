#include "Serie.h"
#include <vector>

Serie::Serie(string id, string nombre, string genero, int temporadas)
{
    m_id = id;
    m_nombre = nombre;
    m_genero = genero;
    m_temporadas = temporadas;
}

string Serie::getID()
{
    return m_id;
}

string Serie::getNombre()
{
    return m_nombre;
}

string Serie::getGenero()
{
    return m_genero;
}

int Serie::getTemporadas()
{
    return m_temporadas;
}

vector<Episodio *> Serie::getEpisodios()
{
    return m_episodios;
}

void Serie::setEpisodios(vector<Episodio *> episodios)
{
    m_episodios = episodios;
}

string Serie::mostrarEpisodios()
{

    string str;
    for (auto episodio_ptr : m_episodios)
    {
        str = episodio_ptr->muestraDatos();
    }
    return str;
}

string Serie::mostrarDatos()
{
    string var_mostrar = "Nombre de la serie: " + m_nombre + ", Genero: " + m_genero + ", Temporadas: " + to_string(m_temporadas) + "\n";
    return var_mostrar;
}
