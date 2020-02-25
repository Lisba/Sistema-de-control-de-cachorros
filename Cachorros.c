#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Cachorros.h"
#include "LinkedList.h"
#include "Lisba_libreria.h"

int menu(void)
{
    int opcion;

    system("cls");
    printf("****** ABM CACHORROS *******\n\n");
    printf("1-CARGAR ARCHIVO.\n");
    printf("2-ALTA CACHORRO.\n");
    printf("3-MODIFICAR CACHORRO.\n");
    printf("4-BAJA CACHORRO.\n");
    printf("5-IMPRIMIR LISTA.\n");
    printf("6-FILTRAR POR CRITERIO.\n");
    printf("7-ORDENAR LISTA.\n");
    printf("8-INFORMES.\n");
    printf("9-GUARDAR ARCHIVO.\n");
    printf("10-SALIR.\n\n");
    getInt(&opcion, "INGRESE OPCION: ", "OPCION INVALIDA. ", 1, 12);

    return opcion;
}

int filterMenu(void)
{
    int opcion;

    system("cls");
    printf("****** FILTRAR CACHORROS *******\n\n");
    printf("1-SOLO MAYORES A 45 DIAS.\n");
    printf("2-SOLO HEMBRAS.\n");
    printf("3-SOLO MACHOS.\n");
    printf("4-SOLO CALLEJEROS.\n");
    printf("5-SALIR.\n\n");
    getInt(&opcion, "INGRESE OPCION: ", "OPCION INVALIDA. ", 1, 5);

    return opcion;
}

int informesMenu(void)
{
    int opcion;

    system("cls");
    printf("****** INFORMES CACHORROS *******\n\n");
    printf("1-CACHORRO MAS JOVEN.\n");
    printf("2-CACHORRO MAS VIEJO.\n");
    printf("3-SALIR.\n\n");
    getInt(&opcion, "INGRESE OPCION: ", "OPCION INVALIDA. ", 1, 3);

    return opcion;
}

int guardarArchivoMenu(void)
{
    int opcion;

    system("cls");
    printf("****** GUARDAR ARCHIVO CACHORROS *******\n\n");
    printf("1-SOBREESCRIBIR EL ARCHIVO ORIGINAL.\n");
    printf("2-GENERAR UN NUEVO ARCIVHO.\n");
    getInt(&opcion, "\nINGRESE OPCION: ", "OPCION INVALIDA. ", 1, 2);

    return opcion;
}

eCachorro* cachorro_new(void)
{
    eCachorro* this = (eCachorro*) malloc(sizeof(eCachorro));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, " ");
        this->dias = 0;
        strcpy(this->raza, " ");
        strcpy(this->reservado, " ");
        strcpy(this->genero, " ");
        this->peso = 0;
        strcpy(this->vacunado, " ");
    }

    return this;
}

eCachorro* cachorro_newParametros(char* idStr, char* nombreStr, char* diasStr, char* razaStr, char* reservadoStr, char* generoStr, char* pesoStr, char* vacunadoStr)
{
    eCachorro* this;

        if(idStr != NULL && nombreStr != NULL && diasStr != NULL && razaStr != NULL && reservadoStr != NULL && generoStr != NULL && pesoStr != NULL && vacunadoStr != NULL)
        {
            this = cachorro_new();

            if(this != NULL)
            {
                if( !cachorro_setId(this, atoi(idStr)) || !cachorro_setNombre(this, nombreStr) || !cachorro_setDias(this, atoi(diasStr)) || !cachorro_setRaza(this, razaStr) || !cachorro_setReservado(this, reservadoStr) || !cachorro_setGenero(this, generoStr) || !cachorro_setPeso(this, atoi(pesoStr)) || !cachorro_setVacunado(this, vacunadoStr) )
                {
                        cachorro_delete(this);
                        this = NULL;
                }
            }
        }

    return this;
}

void cachorro_delete(eCachorro* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int cachorro_setId(eCachorro* this, int id)
{
    int able = 0;
    static int maxId = -1;

    if(this != NULL)
    {
        if(id < 0)
        {
            maxId++;
            this->id = maxId;
        }
        else
        {
            this->id = id;
            maxId = id;
        }

        able = 1;
    }

    return able;
}

int cachorro_getId(eCachorro* this, int* id)
{
    int able = 0;

    if(this != NULL && id > 0)
    {
        *id = this->id;
        able = 1;
    }

    return able;
}

int cachorro_setNombre(eCachorro* this, char* nombre)
{
    int able = 0;

    if(this != NULL && (nombre != NULL && strlen(nombre)>1))
    {
        strcpy(this->nombre, nombre);
        able = 1;
    }

    return able;
}

int cachorro_getNombre(eCachorro* this, char* nombre)
{
    int able = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        able = 1;
    }

    return able;
}

int cachorro_setDias(eCachorro* this, int dias)
{
    int able = 0;

    if(this != NULL && dias > 0)
    {
        this->dias = dias;
        able = 1;
    }

    return able;
}

int cachorro_getDias(eCachorro* this, int* dias)
{
    int able = 0;

    if(this != NULL && dias > 0)
    {
        *dias = this->dias;
        able = 1;
    }

    return able;
}

