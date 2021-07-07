#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


#endif // CONTROLLER_H_INCLUDED
int controller_loadFromText(char* path , LinkedList* pListeArticulo, int* flag);

int controller_ListPais(LinkedList* pListPaises);
int controller_sortPais(LinkedList* pListPaises);
int controller_mapPais(LinkedList* pListPaises);

int controller_filterPais(LinkedList* pListPaises);

int controller_saveAsText(char* path , LinkedList* pListPaises);

int controller_paisMasCastigado(LinkedList* pListPaises);


