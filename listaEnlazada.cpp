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
#include "listaEnlazada.h"

using namespace std;

namespace listaenlazada
{
    template<class T>
    VectorDisperso <T>::VectorDisperso() : cabeza(NULL)
    {
        
    }
    
    template<class T>
    VectorDisperso <T>::~VectorDisperso()
    {
        
    }
    
    template<class T>
    bool VectorDisperso<T>::listaVacia() const
    {
        typedef Nodo<T>* NodoPtr;
        NodoPtr temp_Ptr;
        for(temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
            if (temp_Ptr->elemento != 0) break;
        
        if(temp_Ptr == NULL)
        {
            cout << "Lista vacia" << endl;
            return true;
        }
        else
        {
            cout << "Lista con valores" << endl;
            return false;
        }
    }
    
    template<class T>
    void VectorDisperso<T>::deleteEscalar()
    {
        typedef Nodo<T>* NodoPtr;
        NodoPtr temp_Ptr, temp_Ptr_2;
        
        for (temp_Ptr = cabeza; temp_Ptr != NULL; )
        {
            temp_Ptr_2 = temp_Ptr;
            temp_Ptr = temp_Ptr->siguiente;
            delete temp_Ptr_2;
        }
        
        cabeza = NULL;
    }
    
    template<class T>
    void VectorDisperso <T>::productoEscalar()
    {
        int Count;
        typedef Nodo<T>* NodoPtr;
        T X;
        T elem;
        
        cout << endl;
        cout << "Favor introducir la dimension del Vector : " << endl;
        cin >> Count;
        
        cout << "Favor introducir los datos: " << endl;
        
        for(int i = 1; i <= Count; i++)
        {
            cin >> elem;
            
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = elem;
                temp_Ptr->Posicion = i;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = elem;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
                
            }
            
        }
        
        cout << "Favor introducir el numero a Multiplicar: ";
        cin >> X;
        
        for(int i = 1; i <= Count; i++)
        {
            
            NodoPtr temp_Ptr;
            for(temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
            {
                if(i == temp_Ptr->Posicion )
                {
                    temp_Ptr->elemento = temp_Ptr->elemento * X;
                }
            }
        }
        
        NodoPtr temp_Ptr;
        
        cout << endl;
        cout << "Su nuevo Vector es : " << endl;
        
        for(temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            cout << temp_Ptr->elemento << endl;
        }
        
        cout << endl;
        
    }
    
    template<class T>
    void VectorDisperso <T>::ingresarVector()
    {
        int Count, Count2;
        typedef Nodo<T>* NodoPtr;
        
        T X;
        T elem;
        
        cout << endl;
        cout << "Favor introducir la dimension del primer Vector" << endl;
        cin >> Count;
        
        cout << "Favor introducir los datos" << endl;
        
        for(int i = 1; i <= Count; i++)
        {
            cin >> elem;
            
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = elem;
                temp_Ptr->Posicion = i;
                
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = elem;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
                
            }
        }
        
        cout << endl;
        cout << "Favor introducir la dimension del segundo Vector" << endl;
        cin >> Count2;
        
        cout << endl;
        cout << "Favor introducir los datos" << endl;
        
        for(int i = 1; i <= Count2; i++)
        {
            cin >> X;
            NodoPtr temp_Ptr;
            
            if(Count == Count2)
            {
                for(temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
                {
                    if(i == temp_Ptr->Posicion )
                    {
                        temp_Ptr->elemento = temp_Ptr->elemento + X;
                    }
                }
            }
            else
                break;
        }
        
        if(Count != Count2)
        {
            cout << endl;
            cout << "Error. Los Vectores tienen que tener la misma dimension." << endl;
            deleteEscalar();
        }
        else
        {
            NodoPtr temp_Ptr;
            
            cout << endl;
            cout << "Los valores del vector 3 son: " << endl;
            
            for(temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
            {
                cout << temp_Ptr->elemento << endl;
            }
            
            cout << endl;
        }
    }
    
    template<class T>
    void VectorDisperso <T>::igualdadVector()
    {
        int Count, Count2;
        typedef Nodo<T>* NodoPtr;
        T X;
        T elem;
        int check=0;
        cabeza = NULL;
        
        cout << endl;
        cout << "Favor introducir la dimension del primer vector disperso" << endl;
        cin >> Count;
        
        cout << "Favor introducir los datos" << endl;
        for(int i = 1; i <= Count; i++)
        {
            cin >> elem;
            
            if(cabeza == NULL){
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = elem;
                temp_Ptr->Posicion = i;
                
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = elem;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
            }
        }
        
        cout << endl;
        cout << "Favor introducir la dimension del segundo vector disperso" << endl;
        cin >> Count2;
        
        cout << endl;
        cout << "Favor introducir los datos" << endl;
        
        for(int i = 1; i <= Count2; i++)
        {
            cin >> X;
            NodoPtr temp_Ptr;
            for(temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
            {
                if(i == temp_Ptr->Posicion)
                {
                    if(temp_Ptr->elemento == X)
                        check++;
                }
            }
        }
        
        if(Count != Count2)
        {
            cout << endl;
            cout << "Error. Los Vectores tienen que tener la misma dimension." << endl;
            deleteEscalar();
        }
        else
        {
            if(check==Count)
            {
                cout << endl;
                cout << "Los Vectores son iguales." << endl;
            }
            else
            {
                cout << endl;
                cout << "Los Vectores no son iguales." << endl;
            }
        }
    }
    
}