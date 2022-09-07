#include <iostream>
//#include "stdlib.h"
using namespace std;

class Natural{
	
	int n;
	
	public:
		int getN(void){return n;}
		void setN(int N){if(N>=0)n = N;else n=0;}
		//Natural operator-(Natural N){return N;}
		//Natural operator+(Natural N){return n+N;}
		//Natural operator*(Natural N){return n*N;}
		//Natural operator/(Natural N){return n/N}
		//std::string Mostrar (void);
		Natural Suma (Natural A, Natural B){Natural C; C.setN(A.n+B.n); return C;}
		//~Natural ();
		//Natural (const Natural &);
		//Natural (int);
		Natural(){n = 0;}
};

int main(int argc, char *argv[]) {
	
	Natural numeroA, numeroB, numeroC;
	
	numeroA.setN(6);
	numeroB.setN(12);
	
	cout << "El numero A ingresado es " << numeroA.getN() << endl;
	cout << "El numero B ingresado es " << numeroB.getN() << endl;
	
	
	cout << "La suma de A y B es " << numeroC.Suma(numeroA, numeroB).getN() << endl;
	
	
	return 0;
}

