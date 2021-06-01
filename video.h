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
    string m_calificacion;

    public:
    virtual string getID() = 0;
    string getNombre();
    string getDuracion();
    string getGenero();
    string getCalificacion(); 
    void setCalificacion(string);
    virtual string muestraDatos() = 0;
    // virtual ~Video(); 

};

