
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


/** \brief retorna la opcion ingresada por el usuario
 *
 * \return int
 *
 */
int menu()
{
    char auxCadena[200];
    int opcion;

    printf("*******************MENU DE OPCIONES*******************************\n");
    printf(" 1) CARGAR DATOS MODO TEXTO\n 2) IMPRIMIR LISTA \n 3) ASIGNAR ESTADISTICAS\n 4) FILTRAR EXITOSOS\n");
    printf(" 5) FILTRAR EN EL HORNO\n 6) ORDENAR POR NIVEL DE VACUNACION\n 7) PAIS MAS CASTIGADO\n");
    printf(" 8) SALIR\n");

    do
    {
        printf("\nIngresa opcion: ");
        fflush(stdin);
        scanf("%s", auxCadena);

        if(!validateNumber(auxCadena))
        {
            printf("Solo puedes ingresar numeros: ");
            fflush(stdin);
        }else{
            opcion = atoi(auxCadena);
            if(opcion < 1 || opcion > 8){
            	printf("Elije una de las opciones disponibles.\n");
            }

        }
    }
    while (!validateNumber(auxCadena));

    return opcion;
}


/** \brief valida si una cadena esta conformada solamente por numeros
 *
 * \param numero char*
 * \return int
 *
 */
int validateNumber(char* numero)
{

    int retorno = 1;

    for (int i=0; numero[i]!= '\0' ; i++ )
    {
        if(numero[i] < '0' || numero[i] > '9')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

