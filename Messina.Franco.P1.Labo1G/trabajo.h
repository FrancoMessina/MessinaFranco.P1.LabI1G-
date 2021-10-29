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
/** \brief Iniciar los trabajos en isEmpty = 1 para que se puedan cargar los datos
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien.
 *
 */

int iniciarTrabajo(eTrabajo listaTrabajos[],int tamTrabajos);
/** \brief Busca un indice libre en el array de trabajos si es que hay espacio
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */

int buscarLibreTrabajo(eTrabajo listaTrabajos[],int tamTrabajos);
/** \brief Dar de alta un trabajo con todos sus datos respectivos
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */
int altaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos, eServicio listaServicios[],int tamServicios ,eNotebook listaNotebooks [],int tamNotebooks, int *pIdTrabajo, eMarca listaMarcas[], int tamMarcas, eTipo listaTipos[], int tamTipos);
/** \brief Mostrar un trabajo con todos sus datos
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */
int mostrarTrabajo(eTrabajo unTrabajo, eServicio listaS[],int tamS, eMarca listaM[],int tamM, eTipo listaT[], int tamT, eNotebook listaN[], int tamN);
/** \brief Mostrar todas los trabajos  que hay cargados en el sistema
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */
int mostrarTrabajos(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaS[],int tamS, eMarca listaM[],int tamM, eTipo listaT[], int tamTipos, eNotebook listaN[], int tamN);
//Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.
int mostrarTrabajosNotebook(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaS[],int tamS,
                     eMarca listaM[],int tamM, eTipo listaT[], int tamTipos, eNotebook listaN[], int tamN);
//Pedir un notebook e informar la suma de los importes de los servicios se le hicieron a la misma.
int montoTrabajosNotebook(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaS[],int tamS,
                     eMarca listaM[],int tamM, eTipo listaT[], int tamTipos, eNotebook listaN[], int tamN);
//Pedir un servicio y mostrar las notebooks a las que se realizo ese servicio y la fecha.
int mostrarServicioANotebooks(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaS[],int tamS,
                          eMarca listaM[],int tamM, eTipo listaT[], int tamTipos, eNotebook listaN[], int tamN);
//Pedir una fecha y mostrar todos los servicios realizados en la misma.
int mostrarServiciosFecha(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaS[],int tamS,
                          eMarca listaM[],int tamM, eTipo listaT[], int tamTipos, eNotebook listaN[], int tamN);
