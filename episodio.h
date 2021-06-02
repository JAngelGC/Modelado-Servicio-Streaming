#pragma once
#include <iostream>
#include "video.h"

using namespace std;

class Episodio : public Video{
    
    private:
        string m_idEpisodio;
        int m_temporada;
        string m_serie;

    public:
        Episodio(string,string,string,string,string,int);
        string getIdEpisodio();
        int getTemporada();
        void setSerie(string);
        string getSerie();
        void setGenero(string);
        virtual string muestraDatos();
        // virtual ~Episodio();

};