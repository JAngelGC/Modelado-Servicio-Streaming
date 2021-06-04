#pragma once

#include "video.h"
#include <iostream>

using namespace std;

class Pelicula : public Video
{
public:
    Pelicula(string, string, string, string, string);
    virtual string muestraDatos();
};