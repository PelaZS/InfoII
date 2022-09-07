#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

struct alumno
{
 int legajo;
 char nombre[20];
 char sexo;
 float prom;
 int faltas;
};

typedef struct alumno Alumno;

struct nodoArbol
{
 struct nodoArbol *ptrIzq;
 Alumno dato;
 struct nodoArbol *ptrDer;
};

typedef struct nodoArbol NodoArbol;
typedef NodoArbol *ptrNodoArbol;

void insertarNodo(ptrNodoArbol *ptrArbol, Alumno alumnoNuevo);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);


int main(void) {
 
 ptrNodoArbol ptrRaiz = NULL;
 
 puts("\nCargar alumnos en el arbol:\n");
 
 for ( int i = 1; i <= 3; ++i) {
   
  Alumno alumnoCargar;
  
  int legajo;
  char sexo;
  float prom;
  int faltas;
  
  do{
  printf("Ingrese el legajo del alumno %d: ", i);
  scanf("%d", &legajo);
  }while(legajo < 0);
  
  alumnoCargar.legajo = legajo;
  
  printf("Ingrese el nombre del alumno %d (sin espacios): ", i);
  scanf("%s", alumnoCargar.nombre);
  
  do{
  printf("Ingrese el sexo del alumno %d (M/F): ", i);
  scanf(" %c", &sexo);
  }while((sexo != 'M') && (sexo != 'F'));
  
  alumnoCargar.sexo = sexo;
  
  do{
  printf("Ingrese el prom del alumno %d: ", i);
  scanf("%f", &prom);
  }while(prom < 0.0 || prom > 10.0);
  
  alumnoCargar.prom = prom;
  
  do{
  printf("Ingrese el numero de faltas del alumno %d: ", i);
  scanf("%d", &faltas);
  }while(faltas < 0);
  
  alumnoCargar.faltas = faltas;
  
  insertarNodo(&ptrRaiz, alumnoCargar);

  printf("\n");
 }
 
 printf("Recorrido en orden:\n");
 inOrden(ptrRaiz);
 
 printf("\nRecorrido en pre orden:\n");
 preOrden(ptrRaiz);
 
 printf("\nRecorrido en post orden:\n");
 postOrden(ptrRaiz);
 
 printf("\n");
 
 return 0;
}

void insertarNodo(ptrNodoArbol *ptrArbol, Alumno alumnoNuevo){

 if(*ptrArbol == NULL){
  
  *ptrArbol = malloc(sizeof(NodoArbol));
  
  if(*ptrArbol != NULL){
  
   (*ptrArbol)->dato = alumnoNuevo;
   (*ptrArbol)->ptrDer = NULL;
   (*ptrArbol)->ptrIzq = NULL;
   
  }else{
  
   printf("No hay memoria disponible. \n");
   }
   
  }else{

   if (alumnoNuevo.legajo < (*ptrArbol)->dato.legajo){
    insertarNodo(&((*ptrArbol)->ptrIzq),alumnoNuevo);
    }else
     if (alumnoNuevo.legajo > (*ptrArbol)->dato.legajo){
      insertarNodo(&((*ptrArbol)->ptrDer),alumnoNuevo);
      
      }else
       printf("Valor ya existente.\n");
     }
}

void inOrden(ptrNodoArbol ptrArbol){

 if (ptrArbol != NULL) {
 
  inOrden(ptrArbol->ptrIzq);
  
  printf("\nLegajo: %6d \n", ptrArbol->dato.legajo);
  printf("Nombre: %s \n", ptrArbol->dato.nombre);
  
  if(ptrArbol->dato.sexo == 'F')
   printf("Sexo: Femenino \n");
  else
   printf("Sexo: Masculino \n");
   
  printf("Prom: %.2f \n", ptrArbol->dato.prom);
  printf("Faltas: %d \n", ptrArbol->dato.faltas);
  
  inOrden(ptrArbol->ptrDer);
  }
}

void preOrden(ptrNodoArbol ptrArbol){

 if (ptrArbol != NULL) {
  
  printf("\nLegajo: %6d \n", ptrArbol->dato.legajo);
  printf("Nombre: %s \n", ptrArbol->dato.nombre);
  
  if(ptrArbol->dato.sexo == 'F')
   printf("Sexo: Femenino \n");
  else
   printf("Sexo: Masculino \n");
   
  printf("Prom: %.2f \n", ptrArbol->dato.prom);
  printf("Faltas: %d \n", ptrArbol->dato.faltas);
  
  preOrden(ptrArbol->ptrIzq);
  preOrden(ptrArbol->ptrDer);
  }
}

void postOrden(ptrNodoArbol ptrArbol){

 if (ptrArbol != NULL) {
  postOrden(ptrArbol->ptrIzq);
  postOrden(ptrArbol->ptrDer);
  
  printf("\nLegajo: %6d \n", ptrArbol->dato.legajo);
  printf("Nombre: %s \n", ptrArbol->dato.nombre);
  
  if(ptrArbol->dato.sexo == 'F')
   printf("Sexo: Femenino \n");
  else
   printf("Sexo: Masculino \n");
   
  printf("Prom: %.2f \n", ptrArbol->dato.prom);
  printf("Faltas: %d \n", ptrArbol->dato.faltas);
  }
}
