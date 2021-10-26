#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion [25];
    int precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
/** \brief Compara el id que se le envia por parametro hasta encontrar un id de servicio
 y se carga la descripcion de su respectiva servicio.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam o null puntero. 1 Si cargo la descripcion. -1 Si no cargo la descripcion.
 *
 */

int cargarDescripcionServicio(eServicio listaServicios[], int tam, int idServicio, char descripcion[], int *precio);
/** \brief Muestra los servicios
 *
 * \param Lista de servicios
 * \param Tam del array
 * \return Retorna 0 si hay error en tam o null puntero. 1 Si mostro las servicios.
 */
int mostrarServicios(eServicio listaServicios[], int tam);
/** \brief  Comparada id que enviado por parametro con todos los id de servicio que existen.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam, null puntero o si no se encontro tipo. 1 Si el id es valido.
 *
 */
int validarIdServicio(int id, eServicio listaServicios[], int tam);
