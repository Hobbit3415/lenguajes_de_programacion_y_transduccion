#include <iostream>
#include <stack>
using namespace std;

stack <int> pila;

int main(){
  system("cls");
  pila.push(23);
  pila.push(12);
  pila.push(50);

  cout<<"Elementos de la pila "<<pila.size()<<endl;
  cout<<pila.top()<<endl;
  pila.pop();
  cout<<pila.top()<<endl;
  pila.pop();
  cout<<"Estado de la pila: "<<pila.empty()<<endl;
  cout<<pila.top()<<endl;
  pila.pop();
  cout<<"Estado de la pila: "<<pila.empty()<<endl;
}