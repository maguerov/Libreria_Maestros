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

void L_Categorias::agregarInicio(Categoria* categoria)
{
	NodoCategoria* aux = new NodoCategoria(categoria);
	aux->setSgte(getCab());

	setCab(aux);
	setLargo(getLargo() + 1);
}





void L_Categorias::desplegar()
{

	NodoCategoria* aux = getCab();
	while (aux != NULL)
	{
		cout << aux->getCategoria()->getDescripcion()<<endl;
		aux = aux->getSgte();
	}
	cout << "Fin de la lista  " << endl;


}




NodoCategoria* L_Categorias::dirNodo(string descripcion)
{
	NodoCategoria* aux = getCab();
	bool encontrado = false;
	if (aux->getCategoria()->getDescripcion().compare(descripcion) == 0) {
		encontrado = true;
		return aux;
	}
	else
	{
		while (aux->getSgte() != NULL)
		{
			if (aux->getSgte()->getCategoria()->getDescripcion().compare(descripcion) == 0) {
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

NodoCategoria* L_Categorias::dirAnterior(string descripcion)
{
	bool encontrado = false;

	if (cat->getCategoria()->getDescripcion().compare(descripcion) == 0)
	{
		return NULL;
	}
	else
	{
		NodoCategoria* ant = cat;
		while (ant->getSgte() != NULL) {
			if (ant->getSgte()->getCategoria()->getDescripcion().compare(descripcion) == 0)
			{
				return ant;
				encontrado = true;
			}
			ant = ant->getSgte();
		}
	}
	if (encontrado == false)
	{
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

bool L_Categorias::eliminar(string descripcion)
{
	
	bool removido = true;
	NodoCategoria* aux;
	if (!esVacia())

		if (getCab()->getCategoria()->getDescripcion().compare(descripcion) == 0) {
			aux = getCab();
			setCab(aux->getSgte());
			delete aux;
			largo--;
			removido = true;

		}
		else {
			NodoCategoria* ant = dirAnterior(descripcion);
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
