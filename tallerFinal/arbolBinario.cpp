#include <iostream>
using namespace std;

bool seguir = true;
bool esPerfecto = false;
int contadorNiveles = 1;
int peso = 0;
//int nRamas = 0;

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

void menu()
{
  //system("cls");
  cout << "** Operaciones Arbol Binario **" << endl;
  cout << "1. Insertar nodo\n2. Info. del arbol\n3. Mostrar In Orden" << endl;
  cout << "4. Mostrar Pre Orden\n5. Mostrar Post Orden\n6. Salir" << endl;
  cout << "Ingrese una opcion..." << endl;
}

void insertar(NodoA *&arbol, int d)
{
  if (arbol == NULL)
  {
    NodoA *nnodo = crearNodos(d);
    arbol = nnodo;
    peso += 1;
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

void inOrden(NodoA *arbol)
{
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    inOrden(arbol->izq);
    cout << arbol->dato << "\t";
    inOrden(arbol->der);
  }
}

void preOrden(NodoA *arbol)
{
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    cout << arbol->dato << "\t";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}

void postOrden(NodoA *arbol)
{
  if (arbol == NULL)
  {
    //system("pause");
    return;
  }
  else
  {
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << "\t";
  }
}

int mostrarNiveles(NodoA *arbol)
{
  int alturaIzq = 0, alturaDer = 0;
  //Nodo terminal
  if (arbol->izq == NULL && arbol->der == NULL)
  {
    return 0;
  }

  if (arbol->der != NULL)
  {
    alturaDer = mostrarNiveles(arbol->der);
  }

  if (arbol->izq != NULL)
  {
    alturaIzq = mostrarNiveles(arbol->izq);
  }

  if (alturaDer == alturaIzq)
  {
    esPerfecto = true;
  }
  else
  {
    esPerfecto = false;
  }

  if (alturaDer > alturaIzq)
  {
    return alturaDer + 1;
  }
  else
  {
    return alturaIzq + 1;
  }
}

string arbolPerfecto()
{
  if (esPerfecto)
  {
    return "El arbol es perfecto";
  }
  else
  {
    return "El arbol es imperfecto";
  }
}

int numeroRamas(NodoA *arbol)
{
  if (arbol == NULL)
  {
    return 0;
  }
  else
  {

    if (arbol->der == NULL && arbol->izq == NULL)
    {
      return 0;
    }
    else
    {
      return 1 + (numeroRamas(arbol->der) + numeroRamas(arbol->izq));
    }
  }
}

int numeroHojas(NodoA *arbol)
{
  if (arbol == NULL)
  {
    return 0;
  }
  else
  {
    if (arbol->der != NULL)
    {
      return numeroHojas(arbol->der)+numeroHojas(arbol->izq);
    }
    else if (arbol->izq != NULL)
    {
      return numeroHojas(arbol->izq)+numeroHojas(arbol->der);
    }
    else
    {
      return 1;
    }
  }
}

int main()
{
  int opcion, contador = 0;
  int dato;

  do
  {
    menu();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      //system("cls");
      cout << "Ingrese el elemento que va a almacenar en el arbol: " << endl;
      cin >> dato;
      insertar(arbol, dato);
      break;

    case 2:
      //system("cls");
      cout << "** Arbol binario **" << endl;
      mostrar(arbol, contador);
      cout << "*******************" << endl;
      cout << "* Peso del arbol: " << peso << endl;
      cout << "* Nivel del arbol: " << mostrarNiveles(arbol) << endl;
      cout << "* " << arbolPerfecto() << endl;
      cout << "* Numero de ramas: " << numeroRamas(arbol) << endl;
      cout << "* Numero de hojas: " << numeroHojas(arbol) << endl;

      system("pause");
      break;

    case 3:
      //system("cls");
      cout << "** In Orden **" << endl;
      inOrden(arbol);
      cout << endl;
      system("pause");
      break;

    case 4:
      //system("cls");
      cout << "** Pre Orden **" << endl;
      preOrden(arbol);
      cout << endl;
      system("pause");
      break;

    case 5:
      //system("cls");
      cout << "** Post Orden **" << endl;
      postOrden(arbol);
      cout << endl;
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