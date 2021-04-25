// ******************************************** //
// Proyecto de Estructuras de datos 1 - 01/2021
//Elian Rocha
// Daniel Mesen
// Marlon Aguero
// ******************************************** //

#include <iostream>
using namespace std;
#include <stdlib.h>
#include "L_Libros.h"
#include "L_Categorias.h"

void test();
void menu();
void procesarOpcion(int opcion);

void menuLibros();
void procesarLibros(int opcion);
void menuModificarLibro(Libro* libro);
void procesarModificarLibro(Libro* libro, int opcion);

void menuCategorias();
void procesarCategorias(int opcion);

/*
void menuReportes();
void procesarReportes(int opcion);*/


int opcionMenu;
int nuevoNumero;
int posicion;

L_Libros* l = new L_Libros();
NodoLibro* nodoAux;
Libro* libro = new Libro();
char titulo[100], autor[50], editorial[50];
int codigo, anio, cantInventario;
float precio;


L_Categorias* lCat = new L_Categorias();
NodoCategoria* nodoCat = new NodoCategoria();
Categoria* categoria = new Categoria();
char descripcion[50];

int main()
{
    test();
    
    menu();
    system("Pause");
    return 0;
}



void test() {
 

    Libro* libro1 = new Libro("Suzanne Collins", "The Hunger Games", 7500.0, "Scholastic", 3, 1928);
    Libro* libro4 = new Libro("J.R.R Tolkien", "Silmarillion", 7500.0, "Editorial Alma", 3, 1928);
    Libro* libro2 = new Libro("Dante Allighieri", "La Divina Comedia", 4500.0, "Editorial Alma", 3, 1600);

    l->agregarInicio(libro1);
    l->agregarInicio(libro2);
    l->agregarInicio(libro4);

    Categoria* categoria = new Categoria("Terror");
    Categoria* categoria2 = new Categoria("Espiritual");
    Categoria* categoria3 = new Categoria("Actualidad");

    lCat->agregarFinal(categoria);
    lCat->agregarFinal(categoria2);
    lCat->agregarFinal(categoria3);

    /*
   
    l->precioInventarioTotal();

    


  
    int agotados = l->cantidadLibrosAgotados();

    cout << "Libros Agotados: " << agotados << endl;
    cout << "---" << endl;
    cout << "Lista de libros agotados: " << endl;
    l->librosAgotados();

    cout << "---" << endl;
    cout << "Lista de libros no agotados: " << endl;
    l->librosNoAgotados();
   

    cout << "---" << endl;
    cout << "Actualizar precio: " << endl;
    Libro* lib = new Libro();
    cout << "Antes de actualizar: " << endl;
    lib = l->buscarCodigo(1);
    lib->toString();
    l->actualizarPrecio(5, 1);
    cout << "Despues de actualizar: " << endl;
    lib->toString();
    /*
    cout << "---" << endl;
    cout << "Eliminar el libro: " << endl;
    l->eliminar(1);
    l->desplegar();
 
   
 
    cout << "Lista de libros para la categoria dada" << endl;
    cat->buscarCategoria("Terror")->getLista()->desplegar();

    cat->buscarCategoria("Terror")->getLista()->agregarLibro(l->buscarNombre("La Divina Comedia"));
    cout << "Lista de libros para la categoria dada" << endl;

    cat->buscarCategoria("Terror")->getLista()->desplegar();


  //  cat->desplegar();
    /*
    cout<<cat->dirNodo(1)<<endl;
    cout << cat->dirNodo(2) << endl;
    cout << cat->dirNodo(3) << endl;
    */   
    // cat->dirNodo(1)->: busca el nodoCategoria, es decir el puntero en el cual se encuentra la categoria en la que queremos agregar el libro
    //getLista()-: llamar a la sublista que vive dentro del nodoCategoria 
    //->agregarLibro(l->dirNodo(1));: funcion que agrega el libro y recibe el nodoLibro como parametro 
  
    
    /*

    cat->dirNodo(1)->getLista()->agregarLibro(l->dirNodo(1));
    //Crear buscarCategoria(descripcion) que devuelva el NodoCategoria
    cat->dirNodo(1)->getLista()->agregarLibro(l->dirNodo(3));

    cout << "Lista de todas las categorias" << endl;
    cat->desplegar();//La lista de todas las categorias 


    cout << "Lista de libros para la categoria dada" << endl;
    cat->dirNodo(1)->getLista()->desplegar();//La sublista que contiene todos los libros dentro de esta categoria

    

    Categoria* categoria = new Categoria("Terror");
    Categoria* categoria2 = new Categoria("Espiritual");
    Categoria* categoria3 = new Categoria("Actualidad");
    cat->agregarFinal(categoria);
    cat->agregarFinal(categoria2);
    cat->agregarFinal(categoria3);

    cat->desplegar();



  //prueba modificar categoria

    if (cat->ModificarCategoria("Terror")) {

        cout << "Categoria modificada"<<endl;
    }
    else {
        cout << "Categoria no pudo ser modificada" << endl;
    }

    cat->desplegar();

        */

  


}



