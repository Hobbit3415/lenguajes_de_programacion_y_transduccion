#include <iostream>
using namespace std;

//Definicion de las variables globales

int x = 0;
int *y;

int main()
{
  system("cls");
  cout << "Punteros, ingrese un numero entero" << endl;
  cin >> x;

  cout << "Valor almacenado en X -->" << x << endl;
  cout << "Direccion de memoria de x -->" << &x << endl;
  cout << "Direccion de memoria de y -->" << &x << endl;
  y = &x;
  cout << "Valor almacenado en y -->" << *y << endl;
  cout << "Valor almacenado de la variable a la que apunta -->" << *y << endl;
  *y = 36;
  cout << "Valor almacenado de la variable a la que apunta --> " << *y << endl;
  cout << "Valor almacenado en x --> " << x << endl;
  system("pause");
}