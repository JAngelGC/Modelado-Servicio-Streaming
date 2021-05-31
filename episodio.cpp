#include "episodio.h"


Episodio::Episodio(string id, string nombre, string duracion, string genero, double calificacion, int temporada){
    m_id = id;
    m_nombre = nombre;
    m_duracion = duracion;
    m_genero = genero;
    m_calificacion = calificacion;
    m_temporada = temporada;

}

int Episodio::getTemporada(){
    return m_temporada;
}

string Episodio::muestraDatos(){
    string var_mostrar = "Nombre del Episodio: " + m_nombre + ", " + "Duracion: " + m_duracion + " minutos, " + "Genero: " + m_genero + ", " + "Calificacion: " + to_string(m_calificacion) + ", Temporada: " + to_string(m_temporada) + "\n";
    return var_mostrar;
}

