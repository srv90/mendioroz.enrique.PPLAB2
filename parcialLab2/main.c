#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menu.h"
#include "controller.h"
#include "time.h"

int main()
{

    char respuesta;
    char path[30];
    int flag =0;


    LinkedList* listaEPaises = ll_newLinkedList();


    srand(time(NULL));


    if(listaEPaises == NULL)
    {
        printf("No se pudo crear la lista");
    }

    do
    {

        switch(menu())
        {
        case 1:
            system("cls");
            if(!flag)
            {
                printf("Ingresa el nombre del listado:\n");
                scanf("%s", path);
                if(!controller_loadFromText(path,listaEPaises, &flag))
                {
                    printf("Ocurrio un error.\n");

                }

            }
            else
            {
                printf("Deseas sobreescribir el listado actual?\nPresiona 'y' para confirmar o cualquier tecla para salir.\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 'y')
                {

                    ll_clear(listaEPaises);
                    printf("Ingresa el nombre del listado:\n");
                    scanf("%s", path);

                    if(!controller_loadFromText(path,listaEPaises, &flag))
                    {
                        printf("Ocurrio un error.\n");
                    }

                }
            }
            break;
        case 2:
            system("cls");
            if(ll_isEmpty(listaEPaises)== 0)
            {
                if(!controller_ListPais(listaEPaises))
                {
                    printf("Ocurrio un error");
                }
            }
            else if(ll_isEmpty(listaEPaises) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 3:
            system("cls");
            if(ll_isEmpty(listaEPaises)== 0)
            {
                if(!controller_mapPais(listaEPaises))
                {
                    printf("Ocurrio un error");
                }
                else printf("Listado mapeado con exito.\n");
            }
            else if(ll_isEmpty(listaEPaises) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 4:
            system("cls");
            if(ll_isEmpty(listaEPaises)== 0)
            {
                if(!controller_filterPais(listaEPaises))
                {
                    printf("Ocurrio un error");
                }
            }
            else if(ll_isEmpty(listaEPaises) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 5:
            system("cls");
            if(ll_isEmpty(listaEPaises)== 0)
            {
                if(!controller_filterPais(listaEPaises))
                {
                    printf("Ocurrio un error");
                }
            }
            else if(ll_isEmpty(listaEPaises) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 6:
            system("cls");
            if(ll_isEmpty(listaEPaises)== 0)
            {
                if(!controller_sortPais(listaEPaises))
                {
                    printf("Ocurrio un error");
                }
                else printf("\nEl listado ha sido ordenado por cantidad de vacunados con 1 dosis .\n");
            }
            else if(ll_isEmpty(listaEPaises) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 7:
            system("cls");
            if(ll_isEmpty(listaEPaises)== 0)
            {
                if(!controller_paisMasCastigado(listaEPaises))
                {
                    printf("Ocurrio un error");
                }
            }
            else if(ll_isEmpty(listaEPaises) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 8:
            printf("\nSeguro que deseas salir? s/n \n");
            fflush(stdin);
            respuesta = getchar();
            while (respuesta != 's' && respuesta != 'n')
            {
                printf("\nIngresa s o n \n");
                respuesta = getchar();
            }
            break;
        }
        system("pause");
        system("cls");

    }
    while (respuesta != 's' );
    return 0;
}
