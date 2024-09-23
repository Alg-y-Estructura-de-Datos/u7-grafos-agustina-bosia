#include <iostream>
#include "Grafos/Grafo.h"
using namespace std;
/*
En una red social, los usuarios son representados como nodos, y las relaciones de amistad o
conexión entre ellos son aristas. Este grafo es no dirigido, ya que, si dos usuarios son amigos,
la relación es bidireccional. También puedes almacenar atributos adicionales, como el
número de interacciones entre ellos, que podrían ser ponderaciones en las aristas.
Descripción del problema:
● Cada usuario de la red social es un nodo en el grafo.
● Las amistades entre usuarios son las aristas.
● Puedes buscar si dos usuarios son amigos.
● Puedes agregar nuevas amistades.
● Eliminar amistades o usuarios de la red.
Operaciones:
1. Insertar Usuario: Añadir un nodo al grafo representando a un nuevo usuario.
2. Agregar Amistad: Añadir una arista entre dos nodos (usuarios) para representar una
amistad.
3. Eliminar Amistad: Quitar la conexión entre dos usuarios.
4. Buscar Usuario: Ver si un usuario está en la red social.
5. Imprimir la Red Social: Mostrar todos los usuarios y sus amigos (las conexiones en el
grafo).

*/

int main() {
    Grafo<string> grafo;

    cout << "Ejercicio N° 1" << endl;

    bool c=true;
    int op;
    string valor,valor1;

     while (c)
    {
        cout<<"quiere:\n 1. Insertar Usuario. \n 2. Agregar Amistad. \n 3. Eliminar Amistad. \n 4. Buscar Usuario  \n 5. Imprimir la Red Social \n 6.Salir del programa.\n";
        cin>>op;

        switch (op){
        case 1:
            cout<<"ingrese el usuario: \n";
            cin>>valor;
            grafo.agregarNodo(valor);

            break;
        case 2:
            cout<<"cual es el usuario 1? \n";
            cin>>valor;
            cout<<"cual es el usuario 2? \n";
            cin>>valor1;
            try {
                grafo.agregarArista(valor,valor1);
                cout << "Los socios "<<valor<<" y "<<valor1<<" son ahora amigos." <<endl;
            } catch (int e) {
                cout<<"no"<<endl;
            }

            break;
        case 3:
            cout<<"cual es el usuario 1? \n";
            cin>>valor;
            cout<<"cual es el usuario 2? \n";
            cin>>valor1;
            try {
                grafo.eliminarArista(valor,valor1);
                cout << "Los socios "<<valor<<" y "<<valor1<<" ya no son amigos." <<endl;
            } catch (int e) {
                cout<<"no"<<endl;
            }
            break;

        case 4:
            cout<<"cual es el que quiere buscar? \n";
            cin>>valor;

                if (grafo.buscarNodo(valor)){
                    cout << "El usuario "<<valor<<" se ha encontrado " <<endl;
                }
         
                else {
                    cout << "no se encontró" << endl;
                }

            break;

        case 5:
            grafo.imprimir();
            break;
        default:
            cout<<"Saliendo del programa...";
            return 0;
            break;
        }
    }

    return 0;
}
