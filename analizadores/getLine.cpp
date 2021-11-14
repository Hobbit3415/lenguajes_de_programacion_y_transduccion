#include <iostream>
using namespace std;

string nombres;

int main(int argc, char const *argv[])
{
  system("cls");
  cout<<"Ingrese los nombres completos..."<<endl;
  getline(cin, nombres);
  cout<<nombres<<endl;
  for(int i=0; i<nombres.size(); i++){
    cout<<nombres[i]<<endl;
  }
  return 0;
}
