#pragma once
#include "NodoCategoria.h"

class L_Categorias
{

private:
	NodoCategoria* cat;
	int largo;
public:

	L_Categorias();
	int getLargo();//listo
	void setLargo(int largo);
	NodoCategoria* getCab();//listo
	void setCab(NodoCategoria* cat);//listo
	void desplegar(); //listo
	bool esVacia();//listo
	//void agregarInicio(Categoria* categoria);//listo

	bool eliminar(int id);//listo
	NodoCategoria* dirNodo(int id);//listo
	NodoCategoria* dirUltimo();//listo
	void agregarFinal(Categoria* categoria);//listo
	NodoCategoria* dirAnterior(int id);//listo
    bool modificarCategoria(string descripcion);//listo
	NodoCategoria* buscarCategoria(string descripcion);//listo
	


};

