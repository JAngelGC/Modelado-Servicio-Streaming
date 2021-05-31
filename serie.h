#pragma once
#include <iostream>
#include <vector>
#include "episodio.h"

using namespace std;

class Serie{

    protected:
        string m_id;
        string m_nombre;
        string m_genero;
        int m_temporadas;
        vector <Episodio *> m_episodios;

    public:
        Serie(string, string, string, int, vector <Episodio *>);
        string getID();
        string getNombre();
        string getGenero();
        int getTemporadas();
        vector<Episodio *> getEpisodios();
        string mostrarEpisodios();
        string mostrarDatos();




};