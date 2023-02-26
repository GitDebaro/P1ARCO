#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include "Persona.h"
#include <string>

using namespace std;

class Alumno : public Persona{
public:

    using Persona::Persona;

    string getName();

    string getSurname();

    int getID();

    float getN1();

    float getN2();

    float getN3();

    float getMedia();

    int getNmarks();

    void setMarks(float a);

    void setMarks(float a, float b);

    void setMarks(float a, float b, float c);

    void Media();

    void toString();
private:
    float n1;
    float n2;
    float n3;
    float media;
    int nmarks=0;
};

#endif // ALUMNO_H
