#pragma once
#include "NodoLibro.h"
class L_Libros
{
private:
	NodoLibro* cab;
	int largo;
public:
	L_Libros();
	int getLargo();
	void setLargo(int largo);
	NodoLibro* getCab();
	void setCab(NodoLibro* cab);
	void desplegar();
	void agregarInicio(Libro* libro);
	bool esVacia();
	void precioInventarioTotal();
	int cantidadLibrosAgotados();
	void librosAgotados();
	void librosNoAgotados();
	void actualizarPrecio(int porcentaje);
	bool eliminar(int codigo);
	NodoLibro* dirNodo(int codigo);
	NodoLibro* dirAnterior(int codigo);
	void buscarNombre(string titulo);
	void buscarCodigo(int codigo);
};
