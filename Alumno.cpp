#include "Alumno.h"

using namespace std;


string Alumno::getName(){
    return name;
}

string Alumno::getSurname(){
    return surname;
}

int Alumno::getID(){
    return id;
}

float Alumno::getN1(){
    if(nmarks >=1){
        return n1;
    }
    else{
        return -1;
    }
}

float Alumno::getN2(){
    if(nmarks >=2){
        return n2;
    }
    else{
        return -1;
    }
}

float Alumno::getN3(){
    if(nmarks == 3){
        return n3;
    }
    else{
        return -1;
    }
}

float Alumno::getMedia(){
    return media;
}

int Alumno::getNmarks(){
    return nmarks;
}

void Alumno::setMarks(float a){
    n1=a;
    nmarks = 1;
}

void Alumno::setMarks(float a, float b){
    n1 = a;
    n2 = b;
    nmarks = 2;
}

void Alumno::setMarks(float a, float b, float c){
    n1 = a;
    n2 = b;
    n3 = c;
    nmarks = 3;
}

void Alumno::Media(){
    if(nmarks > 0){
        if(nmarks == 1){
            media = n1;
        }
        else if(nmarks == 2){
            media = (n1+n2)/2;
        }
        else{
            media = (n1+n2+n3)/3;
        }

    }
}

void Alumno::toString(){
    if(nmarks > 0){
        if(nmarks == 1){
            cout<<name<<" "<<surname<<" DNI: "<<id<<endl;
            cout<<"Notas: "<<n1<<endl;
            cout<<"Nota media: "<<media<<endl;
        }
        else if(nmarks == 2){
            cout<<name<<" "<<surname<<" DNI: "<<id<<endl;
            cout<<"Notas: "<<n1<<"    "<<n2<<endl;
            cout<<"Nota media: "<<media<<endl;
        }
        else{
            cout<<name<<" "<<surname<<" DNI: "<<id<<endl;
            cout<<"Notas: "<<n1<<"    "<<n2<<"    "<<n3<<endl;
            cout<<"Nota media: "<<media<<endl;
        }

    }
}

