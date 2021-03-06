#include "L_LibroxCat.h"
#include "L_Categorias.h"
#include "Categoria.h"
#include "NodoCategoria.h"
#include "iostream"
using namespace std;

L_LibroXCat::L_LibroXCat() {
    this->nodoI = NULL;
    this->largo = 0;
};
L_LibroXCat::~L_LibroXCat() {
};
L_LibroXCat::L_LibroXCat(NodoIntermedio* nodoI) {
    this->nodoI = nodoI;
    this->largo = 0;
};

bool L_LibroXCat::esVacia() {
    bool esVacia = false;
    if (getLargo() == 0) {
        esVacia = true;
    }
    return esVacia;
}


int L_LibroXCat::getLargo() {
    return this->largo;
}
void L_LibroXCat::setLargo(int largo) {
    this->largo = largo;
}

NodoIntermedio* L_LibroXCat::getNodoI() {
    return this->nodoI;
}
void L_LibroXCat::setNodoI(NodoIntermedio* nodoI) {
    this->nodoI = nodoI;
}

void L_LibroXCat::agregarLibro(NodoLibro* nodoA) {
    NodoIntermedio* nuevoNodoI = new NodoIntermedio(nodoA);
    if (esVacia())
        this->setNodoI(nuevoNodoI);
    else {
        NodoIntermedio* aux = this->getNodoI();
        while (aux->getSgte() != NULL) {
            aux = aux->getSgte();
        }
        aux->setSgte(nuevoNodoI);
    }
    largo++;
}

void L_LibroXCat::desplegar() {
    NodoIntermedio* aux = this->getNodoI();
    while (aux != NULL) {
        aux->getNodoLibro()->getLibro()->toString();
        aux = aux->getSgte();
    }
}


void L_LibroXCat::desplegarLibros()
{
    // ?
}

// NO SE SI SIRVE - FALTA HACER LA FUNCION DE GETLISTALIBROSCAT
void L_LibroXCat::consultaLibrosCat(int _idCat)
{
    NodoCategoria* aux = L_Categorias().dirNodo(_idCat);
    if (aux != NULL) {
        //aux->getListaLibroCat()->desplegar();
    }

}
