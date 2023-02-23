#include <iostream>
#include <vector>

using namespace std;

void separador();

class Persona{
    public:
        string name;
        string surname;
        int id;

        void setData(string n, string s, int i){
            name = n;
            surname = s;
            id = i;
        }

};

class Alumno : public Persona{
    public:
        float n1;
        float n2;
        float n3;
        float media;
        int nmarks=0;

        void setMarks(float a){
            n1=a;
            nmarks = 1;
        }

        void setMarks(float a, float b){
            n1 = a;
            n2 = b;
            nmarks = 2;
        }

        void setMarks(float a, float b, float c){
            n1 = a;
            n2 = b;
            n3 = c;
            nmarks = 3;
        }

        void Media(){
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

        void toString(){
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
};

class Profesor : public Persona{
    public:

    vector<Alumno> lista;

    void addStudent(string n, string s, int i){
        Alumno tmp;
        tmp.setData(n,s,i);
        lista.push_back(tmp);
    }

    void setMark(int i, float a){
        for(int j=0; j<lista.size(); j++){
            if(lista[j].id == i){
                lista[j].setMarks(a);
            }
        }
    }

    void setMark(int i, float a, float b){
        for(int j=0; j<lista.size(); j++){
            if(lista[j].id == i){
                lista[j].setMarks(a, b);
            }
        }
    }

    void setMark(int i, float a, float b, float c){
        for(int j=0; j<lista.size(); j++){
            if(lista[j].id == i){
                lista[j].setMarks(a, b, c);
            }
        }

    }

    void setMedia(int i){
        for(int j=0; j<lista.size(); j++){
            if(lista[j].id == i){
                lista[j].Media();
            }
        }
    }

    void toString(){
        cout<<endl<<"PROFESOR: "<<endl<<name<<" "<<surname<<" DNI: "<<id<<endl;
        separador();
        for(int i=0; i<lista.size(); i++){
            lista[i].toString();
            separador();
        }

    }


    void printBestStu(){
        int pos = -1;
        float bm = 0.0;
        for(int i=0; i<lista.size();i++){
            if(lista[i].nmarks == 3){
                if(lista[i].media > bm){
                        pos = i;
                        bm = lista[i].media;
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
            cout<<lista[pos].name<<" "<<lista[pos].surname<<" DNI: "<<lista[pos].id<<endl;
            cout<<"Notas: "<<lista[pos].n1<<"    "<<lista[pos].n2<<"    "<<lista[pos].n3<<endl;
            cout<<"Nota media: "<<lista[pos].media<<endl;
            separador();
        }
    }
};

void Calificando();
void dataInit(vector<Profesor> &l);

int main(){
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
           for(int i=0; i<datos.size(); i++){
               if(n == datos[i].id){
                   datos[i].toString();
                   datos[i].printBestStu();
                   found = true;
               }
           }
           if(!found){
                for(int i=0; i<datos.size() && !found; i++){
                    for(int j=0; j<datos[i].lista.size(); j++){
                        if(n == datos[i].lista[j].id){
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
    Profesor p1;
    p1.setData("David", "Martinez Martinez", 1234567);
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
    Profesor p2;
    p2.setData("Ramon", "Fernandez Diaz", 1234568);
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
    Profesor p3;
    p3.setData("Lidia", "Nuñez Sanchez", 1934567);
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
