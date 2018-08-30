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
#include "listaEnlazada.cpp"


using namespace std;
using namespace listaenlazada;

void menu(int Choice)
{
    
    VectorDisperso<int> num_entero;
    VectorDisperso<double> num_double;
    
    int Opcion;
    
    do
    {
        cout << "1) SUMA" << endl;
        cout << "2) PRODUCTO ESCALAR" << endl;
        cout << "3) IGUALDADES" << endl;
        cout << "0) VOLVER A SELECCIONAR ENTEROS O REALES" << endl;
        cout << "Opcion: ";
        
        cin >> Opcion;
        cout << endl;
        
        switch(Opcion)
        {
            case 1:
                if(Choice == 1)
                {
                    num_entero.deleteEscalar();
                    num_entero.ingresarVector();
                    break;
                }
                else
                {
                    num_double.deleteEscalar();
                    num_double.ingresarVector();
                    break;
                }
            case 2:
                if(Choice == 1)
                {
                    num_entero.deleteEscalar();
                    num_entero.productoEscalar();
                    break;
                }
                else
                {
                    num_double.deleteEscalar();
                    num_double.productoEscalar();
                    break;
                }
            case 3:
                if(Choice == 1)
                {
                    num_entero.igualdadVector();
                    break;
                }
                else
                {
                    num_double.igualdadVector();
                    break;
                }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        
        cout << endl;
        
    }while(Opcion != 0);
    
}

void Menu_Numero()
{
    int Choice;
    do{
        cout << "ESCOGER NUMERO ENTERO O REAL" << endl;
        cout << "1) ENTERO" << endl;
        cout << "2) REAL" << endl;
        cout << "0) TERMINAR EL PROGRAMA" << endl;
        cout << "Opcion: ";
        cin >> Choice;
        
        switch(Choice)
        {
            case 1:
                cout << endl;
                menu(Choice);
                break;
            case 2:
                cout << endl;
                menu(Choice);
                break;
            case 0:
                cout << "FIN DEL PROGRAMA" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        
    }while(Choice != 0);
}

int main()
{
    Menu_Numero();
    
    return 0;
}

