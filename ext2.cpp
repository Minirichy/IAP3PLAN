#include<iostream>
#include<ctime>

using namespace std;

const char orientacions[] = {'N', 'S', 'E', 'O'};

struct habitacion {
    int id;
    int per;
    char orien;
};

struct peticion {
    int id;
    int per;
    int fechaIni;
    int fechaFin;
    char orien;
};

int main(){
    srand(time(NULL));
    string s; 
    cout << "Pulse cualquier tecla para generar habitaciones ";
    cout << "y peticiones aleatorias:" << endl;
    cin >> s;
    while(s != "acaba"){

        int habsl = 3 + rand() % (8 - 3);
        struct habitacion habs[habsl];
        int petsl = 7 + rand() % (12 - 7);
        struct peticion pets[petsl];

        for(int i = 1; i <= habsl; ++i){
            habs[i-1].id = i;
            habs[i-1].per = 1 + rand() % 4;
            habs[i-1].orien = orientacions[rand() % 4];
            cout << habs[i-1].orien << endl;
        }

        for(int i = 1; i <= petsl; ++i){
            pets[i-1].id = i;
            pets[i-1].per = 1 + rand() % 4;
            pets[i-1].fechaIni = 1 + rand() % 30;
            pets[i-1].fechaFin = pets[i-1].fechaIni + rand() % (30 + 1 - pets[i-1].fechaIni);
            pets[i-1].orien = orientacions[rand() % 4];
        }

        cout << "Codigo en PDDL: " << endl;

        cout << "(define (problem asignar-reservas-ext2)" << endl;
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

        cout << "    ";
        for (int i = 0; i < 4; ++i) {
            cout << orientacions[i] << " ";
        }
        cout << "- orientacion" << endl;
        cout << "  )" << endl;

        cout << "  (:init" << endl;
        for(int i = 1; i <= 30; ++i){
            cout << "    (= (que-dia D" << i << ") " << i << ")" << endl;
        }
        cout << endl;
        for(int i = 0; i < habsl; ++i) {
            cout << "    (= ( num-personas-hab H" << habs[i].id << ") " << habs[i].per << ")" << endl;
            cout << "    (orientacion-hab H" << habs[i].id << " " << habs[i].orien << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (= ( num-personas-res R" << pets[i].id << ") " << pets[i].per << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (= ( dia-inicial R" << pets[i].id << ") " << pets[i].fechaIni << ")" << endl;
            cout << "    (= ( dia-final R" << pets[i].id << ") " << pets[i].fechaFin << ")" << endl;
        }
        for(int i = 0; i < petsl; ++i) {
            cout << "    (orientacion-res R" << pets[i].id << " " << pets[i].orien << ")" << endl;
        }
        cout << endl;
        cout << "    (= (reservas-no-asig) 0)" << endl;
        cout << "    (= (plazas-no-asig) 0)" << endl;
        cout << "    (= (reservas-orientacion-incorrecta) 0)" << endl;
        cout << "  )" << endl;

        cout << "Pulse cualquier tecla para generar otra vez, escribe ";
        cout << "'acaba' si quiere finalizar." << endl;
        cin >> s;
    }
    
}