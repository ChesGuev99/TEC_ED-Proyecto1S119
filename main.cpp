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

        abajo = NULL;

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

    string getByPos(int pos);

    string getStr(string linea,int opc,string busq);

    int Valid(string cod,int opc);






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

    int cont=1;

    pnodo aux = primero;

    if(ListaVacia())

    {

        return 0;

    }

    else

    {

        while(aux->siguiente!=primero)

        {
            aux=aux->siguiente;

            cont++;

        }

        return cont;

    }



}


string listaDC::getByPos(int pos)
{
    if(ListaVacia())
        cout << "Lista vacia" <<endl;
    else
    {
        if (pos == 1) return primero->valor;
        if((pos>largoLista())||(pos<0))
            cout << "Error en posicion" << endl;
        else
        {
            int cont=1;
            pnodo aux=  primero;
            while(cont<pos)
            {
                aux=aux->siguiente;
                cont++;
            }
            return aux->valor;
        }
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
                
                abajo = NULL;
                
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
            
            nodo *abajo;
            
            
            
            
            
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
            
            void archivos();
            
            void Imprime(string N);
            
            string getByPos(int pos);
            
            string getStr(string linea,int opc,string busq);
            
            int Valid(string cod,int opc);
            
            void MostrarAbajo();
            
            
            
            
            
            
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
            
            int cont=1;
            
            pnodo aux = primero;
            
            if(ListaVacia())
                
            {
                
                return 0;
                
            }
            
            else
                
            {
                
                while(aux->siguiente!=primero)
                    
                {
                    aux=aux->siguiente;
                    
                    cont++;
                    
                }
                
                return cont;
                
            }
            
            
            
        }
        
        
        string listaDC::getByPos(int pos)
        {
            if(ListaVacia())
                cout << "Lista vacia" <<endl;
            else
            {
                if (pos == 1) return primero->valor;
                if((pos>largoLista())||(pos<0))
                    cout << "Error en posicion" << endl;
                else
                {
                    int cont=1;
                    pnodo aux=  primero;
                    while(cont<pos)
                    {
                        aux=aux->siguiente;
                        cont++;
                    }
                    return aux->valor;
                }
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
        
        void listaDC::MostrarAbajo()
        {
            pnodo aux= primero;
            
            while(aux->siguiente!=primero)
            {
                cout << aux->valor << "-> ";
                pnodo abaux = aux->abajo;
                cout<<"abajo"<<endl;
                while (abaux != NULL){
                    cout<<abaux->valor<<"->";
                    abaux = abaux->abajo;
                }
                aux = aux->siguiente;
                
            }
            
            cout<<endl;
            
            
            
        }
        string listaDC::getStr(string linea,int opc,string busq)
        {
            string Str[6];
            //int largo= (sizeof(Str)/sizeof(Str[0]));
            //for (int j=0, j<largo,j++){*/
            string palabra;
            int i = 0;
            int j = 0;
            while (i < linea.size()) {
                if (linea[i] != 59) {
                    palabra += linea[i];
                }
                else {
                    Str[j]=palabra;
                    j++;
                    palabra = "";
                }
                i++;
            }
            Str[j]= palabra;
            
            
            if (busq == "CodPais")return Str[0];
            if (busq == "NombrePais")return Str[1];
            if (busq == "CodCiudad")return Str[1];
            if (busq == "NombreCiudad")return Str[2];
            if (busq == "CodConexion")return Str[2];
            if (busq == "InicioConexion")return (Str[0]+";"+Str[1]);
            if (busq == "DestinoConexion")return (Str[3]+";"+Str[4]);
            if (busq == "HorasConexion")return Str[5];
            
            return 0;
            
        }
        
        int listaDC::Valid(string cod,int opc)
        {
            string st;
            if (opc==1)st="CodPais";
            if (opc==2)st="CodCiudad";
            if (opc==3)st="CodConexion";
            int i =0;
            cod= getStr(cod,opc,st);
            //string lista[100];
            
            while (i <(this->largoLista())){
                string linea = getByPos(i+1);
                string comp = getStr(linea,opc,st);
                if (cod == comp){
                    return 1;
                }
                i++;
            }
            return 0;
        }
        
        
        void listaDC:: archivos() {
            
            ifstream archivo;
            
            string linea;
            int opc=1;
            
            if (opc == 1) {
                archivo.open("Paises.txt");
                while (getline(archivo, linea)) {
                    if (ListaVacia()) InsertarFinal(linea);
                    else{
                        int val = Valid(linea,opc);
                        if(val==0){
                            InsertarFinal(linea);
                        }}}}
            opc++;
            if (opc == 2) {
                archivo.open("Ciudades.txt");
                while (getline(archivo, linea)) {
                    if (ListaVacia()) {
                        string pais = getStr(linea, opc, "CodPais");
                        pnodo aux = primero;
                        pnodo pabajo = aux->abajo;
                        string codCiud = getStr(linea, opc, "CodCiudad");
                        string nombre = getStr(linea, opc, "NombreCiudad");
                        for (int i = 0; i < largoLista(); i++) {
                            if (pais == getStr(linea, opc, (aux->valor))) {
                                if (pabajo == NULL) pabajo = InsertarFinal((codCiud + ";" + nombre));
                                else {
                                    while (pabajo != NULL) {
                                        pabajo = pabajo->abajo;
                                    }
                                    InsertarFinal((codCiud + ";" + nombre));
                                }
                            } else aux = aux->siguiente;
                        }
                        
                        
                        InsertarFinal(linea);
                    }
                    else{
                        int val = Valid(linea,opc);
                        if(val==0){
                            InsertarFinal(linea);
                        }}}
                
            }
            opc++;
            if (opc == 3) archivo.open("Conexiones.txt");
            
            archivo.close();
            
        }
        //InsertarFinal(linea);
        //Mostrar();
        
        
        
        
        int main() {
            
            listaDC PCC;
            listaDC TiposTrenes;
            listaDC Trenes;
            listaDC Rutas;
            
            
            
            
            PCC.archivos();
            
            PCC.Mostrar();
            
            
            /*Lista.borrarPosicion(2);
             
             Lista.Mostrar();*/
            
            
            
            cin.get();
            
            
            
            return 0;
            
            
            
        }
