#pragma once
#include <stdlib.h>
#include <iostream>
#include "NodoLibro.h"
using namespace std;
#ifndef NODOINTERMEDIO_H
#define NODOINTERMEDIO_H

class NodoIntermedio
{
private:
	NodoIntermedio* sgte;
	NodoLibro* link;
public:
	NodoIntermedio();
	NodoIntermedio(int codigo);
	NodoIntermedio(NodoLibro* nodoLibro);
	~NodoIntermedio();

	NodoIntermedio* getSgte();
	void setSgte(NodoIntermedio* nodoLibro);

	NodoLibro* getNodoLibro();
	void setNodoLibro(NodoLibro* nodoLibro);
};
#endif