#include <iostream>
#include <queue>
using namespace std;

queue<int> bus;
queue<int> torniquete1, torniquete2;
queue<int> fueraDelSistema;

int contador = 0;

bool continuar = true;

void cargarBus()
{
  if (!bus.empty())
  {
    system("cls");
    cout << "Aun quedan pasajeros adentro..." << endl;
    system("pause");
  }
  else
  {
    for (int i = 0; i < 5; i++)
    {
      bus.push(1);
    }
  }
}

void llenarTor()
{
  if(bus.empty()){
    system("cls");
    cout << "El bus esta vacio..." << endl;
    cout << "Esperando el siguiente..." << endl;
    system("pause");
  }else if (torniquete1.size() < 3)
  {
    bus.pop();
    torniquete1.push(1);
    system("cls");
    cout << "Success..." << endl;
    system("pause");
  }
  else
  {
    system("cls");
    cout << "** Torniquete 1 lleno  **" << endl;
    system("pause");
  }

}

void retirarTor()
{
  if (bus.empty())
  {
    system("cls");
    cout << "Bus vacio..." << endl;
    cout << "En espera del siguiente..." << endl;
    system("pause");
  }
  else if (torniquete1.size() < 3)
  {
    bus.pop();
    torniquete1.push(1);
  }

  if (torniquete1.empty())
  {
    system("cls");
    cout << "Torniquete 1 vacio..." << endl;
    system("pause");
  }
  else if (torniquete2.size() < 3)
  {
    torniquete1.pop();
    torniquete2.push(1);
  }

  if (torniquete2.empty())
  {
    system("cls");
    cout << "Torniquete 2 vacio..." << endl;
    system("pause");
  }
  else if (torniquete2.size() < 3)
  {
    system("cls");
    torniquete2.pop();
    fueraDelSistema.push(1);
    system("pause");
  }

  system("cls");
  cout << "Success..." << endl;
  system("pause");
}

void mostrarEstado()
{
  int sumaPipol = 0;
  sumaPipol = bus.size() + torniquete1.size() + torniquete2.size() + fueraDelSistema.size();
  system("cls");
  cout << "Cantidad de personas en el sistema: " << sumaPipol << endl;
  cout << "Pasajeros en el bus: " << bus.size() << endl;
  cout << "Pasajeros en el torniquete 1: " << torniquete1.size() << endl;
  cout << "Pasajeros en el torniquete 2: " << torniquete2.size() << endl;
  cout << "Pasajeros fuera del sistema: " << fueraDelSistema.size() << endl;
  system("pause");
}

void menu()
{
  system("cls");
  cout << "********     App Transmilenio       ********" << endl;
  cout << "1. Cargar el bus." << endl;
  cout << "2. Pasar pasajeros el bus a los torniquetes." << endl;
  cout << "3. Retirar personas de los torniquetes." << endl;
  cout << "4. Mostrar estado del sistema." << endl;
  cout << "5. Salir." << endl;
  cout << "********************************************" << endl;
}

int main(int argc, char const *argv[])
{
  int opcion = 0;
  cargarBus();
  do
  {
    system("cls");
    menu();
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      cargarBus();
      break;

    case 2:
      llenarTor();
      break;

    case 3:
      retirarTor();
      break;
    case 4:
      mostrarEstado();
      break;

    default:
      system("cls");
      cout << "Opcion no valida..." << endl;
      system("pause");
      break;
    }
  } while (continuar);

  system("pause");
  return 0;
}
