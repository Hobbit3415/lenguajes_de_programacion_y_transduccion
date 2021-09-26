#include <iostream>
using namespace std;

bool seguir = true;
bool esPerfecto = false;
int contadorNiveles = 1;
int peso = 0;

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
/**
 * Metodo que imprime por pantalla el menu principal
 **/
void menu()
{
  system("cls");
  cout << "*******************************" << endl;
  cout << "** Operaciones Arbol Binario **" << endl;
  cout << "1. Insertar nodo\n2. Info. del arbol\n3. Mostrar In Orden" << endl;
  cout << "4. Mostrar Pre Orden\n5. Mostrar Post Orden\n6. Salir" << endl;
  cout << "*******************************" << endl;
}

void insertar(NodoA *&arbol, int d)
{
  if (arbol == NULL)
  {
    NodoA *nnodo = crearNodos(d);
    arbol = nnodo;
    //Aumenta el peso del arbol cada vez que se agrega un nodo
    peso += 1;
  }
  else
  {
    int valorRaiz = arbol->dato;
    //Agrega el nodo a la izquierda o a la derecha
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
/**
 * Metodo que muestra por pantalla el arbol
 **/
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
/**
 * Metodo imprime el arbol en InOrden
 **/
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
/**
 * Metodo imprime el arbol en PreOrden
 **/
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
/**
 * Metodo imprime el arbol en PostOrden
 **/
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
  //Si el nodo es un nodo terminal, retorne 0
  if (arbol->izq == NULL && arbol->der == NULL)
  {
    return 0;
  }
  //Si el nodo derecho no es nulo, retorne la altura derecha
  if (arbol->der != NULL)
  {
    alturaDer = mostrarNiveles(arbol->der);
  }
  //Si el nodo izquierdo no es nulo, retorne la altura izquierda
  if (arbol->izq != NULL)
  {
    alturaIzq = mostrarNiveles(arbol->izq);
  }
  /*Si la altura izquierda es igual a la altura derecha,
  el arbol es perfecto*/
  if (alturaDer == alturaIzq)
  {
    esPerfecto = true;
  }P
  else
  {
    esPerfecto = false;
  }
  /*Si la altura derecha es mayor a la izquierda, retorne esa*/
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
      system("cls");
      cout << "*************************" << endl;
      cout << "Ingrese el elemento que va a almacenar en el arbol: " << endl;
      cin >> dato;
      insertar(arbol, dato);
      break;

    case 2:
      system("cls");
      cout << "*************************" << endl;
      cout << "***** Arbol binario *****" << endl;
      mostrar(arbol, contador);
      cout << "*************************" << endl;
      cout << "* " << arbolPerfecto() << endl;
      cout << "* Peso del arbol:  " << peso << endl;
      cout << "* Nivel del arbol: " << mostrarNiveles(arbol) << endl;
      cout << "* Numero de ramas: " << numeroRamas(arbol) << endl;
      cout << "* Numero de hojas: " << numeroHojas(arbol) << endl;
      cout << "*************************" << endl;
      cout << endl;
      system("pause");
      break;

    case 3:
      system("cls");
      cout << "*************************" << endl;
      cout << "** In Orden **" << endl;
      inOrden(arbol);
      cout << "\n*************************" << endl;
      cout << endl;
      system("pause");
      break;

    case 4:
      system("cls");
      cout << "*************************" << endl;
      cout << "** Pre Orden **" << endl;
      preOrden(arbol);
      cout << "\n*************************" << endl;
      cout << endl;
      system("pause");
      break;

    case 5:
      system("cls");
      cout << "*************************" << endl;
      cout << "** Post Orden **" << endl;
      postOrden(arbol);
      cout << "\n*************************" << endl;
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