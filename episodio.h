#pragma once
#include <iostream>
#include "video.h"

using namespace std;

class Episodio : public Video{
    
    protected:
        int m_temporada;

    public:
        Episodio(string,string,string,string,double,int);
        int getTemporada();
        virtual string muestraDatos();
        // virtual ~Episodio();

};