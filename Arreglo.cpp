 #include <iostream>

using namespace std;

class Arreglo{
	
	int *p;
	int Tam;
	
public:
	
		int Num;
		Arreglo(int t=10);
		~Arreglo();
		int getTam(void);
};

Arreglo::Arreglo(int t){
	
	Tam = t;
	
	p = new int[t];
		if (p == NULL)
		Tam = 0;
}

Arreglo::~Arreglo(){
	
	delete[]p;
}

Arreglo::getTam(void){
	
	return Tam;
}

int main(void){
	
	return 0;
}
