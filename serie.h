#pragma once
#include <iostream>
#include <vector>
#include "episodio.h"
#include "video.h"

using namespace std;

class Serie{

    protected:
        string m_id;
        string m_nombre;
        string m_genero;
        int m_temporadas;
        //NOTA: Debe ser un vector de video para que funcione el polimorfismo
        vector <Video *> m_episodios;

    public:
        Serie(string, string, string, int);
        string getID();
        string getNombre();
        string getGenero();
        int getTemporadas();
        vector<Video *> getEpisodios();
        //NOTA: Debe ser un vector de video para que funcione el polimorfismo
        void setEpisodios(vector<Video *>);
        void mostrarEpisodios();
        string mostrarDatos();




};