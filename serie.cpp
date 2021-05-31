#include "serie.h"

Serie::Serie(string id, string nombre, string genero, int temporadas, vector<Episodio *> episodios){
    m_id = id;
    m_nombre = nombre;
    m_genero = genero;
    m_temporadas = temporadas;
    m_episodios = episodios;
}

string Serie::getID(){
    return m_id;
}

string Serie::getNombre(){
    return m_nombre;
}

string Serie::getGenero(){
    return m_genero;
}

int Serie::getTemporadas(){
    return m_temporadas;
}

vector<Episodio *> Serie::getEpisodios(){
    return m_episodios;
}

string Serie::mostrarEpisodios(){
    
}

string Serie::mostrarDatos(){
    string var_mostrar = m_id + " / " + m_nombre + " / " + m_genero + " / " + " / " + to_string(m_temporadas) + "\n";
    return var_mostrar;
}