int cachorro_setRaza(eCachorro* this, char* raza)
{
    int able = 0;

    if(this != NULL && (raza != NULL && strlen(raza)>1))
    {
        strcpy(this->raza, raza);
        able = 1;
    }

    return able;
}

int cachorro_getRaza(eCachorro* this, char* raza)
{
    int able = 0;

    if(this != NULL && raza != NULL)
    {
        strcpy(raza, this->raza);
        able = 1;
    }

    return able;
}

int cachorro_setReservado(eCachorro* this, char* reservado)
{
    int able = 0;

    if(this != NULL && (reservado != NULL && strlen(reservado)>1))
    {
        strcpy(this->reservado, reservado);
        able = 1;
    }

    return able;
}

int cachorro_getReservado(eCachorro* this, char* reservado)
{
    int able = 0;

    if(this != NULL && reservado != NULL)
    {
        strcpy(reservado, this->reservado);
        able = 1;
    }

    return able;
}

int cachorro_setGenero(eCachorro* this, char* genero)
{
    int able = 0;

    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        able = 1;
    }

    return able;
}

int cachorro_getGenero(eCachorro* this, char* genero)
{
    int able = 0;

    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        able = 1;
    }

    return able;
}

int cachorro_setPeso(eCachorro* this, int peso)
{
    int able = 0;

    if(this != NULL && peso > 0)
    {
        this->peso = peso;
        able = 1;
    }

    return able;
}

int cachorro_getPeso(eCachorro* this, int* peso)
{
    int able = 0;

    if(this != NULL && peso > 0)
    {
        *peso = this->peso;
        able = 1;
    }

    return able;
}

int cachorro_setVacunado(eCachorro* this, char* vacunado)
{
    int able = 0;

    if(this != NULL && (vacunado != NULL && strlen(vacunado)>1))
    {
        strcpy(this->vacunado, vacunado);
        able = 1;
    }

    return able;
}

int cachorro_getVacunado(eCachorro* this, char* vacunado)
{
    int able = 0;

    if(this != NULL && vacunado != NULL)
    {
        strcpy(vacunado, this->vacunado);
        able = 1;
    }

    return able;
}

int printCachorro(eCachorro* this)
{
    int able = 0;

    printf("%d %18s %9d %12s %12s %12s %12d %12s\n", this->id, this->nombre, this->dias, this->raza, this->reservado, this->genero, this->peso, this->vacunado);
    able = 1;

    return able;
}

int printCachorros(LinkedList* this)
{
    int able = 0;
    int tam;

    if( this != NULL )
    {
        tam = ll_len(this);
        system("cls");
        printf("ID            NOMBRE        DIAS      RAZA        RESERVADO       GENERO       PESO      VACUNADO\n");

        for(int i=0; i<tam; i++)
        {
            printCachorro(((eCachorro*) ll_get(this, i)));
            able = 1;
        }
    }

    return able;
}

int validateCachorro(eCachorro* this)
{
    int isUsed = 0;
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero[2];
    int peso;
    char vacunado[3];

    if(this != NULL)
    {
        cachorro_getId(this, &id);
        cachorro_getNombre(this, nombre);
        cachorro_getDias(this, &dias);
        cachorro_getRaza(this, raza);
        cachorro_getReservado(this, reservado);
        cachorro_getGenero(this, genero);
        cachorro_getPeso(this, &peso);
        cachorro_getVacunado(this, vacunado);

        if(id > 0 &&  strlen(nombre) > 0 && dias > 0 && strlen(raza) > 0 && strlen(reservado) > 0 && strlen(genero) > 0 && peso > 0 && strlen(vacunado) > 0)
        {
            isUsed = 1;
        }
    }

    return isUsed;
}

int filtrarMenores45(void* pElement)
{
    int value = -1;

    if(pElement != NULL)
    {
        eCachorro* pElementCasted = (eCachorro*) pElement;

        if(pElementCasted->dias >= 45)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }

    return value;
}

int filtrarMachos(void* pElement)
{
    int value = -1;

    if(pElement != NULL)
    {
        eCachorro* pElementCasted = (eCachorro*) pElement;

        if(strcmp(pElementCasted->genero, "H")==0)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }

    return value;
}

int filtrarHembras(void* pElement)
{
    int value = -1;

    if(pElement != NULL)
    {
        eCachorro* pElementCasted = (eCachorro*) pElement;

        if(strcmp(pElementCasted->genero, "M")==0)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }

    return value;
}

int filtrarCallejeros(void* pElement)
{
    int value = -1;

    if(pElement != NULL)
    {
        eCachorro* pElementCasted = (eCachorro*) pElement;

        if(strcmp(pElementCasted->raza, "Callejero")==0)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }

    return value;
}

int ordenarListaPorId(void* first, void* second)
{
    int value = 0;

    eCachorro* firstElement = (eCachorro*) first;
    eCachorro* secondElement = (eCachorro*) second;

    if(firstElement->id > secondElement->id)
    {
        value = 1;
    }
    else if(firstElement->id < secondElement->id)
    {
        value = -1;
    }

    return value;
}
