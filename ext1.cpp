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
    srand(time(NULL));
    string s; 
    cout << "Pulse cualquier tecla para generar habitaciones ";
    cout << "y peticiones aleatorias:" << endl;
    cin >> s;
    while(s != "acaba"){

        int habsl = rand() % 7 + 2;
        struct habitacion habs[habsl];
        int petsl = rand() % 14 + 7;
        struct peticion pets[petsl];

        for(int i = 0; i < habsl; ++i){
            habs[i].id = i;
            habs[i].per = 1 + rand() % 4;
        }

        for(int i = 0; i < petsl; ++i){
            pets[i].id = i;
            pets[i].per = 1 + rand() % 4;
            pets[i].fechaIni = 1 + rand() % 30;
            pets[i].fechaFin = pets[i].fechaIni + rand() % (30 + 1 - pets[i].fechaIni);
        }

        cout << "Codigo en PDDL: " << endl;

        cout << "(define (problem asignar-reservas-ext1)" << endl;
        cout << "  (:domain reservas-ext1)" << endl;

        cout << "  (:objects" << endl;
        cout << "    ";
        for (int i = 0; i < 30; ++i) {
            cout << "D" << i << " ";
        }
        cout << "- dia" << endl;

        cout << "    ";
        for (int i = 0; i < habsl; ++i) {
            cout << "H" << i << " ";
        }
        cout << "- habitacion" << endl;

        cout << "    ";
        for (int i = 0; i < petsl; ++i) {
            cout << "R" << i << " ";
        }
        cout << "- reserva" << endl;
        cout << "  )" << endl;

        cout << "  (:init" << endl;
        for(int i = 0; i < 30; ++i){
            cout << "    (= (que-dia D" << i << ") " << i << ")" << endl;
        }
        cout << endl;
        for(int i = 0; i < habsl; ++i) {
            cout << "    (= ( num-persones-hab H" << habs[i].id << ") " << habs[i].per << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (= ( num-persones-res R" << pets[i].id << ") " << pets[i].per << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (= ( dia-inicial R" << pets[i].id << ") " << pets[i].fechaIni << ")" << endl;
            cout << "    (= ( dia-final R" << pets[i].id << ") " << pets[i].fechaFin << ")" << endl;
        }
        cout << endl;
        cout << "    (= (num-reservas-asig) 0)" << endl;
        cout << "  )" << endl;

        cout << "Pulse cualquier tecla para generar otra vez, escribe ";
        cout << "'acaba' si quiere finalizar." << endl;
        cin >> s;
    }
    
}