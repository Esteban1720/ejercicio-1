#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_ATLETAS = 100;
const int MAX_TIEMPOS = 2;

struct Atleta {
    char nombre[50];
    int numero;
    int tiempos[MAX_TIEMPOS];
};

struct Prueba {
    Atleta* atletas[MAX_ATLETAS];
    int num_atletas;
    int tiempos_fifo[MAX_ATLETAS * MAX_TIEMPOS];
    int num_tiempos_fifo;
    Atleta* tiempos_lifo[MAX_ATLETAS];
    int num_tiempos_lifo;
};

void agregar_atleta(Prueba* prueba, Atleta* atleta) {
    if (prueba->num_atletas < MAX_ATLETAS) {
        prueba->atletas[prueba->num_atletas] = atleta;
        prueba->num_atletas++;
    }
}

void registrar_tiempo_fifo(Prueba* prueba, Atleta* atleta, int tiempo) {
    if (prueba->num_tiempos_fifo < MAX_ATLETAS * MAX_TIEMPOS) {
        prueba->tiempos_fifo[prueba->num_tiempos_fifo] = tiempo;
        prueba->num_tiempos_fifo++;
    }
}

bool compara_promedios(const Atleta* a, const Atleta* b) {
    int promedio_a = (a->tiempos[0] + a->tiempos[1]) / 2;
    int promedio_b = (b->tiempos[0] + b->tiempos[1]) / 2;
    return promedio_a < promedio_b;
}

void ordenar_tiempos_lifo(Prueba* prueba) {
    sort(prueba->tiempos_lifo, prueba->tiempos_lifo + prueba->num_tiempos_lifo, compara_promedios);
}

void agregar_tiempos_lifo(Prueba* prueba, Atleta* atleta) {
    if (atleta->tiempos[1] != 0) {
        if (prueba->num_tiempos_lifo < MAX_ATLETAS) {
            prueba->tiempos_lifo[prueba->num_tiempos_lifo] = atleta;
            prueba->num_tiempos_lifo++;
            ordenar_tiempos_lifo(prueba);
        }
    }
}

int main() {
    Prueba prueba;
    prueba.num_atletas = 0;
    prueba.num_tiempos_fifo = 0;
    prueba.num_tiempos_lifo = 0;

    // Agregar algunos atletas
    Atleta* atleta1 = new Atleta;
    strcpy(atleta1->nombre, "Juan");
    atleta1->numero = 1;
    atleta1->tiempos[0] = 10;
    atleta1->tiempos[1] = 12;
    agregar_atleta(&prueba, atleta1);

    Atleta* atleta2 = new Atleta;
    strcpy(atleta2->nombre, "Maria");
    atleta2->numero = 2;
    atleta2->tiempos[0] = 9;
    agregar_atleta(&prueba, atleta2);

    Atleta* atleta3 = new Atleta;
    strcpy(atleta3->nombre, "Pedro");
    atleta3->numero = 3;
}

