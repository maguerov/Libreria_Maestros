#include "Categoria.h"
#include "L_LibroXCat.h"
#include <iostream>
using namespace std;

Categoria::Categoria()
{
	this->lista = new L_LibroXCat();
	this->descripcion = "";
}


Categoria::Categoria(string descripcion)
{
	this->descripcion = descripcion;
	this->lista = new L_LibroXCat();
}
Categoria::Categoria(string descripcion, L_LibroXCat* lista)
{
	this->descripcion = descripcion;
	this->lista = lista;
}
Categoria::~Categoria()
{

}
string Categoria::getDescripcion() {
	return this->descripcion;
}
void Categoria::setDescripcion(string pDescripcion) {
	this->descripcion = pDescripcion;
}

L_LibroXCat* Categoria::getLista() {
	return this->lista;
}

void Categoria::setLista(L_LibroXCat* lista) {
	this->lista = lista;
}