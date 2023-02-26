#include <iostream>
#include <vector>
#include "Alumno.h"
#include "Profesor.h"

using namespace std;

void Calificando();
void dataInit(vector<Profesor> &l);
void separador();

int main()
{
    Calificando();
    return 0;
}

void Calificando(){
   bool salir = false;
   int n = -1;
   vector<Profesor> datos;
   dataInit(datos);
   while(!salir){
       cout<<endl<<"Por favor, introduzca un DNI (numero de 7 cifras) sin letra."<<endl;
       cout<<"Si desea salir de la aplicacion introduzca un 0."<<endl;
       cin>>n;
       if(n == 0){
           salir = true;
           cout<<"Hasta pronto!"<<endl;
       }
       else{
           bool found = false;
           for(int i=0; i<int(datos.size()); i++){
               if(n == datos[i].getID()){
                   datos[i].toString();
                   datos[i].printBestStu();
                   found = true;
               }
           }
           if(!found){
                for(int i=0; i<int(datos.size()) && !found; i++){
                    for(int j=0; j<int(datos[i].lista.size()); j++){
                        if(n == datos[i].lista[j].getID()){
                            cout<<endl;
                            separador();
                            datos[i].lista[j].toString();
                            separador();
                            found = true;
                        }
                    }
                }
           }
           if(!found){
               cout<<"El DNI introducido no pertenece a ningun alumno o profesor."<<endl;
           }
       }
   }
}

void dataInit(vector<Profesor> &l){
    Profesor p1("David", "Martinez Martinez", 1234567);
    p1.addStudent("David", "Fernandez Fernandez", 2345678);
    p1.setMark(2345678, 7.5, 7, 8.9);
    p1.setMedia(2345678);
    p1.addStudent("Daniel", "Rivas Rodriguez", 2345679);
    p1.setMark(2345679, 4, 6);
    p1.setMedia(2345679);
    p1.addStudent("Francisco", "Rivera Gomez", 2345680);
    p1.setMark(2345680, 10);
    p1.setMedia(2345680);
    p1.addStudent("Angela", "de la Riva Rodriguez", 2345682);
    p1.setMark(2345682, 9, 10);
    p1.setMedia(2345682);
    p1.addStudent("Esther", "Diaz Fernandez", 2345690);
    p1.setMark(2345690, 2, 6, 4);
    p1.setMedia(2345690);
    Profesor p2("Ramon", "Fernandez Diaz", 1234568);
    p2.addStudent("Laura", "Gomez Garcia", 2345578);
    p2.setMark(2345578, 8.5);
    p2.setMedia(2345578);
    p2.addStudent("Ignacio", "Fernandez Robles", 2345579);
    p2.setMark(2345579, 8, 9.5);
    p2.setMedia(2345579);
    p2.addStudent("Maria", "Perez Martinez", 2345580);
    p2.setMark(2345580, 10, 10, 2);
    p2.setMedia(2345580);
    p2.addStudent("Victor", "Cisneros Conde", 2345582);
    p2.setMark(2345582, 5, 4);
    p2.setMedia(2345582);
    p2.addStudent("Kevin", "Sanchez Diaz", 2345590);
    p2.setMark(2345590, 6, 4);
    p2.setMedia(2345590);
    Profesor p3("Lidia", "Nuñez Sanchez", 1934567);
    p3.addStudent("Diego", "Martinez Carrera", 2945678);
    p3.setMark(2945678, 2, 2.2, 2);
    p3.setMedia(2945678);
    p3.addStudent("Olga", "Garcia Garcia", 2945679);
    p3.setMark(2945679, 10, 5);
    p3.setMedia(2945679);
    p3.addStudent("Vanessa", "De la Torre Lopez", 2945680);
    p3.setMark(2945680, 10);
    p3.setMedia(2945680);
    p3.addStudent("Rogelio", "Alonso Morales", 2945682);
    p3.setMark(2945682, 9, 10);
    p3.setMedia(2945682);
    p3.addStudent("Sergio", "Garcia Alonso", 2945690);
    p3.setMark(2945690, 2, 6, 1);
    p3.setMedia(2945690);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);

    p1.toString();
    p1.printBestStu();
    p2.toString();
    p2.printBestStu();
    p3.toString();
    p3.printBestStu();
}

void separador(){
    cout<<"----------------------------------------------"<<endl;
}
