#include "fecha.h"
#include "servicio.h"
#include "notebook.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;


#endif // TRABAJO_H_INCLUDED
int iniciarTrabajo(eTrabajo listaTrabajos[],int tamTrabajos);
int buscarLibreTrabajo(eTrabajo listaTrabajos[],int tamTrabajos);
int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[],int tamServicios ,eNotebook listaNotebooks [],int tamNotebooks, int *pIdTrabajo, eMarca listaMarcas[], int tamMarcas, eTipo listaTipos[], int tamTipos);
void mostrarTrabajo(eTrabajo unTrabajo, eServicio listaServicios[],int tamServicios);
int mostrarTrabajos(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaServicios[],int tamServicios);
