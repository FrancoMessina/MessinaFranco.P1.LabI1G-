#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion [25];
    int precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
int cargarDescripcionServicio(eServicio listaServicios[], int tam, int idServicio, char descripcion[], int *precio);
int mostrarServicios(eServicio listaServicios[], int tam);
int validarIdServicio(int id, eServicio listaServicios[], int tam);
