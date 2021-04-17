#pragma once
#include "NodoCategoria.h"

class L_Categorias
{

private:
	NodoCategoria* cat;
	int largo;
public:

	L_Categorias();
	int getLargo();
	void setLargo(int largo);
	NodoCategoria* getCab();
	void setCab(NodoCategoria* cat);
	void desplegar();
	bool esVacia();
	void agregarInicio(Categoria* categoria);

};

