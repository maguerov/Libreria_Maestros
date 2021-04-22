#include "L_Categorias.h"


L_Categorias::L_Categorias()
{
	cat = NULL;
	largo = 0;
}

bool L_Categorias::esVacia()
{
	if (largo < 1)
		return true;
	return false;
}


int L_Categorias::getLargo()
{
	return largo;
}

void L_Categorias::setLargo(int largo)
{
	this->largo = largo;
}

NodoCategoria* L_Categorias::getCab()
{
	return cat;
}

void L_Categorias::setCab(NodoCategoria* cat)
{
	this->cat = cat;
}



/*
void L_Categorias::agregarFinal(Categoria* categoria)
{
	NodoCategoria* aux = new NodoCategoria(categoria);
	aux->setSgte(getCab());

	setCab(aux);
	setLargo(getLargo() + 1);
}*/


NodoCategoria* L_Categorias::dirUltimo()
{
	NodoCategoria* ult = getCab();

	if (!esVacia()) {
		while (ult->getSgte() != NULL) {
			ult = ult->getSgte();
		}
	}
	else {
		ult = NULL;
	}
	return ult;
	
}

void L_Categorias::agregarFinal(Categoria* categoria)
{
	NodoCategoria* aux = new NodoCategoria(categoria);

	if (esVacia()) {
		setCab(aux);
		setLargo(getLargo() + 1);
	}
	else {
		dirUltimo()->setSgte(aux);
	}
	setLargo(getLargo() + 1);
	

}





void L_Categorias::desplegar()
{

	NodoCategoria* aux = getCab();
	while (aux != NULL)
	{
		cout << aux->getCategoria()->getIdCat()<<" "<< aux->getCategoria()->getDescripcion()<<endl;
		aux = aux->getSgte();
	}
	cout << "Fin de la lista  " << endl;
}


NodoCategoria* L_Categorias::dirNodo(int _idCat)
{
	NodoCategoria* aux = getCab();
	bool encontrado = false;
	if (aux->getCategoria()->getIdCat() == _idCat) {
		encontrado = true;
		return aux;
	}
	else
	{
		while (aux->getSgte() != NULL)
		{
			if (aux->getSgte()->getCategoria()->getIdCat() == _idCat) {
				return aux->getSgte();
				encontrado = true;
			}
			aux = aux->getSgte();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}
}




NodoCategoria* L_Categorias::dirAnterior(int pId)
{

	bool encontrado = false;
	NodoCategoria* ant = getCab();

	if (!esVacia()) {

		while (ant->getSgte() != NULL && !encontrado) {
			if (ant->getSgte()->getCategoria()->getIdCat() == pId) {
				encontrado = true;
			}
			else {
				ant = ant->getSgte();
			}
		}
	}
	if (encontrado) {
		return ant;
	}
	else {
		return NULL;
	}
}

Categoria* L_Categorias::buscarCategoria(string descripcion)
{
	NodoCategoria* aux = getCab();
	Categoria* categoria = new Categoria();
	bool encontrado = false;
	if (aux->getCategoria()->getDescripcion().compare(descripcion) == 0) {
		encontrado = true;

		categoria = aux->getCategoria();
		//cout << "Categoria: " << aux->getCategoria()->getDescripcion();
	}
	else
	{
		while (aux->getSgte() != NULL)
		{
			if (aux->getSgte()->getCategoria()->getDescripcion().compare(descripcion) == 0) {
				categoria = aux->getCategoria();
				encontrado = true;
			}
			aux = aux->getSgte();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}

	return categoria;
}

bool L_Categorias::eliminar(int pId)
{
	
	bool removido = true;
	NodoCategoria* aux;
	if (!esVacia())

		if (getCab()->getCategoria()->getIdCat()==pId) {
			aux = getCab();
			setCab(aux->getSgte());
			delete aux;
			largo--;
			removido = true;

		}
		else {
			NodoCategoria* ant = dirAnterior(pId);
			if (ant != NULL) {
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				delete aux;
				largo--;
				removido = true;
			}

		}

	return removido;
}
