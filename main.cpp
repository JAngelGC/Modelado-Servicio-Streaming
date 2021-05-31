#include <iostream>
#include "serie.cpp"
#include "episodio.cpp"
#include "video.cpp"
#include "pelicula.cpp"


using namespace std;


int main(){

    vector<Episodio *> episodios;
    episodios[0] = new Episodio(
        "20110125-S01E01",
        "Winter is coming",
        "1:02",
        "Drama",
        7.8,
        2
    );

    
    Serie s1(
        "20110125",
        "Game of Thrones",
        "Drama",
        8);
    
    s1.mostrarDatos();

    s1.setEpisodios(episodios);
    s1.mostrarEpisodios();

    return 0;
}