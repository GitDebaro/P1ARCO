#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <vector>
#include "Persona.h"
#include "Alumno.h"

class Profesor: public Persona{
public:

vector<Alumno> lista;

using Persona::Persona;

void addStudent(string n, string s, int i);

void setMark(int i, float a);

void setMark(int i, float a, float b);

void setMark(int i, float a, float b, float c);

void setMedia(int i);

void toString();

void printBestStu();

void separador();

int getID();

};


#endif // PROFESOR_H
