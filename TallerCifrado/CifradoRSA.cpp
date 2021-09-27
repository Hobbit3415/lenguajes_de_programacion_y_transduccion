#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
using namespace std;

long long n = 0;
long long p = 0;
long long q = 0;
long long z = 0;
long long k = 0;

bool esPrimo(int numero)
{
  // Casos especiales
  if (numero == 0 || numero == 1 || numero == 4)
    return false;
  for (int x = 2; x < numero / 2; x++)
  {
    if (numero % x == 0)
      return false;
  }
  // Si no se pudo dividir por ninguno de los de arriba, sí es primo
  return true;
}

int obtenerNumeroPrimo()
{
  long long num = 0;
  do
  {
    num = rand();
  } while (esPrimo(num) == false);
  return num;
}

//Metodo que retorna el maximo comun divisor
int MCD(long long z, long long k)
{
  if (k == 0)
  {
    return z;
  }
  else
  {
    return MCD(k, z % k);
  }
}
//Metodo que genera una clave publica para RSA
int generarClavePublica()
{
  //Se obtienen dos primos al azar diferentes
  p = obtenerNumeroPrimo();
  q = obtenerNumeroPrimo();
  n = p * q;
  z = (p - 1) * (q - 1);
  /**
   * Dos numeros son coprimos si y solo si su
   * maximo comun divisor es 1
   */
  // Se obtiene un numero co primo a Z
  do
  {
    k = obtenerNumeroPrimo();
  } while (MCD(z, k) != 1);
  return k;
}

//Metodo que genera una clave privada para RSA
int generarClavePrivada()
{
  long long j = 0;
  do
  {
    j = rand();
  } while (((k * j) % z) != 1);
  return j;
}

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

    // Append the current digit
    num = num * 10 + (str[i] - '0');

    // If num is within the required range
    if (num > 31 && num < 255)
    {
      if (num == 127)
      {
        char ch = '~';
        cout << ch;
      }
      // Convert num to char
      char ch = (char)num;
      cout << ch;

      // Reset num to 0
      num = 0;
    }
  }
}

string cifrarMensaje(string mensaje, long len)
{
  long num = 0;
  long temp = 0;
  string salida = "";
  //temp = (stol(mensaje)^clavePublica)%n;
  //salida = to_string(temp);

  // code...
  //stringstream buffer(mensaje);
  //buffer >> num;
  
  for (int i = 0; i < len; i++)
  {

    // Append the current digit
    num = num * 10 + (mensaje[i] - '0');

    // If num is within the required range
    if (num > 31 && num < 255)
    {
      if (num == 127)
      {
        char ch = '~';
        cout << ch;
      }
      // Convert num to char
      char ch = (char)num;
      temp = (char)num+3;
      salida += to_string(temp);
      //cout << ch;

      // Reset num to 0
      num = 0;
      temp=0;
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

    // Append the current digit
    num = num * 10 + (mensaje[i] - '0');

    // If num is within the required range
    if (num > 31 && num < 255)
    {
      if (num == 127)
      {
        char ch = '~';
        cout << ch;
      }
      // Convert num to char
      char ch = (char)num;
      temp = (char)num-3;
      salida += to_string(temp);
      //cout << ch;

      // Reset num to 0
      num = 0;
      temp=0;
    }
  }
  return salida;
}

int main(int argc, char const *argv[])
{
  system("cls");
  //long clavePublica = generarClavePublica();
  //long clavePrivada = generarClavePrivada();
  string mensaje_cifrado = "";
  string mensaje_descifrado = "";
  long len = 0;
  string mensaje = "";
  /*cout << "Clave publica: " << clavePublica[0] << ", " << clavePublica[1] << endl;
  cout << "n: " << n << endl;
  cout << "z: " << z << endl;
  cout << "k: " << k << endl;
  cout << "j: " << j << endl;*/
  //cout << "Clave privada: " << generarClavePrivada() << endl;

  cout << "Digite el mensaje a cifrar: " << endl;
  getline(cin, mensaje);
  cout << endl;

  //Conversion del mensaje a format ASCII
  string mensajeAscii = convertir_a_ascii(mensaje);
  cout << "Mensaje en ASCII: " << endl;
  cout << mensajeAscii << endl;
  //string convert;
  /*
  cout << "\nASCII a texto" << endl;
  */
  len = mensajeAscii.length();
  
  convertir_ascii_a_texto(mensajeAscii, len);
  
  cout << "Mensaje cifrado:" << endl;
  mensaje_cifrado = cifrarMensaje(mensajeAscii, len);
  cout << mensaje_cifrado << endl;

  cout << "\nMensaje cifrado en texto: " << endl;
  len = mensaje_cifrado.length();
  convertir_ascii_a_texto(mensaje_cifrado, len);
  cout << endl;

  cout << "Mensaje descifrado:" << endl;
  mensaje_descifrado = descifrarMensaje(mensaje_cifrado, len);
  cout << mensaje_descifrado << endl;

  cout << "\nMensaje descifrado en texto: " << endl;
  len = mensaje_descifrado.length();
  convertir_ascii_a_texto(mensaje_descifrado, len);
  cout << endl;

  return 0;
}