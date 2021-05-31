#include <iostream>

using namespace std;

class Persona{

    private:
        int edad;
        int numFavorito;

    public:
        Persona(): edad{0}, numFavorito{0} {}
    
    friend void friendFunction(Persona &alguien);
};

class Archivo{

    private:
        int address;
    public:
        int getAdress(){return address;}

};

void friendFunction(Persona &alguien){
    alguien.edad = 99;
    cout << alguien.edad << endl;

}


int main(){

    Persona bob;
    friendFunction(bob);

    cout << "It works!!!" << endl;


    return 0;
}