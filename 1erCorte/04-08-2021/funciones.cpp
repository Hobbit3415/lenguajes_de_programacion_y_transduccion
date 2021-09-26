#include <iostream>

using namespace std;

int a, b, c;

int suma(int a1, int b1)
{
  c = a1 + b1;
  return c;
}

int main()
{
  system("cls");
  cout << "Ingrese primer numero" << endl;
  cin >> a;
  cout << "Ingrese segundo numero" << endl;
  cin >> b;
  cout<<"El resultado es "<<suma(a, b)<<endl;
}