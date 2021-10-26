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
/** \brief Iniciar las notebooks en isEmpty = 1 para que se puedan cargar los datos
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien.
 *
 */

int iniciarNotebooks(eNotebook lista[],int tam);
/** \brief Busca un indice libre en el array de notebooks si es que hay espacio
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */

int buscarLibre(eNotebook lista[], int tam);
/** \brief Dar de alta una notebook con todos sus datos respectivos
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */
int altaNotebook(eNotebook lista[],int tamN ,int *pId, eTipo listaT[],int tamT, eMarca listaM[], int tamM);
/** \brief Mostrar una notebook con todos sus datos
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */

int mostrarNotebook(eNotebook unaNotebook ,eMarca listaM[],int tamM, eTipo listaT[],int tamT);
/** \brief Mostrar todas las notebooks que hay cargadas en el sistema
 *
 * \param
 * \param
 * \return Retorna 0 si hay error 1 si esta bien
 *
 */

int mostrarNotebooks(eNotebook lista[],int tamN , eMarca listaM[],int tamM, eTipo listaT[],int tamT);
/** \brief Buscar una notebook por id  y tiene que estar cargada
 *
 * \param
 * \param
 * \return Retorna -1 si hay error. Si funciona bien retorna el indice de esa notebook.
 *
 */

int buscarNotebookId(eNotebook lista[], int tam, int Id);
/** \brief Dar de baja notebook, si existe el id de esa notebook se confirma la respuesta por si o no para dar de baja
 *
 * \param
 * \param
 * \return Retorna 0 cuando no se pudo dar de baja por error o porque el usuario eligio que no, 1 Si lo dio de baja.
 *
 */

int bajaNotebook(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT);
/** \brief Modificar notebook, si existe el id de esa notebook se le pregunte si quiere modificar el precio,tipo o salir.
 *
 * \param
 * \param
 * \return Retorna 0 por error, 1 si funciona bien.
 *
 */

int modificarNotebook(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT);
/** \brief Menu de opciones que tiene el usuario para modificar.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error, 1 si quiere modificar el precio, 2 si quiere modificar el tipo, 3 si quiere salir.
 *
 */

int menuModificar(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT, int indice);
/** \brief Ordena las notebooks  por tipo en y si son iguales desempate el precio. Forma ascendente.
 *
 * \param
 * \param
 * \return 0 si hay error, 1 si ordeno bien.
 *
 */

int ordenarNotebook(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas);
/** \brief  Validar si el id enviado por el usuario existe. Si existe el id es que hay una notebook dada de alta en sistema
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam, null puntero o si no se encontro la notebook. 1 Si el id es valido.
 *
 */
int validarIdNotebook(int id, eNotebook lista[], int tam);

