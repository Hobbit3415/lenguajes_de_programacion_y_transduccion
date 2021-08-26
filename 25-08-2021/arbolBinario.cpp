#include <iostream>
using namespace std;
bool seguir = true;

struct NodoA
{
  int dato;
  NodoA *der;
  NodoA *izq;
};

NodoA *arbol = NULL;

NodoA *crearNodos(int d)
{
  NodoA *nnodo = new NodoA();
  nnodo->dato = d;
  nnodo->der = NULL;
  nnodo->izq = NULL;
  return nnodo;
}

void insertar(NodoA *&arbol, int d)
{
  if (arbol == NULL)
  {
    NodoA *nnodo = crearNodos(d);
    arbol = nnodo;
  }
  else
  {
    int valorRaiz = arbol->dato;
    if (d < valorRaiz)
    {
      insertar(arbol->izq, d);
    }
    else
    {
      insertar(arbol->der, d);
    }
  }
}

void mostrar(NodoA *arbol, int cont)
{
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    mostrar(arbol->der, cont + 1);
    for (int i = 0; i < cont; i++)
    {
      cout << "\t";
    }
    cout << arbol->dato << endl;
    mostrar(arbol->izq, cont + 1);
  }
}

void inOrden(NodoA *arbol){
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    inOrden(arbol->izq);
    cout << arbol->dato<< "\t";
    inOrden(arbol->der);
  }
}

void preOrden(NodoA *arbol){
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    cout << arbol->dato<< "\t";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}

void postOrden(NodoA *arbol){
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato<< "\t";
  }
}

int main()
{
  int opcion, contador = 0;
  int dato;

  do
  {
    system("cls");
    cout << "Operaciones Arbol Binario" << endl;
    cout << "1. Insertar nodo\n2. Mostrar\n3. Mostrar In Orden" << endl;
    cout << "4. Mostrar Pre Orden\n5. Mostrar Post Orden\n6. Salir" << endl;
    cout << "Ingrese una opcion..." << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      system("cls");
      cout << "Ingrese el elemento que va a almacenar en el arbol: " << endl;
      cin >> dato;
      insertar(arbol, dato);
      break;

    case 2:
      system("cls");
      cout << "Mostrar Arbol..." << endl;
      mostrar(arbol, contador);
      system("pause");
      break;

    case 3:
      system("cls");
      cout << "** In Orden **" << endl;
      inOrden(arbol);
      cout<<endl;
      system("pause");
      break;

    case 4:
      system("cls");
      cout << "** Pre Orden **" << endl;
      preOrden(arbol);
      cout<<endl;
      system("pause");
      break;

    case 5:
      system("cls");
      cout << "** Post Orden **" << endl;
      postOrden(arbol);
      cout<<endl;
      system("pause");
      break;

    case 6:
      seguir = false;
      break;

    default:
      cout << "Opcion no valida..." << endl;
      break;
    }
  } while (seguir == true);
}