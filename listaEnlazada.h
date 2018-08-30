#ifndef listaEnlazada_h
#define listaEnlazada_h
#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstddef>

using namespace std;

namespace listaenlazada
{
    template <class T>
    struct Nodo
    {
        T elemento;
        int Posicion;
        Nodo<T> *siguiente;
    };
    
    template<class T>
    class VectorDisperso
    {
    public:
        
        VectorDisperso();
        ~VectorDisperso();
        
        void ingresarVector();
        void igualdadVector();
        void productoEscalar();
        void escribir();
        bool listaVacia() const;
        void deleteEscalar();
        
    private:
        Nodo<T>* cabeza;
    };
}
#endif