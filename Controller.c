#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"
#include "parser.h"
#include "conio.h"
#include "Lisba_libreria.h"

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

int controller_addCachorro(LinkedList* pArrayListCachorro)
{
    int able = 0;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[3];
    char genero[2];
    eCachorro* cachorro;
    int respuesta;
    int indice;

    cachorro = cachorro_new();

    if(cachorro != NULL)
    {
        able = 1;
    }
    system("cls");
    printf("\nDESEA AGREAR UN NUEVO CACHORRO AL FINAL DE LA LISTA O DENTRO DE UN IDICE ESPECIFICO?\n\n");
    printf("1) AL FINAL DE LA LISTA.\n");
    printf("2) EN UN INDICE ESPECIFICO.\n");
    printf("3) SALIR.\n\n");
    getInt(&respuesta, "INGRESE OPCION: ", "ERROR. OPCION INVALIDA! ", 1, 3);

    if(respuesta != 3 && able)
    {
        system("cls");
        fflush(stdin);
        getName(nombre, "\nINGRESE EL NOMBRE: ", "Error. Debe contener entre 2 y 19 caracteres. ", 2, 19);
        system("cls");
        getInt(&dias, "\nINGRESE LOS DIAS: ", "Error. Debe estar entre 1 y 10.000.000", 1, 10000000);
        system("cls");
        fflush(stdin);
        getName(raza, "\nINGRESE LA RAZA: ", "Error. Debe contener entre 2 y 19 caracteres. ", 2, 19);
        system("cls");
        fflush(stdin);
        getName(reservado, "\nINGRESE SI ESTA RESERVADO: ", "Error. Debe contener 2 caracteres. ", 2, 2);
        system("cls");
        fflush(stdin);
        getName(genero, "\nINGRESE EL GENERO: ", "Error. Debe contener 1 caracteres. ", 1, 1);

        if( cachorro_setId(cachorro, -1) && cachorro_setNombre(cachorro, nombre) && cachorro_setDias(cachorro, dias) && cachorro_setRaza(cachorro, raza) && cachorro_setReservado(cachorro, reservado) && cachorro_setGenero(cachorro, genero) )
        {
            switch(respuesta)
            {
            case 1:
                if( !ll_add(pArrayListCachorro, cachorro) )
                {
                    able = 1;
                    printf("\nALTA EXITOSA!\n\n");
                }
                else
                {
                    able = 0;
                }
                break;

            case 2:
                system("cls");
                getInt(&indice, "\nINGRESE EL INDICE: ", "ERROR! ", 0, ll_len(pArrayListCachorro));

                if( !ll_push(pArrayListCachorro, indice, cachorro) )
                {
                    able = 1;
                    printf("\nALTA EXITOSA!\n\n");
                }
                else
                {
                    able = 0;
                }
                break;
            }
        }
        else
        {
            able = 0;
        }

        if( !able )
        {
            printf("\nOCURRIO UN PROBLEMA DURANTE EL ALTA!\n\n");
        }
    }
    else
    {
        printf("\nALTA NO REALIZADA!\n\n");
        able = 0;
    }


    return able;
}

