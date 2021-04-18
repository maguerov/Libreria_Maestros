#include "L_Libros.h"

L_Libros::L_Libros()
{
	cab = NULL;
	largo = 0;
}


int L_Libros::getLargo()
{
	return largo;
}

void L_Libros::setLargo(int largo)
{
	this->largo = largo;
}

NodoLibro* L_Libros::getCab()
{
	return cab;
}

void L_Libros::setCab(NodoLibro* cab)
{
	this->cab = cab;
}

void L_Libros::desplegar()
{
	NodoLibro* aux = cab;
	while (aux != NULL)
	{
		aux->getLibro()->toString();
		aux = aux->getSiguiente();
	}
}

void L_Libros::agregarInicio(Libro* libro)
{
	NodoLibro* aux = new NodoLibro(libro);
	aux->setSiguiente(cab);
	setCab(aux);
	setLargo(getLargo() + 1);
}


bool L_Libros::esVacia()
{
	if (largo < 1)
		return true;
	return false;
}

void L_Libros::precioInventarioTotal()
{
	if (!esVacia()) {
		NodoLibro* aux = cab;
		int precioIn = 0;
		while (aux->getSiguiente() != NULL) {
			if (aux->getLibro()->getCantidad() != 0)
				precioIn += aux->getLibro()->getPrecio();
			aux = aux->getSiguiente();
		}
		cout << "Precio del inventario es de: " << precioIn << endl;
	}
}

int L_Libros::cantidadLibrosAgotados()
{
	int agotados = 0;
	if (!esVacia()) {
		NodoLibro* aux = cab;
		while (aux != NULL) {
			if (aux->getLibro()->getCantidad() == 0) {
				agotados++;
			}
			aux = aux->getSiguiente();
		}
	}
	return agotados;
}

void L_Libros::librosAgotados()
{
	if (!esVacia()) {
		NodoLibro* aux = cab;
		while (aux != NULL) {
			if (aux->getLibro()->getCantidad() == 0)
				aux->getLibro()->toString();
			aux = aux->getSiguiente();
		}
	}
}

void L_Libros::librosNoAgotados()
{
	if (!esVacia()) {
		NodoLibro* aux = cab;
		while (aux != NULL) {
			if (aux->getLibro()->getCantidad() != 0)
				aux->getLibro()->toString();
			aux = aux->getSiguiente();
		}
	}
}

bool L_Libros::actualizarPrecio(int porcentaje, int codigo)
{
	bool encontrado = false;
	Libro* libro = buscarCodigo(codigo);
	if (libro->getCodigo()!=NULL) {
		double diferencia = (porcentaje * libro->getPrecio()) / 100;
		libro->setPrecio(libro->getPrecio() + diferencia);
		encontrado = true;
	}

	return encontrado;
}

bool L_Libros::eliminar(int codigo)
{
	bool removido = true;
	NodoLibro* aux;
	if (!esVacia())

		if (getCab()->getLibro()->getCodigo() == codigo) {
			aux = getCab();
			setCab(aux->getSiguiente());
			delete aux;
			largo--;
			removido = true;

		}
		else {
			NodoLibro* ant = dirAnterior(codigo);
			if (ant != NULL) {
				aux = ant->getSiguiente();
				ant->setSiguiente(aux->getSiguiente());
				delete aux;
				largo--;
				removido = true;
			}

		}

	return removido;
}

NodoLibro* L_Libros::dirNodo(int codigo)
{
	NodoLibro* aux = getCab();
	bool encontrado = false;
	if (aux->getLibro()->getCodigo() == codigo) {
		encontrado = true;
		return aux;
	}
	else
	{
		while (aux->getSiguiente() != NULL)
		{
			if (aux->getSiguiente()->getLibro()->getCodigo() == codigo) {
				return aux->getSiguiente();
				encontrado = true;
			}
			aux = aux->getSiguiente();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}
}

NodoLibro* L_Libros::dirAnterior(int codigo)
{
	bool encontrado = false;

	if (cab->getLibro()->getCodigo() == codigo)
	{
		return NULL;
	}
	else
	{
		NodoLibro* ant = cab;
		while (ant->getSiguiente() != NULL) {
			if (ant->getSiguiente()->getLibro()->getCodigo() == codigo)
			{
				return ant;
				encontrado = true;
			}
			ant = ant->getSiguiente();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}
}

void L_Libros::buscarNombre(string nombre)
{
	NodoLibro* aux = getCab();
	bool encontrado = false;
	if (aux->getLibro()->getTituloLibro() == nombre) {
		encontrado = true;
		aux->getLibro()->toString();
	}
	else
	{
		while (aux->getSiguiente() != NULL)
		{
			if (aux->getSiguiente()->getLibro()->getTituloLibro() == nombre) {
				aux->getLibro()->toString();
				encontrado = true;
			}
			aux = aux->getSiguiente();
		}
	}
	if (encontrado == false)
	{
		cout << "Libro no encontrado" << endl;
	}
}

Libro *L_Libros::buscarCodigo(int codigo)
{
	NodoLibro* aux = getCab();
	Libro *lib = new Libro();
	bool encontrado = false;
	if (aux->getLibro()->getCodigo() == codigo) {
		encontrado = true;
		aux->getLibro()->toString();
	}
	else
	{
		while (aux->getSiguiente() != NULL)
		{
			if (aux->getSiguiente()->getLibro()->getCodigo() == codigo) {
				lib = aux->getLibro();
				encontrado = true;
			}
			aux = aux->getSiguiente();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}

	return lib;
}
