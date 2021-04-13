#include "NodoCategoria.h"

NodoCategoria::NodoCategoria() {
    this->categoria = new Categoria();
    this->sgte = NULL;
}

NodoCategoria::~NodoCategoria() {

}

NodoCategoria::NodoCategoria(Categoria* categoria) {
    this->categoria = categoria;
    this->sgte = NULL;
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
