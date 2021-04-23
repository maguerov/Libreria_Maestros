#pragma once
#include <stdlib.h>
#include <iostream>
#include "NodoLibro.h"
#include "NodoIntermedio.h"
using namespace std;
#ifndef LISTALIBROSXCATEGORIA_H
#define LISTALIBROSXCATEGORIA_H

class L_LibroXCat
{
private:
	int largo;
	int idCat;
	int idLibro;
	NodoIntermedio* sgte;
	NodoLibro* ptrLibro;
	NodoIntermedio* nodoI; 

public:
	L_LibroXCat();
	~L_LibroXCat();
	L_LibroXCat(NodoIntermedio* nodoI);

	int getLargo();
	void setLargo(int);

	bool esVacia();

	NodoIntermedio* getNodoI();
	void setNodoI(NodoIntermedio*);

	void agregarArticulo(NodoLibro*);

	void desplegar();

	void desplegarLibros();
	void consultaLibrosCat(int);
};
#endif