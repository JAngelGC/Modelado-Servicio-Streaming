#pragma once
#include <iostream>
#include <vector>
#include "Episodio.h"

using namespace std;

class Serie
{

protected:
    string m_id;
    string m_nombre;
    string m_genero;
    int m_temporadas;
    vector<Episodio *> m_episodios;

public:
    Serie(string, string, string, int);
    string getID();
    string getNombre();
    string getGenero();
    int getTemporadas();
    vector<Episodio *> getEpisodios();
    void setEpisodios(vector<Episodio *>);
    string mostrarEpisodios();
    string mostrarDatos();
};