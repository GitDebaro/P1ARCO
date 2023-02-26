#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

class Persona{
public:
    Persona(string n, string s, int i);
protected:
    string name;
    string surname;
    int id;
};

#endif // PERSONA_H
