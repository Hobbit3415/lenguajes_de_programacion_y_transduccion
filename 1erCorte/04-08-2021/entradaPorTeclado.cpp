#include <iostream>
using namespace std;

int a = 13;
int op = 0;
bool seguir = true;

void opcion1()
{
  system("cls");
  cout << "Ingreso a la opcion 1 - estado" << endl;
  cout << "En  construccion" << endl;
  system("pause");
}

void opcion2()
{
  system("cls");
  cout << "Ingreso a la opcion 2 - estado" << endl;
  cout << "En  construccion" << endl;
  system("pause");
}

int main()
{
  do
  {
    system("cls");
    cout << "Menu principal" << endl;
    cout << "1. primera opcion" << endl;
    cout << "2. segunda opcion" << endl;
    cout << "3. salir" << endl;
    cout << "Ingrese una opcion..." << endl;
    cin >> op;
    switch (op)
    {
    case 1:
      opcion1();
      break;
    case 2:
      opcion2();
      break;
    case 3:
      seguir = false;
      break;
    }
  } while (seguir == true);
}