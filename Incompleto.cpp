#include <iostream>
#include <malloc.h>

using namespace std;

struct persona{
    char nombre[20];
    int nasignado;
    int val = 0;
    persona *sig;

};

persona *cab, *aux;

int numero;
int registrar(){

    aux = (struct persona *)malloc(sizeof(struct persona));

    cout << "INGRESE NOMBRE DEL CORREDOR: ";
    cin >> aux->nombre;
    
   
    
    

    if (cab == NULL){
        numero++;
    aux->nasignado = 0;
    aux->nasignado++;

        cab = aux;
        cab->sig = NULL;
    }
    else{
        numero++;
        aux->nasignado += numero;
        
        aux->sig = cab;
        cab = aux;
    }
    
    aux = NULL;
    free(aux);
    return 0;
}



int eliminar() {
 if(cab!=NULL){
    aux = cab;
    cab = cab->sig;
    free(aux);
 }
 return 0;
}


int mostrar() {
    aux = cab;
    while(aux!=NULL){
        
        
        cout<<"Atleta # ";
        cout<<aux->nasignado<<"  ";
        cout<<aux->nombre<<endl;
        aux = aux->sig;
    }
    return 0;
}

int main(){

    int opc = 0;

    do {
        cout<<endl;
        cout<<endl;
        cout<<"<<  SISTEMA DE ATLETAS  >>"<<endl;cout<<endl;
        cout << "1.REGISTRAR CORREDOR" << endl;
        cout << "2.ELIMINAR CORREDOR" << endl;
        cout << "3.MOSTRAR CORREDOR" << endl;
        cout << "4.SALIR" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            registrar();
            break;

        case 2:
            eliminar();

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
