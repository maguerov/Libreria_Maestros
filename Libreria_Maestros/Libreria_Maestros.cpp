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

void menuCategorias();
void procesarCategorias(int opcion);

void menuReportes();
void procesarReportes(int opcion);

int opcionMenu;
int nuevoNumero;
int posicion;
L_Libros* l = new L_Libros();
L_Categorias* cat = new L_Categorias();

int main()
{
    test();
    //menu();
    system("Pause");
    return 0;
}



void test() {
 
    Libro *libro = new Libro("Arthur Conan Doyle", 1, "Estudio en Escarlata", 3500, "No agotado", "Editorial Alma", 0, 1887);
    Libro* libro2 = new Libro("Dante Allighieri", 2, "La Divina Comedia", 4500, "No agotado", "Editorial Alma", 3, 1600);
    Libro* libro3 = new Libro("Mary Shelley", 3, "Frankestein", 5500, "No agotado", "Editorial Oceano", 7, 1890);
    Libro* libro4 = new Libro("J.R.R Tolkien", 4, "Silmarillion", 7500, "No agotado", "Editorial Alma", 3, 1928);
    l->agregarInicio(libro);
    l->agregarInicio(libro2);
    l->agregarInicio(libro3);
    l->agregarInicio(libro4);

    l->desplegar();

    cout << "______________ " << endl;
    cout << "______________ " << endl;

    cout << "modificar existencia " << endl;
    l->modificarExistencia(2, 2);
    l->desplegar();
    cout << "______________ " << endl;

    cout << "modificar existencia " << endl;
    l->modificarExistencia(2, 0);
    l->desplegar();
    cout << "______________ " << endl;


    /**
    l->precioInventarioTotal();




  
    int agotados = l->cantidadLibrosAgotados();

    cout << "Libros Agotados: " << agotados << endl;
    cout << "---" << endl;
    cout << "Lista de libros agotados: " << endl;
    l->librosAgotados();

    cout << "---" << endl;
    cout << "Lista de libros no agotados: " << endl;
    l->librosNoAgotados();
   
   */
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
 
   
  /*
    Categoria* categoria = new Categoria("Terror");
    Categoria* categoria2 = new Categoria("Espiritual");
    Categoria* categoria3 = new Categoria("Actualidad");

    cat->agregarInicio(categoria);
    cat->agregarInicio(categoria2);
    cat->agregarInicio(categoria3);

    cat->desplegar();
    
        */

  


}

/*

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
        menuReportes();
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
    cad += "7. Volver al menu principal. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    procesarLibros(opcionMenu);
}

void procesarLibros(int pOpcion)
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
    menuLibros();
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
    cad += "6. Desplegar libros por categoria. \n";
    cad += "7. Volver al menu principal. \n";
    cad += "0. Salir \n";
    cout << cad;
    cout << "\n";
    cin >> opcionMenu;
    procesarCategorias(opcionMenu);
}

void procesarCategorias(int pOpcion)
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
}



*/