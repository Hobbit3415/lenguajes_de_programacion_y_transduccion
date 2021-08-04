#include <iostream>
using namespace std;

int vector[5]={0,0,0,0,0};
int matriz[3][3]={0,0,0,0,0,0,0,0,0,};

int main()
{
  system("cls");
  for (int i = 0; i <= 5; i++)
  {
    vector[i] = i + 1;
  }

  for (int i = 0; i <= 5; i++)
  {
    cout << vector[i] << "\t";
  }

  int contador = 1;
  for (int i = 0; i <= 2; i++)
  {
    for (int j = 0; j <= 2; j++)
    {
      matriz[i][j] = contador++;
    }
  }
  cout<<endl<<endl;
  for (int i = 0; i <= 2; i++)
  {
    for (int j = 0; j <= 2; j++)
    {
      cout<<matriz[i][j]<<"\t";
    }
    cout<<"\n";
  }
  cout<<"\n";
}