#ifndef EPAIS_H_INCLUDED
#define EPAIS_H_INCLUDED



#endif // EPAIS_H_INCLUDED



typedef struct{

int id;
char nombre [50];
int vac1dosis;
int vac2dosis;
int sinVacunar;

}ePais;


ePais* ePais_new();
ePais* ePais_newParametros(char* idStr,char* nombre,char* vac1dosisStr, char* vac2dosisStr, char* sinVacunarIdStr);

void ePais_delete(ePais* this);

int ePais_setId(ePais* this,int id);
int ePais_getId(ePais* this,int* id);

int ePais_setNombre(ePais* this,char* nombre);
int ePais_getNombre(ePais* this,char* nombre);


int ePais_setVac1dosis(ePais* this,int vac1dosis);
int ePais_getVac1dosis(ePais* this,int* vac1dosis);

int ePais_setVac2dosis(ePais* this,int vac2dosis);
int ePais_getVac2dosis(ePais* this,int* vac2dosis);

int ePais_getsinVacunar(ePais* this,int* sinVacunar);
int ePais_setsinVacunar(ePais* this,int sinVacunar);


int mostrar_ePais(ePais* this);
int asignarEstadisticas(void*);

int filtrarMasExitosos(void*);
int filtrarEnElHorno(void*);

int sortByVac1dosis(void*, void* );
