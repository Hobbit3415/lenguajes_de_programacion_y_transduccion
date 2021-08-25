#include <iostream>
using namespace std;
bool seguir = true;

struct NodoA{
  int dato;
  NodoA *der;
  NodoA *izq;
};

NodoA *arbol = NULL;

NodoA *crearNodos(int d){
  NodoA *nnodo = new NodoA();
  nnodo -> dato = d;
  nnodo -> der=NULL; 
  nnodo -> izq=NULL;
  return nnodo;
}

void insertar(NodoA *&arbol, int d){
  if(arbol==NULL){
    NodoA *nnodo = crearNodos(d);
    arbol = nnodo;
  }else{
    int valorRaiz = arbol -> dato;
    if(d < valorRaiz){
      insertar(arbol -> izq, d);
    }else{
      insertar(arbol -> der, d);
    }
  }
}

void mostrar(NodoA *arbol, int cont){
  if(arbol==NULL){
    //system("pause");
    return;
  }else{
    mostrar(arbol ->der, cont+1);
    for(int i =0; i< cont; i++){
      cout<<"\t";
    }
    cout<<arbol->dato<<endl;
    mostrar(arbol ->izq, cont+1);
  }
}

int main(){
  int opcion, contador=0;
  int dato;

  do{
    system("cls");
    cout<<"Operaciones Arbol Binario"<<endl;
    cout<<"1. Insertar nodo\n2. Mostrar\n3. Salir"<<endl;
    cout<<"Ingrese una opcion..."<<endl;
    cin>>opcion;
    switch(opcion){
      case 1:
        system("cls");
        cout<<"Ingrese el elemento que va a almacenar en el arbol: "<<endl;
        cin>>dato;
        insertar(arbol, dato);
        break;

      case 2:
        system("cls");
        cout<<"Mostrar Arbol..."<<endl;
        mostrar(arbol, contador);
        system("pause");
        break;

      case 3:
        seguir = false;
        break;
      
      default:
        cout<<"Opcion no valida..."<<endl;
        break;
    }
  }while(seguir == true);

}