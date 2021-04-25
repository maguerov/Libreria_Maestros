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
	categoria->setIdCat(getLargo() + 1);
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

bool L_Categorias::ModificarCategoria(string descripcion)
{
	//simplificado
	NodoCategoria* aux = getCab();
	string  newDescripcion;
	bool modificado = false;

	if (!esVacia()) {
		while (aux != NULL)
		{
			if (aux->getCategoria()->getDescripcion().compare(descripcion) == 0) {

				cout << "Modificar Categoria" << endl;
				cout << "Id: " << aux->getCategoria()->getIdCat() << endl;
				cout << "Descripcion actual: " << aux->getCategoria()->getDescripcion() << endl;
				cout << "ingrese la nueva descripcion: " << endl;
				cin >> descripcion;
				aux->getCategoria()->setDescripcion(descripcion);
				modificado = true;
			}
			aux = aux->getSgte();
		}
	}
	return modificado;

	/*	NodoCategoria* aux = getCab();
	string  newDescripcion;
	bool modificado = false;

	if (aux->getCategoria()->getDescripcion().compare(descripcion) == 0) {
		
		cout << "Modificar Categoria" << endl;
		cout <<"Id: "<< aux->getCategoria()->getIdCat() << endl;
		cout <<"Descripcion actual: " << aux->getCategoria()->getDescripcion() << endl;
		cout << "ingrese la nueva descripcion: " << endl;
		cin >> newDescripcion;
		aux->getCategoria()->setDescripcion(newDescripcion);
		modificado = true;

	}
	else
	{
		while (aux != NULL)
		{
			if (aux->getCategoria()->getDescripcion().compare(descripcion) == 0) {

				cout << "Modificar Categoria" << endl;
				cout << "Id: " << aux->getCategoria()->getIdCat() << endl;
				cout << "Descripcion actual: " << aux->getCategoria()->getDescripcion() << endl;
				cout << "ingrese la nueva descripcion: " << endl;
				cin >> descripcion;
				aux->getCategoria()->setDescripcion(descripcion);
				modificado = true;
			}
			aux = aux->getSgte();
		}
	}
	return modificado;*/
}



NodoCategoria* L_Categorias::buscarCategoria(string descripcion)
{
	NodoCategoria* aux = getCab();
	NodoCategoria* nodoCategoria = new NodoCategoria();
	bool encontrado = false;
	if (aux->getCategoria()->getDescripcion().compare(descripcion) == 0) {
		encontrado = true;

		nodoCategoria = aux;
	}
	else
	{
		while (aux->getSgte() != NULL)
		{
			if (aux->getSgte()->getCategoria()->getDescripcion().compare(descripcion) == 0) {
				nodoCategoria = aux;
				encontrado = true;
			}
			aux = aux->getSgte();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}
	return nodoCategoria;
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
