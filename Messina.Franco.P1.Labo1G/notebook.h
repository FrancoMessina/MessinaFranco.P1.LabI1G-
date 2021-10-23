#include "tipo.h"
#include "marca.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
}eNotebook;


#endif // NOTEBOOK_H_INCLUDED
int iniciarNotebooks(eNotebook lista[],int tam);
int buscarLibre(eNotebook lista[], int tam);
int altaNotebook(eNotebook lista[],int tamNotebooks ,int *pId, eTipo tipos[],int tamTipos, eMarca marcas[], int tamMarcas);
void mostrarNotebook(eNotebook unaNotebook ,eMarca marcas[],int tamMarcas, eTipo tipos[],int tamTipos);
int mostrarNotebooks(eNotebook lista[],int tamNotebooks , eMarca marcas[],int tamMarcas, eTipo tipos[],int tamTipos);
int buscarNotebookId(eNotebook lista[], int tam, int Id);
int bajaNotebook(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas, eTipo tipos[],int tamTipos);
int modificarNotebook(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas, eTipo tipos[],int tamTipos);
int menuModificar(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas, eTipo tipos[],int tamTipos, int indice);
int ordenarNotebook(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas);
int validarIdNotebook(int id, eNotebook lista[], int tam);

