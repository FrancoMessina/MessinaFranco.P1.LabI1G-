#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

#endif // FECHA_H_INCLUDED
/** \brief Se le envia por parametros 3 valores.Dia,mes, anio .Y se verifica si los datos son validos.El año se cuenta de 2021 hasta 2025
 *
 * \param
 * \param
 * \return Retorna 0 si no existe esa fecha, retorna 1 si existe.
 *
 */

int verificarFecha(int dia, int mes, int anio);
