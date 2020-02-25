#include <stdio.h>
#include <stdlib.h>
#include "Cachorros.h"
#include "Controller.h"
#include "Lisba_libreria.h"
#include "LinkedList.h"
#include "informes.h"

int main()
{
    LinkedList* listaCachorros = NULL;
    LinkedList* listaCachorrosMayores45Dias = NULL;
    LinkedList* listaMachos = NULL;
    LinkedList* ListaCallejeros = NULL;
    char respuestaSalirPrograma = 'n';
    char nombreArchivo[31];
    int sortOption;
    char respuestaSalirMenuFiltro = 'n';
    char respuestaGeneraArchivoFiltros = 'n';
    char respuestaSalirMenuInformes = 'n';
    char nombreArchCachorrMayor45Dias[31];
    char nombreArchSoloHembras[31];
    char nombreArchSoloCallejeros[31];
    char newNombreArchivo[31];

    do
    {
        switch( menu() )
        {
        case 1:
            listaCachorros = ll_newLinkedList();
            if( listaCachorros != NULL )
            {
                getString(nombreArchivo, "\nINGRESE EL NOMBRE DEL ARCHIVO A ABRIR (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);
                if( controller_loadFromText(nombreArchivo, listaCachorros) )
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
                controller_editCachorro(listaCachorros);
            }
            else
            {
                printf("\nPRIMERO DEBE CARGAR LOS DATOS DESDE EL ARCHIVO!\n\n");
            }
            system("pause");
            break;
        case 4:
             if( !ll_isEmpty(listaCachorros) )
            {
                controller_removeCachorro(listaCachorros);
            }
            else
            {
                printf("\nPRIMERO DEBE CARGAR LOS DATOS DESDE EL ARCHIVO!\n\n");
            }
            system("pause");
            break;
        case 5:
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
        case 6:
            if( !ll_isEmpty(listaCachorros) )
            {
                do
                {
                    switch( filterMenu() )
                    {
                        case 1:
                            listaCachorrosMayores45Dias = ll_filter(listaCachorros, filtrarMenores45);

                            controller_ListCachorros(listaCachorrosMayores45Dias);

                            getChar(&respuestaGeneraArchivoFiltros, "\nDESEA GENERAR UN ARCHIVO DE ESTA LISTA? (s/n): ", "ERROR, INGRESE SOLO 's' O 'n'. ", 'n', 's');

                            if(respuestaGeneraArchivoFiltros == 's')
                            {
                                getString(nombreArchCachorrMayor45Dias, "\nINGRESE EL NOMBRE DEL ARCHIVO (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);

                                if( controller_saveAsText(nombreArchCachorrMayor45Dias, listaCachorrosMayores45Dias) )
                                {
                                    printf("\nARCHIVO DE CACHORROS MAYORES A 45 DIAS GUARDADO!\n\n");
                                }
                                else
                                {
                                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS MAYORES A 45 DIAS!\n\n");
                                }
                                system("pause");
                            }
                            break;
                        case 2:
                            listaMachos = ll_filter(listaCachorros, filtrarMachos);

                            controller_ListCachorros(listaMachos);

                            getChar(&respuestaGeneraArchivoFiltros, "\nDESEA GENERAR UN ARCHIVO DE ESTA LISTA? (s/n): ", "ERROR, INGRESE SOLO 's' O 'n'. ", 'n', 's');

                            if(respuestaGeneraArchivoFiltros == 's')
                            {
                                getString(nombreArchSoloHembras, "\nINGRESE EL NOMBRE DEL ARCHIVO (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);

                                if( controller_saveAsText(nombreArchSoloHembras, listaMachos) )
                                   {
                                        printf("\nARCHIVO DE CACHORROS HEMBRAS GUARDADO!\n\n");
                                   }
                                else
                                {
                                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS HEMBRAS!\n\n");
                                }
                                system("pause");
                            }
                            break;
                        case 3:
                            ListaCallejeros = ll_filter(listaCachorros, filtrarCallejeros);

                            controller_ListCachorros(ListaCallejeros);

                            getChar(&respuestaGeneraArchivoFiltros, "\nDESEA GENERAR UN ARCHIVO DE ESTA LISTA? (s/n): ", "ERROR, INGRESE SOLO 's' O 'n'. ", 'n', 's');

                            if(respuestaGeneraArchivoFiltros == 's')
                            {
                                getString(nombreArchSoloCallejeros, "\nINGRESE EL NOMBRE DEL ARCHIVO (CON EXTENSION): ", "ERROR! MAXIMO 30 CARACTERES! ", 1, 30);

                                if( controller_saveAsText(nombreArchSoloCallejeros, ListaCallejeros) )
                                   {
                                        printf("\nARCHIVO DE CACHORROS CALLEJEROS GUARDADO!\n\n");
                                   }
                                else
                                {
                                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO DE CACHORROS CALLEJEROS!\n\n");
                                }
                                system("pause");
                            }
                            break;
                        case 4:
                            getChar(&respuestaSalirMenuFiltro, "\nSEGURO QUE DESEA SALIR? (s/n): ", "\nOPCION INVALIDA! \n", 'n', 's');
                            break;
                        default:
                            printf("\nOPCION INVALIDA!!!\n\n");
                            system("pause");
                            break;
                    }

                }while(respuestaSalirMenuFiltro != 's');
            }
            else
            {
                printf("\nNO SE PUDO GENERAR LA LISTA!\n\n");
            }
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
             if( !ll_isEmpty(listaCachorros) )
            {
                do
                {
                    switch( informesMenu() )
                    {
                        case 1:
                            cachorroMasJoven(listaCachorros);
                            system("pause");
                            break;
                        case 2:
                            cachorroMasViejo(listaCachorros);
                            system("pause");
                            break;
                        case 3:
                            getChar(&respuestaSalirMenuInformes, "\nSEGURO QUE DESEA SALIR? (s/n): ", "\nOPCION INVALIDA! \n", 'n', 's');
                            break;
                        default:
                            printf("\nOPCION INVALIDA!!!\n\n");
                            break;
                    }

                }while(respuestaSalirMenuInformes != 's');
            }
            else
            {
                printf("\nPRIMERO DEBE CARGAR LOS DATOS DESDE EL ARCHIVO!\n\n");
            }
            system("pause");
            break;
        case 9:
            if ( !ll_isEmpty(listaCachorros) )
                {
                    switch( guardarArchivoMenu() )
                    {
                    case 1:
                        if( controller_saveAsText(nombreArchivo, listaCachorros) )
                        {
                            printf("\nDATOS GUARDADOS EN EL ARCHIVO DE TEXTO EXITOSAMENTE!\n\n");
                        }
                        else
                        {
                            printf("\nNO SE PUDO GUARDAR LOS DATOS!\n\n");
                        }
                        break;
                    case 2:
                        getString(newNombreArchivo, "\nINGRESE EL NOMBRE DEL NUEVO ARCHIVO: ", "ERROR, DEBE CONTENER ENTRE 1 Y 30 CARACTERES. ", 1, 30);
                        if( controller_saveAsText(newNombreArchivo, listaCachorros) )
                        {
                            printf("\nDATOS GUARDADOS EN EL ARCHIVO DE TEXTO EXITOSAMENTE!\n\n");
                        }
                        else
                        {
                            printf("\nNO SE PUDO GUARDAR LOS DATOS!\n\n");
                        }
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    printf("\nNO HAY DATOS CARGADOS!\n\n");
                }
                system("pause");
            break;
        case 10:
            getChar(&respuestaSalirPrograma, "\nSEGURO QUE DESEA SALIR? (s/n): ", "\nOPCION INVALIDA! \n", 'n', 's');
            break;
        default:
            printf("\nOPCION INVALIDA!!!\n\n");
            break;
        }

    }while(respuestaSalirPrograma != 's');

    return 0;
}
