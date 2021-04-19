#pragma once
#include "NodoCategoria.h"

class L_Categorias
{

private:
	NodoCategoria* cat;
	int largo;
public:

	L_Categorias();
	int getLargo();//listo
	void setLargo(int largo);
	NodoCategoria* getCab();//listo
	void setCab(NodoCategoria* cat);//listo
	void desplegar(); //listo
	bool esVacia();//listo
	void agregarInicio(Categoria* categoria);//listo
	
	NodoCategoria* dirNodo(string descripcion);
	NodoCategoria* dirAnterior(string descripcion);
};

