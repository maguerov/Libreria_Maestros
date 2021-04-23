#include "Libro.h"

Libro::Libro(string autor, string tituloLibro, float precio, string editorial, int cantInventario, int annio)
{
	this->autor = autor;
	this->tituloLibro = tituloLibro;
	this->precio = precio;
	this->editorial = editorial;
	this->cantInventario = cantInventario;
	this->annio = annio;
}

Libro::~Libro()
{
	
}

Libro::Libro()
{
	this->autor = "";
	this->codigo = NULL;
	this->tituloLibro = "";
	this->precio = NULL;
	this->estado = "";
	this->editorial = "";
	this->cantInventario = NULL;
	this->annio = NULL;
}

string Libro::getAutor()
{
	return autor;
}

void Libro::setAutor(string nombre)
{
	this->autor = nombre;
}

int Libro::getCodigo()
{
	return codigo;
}

void Libro::setCodigo(int codigo)
{
	this->codigo = codigo;
}

int Libro::getAnnio()
{
	return annio;
}

void Libro::setAnnio(int codigo)
{
	this->annio = codigo;
}

string Libro::getTituloLibro()
{
	return tituloLibro;
}

void Libro::setTituloLibro(string descripcion)
{
	this->tituloLibro = descripcion;
}

float Libro::getPrecio()
{
	return precio;
}

void Libro::setPrecio(float precio)
{
	this->precio = precio;
}

string Libro::getEstado()
{
	return estado;
}

void Libro::setEstado(string estatus)
{
	this->estado = estatus;
}

string Libro::getEditorial()
{
	return editorial;
}

void Libro::setEditorial(string editorial)
{
	this->editorial = editorial;
}

int Libro::getCantidad()
{
	return cantInventario;
}

void Libro::setCantidad(int cantidad)
{
	this->cantInventario = cantidad;
	if (cantidad == 0)
		setEstado("Agotado");
}

void Libro::toString()
{
	cout << "Autor: " << autor << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Titulo del libro: " << tituloLibro << endl;
	cout << "Precio: " << precio << endl;
	cout << "Estado: " << estado << endl;
	cout << "Cantidad en inventario: " << cantInventario << endl;
}
