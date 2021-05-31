#include <iostream>
#include "serie.cpp"
#include "episodio.cpp"
#include "video.cpp"
#include "pelicula.cpp"
#include <vector>


using namespace std;


int main(){

    // Creando un episodio
    Video *unEpisodio = new Episodio(
        "20110125-S01E01",
        "Winter is coming",
        "1:02",
        "Drama",
        7.8,
        2
    );

    // Creando un vector de videos que en realidad son episodios
    vector<Video *> episodios;
    episodios.push_back(unEpisodio); // Guarando un episodio en el vector
    
    // Creando una serie
    Serie s1(
        "20110125",
        "Game of Thrones",
        "Drama",
        8);
    
    // Mostrando los datos de la serie
    cout << s1.mostrarDatos() << endl;
    
    // Agregando el vector de episodios a la serie e imprimiendo en pantalla
    s1.setEpisodios(episodios);
    s1.mostrarEpisodios();

    return 0;
}

