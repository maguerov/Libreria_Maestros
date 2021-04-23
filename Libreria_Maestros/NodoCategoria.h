#pragma once
#include <stdlib.h>
#include "iostream"
#include "Categoria.h"
using namespace std;
#ifndef NODOCATEGORIA_H
#define NODOCATEGORIA_H

class NodoCategoria
{
private:
	Categoria* categoria;
	NodoCategoria* sgte;
	L_LibroXCat* lista;
public:
	NodoCategoria();
	~NodoCategoria();
	NodoCategoria(Categoria* categoria);

	Categoria* getCategoria();
	void setCategoria(Categoria* categoria);

	NodoCategoria* getSgte();
	void setSgte(NodoCategoria* nodoCategoria);

	L_LibroXCat* getLista();
	void setLista(L_LibroXCat*);
};
#endif