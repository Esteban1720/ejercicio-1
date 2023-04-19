#include <iostream>
#include <malloc.h>

using namespace std;

struct Times
{
    int contador = 0;
    int time;
    int promedio = 0;
};

struct corredor
{
    char nombre[20];
    int nasignado;
    Times estruc2;
    corredor *sig;
};

corredor *cab, *aux, *aux2;

int numero;
int contador = 0;
 



// REGISTRAR ATLETA

int registrar()
{

    if (cab == NULL){

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

    

    aux = (struct corredor *)malloc(sizeof(struct corredor));

    aux->sig = NULL;
    aux2 = cab;
    int camisa;
    bool encontrado = false;
    cout << "INGRESE NUMERO DE CAMISETA DEL CORREDOR: ";
    cin >> camisa;

    

    for (aux2 = cab; aux2 != NULL; aux2 = aux2->sig)
    {
        if (camisa == aux2->nasignado)
        {
            if (aux2->estruc2.promedio == 1)
            {
               cout<<"ESTE ATLETA NO PUEDE REGISTRAR MAS CARRERAS";
                encontrado = true;
                 break;
            }
            
            if(aux2->estruc2.contador == 555){
                int segundotime;
                 cout << "INGRESE TIEMPO: ";
                cin >> segundotime;
                int resultado =  (aux2->estruc2.time + segundotime) / 2;
                aux2->estruc2.time = resultado;
                aux2->estruc2.promedio = 1;
                 encontrado = true;
                  aux2 = aux = NULL;
                cout << "Registro Exitoso";

                break;
            }

                cout << "INGRESE TIEMPO: ";
                cin >> aux2->estruc2.time;
                encontrado = true;
                aux2->estruc2.contador = 555;
                aux2 = aux = NULL;

                cout << "Registro Exitoso";

                break;
          
            
        }
    }

    if (encontrado == false)
    {
        printf("No se encontro el atleta");
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
        cout << i++ << ".corredor  camisa #" << aux->nasignado << " Nombre: " << aux->nombre << "  Tiempo: " << aux->estruc2.time << endl;
        j++;
    }

    return 0;
}



  
    


int main()
{

    int opc = 0;
     
     //vaciar();

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
