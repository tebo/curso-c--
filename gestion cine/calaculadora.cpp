#include <iostream>
#include <limits>
using namespace std;
	int main(){
		double num1;
		double num2;
		char operacion;
		cout<<"==== CALCULADORA ===="<<endl;
		cout<<"==OPERACIONES BASICAS=="<<endl;
		cout <<"ingresa el primer numero: ";
		cin>>num1;
		
		while (cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			cout<<"ERROR. No es un numero. intenta otra vez: ";
			cin>>num1;
		}
		
		cout<<"ingresa que operacion deseas (+,-,*,/): ";
		cin>>operacion;
		
		while (operacion != '+' && operacion != '-' && operacion != '*' && operacion != '/'){
		cout<<"operacion no valida elija (+,-,*,/): ";
		cin>>operacion;
		}
		
		cout<<"ingresa el segundo numero: ";
		cin>>num2;
		while(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>:: max() , '\n');
			
			cout<<"ERROR. ingrese un numero intente otra vez: ";
			cin>> num2;
		}
		
		if (operacion == '+'){
		cout <<"El resultado: " <<num1 + num2 << endl;
		}
		else if (operacion == '-'){
			cout <<"El resultado: "<<num1-num2<<endl;	
		}
		else if (operacion == '*'){
			cout <<"El resultado: "<<num1*num2<<endl;
		}
		else if (operacion == '/'){
			if( num2 != 0)
			cout <<"El resultado: "<<num1/num2<<endl;
		
		else {
			cout <<"Error: no se puede dividir entre cero. "<<endl;		
			}
		}
		else {
			cout <<"la operacion no es valida."<<endl;
		}
		return 0;
	}
