#pragma once

#include <iostream>

using namespace std;

class Video
{
    protected:
    string m_id;
    string m_nombre;
    string m_duracion;
    string m_genero;
    double m_calificacion;

    public:
    string getID();
    string getNombre();
    string getDuracion();
    string getGenero();
    double getCalificacion(); 
    void setCalificacion(double);
    virtual string muestraDatos() = 0;
    // virtual ~Video(); 

};

