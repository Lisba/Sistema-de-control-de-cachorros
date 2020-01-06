#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"
#include "parser.h"
#include "conio.h"

int controller_loadFromText(char* path , LinkedList* pArrayListCachorro)
{
    int able = 0;
    FILE* f = NULL;

    if( path != NULL && pArrayListCachorro != NULL )
    {
        f = fopen(path, "r");

        if( f != NULL )
        {
            if( parser_CachorrosFromText(f, pArrayListCachorro) )
            {
                fclose(f);
                able = 1;

            }
        }
        else
        {
            printf("\nEL ARCHIVO NO EXISTE!\n");
        }
    }

    return able;
}

int controller_ListCachorros(LinkedList* pArrayListCachorro)
{
    int able = 0;

    if( printCachorros(pArrayListCachorro) )
    {
        able = 1;
    }

    return able;
}

int controller_saveAsText(char* path , LinkedList* pArrayListCachorro)
{
    int able = 0;
    int tam = 0;
    int contador = 0;
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[20];
    char genero[2];
    FILE* f = NULL;
   eCachorro* cachorro;

    if( path != NULL && pArrayListCachorro != NULL )
    {
        tam = ll_len(pArrayListCachorro);
        f = fopen(path, "w");

        if( f != NULL )
        {
            fprintf(f, "id,nombre,dias,raza,reservado,genero\n");
            for(int i=0; i<tam; i++)
            {
                cachorro = (eCachorro*) ll_get(pArrayListCachorro, i);

                cachorro_getId(cachorro, &id);
                cachorro_getNombre(cachorro, nombre);
                cachorro_getDias(cachorro, &dias);
                cachorro_getRaza(cachorro, raza);
                cachorro_getReservado(cachorro, reservado);
                cachorro_getGenero(cachorro, genero);

                fprintf(f, "%d,%s,%d,%s,%s,%s\n", id, nombre, dias, raza, reservado, genero);
                contador++;
            }

            fclose(f);

            if( contador == tam )
            {
                able = 1;
            }

        }
        else
        {
            printf("NO SE PUDO CREAR/ABRIR EL ARCHIVO DE TEXTO EN MODO ESCRITURA.\n");
        }
    }

    return able;
}
