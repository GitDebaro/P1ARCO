#include "Profesor.h"

void Profesor::addStudent(string n, string s, int i){
    Alumno tmp(n,s,i);
    lista.push_back(tmp);
}

void Profesor::setMark(int i, float a){
    for(int j=0; j<int(lista.size()); j++){
        if(lista[j].getID() == i){
            lista[j].setMarks(a);
        }
    }
}

void Profesor::setMark(int i, float a, float b){
    for(int j=0; j<int(lista.size()); j++){
        if(lista[j].getID() == i){
            lista[j].setMarks(a, b);
        }
    }
}

void Profesor::setMark(int i, float a, float b, float c){
    for(int j=0; j<int(lista.size()); j++){
        if(lista[j].getID() == i){
            lista[j].setMarks(a, b, c);
        }
    }

}

void Profesor::setMedia(int i){
    for(int j=0; j<int(lista.size()); j++){
        if(lista[j].getID() == i){
            lista[j].Media();
        }
    }
}

void Profesor::toString(){
    cout<<endl<<"PROFESOR: "<<endl<<name<<" "<<surname<<" DNI: "<<id<<endl;
    separador();
    for(int i=0; i<int(lista.size()); i++){
        lista[i].toString();
        separador();
    }

}


void Profesor::printBestStu(){
    int pos = -1;
    float bm = 0.0;
    for(int i=0; i<int(lista.size());i++){
        if(lista[i].getNmarks() == 3){
            if(lista[i].getMedia() > bm){
                    pos = i;
                    bm = lista[i].getMedia();
            }
        }
    }

    if(pos == -1){
        cout<<endl;
        separador();
        cout<<"No hay ningun alumno con 3 notas"<<endl;
        separador();
    }
    else{
        cout<<endl;
        separador();
        cout<<"Mejor alumno: "<<endl;
        cout<<lista[pos].getName()<<" "<<lista[pos].getSurname()<<" DNI: "<<lista[pos].getID()<<endl;
        cout<<"Notas: "<<lista[pos].getN1()<<"    "<<lista[pos].getN2()<<"    "<<lista[pos].getN3()<<endl;
        cout<<"Nota media: "<<lista[pos].getMedia()<<endl;
        separador();
    }
}

void Profesor::separador(){
    cout<<"----------------------------------------------"<<endl;
}

int Profesor::getID(){
    return id;
}