// Menu principal
void menu()
{
    cout << "\n";
    cout << " *** Libreria Maestros ***" << endl;
    string cad = "";
    cad += "\n";
    cad += "Menu de opciones: \n";
    cad += "1. Menu de libros. \n";
    cad += "2. Menu de categorias. \n";
    cad += "3. Reportes y estadisticas. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    cin.ignore();
    procesarOpcion(opcionMenu);
}
void procesarOpcion(int pOpcion)
{
    switch (pOpcion)
    {

    case 1:
        menuLibros();
        break;

    case 2:
        menuCategorias();
        break;

    case 3:
    //    menuReportes();
        break;

    case 0:
        cout << "Adios" << endl;
        exit;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    cout << "\n";
    system("pause");
    menu();
}

// Menu de libros
void menuLibros()
{
    cout << "\n";
    cout << " *** Libreria Maestros ***" << endl;
    cout << " - Menu de libros -" << endl;
    string cad = "";
    cad += "\n";
    cad += "1. Agregar libro. \n";
    cad += "2. Modificar. \n";
    cad += "3. Modificar existencia. \n";
    cad += "4. Eliminar. \n";
    cad += "5. Desplegar lista de libros. \n";
    cad += "6. Actualizacion automatica de precios. \n";
    cad += "7. Desplegar informacion de un libro. \n";
    cad += "8. Volver al menu principal. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    cin.ignore();
    procesarLibros(opcionMenu);
}

void procesarLibros(int pOpcion)
{
    switch (pOpcion)
    {

    case 1:
        cout << "Digite el titulo o nombre del libro que desea agregar" << endl;
        cin.getline(titulo, 100);
        cin.ignore();
        cout << "Digite el nombre del autor del libro" << endl;
        cin.getline(autor, 50);
        cin.ignore();
        cout << "Digite la editorial a la que pertenece el libro" << endl;
        cin.getline(editorial, 50);
        cin.ignore();
        cout << "Digite el año de publicacion del libro" << endl;
        cin >> anio;
        cout << "Digite el precio del libro" << endl;
        cin >> precio;
        cout << "Digite la cantidad de ejemplares a guardar en el inventario" << endl;
        cin >> cantInventario;

        libro->setTituloLibro(titulo);
        libro->setAutor(autor);
        libro->setEditorial(editorial);
        libro->setAnnio(anio);
        libro->setPrecio(precio);
        libro->setCantidad(cantInventario);
        l->agregarInicio(libro);

        cout << " - Libro agregado -" << endl;
        libro->toString();
        break;

    case 2:
        cout << "Digite el nombre de libro que desea buscar " << endl;
        cin.getline(titulo, 100);
        cin.ignore();

        nodoAux = l->buscarNombre(titulo);
        if (nodoAux !=NULL) {
            menuModificarLibro(nodoAux->getLibro());
        }
        else
        {
            cout << "El libro no existe en la base da datos" << endl;
        }
        break;

    case 3:
        cout << "Digite el nombre de libro que desea actualizar" << endl;
        cin.getline(titulo, 100);
        cin.ignore();

        nodoAux = l->buscarNombre(titulo);
        if (nodoAux != NULL) {
            cout << "Digite la nueva cantidad en el inventario" << endl;
            cin >> cantInventario;

            if (l->modificarExistencia(nodoAux->getLibro()->getCodigo(), cantInventario))
            {
                cout << " - Existencia modificada -" << endl;
                nodoAux->getLibro()->toString();
            }
        }
        else
        {
            cout << "El libro no existe en la base da datos" << endl;
        }
        break;

    case 4:
        cout << "Digite el nombre de libro que desea eliminar" << endl;
        cin.getline(titulo, 100);
        cin.ignore();

        nodoAux = l->buscarNombre(titulo);
        if (nodoAux != NULL) {
            if (l->eliminar(nodoAux->getLibro()->getCodigo()))
            {
                cout << nodoAux->getLibro()->getTituloLibro() << " ha sido eliminado. " << endl;
            }
            else
            {
                cout << "Error. No se ha podido eliminar el libro";
            }
           
        }
        else
        {
            cout << "El libro no existe en la base da datos" << endl;
        }
        break;

    case 5:
        l->desplegar();
        break;

    case 6:
        cout << "Digite el nombre de libro del que desea actualizar el precio" << endl;
        cin.getline(titulo, 100);
        cin.ignore();
        
        nodoAux = l->buscarNombre(titulo);
        if (nodoAux != NULL) {

            cout << "Digite el porcentaje del precio que desea cambiar" << endl;
            cin >> precio;

            if (l->actualizarPrecio(precio, nodoAux->getLibro()->getCodigo()))
            {
                cout << "Precio actualizado con exito" << endl;
                nodoAux->getLibro()->toString();
            }
            else
            {
                cout << "Error. No se ha podido actualizar el precio del libro";
            }
        }
        else
        {
            cout << "El libro no existe en la base da datos" << endl;
        }
        break;

    case 7:
        cout << "Digite el nombre de libro que desea buscar " << endl;
        cin.getline(titulo, 100);
        cin.ignore();
        
        nodoAux = l->buscarNombre(titulo);
        if (nodoAux != NULL) {
            nodoAux->getLibro()->toString();
        }
        else
        {
            cout << "El libro no existe en la base da datos" << endl;
        }
        break;

    case 8:
        menu();
        break;

    case 0:
        cout << "Adios" << endl;
        exit;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    cout << "\n";
    menuLibros();
}

void menuModificarLibro(Libro* pLibro)
{
    cout << "\n";
    cout << " *** Libreria Maestros ***" << endl;
    cout << " - Modificar libro -" << endl;
    pLibro->toString();
    cout << " - - - - - - - - - - - -" << endl;
    string cad = "";
    cad += "\n";
    cad += "1. Modificar titulo. \n";
    cad += "2. Modificar autor. \n";
    cad += "3. Modificar editorial. \n";
    cad += "4. Modificar año. \n";
    cad += "5. Volver al menu de libros. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    cin.ignore();
    procesarModificarLibro(pLibro, opcionMenu);
}

void procesarModificarLibro(Libro* pLibro, int pOpcion)
{
    switch (pOpcion)
    {

    case 1:
        cout << "Digite el nuevo titulo del libro" << endl;
        cin.getline(titulo, 100);
        cin.ignore();
        break;

    case 2:
        cout << "Digite el nuevo autor del libro" << endl;
        cin.getline(autor, 50);
        cin.ignore();
        break;

    case 3:
        cout << "Digite la nueva editorial del libro" << endl;
        cin.getline(editorial, 50);
        cin.ignore();
        break;

    case 4:
        cout << "Digite el año de publicacion del libro" << endl;
        cin >> anio;
        break;

    case 5:
        menuLibros();
        break;

    case 0:
        cout << "Adios" << endl;
        exit;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    cout << "\n";
    menuModificarLibro(pLibro);

}


// Menu categorias
void menuCategorias()
{
    cout << "\n";
    cout << " *** Libreria Maestros ***" << endl;
    cout << "  - Menu de categorias -" << endl;
    string cad = "";
    cad += "\n";
    cad += "1. Agregar categoria. \n";
    cad += "2. Modificar nombre. \n";
    cad += "3. Agregar libro a una categoria. \n";
    cad += "4. Eliminar. \n";
    cad += "5. Desplegar lista de categorias. \n";
    cad += "6. Desplegar libros de una categoria. \n";
    cad += "7. Volver al menu principal. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    cin.ignore();
    procesarCategorias(opcionMenu);
}

void procesarCategorias(int pOpcion)
{
    switch (pOpcion)
    {

    case 1:
        cout << "Digite la descripcion de la categoria que desea agregar" << endl;
        cin.getline(descripcion, 50);
        cin.ignore();
        categoria->setDescripcion(descripcion);
        lCat->agregarFinal(categoria);
        cout << " - Categoria agregada - " << endl;
        lCat->buscarCategoria(categoria->getDescripcion())->toString();
        break;

    case 2:
        cout << "Digite la descripcion de la categoria que desea modidicar" << endl;
        cin.getline(descripcion, 50);
        cin.ignore();
        nodoCat = lCat->buscarCategoria(descripcion);

        if (nodoCat != NULL) {
            cout << "Digite la nueva descripcion para la categoria" << endl;
            cin.getline(descripcion, 50);
            cin.ignore();
            nodoCat->getCategoria()->setDescripcion(descripcion);
            if (lCat->ModificarCategoria(nodoCat->getCategoria()->getDescripcion())) {
                cout << " - Categoria modificada - " << endl;
                nodoCat->toString();
            }
            else
            {
                cout << "Error. No se pudo actualizar la categoria";
            }
        }
        else
        {
            cout << "La categoria ingresada no existe en la base de datos";
        }
        break;

    case 3:
        cout << "Digite la categoria a la que desea agregar un libro" << endl;
        cin.getline(descripcion, 50);
        cin.ignore();
        nodoCat = lCat->buscarCategoria(descripcion);

        if (nodoCat != NULL)
        {
            cout << "Digite el nombre del libro que desea agregar a la categoria" << endl;
            cin.getline(titulo, 100);
            cin.ignore();

            nodoAux = l->buscarNombre(titulo);
            if (nodoAux != NULL)
            {
                nodoCat->getLista()->agregarLibro(nodoAux);
                cout << " - El libro ha sido agregado a la categoria - ";
            }
        }
        else
        {
            cout << "La categoria ingresada no existe en la base de datos";
        }



        break;

    case 4:
        cout << "Digite la categoria que desea eliminar" << endl;
        cin.getline(descripcion, 50);
        cin.ignore();
        nodoCat = lCat->buscarCategoria(descripcion);

        if (nodoCat != NULL)
        {
            if (lCat->eliminar(nodoCat->getCategoria()->getIdCat())) {
                cout << "La categoria - " << descripcion << " - ha sido eliminada" << endl;
            }
            else
            {
                cout << "Error. No se ha podido eliminar la categoria." << endl;
            }
            
        }
        else
        {
            cout << "La categoria ingresada no existe" << endl;
        }
        break;

    case 5:
        lCat->desplegar();
        break;

    case 6:
        cout << "Digite la categoria que desea consultar" << endl;
        cin.getline(descripcion, 50);
        cin.ignore();
        nodoCat = lCat->buscarCategoria(descripcion);

        if (nodoCat != NULL)
        {
            if (nodoCat->getLista()->getLargo() > 0)
            {
                nodoCat->getLista()->desplegar();
            }
            else
            {
                cout << " - No existen libros dentro de esta categoria - " << endl;
            }
            
        }
        else
        {
            cout << "La categoria ingresada no existe" << endl;
        }
        break;

    case 7:
        menu();
        break;

    case 0:
        cout << "Adios" << endl;
        exit;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    cout << "\n";
    system("pause");
    menuCategorias();
}

/*
// Menu reportes
void menuReportes()
{
    cout << "\n";
    cout << " *** Libreria Maestros ***" << endl;
    cout << "  - Menu de reportes -" << endl;
    string cad = "";
    cad += "\n";
    cad += "1. Precio total del inventario existente. \n";
    cad += "2. Cantidad de libros con existencia en cero. \n";
    cad += "3. Lista detallada de los libros agotados. \n";
    cad += "4. Lista detallada de libros no agotados.. \n";
    cad += "5. Desplegar lista de libros con todos sus detalles. \n";
    cad += "6. Desplegar lista de categorías. \n";
    cad += "7. Desplegar los libros de una categoría específica. (Muestra todo el detalle del libro) \n";
    cad += "8. Volver al menu principal. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    procesarReportes(opcionMenu);
}

void procesarReportes(int pOpcion)
{
    switch (pOpcion)
    {

    case 1:

        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;

    case 6:

        break;

    case 7:

        break;

    case 8:
        menu();
        break;

    case 0:
        cout << "Adios" << endl;
        exit;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    cout << "\n";
    system("pause");
    menuReportes();
}*/