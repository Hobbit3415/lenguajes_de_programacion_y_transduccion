#include <iostream>
#include <stack>
using namespace std;

/**
 * main
 */
int main()
{
  system("cls");

  stack <char> parentesis;

  string expresion = "";
  cout << "Digite la expresion que desea validar (sin espacios): " << endl;
  cin >> expresion;
  bool esCorrecta = false;

  char arr[expresion.length()];
  //Convertir String a array de Char
  for (int i = 0; i < sizeof(arr); i++)
  {
    arr[i] = expresion[i];
  }

  for (int i = 0; i < sizeof(arr); i++)
  {
    //Validacion de los parentesis
    if(arr[i]=='('){
      parentesis.push(arr[i]);
    }else if(arr[i] == ')'){
      parentesis.pop();
    }
    //Validacion de signos mal escritos
    if (arr[i] == '=')
    {
      // a+b=+c es correcto
      // a+b=-c es correcto
      // a+b+=c no es correcto

      /*if (arr[i + 1] == '+' || arr[i + 1] == '-' || arr[i + 1] == '*' || arr[i + 1] == '/' || arr[i + 1] == ';')
      {
        esCorrecta = false;
      }
      else*/if (arr[i - 1] == '+' || arr[i - 1] == '-' || arr[i - 1] == '*' || arr[i - 1] == '/' || arr[i - 1] == ';')
      {
        esCorrecta = false;
      }else{
        esCorrecta = true;
      }
    }
  }
  
  if(parentesis.empty()==true){
    esCorrecta = true;
  }else{
    esCorrecta = false;
  }

  if(esCorrecta){
    cout<<"La expresion es correcta..."<<endl;
  }else{
    cout<<"La expresion es no correcta, compruebe la entrada..."<<endl;
  }

}