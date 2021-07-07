#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ePais.h"

/** \brief Parsea los datos los datos de los paises desde el archivo vacunas.csv (modo texto).
 *
 * \param path char*
 * \param pListPaises LinkedList*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int parser_ePaisFromText(FILE* pFile , LinkedList* pListPaises)
{

    int retorno = 0;
    ePais* auxPais = NULL;
    char auxVac1dosis[50];
    char auxSinVacunar[50];
    char auxPaisNombre[50];
    char auxId[50];
    char auxVac2dosis[50];

    if(pFile !=NULL && pListPaises != NULL)
    {

        fscanf(pFile, "%s\n", auxPaisNombre);
        while(!feof(pFile))
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", auxId, auxPaisNombre, auxVac1dosis, auxVac2dosis, auxSinVacunar) == 5 )
            {
                auxPais = ePais_newParametros(auxId,auxPaisNombre,auxVac1dosis,auxVac2dosis, auxSinVacunar);
                ll_add(pListPaises,auxPais);
            }
            else
            {
                break;
            }

        }

        retorno = 1;
    }
    return  retorno;
}
