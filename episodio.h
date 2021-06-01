#pragma once
#include <iostream>
#include "video.h"

using namespace std;

class Episodio : public Video{
    
    protected:
        string m_idEpisodio;
        int m_temporada;

    public:
        Episodio(string,string,string,string,string,int);
        virtual string getID();
        string getIdSerie();
        int getTemporada();
        void setGenero(string);
        virtual string muestraDatos();
        // virtual ~Episodio();

};