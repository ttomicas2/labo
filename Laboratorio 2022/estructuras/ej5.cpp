#include <iostream>
#include <vector>
using namespace std;
struct Alumno{
    string nombre;
    string apellido;
    int edad = -1;
    vector<float>notas;
};

float avg(vector<float>notas){
    float promedio = 0;
    int prom= 0;
    for(int i = 0; i < notas.size(); i++){
        promedio += notas[i];
        prom++;
    }
    promedio= promedio/prom;
    return promedio;
}

vector<Alumno>llenar(vector<Alumno>Alumnos){
    Alumno A1;
    float nota;
    for(int i = 0; i < 3; i++){
        nota = 1;
        A1.edad=-1;
        cout<<"Ingrese nombre"<<endl;
        cin>>A1.nombre;
        cout<<"Ingrese apellido"<<endl;
        cin>>A1.apellido;
        while(A1.edad < 0 || A1.edad > 100){
            cout<<"Ingrese edad"<<endl;
            cin>>A1.edad;
            if(A1.edad < 0 || A1.edad > 100){
                cout<<"Ingrese una edad validarda"<<endl;
            }
        }
        while(nota>0){
            cout<<"ingrese nota o 0 para terminar"<<endl;
            cin>>nota;
            if(nota>0){
                A1.notas.push_back(nota);
            }
        }
        Alumnos.push_back(A1);
    }
    return Alumnos;
}

void mostrar(vector<Alumno>Alumnos){
    float promedio;
    float promedio_alto = 0;
    string nombre_alto;
    string apellido_alto;
    for(int i = 0; i < Alumnos.size(); i++){
        promedio = avg(Alumnos[i].notas);
        if(promedio > promedio_alto){
            if(promedio == promedio_alto || i == 0){
                int ASCII_alto = apellido_alto[0];
                int ASCII = Alumnos[i].apellido[0];
                if(ASCII < ASCII_alto || i == 0){
                apellido_alto = Alumnos[i].apellido;
                nombre_alto = Alumnos[i].nombre;
                }
            }
            promedio_alto = promedio;
        }
    }
    cout<<"Promedio mas alto:"<<promedio_alto<<endl<<"Nombre:"<<nombre_alto<<endl<<"Apellido:"<<apellido_alto<<endl;

}

int main(){
    vector<Alumno>Alumnos;
    Alumnos=llenar(Alumnos);
    mostrar(Alumnos);
}