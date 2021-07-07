#include "ePais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** \brief pide espacio en  memoria y devuelve un puntero a pais
 *
 * \return ePais*
 *
 */
ePais* ePais_new()
{

    return (ePais*)malloc(sizeof(ePais));


}
/** \brief crea y devuelve un puntero a pais con parametros
 *
 * \param idStr char*
 * \param nombre char*
 * \param vac1dosisStr char*
 * \param vac2dosisStr char*
 * \param sinVacunarIdStr char*
 * \return ePais*
 *
 */
ePais* ePais_newParametros(char* idStr,char* nombre,char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarIdStr)
{

    ePais* auxPais = ePais_new();

    if(auxPais != NULL)
    {
        if(!(ePais_setId(auxPais,atoi(idStr)) && ePais_setNombre(auxPais,nombre) &&
                ePais_setVac1dosis(auxPais,atoi(vac1dosisStr)) && ePais_setVac2dosis(auxPais,atoi(vac2dosisStr))
                && ePais_setsinVacunar(auxPais,atoi(sinVacunarIdStr))))
        {
            ePais_delete(auxPais);
            auxPais = NULL;

        }
    }
    return auxPais;



}
/** \brief elimina un puntero a pais
 *
 * \param this ePais*
 * \return void
 *
 */
void ePais_delete(ePais* this)
{

    if(this != NULL)
    {
        free(this);
    }
}

/** \brief le otorga el id a un pais
 *
 * \param this ePais*
 * \param id int
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_setId(ePais* this,int id)
{


    int retorno = 0;
    if(this != NULL)
    {
        this->id = id;
        retorno =1;
    }

    return retorno;

}
/** \brief rescata el id de un pais
 *
 * \param this ePais*
 * \param id int*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_getId(ePais* this,int* id)
{

    int retorno = 0;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
        retorno = 1;
    }

    return retorno;

}

/** \brief le otorga el nombre a un pais
 *
 * \param this ePais*
 * \param nombre char*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_setNombre(ePais* this,char* nombre)
{

    int retorno = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno =1;
    }

    return retorno;
}
/** \brief rescata el nombre de un pais
 *
 * \param this ePais*
 * \param nombre char*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_getNombre(ePais* this,char* nombre)
{

    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief establece la cantidad de vacunas a un pais
 *
 * \param this ePais*
 * \param vac1dosis int
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_setVac1dosis(ePais* this,int vac1dosis)
{

    int retorno = 0;
    if(this != NULL)
    {
        this->vac1dosis = vac1dosis;
        retorno =1;
    }

    return retorno;
}

/** \brief rescata la cantidad de vacunas de un pais
 *
 * \param this ePais*
 * \param vac1dosis int*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_getVac1dosis(ePais* this,int* vac1dosis)
{
    int retorno = 0;
    if(this != NULL)
    {
        *vac1dosis = this->vac1dosis;
        retorno =1;
    }

    return retorno;
}
/** \brief establece la cantidad de vacunas a un pais
 *
 * \param this ePais*
 * \param vac2dosis int
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_setVac2dosis(ePais* this,int vac2dosis){


    int retorno = 0;
    if(this != NULL)
    {
        this->vac2dosis = vac2dosis;
        retorno =1;
    }

    return retorno;

}
/** \brief rescata la cantidad de vacunas de un pais
 *
 * \param this ePais*
 * \param vac2dosis int*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_getVac2dosis(ePais* this,int* vac2dosis)
{

    int retorno = 0;
    if(this != NULL)
    {
        *vac2dosis = this->vac2dosis;
        retorno =1;
    }

    return retorno;

}
/** \brief establece la cantidad de vacunas a un pais
 *
 * \param this ePais*
 * \param sinVacunar int
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_setsinVacunar(ePais* this,int sinVacunar)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->sinVacunar = sinVacunar;
        retorno =1;
    }

    return retorno;
}
/** \brief rescata la cantidad de vacunas de un pais
 *
 * \param this ePais*
 * \param sinVacunar int*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int ePais_getsinVacunar(ePais* this,int* sinVacunar)
{
    int retorno = 0;
    if(this != NULL)
    {
        *sinVacunar = this->sinVacunar;
        retorno =1;
    }

    return retorno;
}

/** \brief muestra por pantalla un pais
 *
 * \param this ePais*
 * \return int
 *
 */
int mostrar_ePais(ePais* this)
{

    int retorno = 0;
    int id, sinVacunar, vac1dosis, vac2dosis;
    char nombre [50];
    if(this != NULL && ePais_getId(this, &id) && ePais_getNombre(this,nombre)
            && ePais_getVac1dosis(this, &vac1dosis) && ePais_getVac2dosis(this,&vac2dosis)
            && ePais_getsinVacunar(this, &sinVacunar))
    {
        printf("%d             %-20s       %d           %d          %d\n", id,nombre, vac1dosis, vac2dosis, sinVacunar);
        retorno = 1;
    }


    return retorno;


}

/** \brief le asigna estadisticas aleatorias a un pais
 *
 * \param a void*
 * \return devuelve 1 si tuvo exito y 0 sino
 *
 */
int asignarEstadisticas(void* a)
{


    int retorno = 0;
    int sinVacunar;
    int vac2dosis;
    int vac1dosis;
    ePais* auxPais = NULL;
    if(a != NULL)
    {
        auxPais = (ePais*)a;

        vac2dosis = rand() % (40 - 1 + 1) + 1;
        vac1dosis = rand() % (60 - 1 + 1) + 1;
        sinVacunar = 100 - (vac1dosis + vac2dosis);


        if( ePais_setVac2dosis(auxPais,vac2dosis) && ePais_setVac1dosis(auxPais,vac1dosis)
                && ePais_setsinVacunar(auxPais,sinVacunar))
        {

            retorno = 1;
        }
    }

    return retorno;

}
/** \brief filtra los paises que superan cierta cantidad de vacunados
 *
 * \param a void*
 * \return int
 *
 */
int filtrarMasExitosos(void* a)
{

    int retorno = 0;
    ePais* auxPais = NULL;
    int vac2dosis;

    if(a != NULL)
    {
        auxPais = (ePais*)a;
        ePais_getVac2dosis(auxPais,&vac2dosis);

        if((vac2dosis) > 30){
            retorno = 1;
        }

    }

    return retorno;
}


/** \brief filtra los paises que superan cierta cantidad de no vacunados
 *
 * \param a void*
 * \return int
 *
 */
int filtrarEnElHorno(void* a)
{
    int retorno = 0;
    ePais* auxPais = NULL;
    int sinVacunar;
    int vac2dosis;
    int vac1dosis;


    if(a != NULL)
    {
        auxPais = (ePais*)a;
        ePais_getsinVacunar(auxPais,&sinVacunar);
        ePais_getVac2dosis(auxPais,&vac2dosis);
        ePais_getVac1dosis(auxPais,&vac1dosis);

        if((vac2dosis + vac1dosis) < sinVacunar){
            retorno = 1;
        }

    }

    return retorno;
}

/** \brief ordena los paises de acuerdo a su vacunacion
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int sortByVac1dosis(void* a, void* b){

  int retorno = 0;

    ePais* pais1;
    ePais* pais2;
    int vac1dosis1, vac2dosis1;

    pais1 = (ePais*) a;
    pais2 = (ePais*) b;


    if(ePais_getVac1dosis(pais1,&vac1dosis1) && ePais_getVac1dosis(pais2,&vac2dosis1))
    {
        if(vac1dosis1 > vac2dosis1)
        {
            retorno = -1;
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;

}
