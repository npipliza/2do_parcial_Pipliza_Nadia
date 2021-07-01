/* ============================================================================================================
    Laboratorio I : 2do Parcial
    Division      : 1ro B
    Alumna        : Pipliza Nadia
   ============================================================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eEditoriales.h"
#include "utn.h"
#define TAME 50
int main()
{
    int salir = 0;
    char archivo[20];
    LinkedList* list = ll_newLinkedList();

    printf("\n*********************************************************************************"
           "\n\t\t\t INICIO DEL PROGRAMA"
           "\n*********************************************************************************\n");
    do
    {
        switch(menuDeOpciones())
        {
        	//USUARIO CARGA ARCHIVO CSV
			case 1:
				if(ll_isEmpty(list))
				{
					printf("\nIngrese el nombre del archivo: ");
					scanf("%s",archivo);
					controller_loadFromText(archivo, list);
				}
				else
				{
					printf("\nATENCIÓN! Este archivo ya se encuentra cargado.\n\n");
				}
				system("pause");
			break;

			//MOSTRAR Y ORDENAR LISTA POR AUTOR ASCENDENTE
			case 2:
				if (!ll_isEmpty(list))
				{
					ll_sort(list, ordenarPorAutor, 1);
					controller_List(list);
				}
				else
				{
					printf("\nATENCIÓN! Primero se debe cargar Archivo.\n\n");
				}
				system("pause");
			break;

			//MAPEO
			case 3:
				if (!ll_isEmpty(list))
				{
					LinkedList* listMapear = ll_map(list, mapPrecio);
					if(controller_List(listMapear))
					{
						controller_saveAsText("mapeado.csv",listMapear);
					}
					else
					{
						printf("\nATENCIÓN! No es posible guardar el archivo.\n\n");
					}
				}
				else
				{
					printf("\nATENCIÓN! Primero se debe abrir el Archivo.\n\n");
				}
				system("pause");
			break;

			//SALIR
			case 0:
				salir = 1;
			break;
        }
    }while(salir != 1);

    printf("\n*********************************************************************************"
           "\n\t\t\t  PROGRAMA FINALIZADO"
           "\n*********************************************************************************\n");
    return 0;
}
