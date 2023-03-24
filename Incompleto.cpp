#include <iostream>
#include <malloc.h>

using namespace std;

struct corredor
{
    char nombre[20];
    int nasignado;
    int Time;

    corredor *sig, *sigT;
};

corredor *cab, *aux, *aux2, *cabT, *auxT, *auxT2;

int numero;
int registrar()
{

    if (cab == NULL)
    {

        cab = (struct corredor *)malloc(sizeof(struct corredor));

        cout << "INGRESE NOMBRE DEL CORREDOR: ";
        cin >> cab->nombre;

        cout << "INGRESE NUMERO DE CAMISETA: ";
        cin >> cab->nasignado;

        cab->sig = NULL;
    }
    else
    {
        aux = (struct corredor *)malloc(sizeof(struct corredor));

        cout << "INGRESE NOMBRE DEL CORREDOR: ";
        cin >> aux->nombre;

        cout << "INGRESE NUMERO DE CAMISETA: ";
        cin >> aux->nasignado;

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

    if (cabT == NULL)
    {

        cabT = (struct corredor *)malloc(sizeof(struct corredor));

        cout << "INGRESE TIEMPO: ";
        cin >> cabT->Time;

        cabT->sigT = NULL;
    }
    else
    {
        auxT = (struct corredor *)malloc(sizeof(struct corredor));

        cout << "INGRESE TIEMPO: ";
        cin >> auxT->Time;

        auxT->sigT = NULL;
        auxT2 = cabT;

        while (auxT2->sigT != NULL)

            auxT2 = auxT2->sigT;
        auxT2->sigT = auxT;
        auxT2 = auxT = NULL;
        free(auxT);
        free(auxT2);
    }
    return 0;
}

int mostrar()
{
int c =1;
int i = 1;
    cout << " \t\t\tLista de tiempo de los participante " << endl;
    cout << "\n";
    cout << "\n";

    for (auxT = cabT; auxT != NULL; auxT = auxT->sigT)
    {

        cout << "\t\t\t\t\t " << c++ << ".Tiempo"
                                        ":  "
             << auxT->Time << endl;
    }
    for (aux = cab; aux != NULL; aux = aux->sig)
    {

        cout << i++ << ".corredor  camisa #: " << aux->nasignado << " Nombre: " << aux->nombre << endl;
    }

    return 0;
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
        cout << "2.REGISTRAR TIEMPO CORRIDO" << endl;
        cout << "3.MOSTRAR " << endl;
        cout << "4.SALIR" << endl;
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

            mostrar();

            break;

        default:
            break;
        }

    } while (opc != 4);

    return 0;
}
