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
    string getID();
    string getNombre();
    string getDuracion();
    string getGenero();
<<<<<<< HEAD
    double getCalificacion();
    void setCalificacion(double);
=======
    string getCalificacion(); 
    void setCalificacion(string);
>>>>>>> Menu-4-5
    virtual string muestraDatos() = 0;
    // virtual ~Video();
};
