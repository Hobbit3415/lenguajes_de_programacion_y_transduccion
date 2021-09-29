#include <iostream>
#include <stdio.h>

using namespace std;

string convertir_a_ascii(string str)
{
  long l = str.length();
  long convert;
  string mensaje = "";
  for (int i = 0; i < l; i++)
  {
    convert = str[i] - NULL;
    mensaje += to_string(convert);
  }
  return mensaje;
}

void convertir_ascii_a_texto(string str, long len)
{
  long num = 0;
  for (int i = 0; i < len; i++)
  {

    //Añade el digito actual
    num = num * 10 + (str[i] - '0');

    //Checkea el rango de caracteres ASCII
    if (num > 31 && num < 255)
    {
      //Caracter 127 no existe
      if (num == 127)
      {
        char ch = '~';
        cout << ch;
      }
      //Convertir numero a char
      char ch = (char)num;
      cout << ch;

      //Reset
      num = 0;
    }
  }
}

string cifrarMensaje(string mensaje, long len)
{
  long num = 0;
  long temp = 0;
  string salida = "";

  for (int i = 0; i < len; i++)
  {
    //Agregar el digito actual
    num = num * 10 + (mensaje[i] - '0');

    //Checkea que el numero este en el rango de ASCII
    if (num > 31 && num < 255)
    {
      if (num == 127)
      {
        char ch = '~';
        cout << ch;
      }
      //Convertir numero a char
      temp = (char)num + 3;
      salida += to_string(temp);

      //Reset
      num = 0;
      temp = 0;
    }
  }
  return salida;
}

string descifrarMensaje(string mensaje, long len)
{
  long long num = 0;
  long long temp = 0;
  string salida = "";

  for (int i = 0; i < len; i++)
  {

    //Agregar el digito actual
    num = num * 10 + (mensaje[i] - '0');

    //Checkeo del rango de ASCII
    if (num > 31 && num < 255)
    {
      if (num == 127)
      {
        char ch = '~';
        cout << ch;
      }
      //Convertir el numero a char
      char ch = (char)num;
      temp = (char)num - 3;
      salida += to_string(temp);

      // Reset num to 0
      num = 0;
      temp = 0;
    }
  }
  return salida;
}

void menu()
{
  system("cls");
  cout << "Menu principal" << endl;
  cout << "1. Cifrar mensaje" << endl;
  cout << "2. Descifrar mensaje" << endl;
  cout << "3. Escribir mensaje nuevo" << endl;
}

int main(int argc, char const *argv[])
{
  string mensaje_cifrado = "";
  string mensaje_descifrado = "";
  long len = 0;
  string mensaje = "";
  int op = 0;
  bool continuar = true;

  do
  {
    system("cls");
    cout << "Digite el mensaje a cifrar: " << endl;
    getline(cin, mensaje);
    cout << endl;
    //Conversion del mensaje a format ASCII
    string mensajeAscii = convertir_a_ascii(mensaje);
    cout << "Mensaje en ASCII: " << endl;
    cout << mensajeAscii << endl;
    len = mensajeAscii.length();
    menu();
    cin >> op;
    switch (op)
    {
    case 1:
      system("cls");
      cout << "Mensaje a cifrar:" << endl;
      cout << mensaje << endl;
      mensaje_cifrado = cifrarMensaje(mensajeAscii, len);
      cout << "Texto cifrado:" << endl;
      len = mensaje_cifrado.length();
      convertir_ascii_a_texto(mensaje_cifrado, len);
      cout << endl;
      system("pause");
      break;
    case 2:
      system("cls");
      cout << "Texto a descifrar:" << endl;
      len = mensaje_cifrado.length();
      convertir_ascii_a_texto(mensaje_cifrado, len);
      cout << "\nTexto a descifrado:" << endl;
      mensaje_descifrado = descifrarMensaje(mensaje_cifrado, len);
      convertir_ascii_a_texto(mensaje_descifrado, len);
      cout << endl;
      system("pause");
      break;
    case 3:
      cout << "Digite el mensaje a cifrar: " << endl;
      getline(cin, mensaje);
      mensajeAscii = convertir_a_ascii(mensaje);
      cout << endl;
      break;
    case 4:
      continuar = false;
      break;
    default:
      system("cls");
      cout << "Opcion no valida..." << endl;
      cout << endl;
      system("pause");
      break;
    }
  } while (continuar);

  return 0;
}