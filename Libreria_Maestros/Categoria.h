#pragma once
#include <stdlib.h>
#include <iostream>
#include "L_LibroXCat.h"
using namespace std;
#ifndef CATEGORIA_H
#define CATEGORIA_H

class Categoria
{
private:
	string descripcion;
	L_LibroXCat* lista;
public:
	Categoria();
	Categoria(string);
	Categoria(string, L_LibroXCat*);
	~Categoria();

	L_LibroXCat* getLista();
	void setLista(L_LibroXCat*);

	string getDescripcion();
	void setDescripcion(string);
};
#endif