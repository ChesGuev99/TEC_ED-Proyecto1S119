#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include<fstream>
#include<sstream>
#include<string>
#include<string.h>
#include <stdlib.h>

using namespace std;

class nodo {
public:
    nodo(string v)
    {
        valor = v;
        siguiente = NULL;
        anterior =NULL;
    }

    nodo(string v, nodo * signodo)
    {
        valor = v;
        siguiente = signodo;
    }

private:
    string valor;
    nodo *siguiente;
    nodo *anterior;


    friend class listaDC;
};

typedef nodo *pnodo;

class listaDC {
public:
    listaDC() { primero = actual = NULL; }
    ~listaDC();

    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(string v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void archivos(int opc);
    void Imprime(string N);

private:
    pnodo primero;
    pnodo actual;
};

listaDC::~listaDC()
{
    pnodo aux;

    while(primero) {
        aux = primero;
        primero = primero->siguiente;
        primero->anterior=aux->anterior;
        aux->anterior->siguiente=primero;
        delete aux;
    }
    actual = NULL;
}

int listaDC::largoLista()
{
    int cont=0;

    pnodo aux = primero;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {
        while(aux!=primero)
        {
            aux=aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaDC::InsertarInicio(string v)
{

    if (ListaVacia())
    {
        primero = new nodo(v);
        primero->anterior=primero;
        primero->siguiente=primero;
    }
    else
    {
        pnodo nuevo=new nodo (v);
        nuevo->siguiente=primero;
        nuevo->anterior= primero->anterior;
        primero->anterior->siguiente=nuevo;
        nuevo->siguiente->anterior=nuevo;
        primero= nuevo;
    }
}

void listaDC::InsertarFinal(string v)
{
    if (ListaVacia())
    {
        primero = new nodo(v);
        primero->anterior=primero;
        primero->siguiente=primero;
    }
    else
    {
        pnodo nuevo = new nodo(v);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente=primero->anterior->siguiente;
        primero->anterior->siguiente=nuevo;
        primero->anterior=nuevo;
    }
}


void listaDC::InsertarPos(string v,int pos)
{
    if (ListaVacia())
    {
        primero = new nodo(v);
        primero->anterior=primero;
        primero->siguiente=primero;
    }
    else
    {
        if(pos <=1)
            InsertarInicio(v);
        else
        {
            if (pos==largoLista())
                InsertarFinal(v);
            else
            {
                pnodo aux= primero;
                int i =2;
                while((i != pos )&&(aux->siguiente!= primero))
                {
                    i++;
                    aux=aux->siguiente;
                }
                pnodo nuevo= new nodo(v);
                nuevo->siguiente=aux->siguiente;
                aux->siguiente=nuevo;
                aux->siguiente->anterior=aux;
                nuevo->siguiente->anterior=nuevo;
            }
        }
    }
}

void listaDC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp= primero;
            primero= NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodo temp = aux->siguiente;
            aux->siguiente= primero;
            primero->anterior=aux;
            delete temp;
        }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp= primero;
            primero= NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero->anterior;
            pnodo temp= primero;
            aux->siguiente=primero->siguiente;
            primero=primero->siguiente;
            primero->anterior=aux;
            delete temp;
        }
    }
}

void listaDC:: borrarPosicion(int pos)
{

    if(ListaVacia())
        cout << "Lista vacia" <<endl;
    else
    {
        if((pos>largoLista())||(pos<0))
            cout << "Error en posicion" << endl;
        else
        {
            if(pos==1)
                BorrarInicio();
            else
            {
                int cont=2;
                pnodo aux=  primero;
                while(cont<pos)
                {
                    aux=aux->siguiente;
                    cont++;
                }
                pnodo temp = aux->siguiente;
                aux->siguiente=aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDC::Mostrar()
{
    pnodo aux=primero;
    while(aux->siguiente!=primero)
    {

        cout << aux->valor << "-> ";
        aux = aux->siguiente;
    }
    cout<<aux->valor<<"->";
    cout<<endl;
}

void listaDC:: archivos(int opc) {
    ifstream archivo;
    string linea;
    if (opc == 1) archivo.open("Paises.txt");
    if (opc == 2) archivo.open("Ciudades.txt");
    if (opc == 3) archivo.open("Conexiones.txt");

    while (getline(archivo, linea)) {
        InsertarFinal(linea);

        /*string palabra;
        int i = 0;
        while (i < linea.size()) {
            if (linea[i] != 59) {
                palabra += linea[i];
            } else {
                palabra = "";
            }
            i++;
        */}
    archivo.close();
}
/*
void Imprime(string N)
{
    int start = 0 ;
    index = N.substr(";", start);
    if (index < 0) index = N.size();
    string token = N.substr(start, index - start + 1);
    start = index;

}
*/

int main() {
    listaDC Lista;
    listaDC Paises;
    listaDC Ciudades;
    listaDC Conexiones;

    Paises.archivos(1);
    Ciudades.archivos(2);
    Conexiones.archivos(3);
    Paises.Mostrar();
    Ciudades.Mostrar();
    Conexiones.Mostrar();

    Lista.InsertarInicio("a");
    Lista.InsertarInicio("b");
    Lista.InsertarFinal("c");
    Lista.InsertarFinal("d");
    Lista.Mostrar();
    Lista.InsertarPos("j", 3);
    Lista.Mostrar();
    Lista.InsertarPos("l", 14);
    Lista.Mostrar();
    Lista.BorrarFinal();
    Lista.Mostrar();
    Lista.BorrarInicio();
    Lista.Mostrar();
    /*Lista.borrarPosicion(2);
    Lista.Mostrar();*/

    cin.get();

    return 0;

}