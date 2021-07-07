#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ePais.h"
#include "Controller.h"
#include "menu.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPaises, int* flag)
{
    int retorno = 0;

    if(path != NULL && pArrayListPaises != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f == NULL)
        {
            perror("Error: ");
            flag = 0;
        }
        else
        {
            parser_ePaisFromText(f, pArrayListPaises);
            printf("Listado cargado con exito.\n");
            *flag = 1;

        }
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

/** \brief muestra un listado con todos los paises
 *
 * \param pListPaises LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_ListPais(LinkedList* pListPaises)
{

    int retorno =0;
    ePais* auxPais = NULL;
    if(pListPaises != NULL)
    {
        printf(" ID           PAIS                      1DOSIS     2DOSIS     SIN VACUNAR\n");
        for (int i=0; i<ll_len(pListPaises) ; i++ )
        {
            auxPais = (ePais*)ll_get(pListPaises,i);
            mostrar_ePais(auxPais);
        }
        retorno =1;
    }
    return retorno;

}
//
/** \brief Ordenar los paises de manera ascendente por dosis aplicadas
 *
 * \param path char*
 * \param pListPaisess LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_sortPais(LinkedList* pListPaises)
{
    {
        int retorno = 0;


        if(pListPaises != NULL && ll_sort(pListPaises, sortByVac1dosis, 1) != -1)
        {

            retorno = 1;

        }

        return retorno;
    }
}

/** \brief Guarda los datos de los nombres en el archivo mapeado.csv (modo texto).
 *
 * \param path char*
 * \param pListPaisess LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_saveAsText(char* path, LinkedList* pListPaisess)
{

    int retorno = 0;
    int id, vac1dosis, vac2dosis, sinVacunar;
    char nombre[50];
    ePais* auxPais;

    if(path != NULL && pListPaisess != NULL)
    {
        FILE* f = fopen(path, "w");
        if(f == NULL)
        {
            perror("Error: ");
        }
        else
        {
            fprintf(f, "Id, pais, vac1dosis, vac2dosis, sinVacunar \n");
            for (int i=0; i<ll_len(pListPaisess) ; i++ )
            {

                auxPais = (ePais*)ll_get(pListPaisess,i);

                ePais_getId(auxPais,&id);
                ePais_getNombre(auxPais,nombre);
                ePais_getVac2dosis(auxPais,&vac2dosis);
                ePais_getsinVacunar(auxPais,&sinVacunar);
                ePais_getVac1dosis(auxPais, &vac1dosis);


                fprintf(f, "%d, %s, %d, %d, %d \n", id, nombre,vac1dosis,vac2dosis, sinVacunar);
            }
        }
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

/** \brief mapea un listado de paises
 *
 * \param pListPaises LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_mapPais(LinkedList* pListPaises)
{

    int retorno = 0;

    if(pListPaises != NULL && ll_map(pListPaises, asignarEstadisticas) != NULL)
    {

        retorno = 1;

    }

    return retorno;

}

/** \brief imprime dos listados, uno con los paises mas exitosos y otro con los menos
 *
 * \param pListPaises LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_filterPais(LinkedList* pListPaises)
{


    int retorno = 0;
    LinkedList* pListPaisesMasExitosos = ll_newLinkedList();
    LinkedList* pListPaisesEnElHorno = ll_newLinkedList();

    if(pListPaises != NULL && pListPaisesEnElHorno != NULL && pListPaisesMasExitosos != NULL
            && ll_filter(pListPaises, filtrarMasExitosos) != NULL && ll_filter(pListPaises,filtrarEnElHorno)  != NULL)
    {


        pListPaisesMasExitosos = ll_filter(pListPaises, filtrarMasExitosos);
        pListPaisesEnElHorno = ll_filter(pListPaises,filtrarEnElHorno);

        if(controller_saveAsText("paisesExitosos.csv", pListPaisesMasExitosos)
                && controller_saveAsText("paisesEnElHorno.csv", pListPaisesEnElHorno))
        {
            printf("Listado generado con exito.\n");
            retorno = 1;

        }
        else
        {

            printf("Ocurrio un error al generar el listado");
        }
    }

    return retorno;
}
/** \brief devuelve un listado con el pais o paises con menos vacunados
 *
 * \param pListPaises LinkedList*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int controller_paisMasCastigado(LinkedList* pListPaises)
{
    int retorno = 0;
    int largo;
    int mayor = 0;
    ePais* auxPais = NULL;
    char nombre [50];
    int sinVacunar;

    if(pListPaises != NULL)
    {
       largo = ll_len(pListPaises);
       for(int i=0;i< largo;i++)
       {
           auxPais = ll_get(pListPaises,i);
           ePais_getsinVacunar(auxPais,&sinVacunar);
           if(i == 0 || sinVacunar > mayor )
           {
               mayor = sinVacunar;
           }
       }
       printf("El mayor porcentaje de no vacunados es %d y el pais/es : ", mayor);

       for(int i=0;i< largo;i++)
       {
           auxPais = ll_get(pListPaises,i);
           ePais_getsinVacunar(auxPais,&sinVacunar);
           if(sinVacunar == mayor )
           {
              ePais_getNombre(auxPais,nombre);
              printf("%s", nombre);
           }
       }
     retorno = 1;
    }
    printf("\n");
    return retorno;
}
