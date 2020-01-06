#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"

int parser_CachorrosFromText(FILE* pFile , LinkedList* pArrayListCachorro)
{
    char buffer[6][20];
    int cant;
    eCachorro* cachorro;
    int able = 0;

    if(pFile != NULL && pArrayListCachorro != NULL)
    {
        while( !feof(pFile) )
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
            if(cant < 6)
            {
                break;
            }
            else
            {
                cachorro = cachorro_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

                if(cachorro != NULL && validateCachorro(cachorro))
                {
                    ll_add(pArrayListCachorro, cachorro);
                    able = 1;
                }
            }
        }
    }

    return able;
}
