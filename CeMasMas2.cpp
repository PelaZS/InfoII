#include <iostream>
//#include "stdlib.h"
using namespace std;

class Natural{
	
	int n;
	
	public:
		int getN(void);
		void setN(int);
		Natural operator-(Natural N);
		//Natural operator+(Natural N){return n+N;}
		//Natural operator*(Natural N){return n*N;}
		//Natural operator/(Natural N){return n/N}
		//std::string Mostrar (void);
		Natural Suma (Natural, Natural);
		//~Natural ();
		Natural (const Natural &);
		Natural (int);
		Natural();
};

int Natural::getN(void){

	return n;
}

void Natural::setN(int N){

	if(N>=0)
		n = N;
	else
		n=0;
}

Natural Natural::Suma(Natural A, Natural B){

	Natural C;
	
	C.setN(A.n+B.n);
	
	return C;
}

Natural::Natural(){

	n = 0;
}

Natural::Natural(const Natural &N){
	
	n = N.n;
}

Natural::Natural(int N){
	
	n = N;
}

Natural Natural::operator-(Natural N){
	
	Natural Resultado;
	
	Resultado.n = n - N.n;
		
	return Resultado;
}

int main(int argc, char *argv[]) {
	
	Natural numeroA;
	numeroA.setN(5);
	
	Natural numeroB(2);	
	Natural numeroC = numeroB;
	Natural numeroAux;
		
	cout << "El numero A ingresado es " << numeroA.getN() << endl;
	cout << "El numero B ingresado es " << numeroB.getN() << endl;
	cout << "El numero C ingresado es " << numeroC.getN() << endl;
	
	cout << "La suma de A y B es " << numeroAux.Suma(numeroA, numeroB).getN() << endl;
	
	numeroAux = numeroA - numeroB;
	
	cout << "A - B = " << numeroAux.getN() << endl;
	
	return 0;
}
