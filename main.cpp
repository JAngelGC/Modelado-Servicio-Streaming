#include <iostream>
#include <vector>
#include "serie.cpp"
#include "episodio.cpp"
#include "video.cpp"
#include "pelicula.cpp"
#include <sstream>
#include <fstream>
#include <string.h>

#include <limits> // Aqui va el include para que funcione el forzarInt();
// #undef max

using namespace std;

vector<Serie> cargarSeries()
{
    vector<Serie> series;
    string str;
    string file = "ProyectoIntegrador-Series.csv";
    ifstream s(file);

    if (s.is_open())
    {
        while (getline(s, str))
        {
            stringstream ss(str);
            string line[4];

            int i = 0;

            while (i < 4 && getline(ss, line[i++], ';'))
                ;

            Serie s(
                line[0],
                line[1],
                line[2],
                stoi(line[3]));

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
        while (getline(s1, str))
        {
            stringstream ss(str);
            string line[5];

            int i = 0;

            while (i < 5 && getline(ss, line[i++], ';'));

            Pelicula *p = new Pelicula(
                line[0],
                line[1],
                line[2],
                line[3],
                line[4]);

            peliculas.push_back(p);
        }

        // for(int i= 0;i < peliculas.size(); i++)
        // {
        //     cout << peliculas[i]->muestraDatos()<<endl;
        // }
    }

    return peliculas;
}

<<<<<<< HEAD
// IMPORTANTE: El vector series se debe pasar como referencia para que se modifiquen sus elementos
vector<Episodio *> cargarEpisodios(vector<Serie> &series)
=======
vector<Episodio *> cargarEpisodios(vector<Serie>& series)
>>>>>>> Menu-4-5
{
    vector<Episodio *> episodios;
    string str;
    string file2 = "ProyectoIntegrador-Episodios.csv";
    ifstream s2(file2);

    if (s2.is_open())
    {
        while (getline(s2, str))
        {
            stringstream ss(str);
            string line[6];

            int i = 0;

            while (i < 6 && getline(ss, line[i++], ';'))
                ;

            Episodio *ep = new Episodio(
                line[0],
                line[1],
                line[2],
                line[3],
                line[4],
                stoi(line[5]));

            episodios.push_back(ep);
        }

        //Asignar genero a Episodios (composicion de clase Serie)
        for (int i = 0; i < series.size(); i++)
        {
            for (int j = 0; j < episodios.size(); j++)
            {
                string epId = episodios[j]->getID();
                string sId = series[i].getID();
                if (epId == sId)
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

        for (int i = 0; i < series.size(); i++)
        {
            vector<Episodio *> episodios_Serie;
            for (int j = 0; j < episodios.size(); j++)
            {
                string epId = episodios[j]->getID();
                string sId = series[i].getID();
                if (epId == sId)
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

    return episodios;
}

vector<Video *> cargarVideos(vector<Pelicula *> peliculas, vector<Episodio *> episodios)
{
    vector<Video *> videos;
    videos.reserve(peliculas.size() + episodios.size());
    videos.insert(videos.end(), peliculas.begin(), peliculas.end());
    videos.insert(videos.end(), episodios.begin(), episodios.end());

    // cout << "Videos:\n" << endl;
    // for(int i = 0; i < videos.size(); i++)
    // {
    //     cout << videos[i]->muestraDatos();
    // }

    return videos;
}

// Se puede crear una funcion que guarde los generos
// vector <string> cargarGeneros(vector<Video *> videos)

//Funcion para aceptar solo int's
int forzarInt() {
  int valInt;
  cin >> valInt;

  while (true) {
    if (cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "--Ingresar solo valores numericos. Trata de nuevo--\n";
      cin >> valInt;
      cout << endl;
    }
    else{
      return valInt;
      break;
    }
    }
}

//Funcion para verificar el rango de un valor
int verificarRango(int valor, int menor, int mayor){
  while(1){
    valor = forzarInt();
    if(valor>=menor && valor<=mayor){
      break;
    }else{
      cout << "Valor ingresado fuera del rango. Intenta de nuevo" <<endl;
    }
  }
  return valor;
}



//Funcion para modificar archivos episodios
void modificarArchivoEpisodios(vector<Episodio *> v)
{
    ofstream ofs("ProyectoIntegrador-Episodios.csv", ofstream::trunc);
    for(int i = 0; i < v.size();i++)
    {
        string str = v[i]->getID() + ";" + v[i]->getIdEpisodio() + ";" + v[i]->getNombre() + ";" + v[i]->getDuracion() + ";" + v[i]->getCalificacion() + ";" + to_string(v[i]->getTemporada()) + "\n";
        ofs << str;
    }
    ofs.close();
}

//Funcion para modificar archivos peliculas
void modificarArchivoPeliculas(vector<Pelicula *> v)
{
    ofstream ofs("ProyectoIntegrador-Peliculas.csv", ofstream::trunc);
    for(int i = 0; i < v.size();i++)
    {
        string str = v[i]->getID() + ";" + v[i]->getNombre() + ";" + v[i]->getDuracion() + ";" + v[i]->getGenero() + ";" + v[i]->getCalificacion() + "\n";
        ofs << str;
    }
    ofs.close();
}

int main()
{

    vector<Serie> series;
    vector<Pelicula *> peliculas;
    vector<Episodio *> episodios;
    vector<Video *> videos;
    vector <string> generos; // OJO: ESTO SE DEBE DINAMIZAR

    bool ciclarMenu = 1;
    int hayArchivos = 0;
    while (ciclarMenu)
    {

        cout << "*********** T I T U L O  D E L  P R O G R A M A ***********" << endl;
        cout << "Texto de bienvenida" << endl;

        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar los videos en general con una cierta calificacion o de un cierto genero" << endl;
        cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
        cout << "4. Mostrar las peliculas con cierta calificacion" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "6. Salir" << endl;

        cout << "Ingresa la opcion del menu que te interese: ";
        int opcion = forzarInt();




<<<<<<< HEAD
=======
        // cout << "Valor de hayArchivos: " << hayArchivos << endl;
>>>>>>> Menu-4-5
        if (opcion == 1)
        {
            cout << "Estas en la opcion 1" << endl;
            series = cargarSeries();
            peliculas = cargarPeliculas();
            episodios = cargarEpisodios(series);
            videos = cargarVideos(peliculas, episodios);
            generos = {"Accion", "Drama", "Misterio"}; // OJO: ESTO SE DEBE DINAMIZAR
            hayArchivos = 1;
        }

        else if (opcion == 2) // 2. Mostrar los videos en general con una cierta calificación o de un cierto género
        {
            if (hayArchivos == 1)
            {
                cout << "\nHas selecionado la opcion 2" << endl;

                cout << "\n¿Quieres ver videos por calificacion o por genero?" << endl;
                cout << "1. Calificacion" << endl;
                cout << "2. Genero" << endl;

                cout << "\nIngresa el numero de la opcion que desees: ";
                int opcionMenu2;
                opcionMenu2 = verificarRango(opcionMenu2, 1, 2);

                vector<Video *> videosAMostrar; //Aqui se van a guardar los videos que cumplan la condicion
                bool hayVideos = 0; // Variable que permite verificar si hay videos o no con la califacion

                if(opcionMenu2==1){ // User escogio ver videos por calificacion
                    cout << "Ingresa la calificacion de la cual deseas buscar videos: ";
                    double calificacion; // Variable que guarda la calificacion que el user desea buscar
                    cin >> calificacion;

                    for(auto ptr_video : videos){ // Se itera en el ciclo en busca de la calificacion del user
                        if(ptr_video->getCalificacion()==calificacion){
                            videosAMostrar.push_back(ptr_video);
                            hayVideos = 1; // Si hay videos
                        } 
                    }
                } 
                else if(opcionMenu2==2){ // User escogio ver videos por genero

                    cout << "\nLista de generos disponibles:" << endl;
                    for(int i=0; i<generos.size(); i++) // Se muestran los generos disponibles
                        cout << i+1 << "." << generos[i] << endl;
                    
                    cout << "\nIngrese el genero del cual deseas buscar videos: ";
                    int genero;         // Se guarda el genero que haya escogido el user
                    genero = verificarRango(genero, 1, generos.size());

                    for(auto ptr_video : videos){ // Se itera en el ciclo en busca el genero del user
                        if(ptr_video->getGenero()==generos[genero-1])
                            videosAMostrar.push_back(ptr_video);
                            hayVideos = 1; // Si hay videos
                    }
                }

                if(hayVideos==1){
                    cout << "\nMostrando videos " << endl;
                    for(auto ptr_video: videosAMostrar) // Aqui se muestran los videos que hayan sido encontrados por genero o por calificacion
                        cout << ptr_video->muestraDatos() << endl;
                }
                else{
                    cout << "No hay videos con la calificacion ingresada" << endl;// En caso de que no haya videos, se imprime el mensaje
                }
            }
            else
            {
                cout << "No han cargado los archivos" << endl;
            }
        }
        
        else if (opcion == 3) // Mostrar los episodios de una determinada serie con una calificacion determinada
        {
            if (hayArchivos)
            {
                cout << "\nHas seleccionado opcion 3" << endl;

                cout << "\nA continuacion se muestan las series: " << endl << endl; // Se muestran las series que hay
                for(int i=0; i<series.size(); i++)
                    cout << i+1 << ". " << series[i].mostrarDatos() << endl;

                cout << "Ingresa el numero de la serie que desees: " ;
                int opcionSerie;
                opcionSerie = verificarRango(opcionSerie, 1, series.size());

                cout << "\nSeleccionaste: " << endl;
                cout << series[opcionSerie-1].mostrarDatos() << endl; // Se muestra la serie que escogio el user
                cout << "Ahora selecciona la calificacion a buscar en dicha serie: " ;
                double calificacion;     // La calificacion que servira para buscar episodios en la serie
                cin >> calificacion;

                vector <Episodio *> episodiosAMostrar; // Vector en donde se guardaran los episodios a mostrar
                bool hayEpisodios = 0; // Variable que permite verificar si hay videos o no con la califacion

                // Vector que guarda los episodios de la serie seleccionada
                vector<Episodio *> episodiosSerie = series[opcionSerie-1].getEpisodios();

                for(auto ptr_episodio: episodiosSerie){ // Se guardan los episodios de la serie que tengan la calificacion que pide el user
                    if(ptr_episodio->getCalificacion()==calificacion){
                        episodiosAMostrar.push_back(ptr_episodio);
                        hayEpisodios = 1;
                    }
                }
                
                if(hayEpisodios==1){
                    cout << "\nMostrando videos " << endl;
                    for(auto ptr_video: episodiosAMostrar) // Aqui se muestran los videos que hayan sido encontrados por genero o por calificacion
                        cout << ptr_video->muestraDatos() << endl;
                }
                else{
                    cout << "No hay videos con la calificacion ingresada" << endl;// En caso de que no haya videos, se imprime el mensaje
                }

            }
            else
            {
                cout << "No han cargado los archivos" << endl;
            }
        }

        else if (opcion == 4)
        {
            if (hayArchivos)
            {
                cout << "Estas en la opcion 4" << endl;
                // Preguntar la calificacion de la pelicula que quiere ver
               
                double calif;
                cout << "Introduce la calificacion a buscar: ";
                cin >> calif;

                // Limites y Forzar Int
                
                vector<Pelicula *> temp;
                for(int i = 0;i< peliculas.size();i++)
                {
                    // llamar al vector peliculas y hacer un loop para verficar que lo que ingrese cumpla con una pelicula
                    if(stod(peliculas[i]->getCalificacion()) == calif)
                    {
                         // ir guardando las peliculas que cumplan con la condicion en un vector temporal
                        temp.push_back(peliculas[i]);
                    }
                }

                if(temp.size() > 0)
                {
                    //Imprime todas las peliculas con la calificacion
                    cout << "Estas son las peliculas con una calificacion de: " << calif << endl;
                    for(int i = 0; i < temp.size();i++)
                    {
                        // mostrar dicho vector tempoarl
                        cout << i+1 << ". Nombre de la Pelicula: " << temp[i]->getNombre() << ", Duracion: " << temp[i]->getDuracion() << " hrs, Genero: " << temp[i]->getGenero() << endl; 
                    }
                } else {
                    // mostrar que no hay peliculas que cumplan con esa calificacion en caso contrario
                    cout << "No se encontro ninguna pelicula con una calificacion de: " << calif << endl;
                }         
            }
            else
            {
                cout << "No han cargado los archivos" << endl;
            }
        }

        else if (opcion == 5)
        {
            if (hayArchivos)
            {
                cout << "Estas en la opcion 5" << endl;
                // Preguntar si serie o pelicula
                int opcionCalif;
                cout << "Calificar:\n1. Episodio de una Serie\n2. Pelicula\n\nIngresa el numero de la opcion deseada: ";
                cin >> opcionCalif;

                //forzar Int y limites

                // mostrar lo que sea el caso
                if(opcionCalif == 1)
                {
                    int serie;
                    cout << "Estas son las series disponibles: " << endl;
                    for(int i = 0; i < series.size(); i++)
                    {
                        //Imprime las series
                        cout << i+1 << ". " << series[i].getNombre() << endl;
                    }
                    cout << "Elige la opcion de tu gusto: ";
                    cin >> serie;

                     //forzarInt y limites

                    cout << "Estos son los episodios de " << series[serie-1].getNombre() <<": "<< endl;
                    vector <Episodio *> temp = series[serie-1].getEpisodios();
                    for(int i = 0; i < temp.size(); i++)
                    {
                        //Imprime nombres de los episodios y su calificacion de la serie seleccionada
                        cout << i+1 << ". " << temp[i]->getNombre() << ", Calificacion: "<< temp[i]->getCalificacion() << endl;
                    }
                    int episodio;
                    cout << "Elige el episodio  a calificar: ";
                    cin >> episodio;

                    //forzarInt y limites
                    
                    //Muestra calificacion original del episodio antes de modificar
                    cout << "La calificacion actual del episodio es de: " << temp[episodio-1]->getCalificacion() << endl;
                    string calificacion;

                    //forzarInt convierte string a double solo para verificar rango deseado

                    cout << "Introduce la nueva calificacion: ";
                    cin >> calificacion;
                    series[serie -1].getEpisodios()[episodio-1]->setCalificacion(calificacion);
                    
                    //Cambia el archivo episodio y requiere el vector episodio modificado para poder a escribir el archivo csv
                    modificarArchivoEpisodios(episodios);

                    cout << "La nueva calificacion es: " << temp[episodio-1]->getCalificacion() << endl;

                    cout << "Los cambios se han realizado"<<endl;
                    
                    // cout << "La calificacion actualizada debería ser: " << calificacion << endl;
                    
                    // cout << "Vector Series"<<endl;
                    // cout << "Calificacion: " << series[serie -1].getEpisodios()[episodio-1]->getCalificacion() << endl;
                    // cout << "Vector Episodios"<<endl; 
                    // for(int i = 0; i < episodios.size(); i++)
                    // {
                    //     if(episodios[i]->getID() == series[serie -1].getEpisodios()[episodio-1]->getID())
                    //     {
                    //         cout << "Calificacion: " << episodios[i]->getCalificacion() << endl;
                    //     }
                    // }
                    
                    // cout << "Vector Videos"<<endl; 
                    // for(int i = 0; i < videos.size(); i++)
                    // {
                    //     if(videos[i]->getID() == series[serie -1].getEpisodios()[episodio-1]->getID())
                    //     {
                    //         cout << "Calificacion: " << videos[i]->getCalificacion() << endl;
                    //     }
                    // }

                } else if(opcionCalif == 2)
                {
                    int pelicula;
                    cout << "Estas son las peliculas disponibles: " << endl;
                    for(int i = 0; i < peliculas.size(); i++)
                    {
                        cout << i+1 << ". " << peliculas[i]->getNombre() << ", Calificacion: "<< peliculas[i]->getCalificacion() << endl;
                    }
                    cout << "Elige la pelicula a calificar: ";
                    cin >> pelicula;
                    cout << "La calificacion actual de la pelicula es de: " << peliculas[pelicula-1]->getCalificacion() << endl;
                    string calificacion;
                    cout << "Introduce la nueva calificacion: ";
                    cin >> calificacion;
                    peliculas[pelicula-1]->setCalificacion(calificacion);

                    modificarArchivoPeliculas(peliculas);

                    cout << "La nueva calificacion de la pelicula es de: " << peliculas[pelicula-1]->getCalificacion() << endl;

                    cout << "Los cambios se han realizado"<<endl;

                } 
                // guardar el episodio que indique el usuario mediante el uso de getId - "Enumeracion mejor"
                // Usar lo de loslimites para manejar el rango de la calificacion
                // usar un loop para buscar el ID en el vector videos y cyando lo encuentre, usar un setCalificacion
                // Actualizar la calificacion en el archivo .csv (REVISAR)
            }
            else
            {
                cout << "No han cargado los archivos" << endl;
            }
<<<<<<< HEAD
        } 

        else if(opcion==6){
            ciclarMenu = 0;

        } 
        
        else{
=======
        }
        else if (opcion == 6)
        {
            ciclarMenu = 0;
        }
        else
        {
>>>>>>> Menu-4-5
            cout << "Valor ingresado invalida" << endl;
            cout << "Trata de nuevo" << endl;
        }

        cout << endl;

    } // Cierre del ciclo del menu principal

    return 0;
}