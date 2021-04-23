#pragma once
#include <string>
#include <iostream>

using namespace std;
class Libro
{
private:
	string autor;
	int codigo;
	string tituloLibro;
	float precio;
	string estado;//Disponible o agotado
	string editorial;
	int annio;
	int cantInventario;

public:
	Libro(string autor, string tituloLibro, float precio, string editorial, int cantInventario, int annio);
	~Libro();
	Libro();
	string getAutor();
	void setAutor(string nombre);
	int getCodigo();
	void setCodigo(int codigo);
	string getTituloLibro();
	void setTituloLibro(string descripcion);
	float getPrecio();
	void setPrecio(float precio);
	string getEstado();
	void setEstado(string estatus);
	string getEditorial();
	void setEditorial(string editorial);
	int getCantidad();
	void setCantidad(int cantidad);
	int getAnnio();
	void setAnnio(int cantidad);
	void toString();
};