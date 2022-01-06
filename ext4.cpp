#include<iostream>
#include<ctime>

using namespace std;

struct habitacion {
    int id;
    int per;
};

struct peticion {
    int id;
    int per;
    int fechaIni;
    int fechaFin;
};

int main(){
    srand(time(0));
    string s; 
    cout << "Pulse cualquier tecla para generar habitaciones ";
    cout << "y peticiones aleatorias:" << endl;
    cin >> s;
    while(s != "acaba"){

        int habsl = 8 /*+ rand() % (8 - 3)*/;
        struct habitacion habs[habsl];
        int petsl = 16 /*+ rand() % (15 - 7)*/;
        struct peticion pets[petsl];

        for(int i = 1; i <= habsl; ++i){
            habs[i-1].id = i;
            habs[i-1].per = 1 + rand() % 4;
        }

        for(int i = 1; i <= petsl; ++i){
            pets[i-1].id = i;
            pets[i-1].per = 1 + rand() % 4;
            pets[i-1].fechaIni = 1 + rand() % 30;
            pets[i-1].fechaFin = pets[i-1].fechaIni + rand() % (30 + 1 - pets[i-1].fechaIni);
        }

        cout << "Codigo en PDDL: " << endl;

        cout << "(define (problem asignar-reservas-ext4)" << endl;
        cout << "  (:domain reservas)" << endl;

        cout << "  (:objects" << endl;
        cout << "    ";
        for (int i = 1; i <= 30; ++i) {
            cout << "D" << i << " ";
        }
        cout << "- dia" << endl;

        cout << "    ";
        for (int i = 0; i < habsl; ++i) {
            cout << "H" << habs[i].id << " ";
        }
        cout << "- habitacion" << endl;

        cout << "    ";
        for (int i = 0; i < petsl; ++i) {
            cout << "R" << pets[i].id << " ";
        }
        cout << "- reserva" << endl;
        cout << "  )" << endl;

        cout << "  (:init" << endl;
        for(int i = 1; i <= 30; ++i){
            cout << "    (= (que-dia D" << i << ") " << i << ")" << endl;
        }
        cout << endl;
        for(int i = 0; i < habsl; ++i) {
            cout << "    (= ( num-personas-hab H" << habs[i].id << ") " << habs[i].per << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (= ( num-personas-res R" << pets[i].id << ") " << pets[i].per << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (= ( dia-inicial R" << pets[i].id << ") " << pets[i].fechaIni << ")" << endl;
            cout << "    (= ( dia-final R" << pets[i].id << ") " << pets[i].fechaFin << ")" << endl;
        }
        cout << endl;
        cout << "    (= (reservas-no-asig) 0)" << endl;
        cout << "    (= (plazas-no-asig) 0)" << endl;
        cout << "    (= (habitaciones-abiertas) 0)" << endl;
        cout << "  )" << endl;

        cout << "Pulse cualquier tecla para generar otra vez, escribe ";
        cout << "'acaba' si quiere finalizar." << endl;
        cin >> s;
    }
    
}