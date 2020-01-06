#ifndef CACHORROS_H
#define CACHORROS_H

typedef struct
{
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero[2];
}eCachorro;

#endif // CACHORROS_H

#include "LinkedList.h"

int menu(void);

eCachorro* cachorro_new(void);
eCachorro* cachorro_newParametros(char* idStr, char* nombreStr, char* diasStr, char* razaStr, char* reservadoStr, char* generoStr);
void cachorro_delete(eCachorro* this);
int cachorro_setId(eCachorro* this, int id);
int cachorro_getId(eCachorro* this, int* id);
int cachorro_setNombre(eCachorro* this, char* nombre);
int cachorro_getNombre(eCachorro* this, char* nombre);
int cachorro_setDias(eCachorro* this, int dias);
int cachorro_getDias(eCachorro* this, int* dias);
int cachorro_setRaza(eCachorro* this, char* raza);
int cachorro_getRaza(eCachorro* this, char* raza);
int cachorro_setReservado(eCachorro* this, char* reservado);
int cachorro_getReservado(eCachorro* this, char* reservado);
int cachorro_setGenero(eCachorro* this, char* genero);
int cachorro_getGenero(eCachorro* this, char* genero);
int printCachorro(eCachorro* this);
int printCachorros(LinkedList* this);
int validateCachorro(eCachorro* this);
int filtrarMenores45(void* pElement);
int filtrarMachos(void* pElement);
int filtrarCallejeros(void* pElement);
int ordenarListaPorId(void* first, void* second);

