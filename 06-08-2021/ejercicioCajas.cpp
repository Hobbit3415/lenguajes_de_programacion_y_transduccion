#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

stack<int> caja1;
stack<int> caja2;
stack<int> caja3;
const int maxCaja1 = 5;
const int maxCaja2 = 6;
int contadorCaja1[2] = {0, 0};
int contadorCaja2[2] = {0, 0};
int contadorCaja3[2] = {0, 0};

int clientes[0];
int nClientes = 0;
/**
 * Metodo que imprime por pantalla el menu principal
 **/
void menu()
{
  cout << "** Menu principal  **" << endl;
  cout << "1. Cargar vector clientes\n2. Enviar a la caja" << endl;
  cout << "3. Salir de la caja\n4. Mostrar estado de la caja" << endl;
  cout << "5. Salir" << endl;
}
/**
 * Metodo que carga el vector de clientes y lo inicializa con 1*
 **/
void cargarVectorClientes()
{
  cout << "Digite la cantidad de clientes que hacen fila: " << endl;
  cin >> nClientes;
  clientes[0] = clientes[nClientes];
  for (int i = 0; i < nClientes; i++)
  {
    clientes[i] = 1;
  }
}
/**
 * Metodo que retorna el estado actual de cada una de las cajas
 **/
int estadoCaja(int nCaja)
{
  switch (nCaja)
  {
  case 1:
    return caja1.size();
    break;
  case 2:
    return caja2.size();
    break;
  case 3:
    return caja3.size();
    break;
  }
}
/**
 * Metodo que extrae un cliente de la fila de clientes
 **/
int extraerCliente()
{
  for (int i = 0; i < nClientes; i++)
  {
    if (clientes[i] = 1)
    {
      clientes[i] = 0;
      return 1;
    }
  }
}
/**
 * Metodo que envia un cliente a una de las cajas disponibles
 **/
void enviarCliente()
{
  if (estadoCaja(1) < maxCaja1)
  {
    caja1.push(extraerCliente());
    cout << "Cliente enviado a la caja 1...\n" << endl;
    contadorCaja1[0] += 1;
  }
  else if (estadoCaja(2) < maxCaja2)
  {
    caja2.push(extraerCliente());
    cout << "Cliente enviado a la caja 2...\n" << endl;
    contadorCaja2[0] += 1;
  }
  else
  {
    caja3.push(extraerCliente());
    cout << "Cliente enviado a la caja 3...\n" << endl;
    contadorCaja3[0] += 1;
  }
}

int cajaAleatoria()
{
  int nRandom = 0;
  nRandom = rand() % 3 + 1;
  return nRandom;
}

void evacuarCaja()
{
  int nCaja = 0;
  do
  {
    nCaja = cajaAleatoria();
  } while (nCaja == 0);
  switch (nCaja)
  {
  case 1:
    caja1.pop();
    cout<<"Plaza libre en caja 1"<<endl;
    contadorCaja1[1] += 1;
    break;
  case 2:
    caja2.pop();
    cout<<"Plaza libre en caja 2"<<endl;
    contadorCaja2[1] += 1;
    break;
  case 3:
    caja3.pop();
    contadorCaja3[1] += 1;
    break;
  }
}

int main()
{
  system("cls");
  int op = 0;
  int nCaja = 0;
  do
  {
    cout<<endl;
    menu();
    cin >> op;
    switch (op)
    {
    case 1:
      cargarVectorClientes();
      break;
    case 2:
      enviarCliente();
      break;
    case 3:
      evacuarCaja();
      break;
    case 4:
      cout << "Digite el numero de la caja que desea consultar..." << endl;
      cin >> nCaja;
      cout << "Numero de clientes en la caja " << nCaja << ": " << estadoCaja(nCaja)<<endl;
      break;
    }
  } while (op != 5);
  cout<<"\nClientes que entraron a la caja 1: "<<contadorCaja1[0]<<endl;
  cout<<"Clientes que salieron de la caja 1: "<<contadorCaja1[1]<<endl;
  cout<<"****\nClientes que entraron a la caja 2:  "<<contadorCaja2[0]<<endl;
  cout<<"Clientes que salieron de la caja 2: "<<contadorCaja2[1]<<endl;
  cout<<"****\nClientes que entraron a la caja 3:  "<<contadorCaja3[0]<<endl;
  cout<<"Clientes que salieron de la caja 3: "<<contadorCaja3[1]<<endl;
  
}