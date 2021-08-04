#include <iostream>
/*
Crear un conversor de divisas  
  Pesos Colombianos a Dolares, Dolares a Pesos Colombianos, 
  Pesos Colombianos a Libras est, Libras est. a Pesos Colombianos
  Yenes a dolares y dolares a yenes.
  Pesos mexicanos a Pesos colombianos.
*/
using namespace std;

int cantidad = 0;
string menu = "1. COP a USD\n2. USD a COP\n3. COP a GBP(Libra)\n4. GBP a COP\n5. JPY a USD\n6. MXN a USD\n7. Salir\n";

int main()
{
  int *valor;
  int opcion = 0;
  int resultado = 0;
  int *resu;
  *resu = resultado;

  cout << "** Conversor de divisas  **\n";
  cout << "\nSeleccione la conversion que desea hacer...\n";
  cout << menu;
  cin >> opcion;
  cout << "Digite la cantidad a convertir: \n";
  cin >> cantidad;
  *valor = cantidad;

  switch (opcion)
  {
  case 1:
    cout << *valor << "COP equivale a " << *valor *0.00026 << "USD";
    break;
  case 2:
    cout << *valor << "USD equivale a " << *valor *3877.11 << "COP";
    break;
  case 3:
    cout << *valor << "COP equivale a " << *valor *0.00019 << "GBP";
    break;
  case 4:
    cout << *valor << "GBP equivale a " << *valor *5367.15 << "COP";
    break;
  case 5:
    cout << *valor << "JPY equivale a " << *valor *0.0091 << "USD";
    break;
  case 6:
    cout << *valor << "MXN equivale a " << *valor *0.050 << "USD";
    break;
  case 7:
    cout << "Hasta pronto...";
    break;
  default:
    break;
  }
  system("pause");
}