#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;


struct nodo
{
    char val [40];
    char ape [40];
    int doc  =  0;
    nodo *sig;
};

nodo *cab, *aux, *aux2;

int registrar(){
    system("cls");

      if(cab==NULL){
        cab = (struct nodo *) malloc (sizeof(struct nodo));


        cout<<"<<<<<<<<REGISTRO DE PACIENTES>>>>>>>> ";
        cout<<endl;
        cout<<endl;
        

        cout<<"ingresa el nombre: ";
        cin>>cab->val;

        cout<<"ingresa el apellido: ";
        cin>>cab->ape;

        cout<<"ingresa el documento: ";
        cin>>cab->doc;
        cab->sig = NULL;

        

      }else{
        aux = (struct nodo *) malloc (sizeof(struct nodo));

        cout<<"<<<<<<<<REGISTRO DE PACIENTES>>>>>>>> ";
        cout<<endl;
        cout<<endl;
        cout<<"ingresa el nombre: ";
        cin>>aux->val;

        cout<<"ingresa el apellido: ";
        cin>>aux->ape;

        cout<<"ingresa el documento: ";
        cin>>aux->doc;
        
        
        aux->sig = NULL;
        aux2 = cab;


      while (aux2->sig!=NULL)

    aux2=aux2->sig;
    aux2->sig = aux;
    aux2 = aux = NULL;
    free(aux);
    free(aux2);

      
    
      }
        return 0;
      

}

int mostrar(){
    system("cls");
    int i = 1;

    cout<<"<<<<<<<<PACIENTES>>>>>>>";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for (aux = cab; aux !=NULL; aux=aux->sig)
    {


      

      

       cout<<"Paciente #";
       cout<<i;
       cout<<endl;
       cout<<"nombre : "<<aux->val<<endl;
       cout<<"apellido : "<<aux->ape<<endl; 
       cout<<"documento : "<<aux->doc<<endl;
       cout<<endl;
       cout<<endl;
       i++;

     
        
     

       }
       
       
       
       return 0; 


    } 
    





int main(){
    
    int opc = 0;

    do
    {
        cout<<endl;
        cout<<"<<<MENU>>>"<<endl;
        cout<<endl;
        cout<<"1.REGISTRAR PACIENTES"<< endl;
        cout<<"2.MOSTRAR PACIENTES"<< endl;
        cout<<"3.SALIR" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            registrar();
            system("cls");

            break;
        case 2:
            mostrar();
            system("pause");
            system("cls");
            break;

        case 3:
            cout<<"adios"<< endl;
            break;

        default:
            break;
        }
       

    }while (opc!=3);
    
}