int controller_editCachorro(LinkedList* pArrayListCachorro)
{
    int able = 0;
    int idToModify;
    int datoAModificar;
    int flag = 0;
    char stringAux[128];
    int intAux;
    int tam = ll_len(pArrayListCachorro);

    system("cls");
    printf("**************MODIFICAR EMPLEADO****************\n\n");

    getInt(&idToModify, "INGRESE EL ID DEL EMPLEADO A MODIFICAR: ", "ERROR. DEBE INGRESAR ENTRE 1 Y 2000. ", 1, 2000);

    for(int i=0; i<tam; i++)
    {
        if( idToModify == ( (eCachorro*) ll_get(pArrayListCachorro, i) )->id )
        {
            flag = 1;
            printf("\n");
            printf("ID            NOMBRE      DIAS       RAZA        RESERVADO       GENERO\n");
            printCachorro((eCachorro*) ll_get(pArrayListCachorro, i));
            printf("\n");

            printf("1) MODIFICAR NOMBRE\n");
            printf("2) MODIFICAR DIAS\n");
            printf("3) MODIFCAR RAZA\n");
            printf("4) MODIFCAR RESERVA\n");
            printf("5) MODIFCAR GENERO\n");
            printf("6) SALIR\n\n");

            getInt(&datoAModificar, "SELECCIONE UNA OPCION: ", "ERROR. DEBE INGRESAR ENTRE 1 Y 6 ", 1, 6);

            switch(datoAModificar)
            {
            case 1:
                getName(stringAux, "\nINGRESE EL NOMBRE: ", "Error. Debe contener entre 2 y 19 caracteres. ", 2, 19);
                if( cachorro_setNombre( (eCachorro*) ll_get(pArrayListCachorro, i), stringAux) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 2:
                getInt(&intAux, "\nINGRESE LOS DIAS: ", "Error. Debe estar entre 1 y 10.000.000. ", 1, 10000000);
                if( cachorro_setDias( (eCachorro*) ll_get(pArrayListCachorro, i), intAux) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 3:
                getName(stringAux, "\nINGRESE LA RAZA: ", "Error. Debe contener entre 2 y 19 caracteres. ", 2, 19);
                if( cachorro_setRaza( (eCachorro*) ll_get(pArrayListCachorro, i), stringAux) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 4:
                getName(stringAux, "\nINGRESE EL ESTADO DE RESERVA: ", "Error. Debe contener 2 caracteres. ", 2, 2);
                if( cachorro_setReservado( (eCachorro*) ll_get(pArrayListCachorro, i), stringAux) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 5:
                getName(stringAux, "\nINGRESE EL GENERO: ", "Error. Debe contener 1 caracter. ", 1, 1);
                if( cachorro_setGenero( (eCachorro*) ll_get(pArrayListCachorro, i), stringAux) )
                {
                    able = 1;
                    printf("\nMODIFICACION REALIZADA CON EXITO!\n");
                }
                break;
            case 6:
                printf("\nSE HA CANCELADO LA MODIFICACION!\n");
                break;
            default:
                printf("OPCION INVALIDA!\n");
            }
        }
    }

    if( !flag )
    {
        printf("\nNO SE ENCONTRO NINGUN CLIENTE CON ESE CODIGO!\n");
    }

    printf("\n");

    return able;
}

int controller_removeCachorro(LinkedList* pArrayListCachorro)
{
    int able = 0;
    int idToSearch;
    char answer = 'n';
    int flag = 0;
    int tam = ll_len(pArrayListCachorro);

    if(pArrayListCachorro != NULL)
    {
        getInt(&idToSearch, "\nINGRESE EL ID DEL CACHORRO A ELIMINAR: ", "ERROR. ", 1, 10000000);

        for(int i=0; i<tam; i++)
        {
            if( idToSearch == ( (eCachorro*) ll_get(pArrayListCachorro, i) )->id )
            {
                printf("ID            NOMBRE      DIAS       RAZA        RESERVADO       GENERO\n");
                printCachorro( (eCachorro*) ll_get(pArrayListCachorro, i) );

                printf("\nDESEA ELIMINAR ESTE CACHORRO? (s/n): ");
                fflush(stdin);
                answer = getche();

                if( answer == 's' )
                {
                    if( !ll_remove(pArrayListCachorro, i) )
                    {
                        printf("\n\nCACHORRO ELIMINADO!\n\n");
                        able = 1;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        printf("\n\nNO SE PUDO ELIMINAR AL CACHORRO!\n\n");
                        flag = 1;
                    }
                }
                else
                {
                    printf("\n\nSE CANCELO LA OPERACION!\n\n");
                    flag = 1;
                    break;
                }
            }
            else
            {
                flag = 0;
            }
        }

        if(flag == 0)
        {
            printf("\nNO SE ENCONTRO CACHORRO CON ESE ID!\n\n");
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
