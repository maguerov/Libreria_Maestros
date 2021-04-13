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
	int cantidad;
	string editorial;
	int annio;
	int cantInventario;

public:
	Libro(string autor, int codigo, string tituloLibro, float precio, string estado, string editorial, int cantInventario, int annio);
	~Libro();
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
	int getCantidad();
	void setCantidad(int cantidad);
	int getAnnio();
	void setAnnio(int cantidad);
	void toString();
};