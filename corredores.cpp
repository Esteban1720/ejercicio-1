#include <iostream>
#include <malloc.h>
#include <cstring>
#include <algorithm>

using namespace std;

struct corredor
{
    int contador = 0;
    int time;
    int promedio = 0;
    int sematemp = 0;

    char nombre[20];
    int nasignado;
    corredor *sig;
    corredor *izquierdo;
    corredor *derecho;
};

corredor *cab, *aux, *aux2, *raiz, *auxA, *auxA2;

int numero;
int i = 0;


// Calcula la altura de un nodo
int calcularAltura(corredor* nodo) {
    if (nodo == NULL)
        return 0;
    return 1 + max(calcularAltura(nodo->izquierdo), calcularAltura(nodo->derecho));
}

// Realiza una rotación simple a la derecha
void rotacionSimpleDerecha(corredor*& nodo) {
    corredor* aux = nodo->izquierdo;
    nodo->izquierdo = aux->derecho;
    aux->derecho = nodo;
    nodo = aux;
}

// Realiza una rotación simple a la izquierda
void rotacionSimpleIzquierda(corredor*& nodo) {
    corredor* aux = nodo->derecho;
    nodo->derecho = aux->izquierdo;
    aux->izquierdo = nodo;
    nodo = aux;
}

// Realiza una rotación doble a la derecha
void rotacionDobleDerecha(corredor*& nodo) {
    rotacionSimpleIzquierda(nodo->izquierdo);
    rotacionSimpleDerecha(nodo);
}

// Realiza una rotación doble a la izquierda
void rotacionDobleIzquierda(corredor*& nodo) {
    rotacionSimpleDerecha(nodo->derecho);
    rotacionSimpleIzquierda(nodo);
}

// Realiza el balanceo del árbol AVL
void balancearArbol(corredor*& nodo) {
    if (nodo == NULL)
        return;

    int alturaIzq = calcularAltura(nodo->izquierdo);
    int alturaDer = calcularAltura(nodo->derecho);
    int diferenciaAltura = alturaDer - alturaIzq;

    if (diferenciaAltura > 1) {
        // Desbalance hacia la derecha
        int alturaDerDer = calcularAltura(nodo->derecho->derecho);
        int alturaDerIzq = calcularAltura(nodo->derecho->izquierdo);
        if (alturaDerDer >= alturaDerIzq)
            rotacionSimpleIzquierda(nodo);
        else
            rotacionDobleIzquierda(nodo);
    } else if (diferenciaAltura < -1) {
        // Desbalance hacia la izquierda
        int alturaIzqIzq = calcularAltura(nodo->izquierdo->izquierdo);
        int alturaIzqDer = calcularAltura(nodo->izquierdo->derecho);
        if (alturaIzqIzq >= alturaIzqDer)
            rotacionSimpleDerecha(nodo);
        else
            rotacionDobleDerecha(nodo);
    }

    // Recursivamente balancear los hijos
    balancearArbol(nodo->izquierdo);
    balancearArbol(nodo->derecho);
}



//FUNCION PARTE DEL REGISTRO EN EL ARBOL
int posicionar()
{
    if (auxA->promedio < auxA2->promedio)
    {
        if (auxA2->izquierdo != NULL)
        {
            auxA2 = auxA2->izquierdo;
            posicionar();
        }
        else
            auxA2->izquierdo = auxA;
    }
    else if (auxA->promedio > auxA2->promedio)
    {
        if (auxA2->derecho != NULL)
        {
            auxA2 = auxA2->derecho;
            posicionar();
        }
        else
            auxA2->derecho = auxA;
    }
    return 0;
}






//REGISTRA EL CALCULO DEL PROMEDIO EN EL ARBOL
int registrarArbol(corredor *fifo)
{

    auxA = (struct corredor *)malloc(sizeof(struct corredor));
    auxA = fifo;

    auxA->izquierdo = auxA->derecho = NULL;
    if (raiz == NULL)
    {
        raiz = auxA;
        auxA = NULL;
        free(auxA);
    }
    else
    {
        auxA2 = raiz;
        posicionar();
    }
    return 0;
}

// REGISTRAR ATLETA

int registrar()
{

    if (cab == NULL)
    {

        cab = (struct corredor *)malloc(sizeof(struct corredor));

        cout << "INGRESE NOMBRE DEL CORREDOR: ";
        cin >> cab->nombre;

        cout << "INGRESE NUMERO DE CAMISETA: ";
        cin >> cab->nasignado;
        cab->contador = 0;
        cab->promedio = 0;
        cab->sematemp = 0;
        cab->time = 0;

        cab->sig = NULL;
    }
    else
    {
        aux = (struct corredor *)malloc(sizeof(struct corredor));

        cout << "INGRESE NOMBRE DEL CORREDOR: ";
        cin >> aux->nombre;

        cout << "INGRESE NUMERO DE CAMISETA: ";
        cin >> aux->nasignado;
        aux->contador = 0;
        aux->promedio = 0;
        aux->sematemp = 0;
        aux->time = 0;

        aux->sig = NULL;
        aux2 = cab;

        while (aux2->sig != NULL)

            aux2 = aux2->sig;
        aux2->sig = aux;

        aux2 = aux = NULL;
        free(aux);
        free(aux2);
    }
    return 0;
}


