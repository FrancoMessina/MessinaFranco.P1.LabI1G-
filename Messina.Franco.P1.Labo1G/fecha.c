#include <stdio.h>
#include <stdlib.h>


int verificarFecha(int dia, int mes, int anio)
{
    int todoOk = 0;
    int verificarMes = 0;
    int verificarAnio = 0;

    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(dia >= 1 && dia <= 31)
        {
            verificarMes = 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if(dia >= 1 && dia <= 30)
        {
            verificarMes = 1;
        }
        break;
    case 2:
        if(dia == 28)
        {
            verificarMes = 1;
        }
        break;

    }
    if(anio >= 2021 && anio <= 2025)
    {
        verificarAnio = 1;
    }
    if(verificarAnio == 1 && verificarMes == 1 )
    {
        todoOk = 1;
    }

    return todoOk;
}
