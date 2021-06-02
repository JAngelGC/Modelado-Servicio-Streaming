#include "episodio.h"


Episodio::Episodio(string id, string idEpisodio, string nombre, string duracion, string calificacion, int temporada){
    m_id = id;
    m_idEpisodio = idEpisodio;
    m_nombre = nombre;
    m_duracion = duracion;
    m_calificacion = calificacion;
    m_temporada = temporada;

}

string Episodio::getIdEpisodio(){
    return m_idEpisodio;
}

int Episodio::getTemporada(){
    return m_temporada;
}

void Episodio::setGenero(string genero){
    m_genero = genero;
}

string Episodio::muestraDatos(){
    string var_mostrar = "Nombre del Episodio: " + m_nombre + ", " + "Duracion: " + m_duracion + " hrs, " + "Genero: " + m_genero + ", " + "Calificacion: " + m_calificacion + ", Temporada: " + to_string(m_temporada) + "\n";
    return var_mostrar;
}

