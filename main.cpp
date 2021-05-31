#include <iostream>
#include <vector>
#include "serie.cpp"
#include "episodio.cpp"
#include "video.cpp"
#include "pelicula.cpp"
#include <sstream>
#include <fstream>
#include <string.h>


using namespace std;

vector<Serie> cargarSeries()
{
    vector<Serie> series;
    string str;
    string file = "ProyectoIntegrador-Series.csv";
    ifstream s(file);

    if (s.is_open())
    {
        while(getline(s, str))
        {
            stringstream ss(str);
            string line[4];

            int i = 0;

            while(i < 4 && getline(ss,line[i++],';'));

            Serie s(
                line[0],
                line[1],
                line[2],
                stoi(line[3])
            );

            series.push_back(s);
        }

        // for(int i= 0;i < series.size(); i++)
        // {
        //     cout << series[i].mostrarDatos()<<endl;;
        // }
    }

    return series;
}

vector<Pelicula *> cargarPeliculas()
{
    vector<Pelicula *> peliculas;
    string str;
    string file1 = "ProyectoIntegrador-Peliculas.csv";
    ifstream s1(file1);

    if (s1.is_open())
    {
        while(getline(s1, str))
        {
            stringstream ss(str);
            string line[5];

            int i = 0;

            while(i < 5 && getline(ss,line[i++],';'));

            Pelicula *p = new Pelicula(
                line[0],
                line[1],
                line[2],
                line[3],
                stod(line[4])
            );

            peliculas.push_back(p);
        }

        for(int i= 0;i < peliculas.size(); i++)
        {
            cout << peliculas[i]->muestraDatos()<<endl;
        }
    }

    return peliculas;
}

vector<Episodio *> cargarEpisodios(vector<Serie> series)
{
    vector<Episodio *> episodios;
    string str;
    string file2 = "ProyectoIntegrador-Episodios.csv";
    ifstream s2(file2);

    if (s2.is_open())
    {
        while(getline(s2, str))
        {
            stringstream ss(str);
            string line[6];

            int i = 0;

            while(i < 6 && getline(ss,line[i++],';'));

            Episodio *ep = new Episodio(
                line[0],
                line[1],
                line[2],
                line[3],
                stod(line[4]),
                stoi(line[5])
            );

            episodios.push_back(ep);
        }

        //Asignar genero a Episodios (composicion de clase Serie)
        for(int i= 0;i < series.size(); i++)
        {
            for(int j=0;j < episodios.size();j++)
            {
                string epId = episodios[j]->getID();
                string sId = series[i].getID();
                if(epId == sId)
                {
                    string g = series[i].getGenero();
                    episodios[j]->setGenero(g);
                }
            }
        }

        // for(int i= 0;i < episodios.size(); i++)
        // {
        //     cout << episodios[i]->muestraDatos()<<endl;;
        // }

        //Asignar Episodios a Series (composicion de clase Serie);
        for(int i= 0;i < series.size(); i++)
        {
            vector<Episodio *> episodios_Serie;
            for(int j=0;j < episodios.size();j++)
            {
                string epId = episodios[j]->getID();
                string sId = series[i].getID();
                if(epId == sId)
                {
                    episodios_Serie.push_back(episodios[j]);
                }
            }
            
            series[i].setEpisodios(episodios_Serie);
        }

        // cout << "Series y Episodios:\n"<< "Series:\n" <<endl;

        // for(int i= 0;i < series.size(); i++)
        // {
        //     cout << series[i].getNombre() << ":\n";
        //     vector<Episodio *> episodios = series[i].getEpisodios();
            
        //     for(int j = 0; j < episodios.size();j++)
        //     {
        //         cout << episodios[j]->muestraDatos();
        //     }

        //     cout << endl;
        // }
    }
}

vector<Video *> cargarVideos(vector<Pelicula *> peliculas,vector<Episodio *> episodios)
{
    vector<Video *> videos;
    videos.reserve(peliculas.size()+ episodios.size());
    videos.insert(videos.end(), peliculas.begin(), peliculas.end());
    videos.insert(videos.end(), episodios.begin(), episodios.end());

    // cout << "Videos:\n" << endl;
    // for(int i = 0; i < videos.size(); i++)
    // {
    //     cout << videos[i]->muestraDatos();
    // }
    // return videos;
}

int main(){

    vector<Serie> series;
    vector<Pelicula *> peliculas;
    vector<Episodio *> episodios;
    vector<Video *> videos;

    series = cargarSeries();
    peliculas = cargarPeliculas();
    episodios = cargarEpisodios(series);
    videos = cargarVideos(peliculas, episodios);

    return 0;
}