#include <iostream>
#include <regex>
#include <string>
using namespace std;
  
int main()
{
    string input;
    regex integer_expr("[[:digit:]]+");
    regex letters_expr("[a-z]+");
    regex symbol_expr("(\\+|-)?");
    //As long as the input is correct ask for another number
    while(true)
    {
        cout<<"Enter the input: ";
        cin>>input;
        if(!cin) break;
        //Exit when the user inputs q
        if(input=="q")
            break;
        //Simbolos
        if(regex_match(input,symbol_expr));
            cout<<"\nInput is a symbol"<<endl;
        //Letras
        if(regex_match(input,letters_expr))
            cout<<"\nInput is a letter"<<endl;
        //Numeros
        if(regex_match(input,integer_expr))
            cout<<"\nInput is an integer"<<endl;
        
        else
        {cout<<"\nInvalid input : Not an integer"<<endl;}
    }

    system("pause");

}