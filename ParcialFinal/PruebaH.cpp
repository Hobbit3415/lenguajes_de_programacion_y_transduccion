#include <iostream>
#include <locale.h>
#include <regex> 
#include<string.h> 

using namespace std;

int main(){
	
	regex regexABC("s[a-z_]+");	
	
	//regex regexBINARIO regexp("s[a-z_]+");
	
	regex regexNUM("s[0-9_]+");
	
	enum Lexemas {regexABC,regexNUM};
	
	setlocale(LC_CTYPE, "Spanish");
	
}
