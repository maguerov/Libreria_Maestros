#include "NodoCategoria.h"

NodoCategoria::NodoCategoria() {
  categoria = NULL;
   sgte = NULL;
   lista = new L_LibroXCat();
}

NodoCategoria::~NodoCategoria() {
    this->categoria = NULL;
    sgte = NULL;
    lista = new L_LibroXCat();
}

NodoCategoria::NodoCategoria(Categoria* categoria) {
    this->categoria = categoria;
    this->sgte = NULL;
    this->lista = new L_LibroXCat();
}

Categoria* NodoCategoria::getCategoria() {
    return this->categoria;
}

void NodoCategoria::setCategoria(Categoria* categoria) {
    this->categoria = categoria;
}

void NodoCategoria::setSgte(NodoCategoria* nodoCategoria) {
    this->sgte = nodoCategoria;
}

NodoCategoria* NodoCategoria::getSgte() {
    return this->sgte;
}

L_LibroXCat* NodoCategoria::getLista() {
    return this->lista;
}

void NodoCategoria::setLista(L_LibroXCat* lista) {
    this->lista = lista;
}
