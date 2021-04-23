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
	int idCat;
	string descripcion;
public:
	Categoria();
	Categoria(string);
	Categoria(int,string);
	~Categoria();



	int getIdCat();
	void setIdCat(int);

	string getDescripcion();
	void setDescripcion(string);

};
#endif