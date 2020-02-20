#include <stdio.h>
#include <stdlib.h>
#include "Cachorros.h"
#include "Controller.h"
#include "Lisba_libreria.h"
#include "LinkedList.h"

int main()
{
    LinkedList* listaCachorros = NULL;
    LinkedList* listaCachorrosMenores45Dias = NULL;
    LinkedList* listaMachos = NULL;
    LinkedList* ListaCallejeros = NULL;
    char respuesta = 'n';
    char NombreArchivo[31];
    int sortOption;
    char nombreArchCachorrMayor45Dias[31];
    char nombreArchSoloHembras[31];
    char nombreArchSoloCallejeros[31];

    do
    {
        switch( menu() )
        {
        case 1:
            listaCachorros = ll_newLinkedList();
            if( listaCachorros != NULL )
            {
                getString(NombreArchivo, "\nINGRESE EL NOMBRE DEL ARCHIVO A ABRIR (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);
                if( controller_loadFromText(NombreArchivo, listaCachorros) )
                {
                    printf("\nDATOS CARGADOS CORRECTAMENTE!\n\n");
                }
                else
                {
                    printf("\nNO SE PUDO CARGAR EL ARCHIVO!\n\n");
                }
            }
            else
            {
                printf("\n\nNO SE PUDO CARGAR EL ARCHIVO YA QUE LA LISTA ES NULL!\n\n");
            }
            system("pause");
            break;
        case 2:
            if( !ll_isEmpty(listaCachorros) )
            {
                controller_addCachorro(listaCachorros);
            }
            else
            {
                printf("\nPRIMERO DEBE CARGAR LOS DATOS DESDE EL ARCHIVO!\n\n");
            }
            system("pause");
            break;
        case 3:
            if( !ll_isEmpty(listaCachorros) )
            {
                controller_ListCachorros(listaCachorros);
            }
            else
            {
                printf("\nNO SE PUDO MOSTRAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 4:
            if( !ll_isEmpty(listaCachorros) )
            {
                listaCachorrosMenores45Dias = ll_filter(listaCachorros, filtrarMenores45);

                getString(nombreArchCachorrMayor45Dias, "\nINGRESE EL NOMBRE DEL ARCHIVO (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);

                controller_ListCachorros(listaCachorrosMenores45Dias);

                if( controller_saveAsText(nombreArchCachorrMayor45Dias, listaCachorrosMenores45Dias) )
                   {
                        printf("\nARCHIVO DE CACHORROS MAYORES A 45 DIAS GUARDADO!\n\n");
                   }
                else
                {
                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS MAYORES A 45 DIAS!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 5:
            if( !ll_isEmpty(listaCachorros) )
            {
                listaMachos = ll_filter(listaCachorros, filtrarMachos);

                getString(nombreArchSoloHembras, "\nINGRESE EL NOMBRE DEL ARCHIVO (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);

                controller_ListCachorros(listaMachos);

                if( controller_saveAsText(nombreArchSoloHembras, listaMachos) )
                   {
                        printf("\nARCHIVO DE CACHORROS HEMBRAS GUARDADO!\n\n");
                   }
                else
                {
                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS HEMBRAS!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 6:
            if( !ll_isEmpty(listaCachorros) )
            {
                ListaCallejeros = ll_filter(listaCachorros, filtrarCallejeros);

                getString(nombreArchSoloCallejeros, "\nINGRESE EL NOMBRE DEL ARCHIVO (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);

                controller_ListCachorros(ListaCallejeros);

                if( controller_saveAsText(nombreArchSoloCallejeros, ListaCallejeros) )
                   {
                        printf("\nARCHIVO DE CACHORROS CALLEJEROS GUARDADO!\n\n");
                   }
                else
                {
                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS CALLEJEROS!\n\n");
                }
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 7:
            if( !ll_isEmpty(listaCachorros) )
            {
                getInt(&sortOption, "ASCENDENTE (1) O DESCENDENTE (0)?: ", "ERROR! ", 0, 1);

                if(sortOption)
                {
                    ll_sort(listaCachorros, ordenarListaPorId, 1);
                }
                else
                {
                    ll_sort(listaCachorros, ordenarListaPorId , 0);
                }
                printf("\nLA LISTA HA SIDO ORDENADA!\n\n");
            }
            else
            {
                printf("\nNO SE PUDO ORDENAR LA LISTA!\n\n");
            }
            system("pause");
            break;
        case 8:
            if ( !ll_isEmpty(listaCachorros) )
                {
                    if( controller_saveAsText("cachorros1.csv", listaCachorros) )
                    {
                        printf("\nDATOS GUARDADOS EN EL ARCHIVO DE TEXTO EXITOSAMENTE!\n\n");
                    }
                    else
                    {
                        printf("\nNO SE PUDO GUARDAR LOS DATOS!\n\n");
                    }
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
                }
                system("pause");
            break;
        case 9:
            getChar(&respuesta, "\nSEGURO QUE DESEA SALIR? (s/n): ", "\nOPCION INVALIDA! \n", 'n', 's');
            break;
        default:
            printf("\nOPCION INVALIDA!!!\n\n");
            break;
        }

    }while(respuesta != 's');

    return 0;
}
