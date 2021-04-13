#include "NodoIntermedio.h"
using namespace std;

NodoIntermedio::NodoIntermedio() {
	this->sgte = NULL;
	this->link = NULL;

}
NodoIntermedio::NodoIntermedio(int codigo) {
	this->sgte = NULL;

}
NodoIntermedio::NodoIntermedio(NodoLibro* nodoLibro) {
	this->sgte = NULL;
	this->link = nodoLibro;
}
NodoIntermedio::~NodoIntermedio() {

}
NodoIntermedio* NodoIntermedio::getSgte() {
	if (this->sgte == NULL) {
		return NULL;
	}
	else {
		return this->sgte;
	}
}
void NodoIntermedio::setSgte(NodoIntermedio* sgte) {
	this->sgte = sgte;
}

NodoLibro* NodoIntermedio::getNodoLibro() {
	return this->link;
}
void NodoIntermedio::setNodoLibro(NodoLibro* nodoLibro) {
	this->link = nodoLibro;
}