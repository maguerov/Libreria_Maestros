#include "Categoria.h"
#include "L_LibroXCat.h"
#include <iostream>
using namespace std;

Categoria::Categoria()
{
	this->lista = new L_LibroXCat();
	this->descripcion = "";
	this->idCat = NULL;
}

Categoria::Categoria(int pId,string descripcion)
{
	this->idCat = pId;
	this->descripcion = descripcion;
	this->lista = new L_LibroXCat();
}
Categoria::Categoria(int pId, string descripcion, L_LibroXCat* lista)
{
	this->idCat = pId;
	this->descripcion = descripcion;
	this->lista = lista;
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

L_LibroXCat* Categoria::getLista() {
	return this->lista;
}

void Categoria::setLista(L_LibroXCat* lista) {
	this->lista = lista;
}
