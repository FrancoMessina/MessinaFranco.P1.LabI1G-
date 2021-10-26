#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;//Comienza en 5000
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED
/** \brief Compara el id que se le envia por parametro hasta encontrar un id de tipo
 y se carga la descripcion de su respectiva tipo.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam o null puntero. 1 Si cargo la descripcion. -1 Si no cargo la descripcion.
 *
 */

int cargarDescripcionTipo(eTipo listaTipos[], int tam, int idTipo, char descripcion[]);
/** \brief Muestra los tipos
 *
 * \param Lista de tipos
 * \param Tam del array
 * \return Retorna 0 si hay error en tam o null puntero. 1 Si mostro las tipos.
 */
int mostrarTipos(eTipo listaTipos[], int tam);
/** \brief  Comparada id que enviado por parametro con todos los id de tipo que existen.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam, null puntero o si no se encontro tipo. 1 Si el id es valido.
 *
 */
int validarIdTipo(int id, eTipo listaTipos[], int tam);
