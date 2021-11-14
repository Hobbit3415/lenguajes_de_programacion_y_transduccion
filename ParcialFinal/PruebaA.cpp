//Clase Token

#include <iostream>
#include <locale.h>
#include <regex> 

using namespace std;


class Token{
	
	Tipos tipo;
	String valor;
	
	
	void setTipo(int s){
		tipo = s;
	}
	
	static Tipos();
	
	Tipos::Tipos(){
		
  		regex regexABC("s[a-z_]+");	
  		
	//	regexBINARIO regexp("s[a-z_]+");
		
		regex regexNUM("s[0-9_]+");  	
	}
	
	
};


int main(){
	setlocale(LC_CTYPE, "Spanish");
	int opcion;
	
	
	
	do{
		system("cls");
		cout<<" Operaciones Árbol Binario"<<endl;
		cout<<" 1. Insertar "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
					system("cls");
					system("pause"); 
					break;
			case 2:
					seguir=false;
					break;
		}
		
	}while (seguir==true);
	
}

