#include <locale.h>
#include <fstream>
#include <iostream>

using namespace std;

bool seguir = true;
int op = 0;
int numeros = 0;
int numerosR = 0;
string datos ="";
ofstream aIngreso;
ifstream aLectura;

int main(int argc, char const *argv[])
{
  //Para establecer el idioma en el que vamos a trabajar
  setlocale(LC_CTYPE, "spanish");
  aIngreso.open("noviembre5.txt");
  //Si NO se presenta una falla, entonces...
  if (!aIngreso.fail())
  {
    do
    {
      system("cls");
      cout << "Menu principal" << endl;
      cout << "1. Ingresar datos" << endl;
      cout << "2. Recuperar datos" << endl;
      cout << "3. Salir" << endl;
      cout << "Ingrese la opcion..." << endl;
      cin >> op;

      switch (op)
      {
      case 1:
        //Vamos a capturar datos y almacenarlos en un archivo
        for (int z = 1; z <= 5; z++)
        {
          system("cls");
          cout << "Ingrese un numero entero..." << endl;
          cin >> numeros;
          if (z == 5)
          {
            aIngreso << numeros;
          }
          else
          {
            //Esta linea imprime EN aIngreso
            aIngreso << numeros << endl;
          }
        }
        //Se limpian los datos
        aIngreso.flush();
        //Se cierra el archivo .txt
        aIngreso.close();

        break;

      case 2:
        system("cls");
        aLectura.open("funciones.cpp");
        //Mientras NO sea fin de archivo, haga...
        while (!aLectura.eof())
        {

          aLectura>>datos;
          cout<<"Dato recuperado: "<<datos<<endl;

          //Saque del archivo e ingreselo a la variable numerosR
          //aLectura >> numerosR;
          //cout << "Dato recuperado: " << numerosR << endl;
        }
        aLectura.close();
        system("pause");
        break;

      case 3:
        seguir = false;
        break;

      default:
        break;
      }

    } while (seguir);
  }else{
    cout<<"Ocurrio un error inesperado..."<<endl;
  }

  return 0;
}
