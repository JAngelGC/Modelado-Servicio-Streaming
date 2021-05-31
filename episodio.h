#pragma once
#include <iostream>

using namespace std;

class Episodio : public {
    
    protected:
        int m_temporada;

    public:
        Episodio(string,string,double,string,int,string,int);
        string getTemporada();
        virtual string muestraDatos();
        virtual ~Episodio();

};