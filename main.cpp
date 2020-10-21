#include <iostream>
#include <iomanip>
using namespace std;


// computadora.h
class computadora 
{
    string sistem_Op;
    string nombre_equipo;
    int ram;
    float almacenamiento;

public:
    computadora ();
    computadora (const string &sistem_Op, const string &nombre_equipo, int ram, float almacenamiento);
    void setSistem_Op (const string &v);
    string getSistem_Op ();
    void setNombre_equipo (const string &v);
    string getNombre_equipo ();
    void setRAM (int v);
    int getRAM ();
    void setAlmacenamiento (float v);
    float getAlmacenamiento ();

// Sobrecarga del operador 
    friend ostream& operator<<(ostream&out, const computadora &p)
    {
        // Imprimir cada atributo con out          
            out << left ; // Para que todo este  alineado          
            out << setw(20) << p.sistem_Op;
            out << setw(20) << p.nombre_equipo;
            out << setw(10) << p.ram;
            out << setw(18) << p.almacenamiento;
            out << endl;
// En out estara toda la informacion
            return out;
    }
// Sobrecargar el operador de entrada
    friend istream& operator>>(istream&in, computadora &p)
    {
            cout << "Sistema Operativo: ";
            getline (cin, p.sistem_Op);

            cout << "Nombre del equipo: ";
            getline (cin, p.nombre_equipo);

            cout << "Ram: ";
            cin >> p.ram;

            cout << "Almacenamiento: ";
            cin >> p.almacenamiento;

            return in;
    }

};





//computadora.cpp
computadora :: computadora ()
{
}

computadora::computadora(const string &sistem_Op, const string &nombre_equipo, int ram, float almacenamiento)
{
    this -> sistem_Op = sistem_Op;
    this -> nombre_equipo = nombre_equipo;
    this -> ram = ram;
    this -> almacenamiento = almacenamiento;
}
//          sistema operativo
void computadora::setSistem_Op(const string &v)
    {
        sistem_Op = v;
    }
    string computadora :: getSistem_Op()
{
    return sistem_Op;
}
//          nombre del equipo
void computadora::setNombre_equipo(const string &v)
    {
        nombre_equipo = v;
    }
    string computadora :: getNombre_equipo()
{
    return nombre_equipo;
}
//          Ram
void computadora::setRAM(int v)
    {
        ram = v;
    }
    int computadora :: getRAM()
{
    return ram;
}
//          almacenamiento
void computadora::setAlmacenamiento(float v)
    {
        almacenamiento = v;
    }
    float computadora :: getAlmacenamiento()
{
    return almacenamiento;
}






//  Clase Administradora.h
class Laboratorio
{
    computadora  arreglo [6];
    size_t cont;
    // Es un tipo de dato entero sin signo para iteraciones, contando de 0 a c/elementos.
public:
    Laboratorio();
    void agregarcompu (const computadora &p);
    void mostrar ();

// FRIEND regresa una referencia a LABORATORIO
// v es referencia a nv
    friend Laboratorio& operator<< (Laboratorio&v, const computadora &p)
    {
        v.agregarcompu (p);
        return v;
    }

};

//  Clase Administradora.cpp

Laboratorio::Laboratorio ()
{
    cont = 0;
}
// contador para almacenar 6 elementos
void Laboratorio::agregarcompu (const computadora &p)
{
    if (cont < 6)
    {
        arreglo [cont] = p;
        cont++;
    }
    else 
    {
        cout << "El arreglo esta lleno" << endl;
    }
}

//Imprimira los datos que hayas ingresado, no necesariamente los 5 elementos.
void Laboratorio::mostrar ()
{   
    cout << left ;
    cout << endl;
    cout << setw (20) << "Sistema Operativo- ";
    cout << setw (20) << "Nombre del equipo- ";
    cout << setw (10) << "Ram- ";
    cout << setw (18) << "Almacenamiento- ";
    cout << endl;

    for (size_t i = 0; i < cont; i++)
    {   //p va a ser la referencia de quien esta opupando el lugar en "i".
        computadora &p = arreglo [i];
        cout << p;
    //    cout << "Sistema Operativo: " << arreglo[i].getSistem_Op() << endl;
    //    cout << "Nombre del equipo: " << arreglo[i].getNombre_equipo() << endl;
    //    cout << "Ram: " << arreglo[i].getRAM() << "GB" << endl;
    //    cout << "Almacenamiento: " << arreglo[i].getAlmacenamiento() << "GB" << endl;
    //    cout << endl;
    }
}   




//main.cpp
int main () 
{
	computadora p02 = computadora ("Windows", "servidor", 16, 36.0); //computadora con contructor parametrizado
    computadora p04 = computadora ("Windows", "pc05", 2, 2.51);
    computadora p06 = computadora ("Windows", "Recepcion", 4, 9.36);

    computadora p03; //computadora que llama al contructor sin parametro, usando metodos de acceso.
    p03.setSistem_Op ("Mac");
    p03.setNombre_equipo ("Computadora_5");
    p03.setRAM (8);
    p03.setAlmacenamiento (15.22);

    computadora p05;
    p05.setSistem_Op ("Mac");
    p05.setNombre_equipo ("maquinawow");
    p05.setRAM (2);
    p05.setAlmacenamiento (16.55);

    Laboratorio nv;

//    nv.agregarcompu (p02);
//    nv.agregarcompu (p03);
//    nv.agregarcompu (p04);
//    nv.agregarcompu (p05);
//    nv.agregarcompu (p06);

    nv << p02 << p03 << p04 << p05 << p06;

//    cout << p02;
    computadora p07;
    cin >> p07;
    nv << p07;


    nv.mostrar ();

    return 0;
}
