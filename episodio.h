#pragma once
#include <iostream>
#include "video.h"

using namespace std;

class Episodio : public Video{
    
    protected:
        string m_idEpisodio;
        int m_temporada;

    public:
        Episodio(string,string,string,string,double,int);
        string getIdEpisodio();
        int getTemporada();
        void setGenero(string);
        virtual string muestraDatos();
        // virtual ~Episodio();

};