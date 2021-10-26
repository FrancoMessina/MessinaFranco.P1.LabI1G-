#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;//Comienza en 1000
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED
/** \brief Compara el id que se le envia por parametro hasta encontrar un id de marca
 y se carga la descripcion de su respectiva Marca.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam o null puntero. 1 Si cargo la descripcion. -1 Si no cargo la descripcion.
 *
 */
int cargarDescripcionMarca(eMarca marcas[], int tam, int idMarca, char descripcion[]);
/** \brief Muestra las marcas
 *
 * \param Lista de marcas
 * \param Tam del array
 * \return Retorna 0 si hay error en tam o null puntero. 1 Si mostro las marcas.
 */
int mostrarMarcas(eMarca marcas[], int tam);
/** \brief  Comparada id que enviado por parametro con todos los id de marca que existen.
 *
 * \param
 * \param
 * \return Retorna 0 si hay error en tam, null puntero o si no se encontro marca. 1 Si el id es valido.
 *
 */
int validarIdMarca(int id, eMarca marcas[], int tam);
