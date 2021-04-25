#include "Categoria.h"
#include "L_LibroXCat.h"
#include <iostream>
using namespace std;

Categoria::Categoria()
{
	this->descripcion;
	this->idCat = NULL;
}

Categoria::Categoria(string descripcion)
{
	this->descripcion = descripcion;
}
Categoria::Categoria(int pId, string descripcion)
{
	this->idCat = pId;
	this->descripcion = descripcion;
}
Categoria::~Categoria()
{

}


int Categoria::getIdCat()
{
	return idCat;
}

void Categoria::setIdCat(int _idCat)
{
	this->idCat = _idCat;
}


string Categoria::getDescripcion() {
	return this->descripcion;
}
void Categoria::setDescripcion(string pDescripcion) {
	this->descripcion = pDescripcion;
}
