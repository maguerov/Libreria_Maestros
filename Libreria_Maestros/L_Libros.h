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
	void desplegar();//Sirve
	void agregarInicio(Libro* libro);//Sirve
	bool esVacia();//Sirve
	float precioInventarioTotal();//Sirve
	int cantidadLibrosAgotados();//Sirve
	void librosAgotados();//Sirve
	void librosNoAgotados();//Sirve
	bool modificarExistencia(int codigo, int numero);//Sirve
	bool actualizarPrecio(int porcentaje, int codigo);//Sirve
	bool eliminar(int codigo);//Sirve
	NodoLibro* dirNodo(int codigo);
	NodoLibro* dirAnterior(int codigo);
	NodoLibro* buscarNombre(string titulo);
	Libro* buscarCodigo(int codigo);//Sirve
};
