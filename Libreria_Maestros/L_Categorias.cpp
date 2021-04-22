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




