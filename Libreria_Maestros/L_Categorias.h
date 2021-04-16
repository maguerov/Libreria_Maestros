#pragma once
#include "NodoCategoria.h"

class L_Categorias
{

private:
	NodoCategoria* cab;
	int largo;
public:

	L_Categorias();
	int getLargo();
	void setLargo(int largo);
	NodoCategoria* getCab();
	void setCab(NodoCategoria* cab);
	void desplegar();
	bool esVacia();
};

