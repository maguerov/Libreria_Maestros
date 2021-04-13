#include "NodoLibro.h"

NodoLibro::NodoLibro()
{
	libro = NULL;
	siguiente = NULL;
}

NodoLibro::NodoLibro(Libro* libro)
{
	this->libro = libro;
	siguiente = NULL;
}

Libro* NodoLibro::getLibro()
{
	return libro;
}

void NodoLibro::setLibro(Libro* libro)
{
	this->libro = libro;
}

NodoLibro* NodoLibro::getSiguiente()
{
	return siguiente;
}

void NodoLibro::setSiguiente(NodoLibro* siguiente)
{
	this->siguiente = siguiente;
}
