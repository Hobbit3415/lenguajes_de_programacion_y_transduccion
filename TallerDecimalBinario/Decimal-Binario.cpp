#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int binario[16];
int contador = 0;

void reset()
{
  for (int i = 0; i < 16; i++)
  {
    binario[i] = 0;
  }
}

void decimal_a_binario(int num)
{

  contador = 0;
  int resultado = 0;
  int residuo = 0;
  reset();

  do
  {
    resultado = num / 2;
    residuo = num % 2;
    binario[contador] = residuo;
    num = resultado;
    contador++;
  } while (resultado != 0);
}

void binario_a_decimal(string num)
{
  string copy(num);
  reverse(copy.begin(), copy.end());
  int temp = 0;
  string actual = "";

  for (int i = 0; i < copy.length(); i++)
  {
    actual = copy[i];
    temp += stoi(actual) * pow(2, i);
  }
  cout << temp;
}

void imprimirArray(int lista[])
{
  for (int i = 0; i <= contador; i++)
  {
    cout << lista[contador - i];
  }
}

void menu()
{
  cout << "** ********************************* **" << endl;
  cout << "** Conversor de Decimales y binarios **" << endl;
  cout << "**            Menu principal         **" << endl;
  cout << "** 1. Convertir decimal a binario    **" << endl;
  cout << "** 2. Convertir binario a decimal    **" << endl;
  cout << "** 3. Salir                          **" << endl;
  cout << "** ********************************* **" << endl;
}

int main(int argc, char const *argv[])
{
  bool continuar = true;
  int num = 0;
  int op = 0;
  do
  {
    system("cls");
    menu();
    cin >> op;

    switch (op)
    {
    case 1:
      system("cls");
      cout << "** ******************************* **" << endl;
      cout << "** Decimal a binario **" << endl;
      cout << "** Digite el numero a convertir:   **" << endl;
      cout << "** ";
      cin >> num;
      cout << "\n***********************************" << endl;
      system("cls");
      decimal_a_binario(num);
      cout << "\n***********************************" << endl;
      cout << num << " => ";
      imprimirArray(binario);
      cout << "\n***********************************" << endl;
      cout << "\n" << endl;
      system("pause");
      break;

    case 2:
      system("cls");
      cout << "** Decimal a binario **" << endl;
      cout << "** Digite el numero a convertir: **" << endl;
      cout << "** ";
      cin >> num;
      cout << "\n********************************* **" << endl;
      system("cls");
      cout << "\n***********************************" << endl;
      cout << "** " << num << " => ";
      binario_a_decimal(to_string(num));
      cout << "\n***********************************\n" << endl;
      system("pause");
      break;

    case 3:
      continuar = false;
      break;

    default:
      system("cls");
      cout << "Opcion no valida..." << endl;
      system("pause");
    }
  } while (continuar);

  return 0;
}
