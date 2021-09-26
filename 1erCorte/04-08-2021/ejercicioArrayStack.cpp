/*
Simular mediante un array de dimension n el comportamiento de una pila
El programa debe permitir:
  1. Ingresar elemento a la pila
  2. Mostrar cima de la pila
  3. Retirar elemento de la pila
  4. Mostrar el estado de la pila (tiene o no tiene elmentos)
  5. Mostrar el tamaño de la pila
*/
#include <iostream>
using namespace std;

int num = 0;
int contador = 0;
int size = 0;
int op = 0;
int array[0];

int imprimirArray(int array[])
{
  for (int i = 0; i < size; i++)
  {
    cout << "|" << array[i] << "|"
         << "\t";
  }
}

int *inicializarArray(int size)
{
  array[0] = array[size];
  for (int i = 0; i < size; i++)
  {
    array[i] = 0;
  }
  return array;
}

void menu()
{
  cout << "\n** Menu Principal  **" << endl;
  cout << "1. Ingresar elemento a la pila\n2. Mostrar cima de la pila\n3. Retirar elemento\n";
  cout << "4. Mostrar estado de la pila\n5. Mostrar dimension de la pila\n6. Imprimir pila\n";
  cout << "7. Salir" << endl;
}

void agregarElemento()
{
  if (contador == size)
  {
    cout << "Limite de la pila alcanzado, remueva un elmento..." << endl;
  }
  else
  {
    cout << "Digite el numero (diferente de cero) que desea agregar a la pila..." << endl;
    cin >> num;
    array[contador] = num;
    contador += 1;
    cout << "Plazas restantes: " << size - contador << endl;
  }
}

void mostrarCima()
{
  for (int i = 0; i < size; i++)
  {
    if (contador == size)
    {
      cout << "Elemento en la cima: " << array[size] << endl;
      break;
    }
    else if (array[i+1] == 0)
    {
      cout << "Elemento en la cima: " << array[i] << endl;
      break;
    }
    else if (array[i] == 0)
    {
      cout << "La pila no tiene elementos..." << endl;
      break;
    }
  }
}

void retirarElemento()
{
  for (int i = 0; i < size; i++)
  {
    if (array[i + 1] == 0)
    {
      array[i] = 0;
      contador-=1;
      break;
    }
  }
}

void mostrarEstado()
{
  if (contador == size)
  {
    cout << "Pila llena" << endl;
  }
  else if (contador < size)
  {
    cout << "Plazas restantes: " << size - contador << endl;
  }
  else
  {
    cout << "Pila vacia" << endl;
  }
}

void mostrarDimension()
{
  cout << "Dimension de la pila -> " << size << endl;
}

int main()
{
  system("cls");
  cout << "Digite la dimension de la pila: ";
  cin >> size;
  //cout << "Array inicializado";
  inicializarArray(size);
  //system("cls");
  do
  {
    menu();
    cin >> op;
    switch (op)
    {
    case 1:
      agregarElemento();
      imprimirArray(array);
      break;
    case 2:
      mostrarCima();
      break;
    case 3:
      retirarElemento();
      break;
    case 4:
      mostrarEstado();
      break;
    case 5:
      mostrarDimension();
      break;
    case 6:
      imprimirArray(array);
      break;
    case 7:
      break;
    default:
      cout<<"Opcion no valida...";
      break;
    }
  } while (op != 7);
}