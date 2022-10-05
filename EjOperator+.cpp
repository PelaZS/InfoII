#include <iostream>
using namespace std;

class Numero{
	
	int n;
	
public:
	
	Numero(int num = 0){n = num;};
	int getN(){return n;};
	Numero operator+ (const Numero) const;	
};

Numero Numero::operator+ (const Numero sumando) const {
	
	Numero resultado;
	
	resultado.n = n + sumando.n;
	
	return resultado;
}

int main(int argc, char *argv[]) {
	
	Numero n1(1), n2(2), n3;
	
	n3 = n1 + n2;
	
	cout << n1.getN() << " + " << n2.getN() << " = " << n3.getN();
	
	return 0;
}
