#include "clientes.h"
#include "consumos.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define nomArchivo "clientes.dat"
#define backupClientes "backupArchivo.dat"
#define nomArchiConsumos "consumos.dat"
#define ANIO 2021
#include "listaConsumo.h"

nodoLista* inicLista(){
    return NULL;
}

nodoLista* crearNodoLista(stConsumos dato){
    nodoLista* nuevo = (nodoLista*)malloc(sizeof(nodoLista));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

void muestraLista(nodoLista* lista){
    nodoLista* aux = lista;
    while(aux){
        muestraNodo(aux);
        aux = aux->sig;
    }
}

void muestraNodo(nodoLista* nodo){
    muestraUnConsumo(nodo->dato);

}
nodoLista* agregarEnOrdenPorID(nodoLista* lista, nodoLista* nuevoNodo){
    if(!lista){   /// if(lista==NULL)
        lista=nuevoNodo;
    }else{
        if(nuevoNodo->dato.id <= lista->dato.id){
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg != NULL && nuevoNodo->dato.id => seg->dato.id){
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }

    return lista;
}

nodoLista* archivo2lista(nodoLista* lista, char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    stConsumos e;
    if(archi){
        while(fread(&e, sizeof(stConsumos), 1, archi)>0){
                nodo *nuevo = crearNodoLista(e);
                ///lista = agregarAlFinal(lista, nuevo);
                ///lista = agregarAlPrincipio(lista, nuevo);
                lista = agregarEnOrdenPorID(lista, nuevo);

        }
        fclose(archi);
    }

    return lista;
}