int correr()
{

    aux = cab;
    int camisa;
    bool encontrado = false;
    cout << "INGRESE NUMERO DE CAMISETA DEL CORREDOR: ";
    cin >> camisa;

    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        if (camisa == aux->nasignado)
        {
          
            if (aux->contador == 1)
            {
                int multime;
                aux->contador++;
                cout << "INGRESE TIEMPO "
                     << "DE VUELTA"
                     << "  " << aux->contador << ":";
                cin >> multime;
                aux->sematemp = (aux->sematemp + multime);
                int resultado = (aux->sematemp) / 2;
                aux->promedio = resultado;
                aux->time = (multime);
                registrarArbol(aux);
                encontrado = true;
                aux = aux2 = NULL;
                cout << "Registro Exitoso";
                i++;
                break;
            }
              if (aux->contador > 1)
            {
                int multime;
                aux->contador++;
                   
                cout << "INGRESE TIEMPO "
                     << "DE VUELTA"
                     << "  " << aux->contador << ":";
                cin >> multime;
                aux->sematemp = (aux->sematemp + multime);
                int resultado = (aux->sematemp) / 2;
                aux->promedio = resultado;
                aux->time = (multime);
                registrarArbol(aux);
                balancearArbol(raiz);
                encontrado = true;
                aux = aux2 = NULL;
                cout << "Registro Exitoso";
                i++;
                break;
            }

            else
            {
                int x = 1;
                int y = aux->contador;

                aux->contador = x + y;

                cout << "INGRESE TIEMPO "
                     << "DE VUELTA "
                     << "  " << aux->contador << ":";
                cin >> aux->time;
                encontrado = true;
                aux = NULL;
                cout << "Registro Exitoso";
                break;
            }
        }
    }

    if (encontrado == false)
    {
        printf("No se encontro el atleta");
    }
    return 0;
}

// MUESTRA DE MENOR A MAYOR
int inorden(corredor *recursive)
{

    if (recursive->izquierdo != NULL)
    {
        inorden(recursive->izquierdo);
    }
    cout << "corredor  camisa #" << recursive->nasignado << " Nombre: " << recursive->nombre << " Ultimo Tiempo: " << recursive->time << " Numero de vueltas: " << recursive->contador << "  Promedio: " << recursive->promedio << endl;

    if (recursive->derecho != NULL)
    {
        inorden(recursive->derecho);
    }
    return 0;
}

int mostrar()
{

    int i = 1;
    int j = 0;
    cout << " \t\t\tLista de participante " << endl;
    cout << "\n";
    cout << "\n";

    for (aux = cab; aux != NULL; aux = aux->sig)
    {
        cout << i++ << ". corredor  camisa #" << aux->nasignado << " Nombre: " << aux->nombre << " Ultimo Tiempo: " << aux->time << " Numero de vueltas: " << aux->contador << "  Promedio: " << aux->promedio << endl;
        j++;
    }

    return 0;
}

void ordenar_FIFO_desc(struct corredor *inicio)
{
    struct corredor *actual = inicio;
    while (actual != NULL)
    {
        struct corredor *mayor = actual;
        struct corredor *sig = actual->sig;
        while (sig != NULL)
        {
            if (sig->promedio > mayor->promedio)
            {
                mayor = sig;
            }
            sig = sig->sig;
        }
        int temp = actual->promedio;
        int tamp = actual->nasignado;
        int tomp = actual->time;
        int timp = actual->contador;
        int tump = actual->sematemp;

        char nom[20];
        memcpy(nom, actual->nombre, 20);

        actual->promedio = mayor->promedio;
        mayor->promedio = temp;

        actual->nasignado = mayor->nasignado;
        mayor->nasignado = tamp;

        actual->time = mayor->time;
        mayor->time = tomp;

        actual->contador = mayor->contador;
        mayor->contador = timp;

        actual->sematemp = mayor->sematemp;
        mayor->sematemp = tump;

        memcpy(actual->nombre, mayor->nombre, 20);
        memcpy(mayor->nombre, nom, 20);
        actual = actual->sig;
    }
}


int main()
{

    int opc = 0;
    do
    {
        cout << endl;
        cout << endl;
        cout << "<<  SISTEMA DE ATLETAS  >>" << endl;
        cout << endl;
        cout << "1.REGISTRAR CORREDOR" << endl;
        cout << "2.REGISTRAR VUELTAS ARBOL & ARREGLO" << endl;
        cout << "3.MOSTRAR ARREGLO" << endl;
        cout << "4.MOSTRAR DE MENOR A MAYOR ARBOL" << endl;
        cout << "SALIR" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            registrar();
            break;

        case 2:
            correr();

            break;
        case 3:
            ordenar_FIFO_desc(cab);
            mostrar();

            break;

        case 4:
            inorden(raiz);
            break;

        case 5:

            break;

        default:
            break;
        }

    } while (opc != 7);

    return 0;
}
