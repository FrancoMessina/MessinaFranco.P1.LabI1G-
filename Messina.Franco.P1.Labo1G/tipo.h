#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;//Comienza en 5000
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED
int cargarDescripcionTipo(eTipo listaTipos[], int tam, int idTipo, char descripcion[]);
int mostrarTipos(eTipo listaTipos[], int tam);
int validarIdTipo(int id, eTipo listaTipos[], int tam);
