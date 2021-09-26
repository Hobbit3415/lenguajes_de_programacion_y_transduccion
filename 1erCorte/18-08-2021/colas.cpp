#include <iostream>
#include <queue>
using namespace std;

queue <int> cola;

int main(){
  system("cls");
  //Ingresar
  cola.push(3);
  cola.push(5);
  cola.push(1);

  cout<<"Numero de elementos de la cola: "<< cola.size()<<endl;
  cout<<"El estado de la cola: "<<cola.empty()<<endl;
  cout<<"Ultimo elemento de la cola: "<<cola.back()<<endl;
  cout<<"Primer elemento de la cola: "<<cola.front()<<endl;
  system("pause");
  cola.pop();
  cout<<"\nNumero de elementos de la cola: "<< cola.size()<<endl;
  cout<<"El estado de la cola: "<<cola.empty()<<endl;
  cout<<"Ultimo elemento de la cola: "<<cola.back()<<endl;
  cout<<"Primer elemento de la cola: "<<cola.front()<<endl;
}