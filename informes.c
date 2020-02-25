#include "stdlib.h"
#include "stdio.h"
#include "Cachorros.h"

void cachorroMasJoven(LinkedList* this)
{
    int menor;
    int tam = ll_len(this);

    menor = ((eCachorro*) ll_get(this, 0))->dias;

    for(int i=0; i<tam; i++)
    {
        if(menor > ((eCachorro*) ll_get(this, i))->dias)
        {
            menor = ((eCachorro*) ll_get(this, i))->dias;
        }
    }

    printf("ID            NOMBRE        DIAS      RAZA        RESERVADO       GENERO       PESO        VACUNADO\n");

    for(int i=0; i<tam; i++)
    {
        if(menor == ((eCachorro*) ll_get(this, i))->dias)
        {
            printCachorro( (eCachorro*) ll_get(this, i) );
        }
    }
}

void cachorroMasViejo(LinkedList* this)
{
    int mayor;
    int tam = ll_len(this);

    mayor = ((eCachorro*) ll_get(this, 0))->dias;

    for(int i=0; i<tam; i++)
    {
        if(mayor < ((eCachorro*) ll_get(this, i))->dias)
        {
            mayor = ((eCachorro*) ll_get(this, i))->dias;
        }
    }

    printf("ID            NOMBRE        DIAS      RAZA        RESERVADO       GENERO       PESO        VACUNADO\n");

    for(int i=0; i<tam; i++)
    {
        if(mayor == ((eCachorro*) ll_get(this, i))->dias)
        {
            printCachorro( (eCachorro*) ll_get(this, i) );
        }
    }
}
