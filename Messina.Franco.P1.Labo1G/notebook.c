#include "notebook.h"
#include "bibiliotecaPersonal.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tipo.h"
#include "marca.h"
#include "string.h"
#define VACIO 1
#define CARGADO 0

int iniciarNotebooks(eNotebook lista[],int tam)
{
    int todoOk = 0;
    if (lista != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = VACIO;
        }
    }
    return todoOk;
}
int buscarLibre(eNotebook lista[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaNotebook(eNotebook lista[],int tamN,int *pId, eTipo listaT[],int tamT, eMarca listaM[], int tamM)
{
    int todoOk = 0;
    int indice;
    eNotebook auxNotebook;
    char auxModelo[100];
    if(lista != NULL && tamN > 0 && listaT!= NULL && tamT > 0 && listaM != NULL && tamM> 0)
    {
        system("cls");
        printf("  ***Alta Notebook*** \n\n");
        indice = buscarLibre(lista,tamN);
        if(indice == -1)
        {
            printf("Error..\n");
        }
        else
        {
            auxNotebook.id = *pId;
            (*pId)++;//ID

            ingresarString("Ingresa el modelo de la notebook : ", auxModelo);//Modelo
            while(validarLargoString(auxModelo,1, 20))
            {
                printf("Error no se puede ingresar mas de 20 caracteres \n");
                ingresarString("Ingresa el modelo de la notebook : ", auxModelo);
            }
            strcpy(auxNotebook.modelo,auxModelo);
            mostrarMarcas(listaM, tamM);
            auxNotebook.idMarca = ingresarEntero("Ingresar marca: ");

            while (!validarIdMarca(auxNotebook.idMarca, listaM, tamM))
            {
                printf("Error, ingrese id de  Marca valido: ");
                auxNotebook.idMarca = ingresarEntero("Ingresar marca: ");
            }

            mostrarTipos(listaT,tamT);
            auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");

            while (!validarIdTipo(auxNotebook.idTipo, listaT, tamT))
            {
                printf("Error, ingrese id de  tipo valido \n");
                auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");
            }
            auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook : ");
            while(auxNotebook.precio <= 0)
            {

                printf("Ingrese un precio valido : ");
                auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook : ");
            }

            auxNotebook.isEmpty = CARGADO;
            lista[indice] = auxNotebook;
            todoOk = 1;
        }
    }

    return todoOk;
}
int mostrarNotebook(eNotebook unaNotebook,eMarca listaM[],int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    char descTipo[20];
    char descMarca[20];
    if(listaM != NULL && listaM != NULL  && tamM > 0 && listaT != NULL && tamT > 0)
    {
        if (cargarDescripcionTipo(listaT,tamT,unaNotebook.idTipo,descTipo) == 1 &&
                cargarDescripcionMarca(listaM,tamM,unaNotebook.idMarca, descMarca) == 1)
        {
            printf(" %d     %-10s           %-10s       %-10s     $%.2f     \n",
                   unaNotebook.id,
                   unaNotebook.modelo,
                   descMarca,
                   descTipo,
                   unaNotebook.precio
                  );
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarNotebooks(eNotebook lista[],int tamN , eMarca listaM[],int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && tamN> 0 && listaM != NULL && listaT != NULL && tamM > 0 && tamT > 0)
    {
        system("cls");
        printf("                     ***Lista de NOTEBOOKS  ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf(" ID         MODELO             MARCA              TIPO         PRECIO\n");
        printf("---------------------------------------------------------------------------\n");
        for (int i = 0; i < tamN; i++)
        {
            if (lista[i].isEmpty == CARGADO)
            {
                mostrarNotebook(lista[i],listaM,tamM,listaT,tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay Notebooks para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
int buscarNotebookId(eNotebook lista[], int tam, int Id)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (lista[i].id == Id && lista[i].isEmpty == CARGADO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}
int bajaNotebook(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && listaT != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Baja Notebook *** \n\n");
        mostrarNotebooks(lista,tamN,listaM,tamM,listaT,tamT);
        printf("------------------------------------------------------------\n");
        id = ingresarEntero("Ingresa Id : ");

        indice = buscarNotebookId(lista,tamN,id);

        if (indice == -1)
        {
            printf("El Id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
            printf("Confirma baja? (S/N): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                lista[indice].isEmpty = VACIO;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}
int modificarNotebook(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    eNotebook auxNotebook;
    if (lista != NULL && tamN > 0  &&  listaM != NULL && tamM> 0 && listaT != NULL && tamT > 0)
    {
        system("cls");
        printf("   *** Modificar Notebook *** \n\n");
        mostrarNotebooks(lista,tamN,listaM,tamM,listaT,tamT);
        printf("-----------------------------------------------------------------------------\n");
        id = ingresarEntero("Ingresar Id : ");

        indice = buscarNotebookId(lista,tamN,id);

        if (indice == -1)
        {
            printf("El Id : %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch (menuModificar(lista,tamN,listaM,tamM,listaT,tamT,indice))
                {
                case 1:
                    mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook : ");
                    while(auxNotebook.precio <= 0)
                    {

                        printf("Ingrese un precio valido : ");
                        auxNotebook.precio = ingresarFlotante("Ingresa el precio de la Notebook: ");
                    }
                    printf("Confirma cambio de precio? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);

                    if (confirma == 's')
                    {
                        lista[indice].precio = auxNotebook.precio;
                    }
                    else
                    {
                        printf("Cancelado. No se modifico.\n");
                    }
                    printf("Estado Actual de la notebook \n");
                    mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    break;
                case 2:
                    mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    mostrarTipos(listaT,tamT);
                    auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");

                    while (!validarIdTipo(auxNotebook.idTipo, listaT, tamT))
                    {
                        printf("Error, ingrese id de  tipo valido \n");
                        auxNotebook.idTipo = ingresarEntero("Ingresar tipo: ");
                    }
                    printf("Confirma cambio de tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = tolower(confirma);
                    if (confirma == 's')
                    {
                        lista[indice].idTipo = auxNotebook.idTipo;
                    }
                    else
                    {
                        printf("Cancelado. No se modifico.\n");
                    }
                    printf("Estado Actual de la notebook \n");
                     mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
                    break;
                case 3:
                    seguir = 'n';
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            }
            while(seguir == 's');

            todoOk = 1;
        }
    }
    return todoOk;
}
int menuModificar(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo listaT[],int tamT, int indice)
{
    int opcion = 0;
    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && listaT != NULL && tamT > 0)
    {
        system("cls");
        printf("------------------------------------------------------------\n");
        mostrarNotebook(lista[indice],listaM,tamM,listaT,tamT);
        printf("------------------------------------------------------------\n");
        printf("1- Editar Precio \n");
        printf("2- Editar Tipo \n");;
        printf("3- Salir\n");
        opcion = ingresarEntero("Ingresa una opcion : ");
    }

    return opcion;
}
int ordenarNotebook(eNotebook lista[], int tamNotebooks, eMarca marcas[], int tamMarcas)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    char descMarcaUno[20];
    char descMarcaDos[20];

    if(lista != NULL && tamNotebooks > 0 && marcas != NULL && tamMarcas > 0)
    {
        for(int i = 0; i < tamNotebooks - 1; i++)
        {
            for(int j = i + 1; j < tamNotebooks ; j++)
            {

                cargarDescripcionMarca(marcas,tamMarcas,lista[i].idMarca,descMarcaUno);
                cargarDescripcionMarca(marcas, tamMarcas, lista[j].idMarca, descMarcaDos);
                if((strcmp(descMarcaUno, descMarcaDos) > 0) || (strcmp(descMarcaUno, descMarcaDos) == 0 && lista[i].precio > lista[j].precio))
                {
                    auxNotebook = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNotebook;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int validarIdNotebook(int id, eNotebook lista[], int tam)
{
    int esValido = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == lista[i].id && lista[i].isEmpty == CARGADO)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
int mostrarNoteboksTipo(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int idTipo;
    if(lista != NULL && tamN > 0 && listaM != NULL && listaM > 0 && tipos != NULL && tamM > 0)
    {
        system("cls");
        printf("               ***Notebooks de un Tipo***\n");
        printf("------------------------------------------------------------\n");

        mostrarTipos(tipos,tamT);

        printf("------------------------------------------------------------\n");
        idTipo = ingresarEntero("Ingresar id de tipo : ");
        while(!validarIdTipo(idTipo,tipos,tamT))
        {
            printf("Error, ingrese id de tipo valido : ");
            idTipo = ingresarEntero("Ingresar id de tipo : ");
        }
        mostrarNoteboksIdTipo(lista,tamN,listaM,tamM,tipos,tamT,idTipo);
        todoOk = 1;
    }
    return todoOk;
}
int mostrarNoteboksIdTipo(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT, int idTipo)
{
    int todoOk = 0;
    char descTipo[20];
    int flag = 1;
    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        printf("--------------------------------------------------------------------------\n");
        printf(" ID         MODELO             MARCA              TIPO         PRECIO\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i = 0; i < tamN ; i++)
        {
            if(lista[i].isEmpty == CARGADO && lista[i].idTipo == idTipo)
            {
                mostrarNotebook(lista[i],listaM,tamM,tipos,tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionTipo(tipos,tamT,idTipo,descTipo);
            printf("No hay notebooks de este tipo  : %s \n",descTipo);
        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarNotebooksMarca(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int idMarca;
    if (lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("               ***Notebooks de una  marca ***\n");
        printf("------------------------------------------------------------\n");

        mostrarMarcas(listaM,tamM);

        printf("------------------------------------------------------------\n");
        idMarca = ingresarEntero("Ingresar id de marca : ");

        while (!validarIdMarca(idMarca,listaM,tamM))
        {
            printf("Error, ingrese id de marca valido \n");
            idMarca = ingresarEntero("Ingresar id de marca : ");
        }

        mostrarNotebooksIdMarca(lista,tamN,listaM,tamM,tipos,tamT,idMarca);

        todoOk = 1;
    }
    return todoOk;
}


int mostrarNotebooksIdMarca(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT, int idMarca)
{
    int todoOk = 0;
    int flag = 1;
    char descMarca[20];
    if (lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        printf("--------------------------------------------------------------------------\n");
        printf(" ID         MODELO             MARCA              TIPO         PRECIO\n");
        printf("---------------------------------------------------------------------------\n");

        for (int i = 0; i < tamN; i++)
        {
            if (lista[i].isEmpty == CARGADO && lista[i].idMarca == idMarca)
            {
                mostrarNotebook(lista[i],listaM,tamM,tipos,tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionMarca(listaM,tamM,idMarca,descMarca);
            printf("   No hay notebooks de la marca :  %s.\n", descMarca);
        }
        todoOk = 1;
    }
    return todoOk;

}
int mostrarNotebooksMenorPrecio(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    float minimo;
    int flagMin = 1;
    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        for(int i = 0 ; i < tamN ; i++) //Averiguo minimo
        {
            if(lista[i].isEmpty == CARGADO)
            {
                if(flagMin || lista[i].precio < minimo)
                {
                    minimo = lista[i].precio;
                    flagMin = 0;
                }
            }
        }
        printf("--------------------------------------------------------------------------\n");
        printf(" ID         MODELO             MARCA              TIPO         PRECIO\n");
        printf("---------------------------------------------------------------------------\n");
        printf("  *** Notebook mas barata ***\n");
        for (int i = 0; i < tamN; i++)
        {
            if(lista[i].isEmpty == CARGADO && lista[i].precio == minimo)
            {

                mostrarNotebook(lista[i],listaM,tamM,tipos,tamT);

            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarNotebooksAllMarcas( eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("               ***Notebooks de cada marca ***\n");
        for (int i = 0; i < tamM; i++)
        {
            printf("\n");
            printf("Marca: %s\n", listaM[i].descripcion);
            mostrarNotebooksIdMarca(lista,tamN,listaM,tamM,tipos,tamT,listaM[i].id);
            printf("\n------------------------------------------------------------\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
int cantidadNotebooksMarcaTipo(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int contador = 0;
    int idMarca;
    int idTipo;
    char descTipo[20];
    char descMarca[20];

    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        mostrarTipos(tipos,tamT);

        printf("------------------------------------------------------------\n");
        idTipo = ingresarEntero("Ingresar id de tipo : ");
        while(!validarIdTipo(idTipo,tipos,tamT))
        {
            printf("Error, ingrese id de tipo valido : ");
            idTipo = ingresarEntero("Ingresar id de tipo : ");
        }

        mostrarMarcas(listaM,tamM);

        printf("------------------------------------------------------------\n");
        idMarca = ingresarEntero("Ingresar id de marca : ");

        while (!validarIdMarca(idMarca,listaM,tamM))
        {
            printf("Error, ingrese id de marca valido \n");
            idMarca = ingresarEntero("Ingresar id de marca : ");
        }


        cargarDescripcionMarca(listaM,tamM,idMarca,descMarca);
        cargarDescripcionTipo(tipos,tamT,idTipo,descTipo);
        system("cls");
        printf("      *** Cantidad de Notebooks de cada tipo y marca***\n");
        printf(" ID       MODELO        MARCA       TIPO        PRECIO\n");
        printf("************************************************************\n");

        for(int i = 0; i < tamN; i++)
        {
            if(lista[i].isEmpty == CARGADO && lista[i].idMarca == idMarca && lista[i].idTipo == idTipo)
            {
                contador++;
                mostrarNotebook(lista[i],listaM,tamM,tipos,tamT);
            }
        }
        if(contador == 0)
        {
            printf("\nNo hay notebook/s de tipo %s y de marca %s para mostrar\n",descTipo, descMarca);
        }
        else
        {
            printf("\nHay %d notebook/s de tipo %s y de marca %s\n", contador, descTipo, descMarca);
        }
        todoOk = 1;
    }
    return todoOk;
}
int marcaMasElegida(eNotebook lista[], int tamN, eMarca listaM[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int contadores[tamM];
    int flag = 1;
    int mayorCantidad;
    for (int i = 0; i < tamM; i++) // inicializo
    {
        contadores[i] = 0;
    }
    if(lista != NULL && tamN > 0 && listaM != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        system("cls");
        printf("               *** Marcas mas elegida ***\n");
        for (int i = 0; i < tamM; i++)
        {
            for (int j = 0; j < tamN; j++)
            {
                if (lista[j].isEmpty  == CARGADO && listaM[i].id == lista[j].idMarca)
                {
                    contadores[i]++;
                }
            }
        }

        for (int i = 0; i < tamM; i++)
        {
            if (flag || contadores[i] > mayorCantidad)
            {
                mayorCantidad = contadores[i];
                flag = 0;
            }
        }
        for (int i = 0; i < tamM; i++)
        {
            if (contadores[i] == mayorCantidad)
            {
                printf("La marca mas elegida es : %s\n", listaM[i].descripcion);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}
