#pragma once
#include "Libro.h"
class NodoLibro
{

	private:
		Libro* libro;
		NodoLibro* siguiente;
	public:
		NodoLibro();
		NodoLibro(Libro* articulo);
		Libro* getLibro();
		void setLibro(Libro* articulo);
		NodoLibro* getSiguiente();
		void setSiguiente(NodoLibro* siguiente);


};

