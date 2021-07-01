#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "eEditoriales.h"
#include "utn.h"

/* ************************************************************************************************************* */
/** \brief Menu de opciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int menuDeOpciones()
{
    printf("\n\t\t***** MENÚ PRINCIPAL *****\n");
    printf("\n 1. CARGAR archivo(.csv).");
    printf("\n 2. LISTAR.");
    printf("\n 3. MAPEO de Datos.");
    printf("\n 0. SALIR");

    setbuf(stdout, NULL);

    return PedirEntero("\n\nIngrese opción: ");
}

/* ************************************************************************************************************* */
/** \brief Carga los datos desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "r"); //Variable puntero al archivo
    int retorno    = 0;

    if(pArchivo != NULL)  //Verifico si la lectura del archivo, si no retorna NULL accedo al parse
    {
        retorno = parser_FromText(pArchivo, pArrayList);
        if(retorno == 1) //Funcion parser modo texto
        {
            printf("\tDatos Cargados exitosamente.\n\n");
        }
    }
    else
    {
        printf("\nArchivo No Encontrado\n\n");
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief Carga los datos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int retorno = 0;
    FILE* pArchivo; //Variable puntero al archivo

    if((pArchivo = fopen(path, "rb")) != NULL)
    {
        parser_FromBinary(pArchivo, pArrayList); //Funcion parser modo bin
        retorno = 1;
    }
    else //Si retorna NULL no encontro el archivo, informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "wb")) != NULL)
        printf("\tNo se encontro el archivo. Se creó uno nuevo con el nombre %s\n\n", path);
    }
    return retorno;
}

/* ************************************************************************************************************* */
int controller_List(LinkedList* pArrayList)
{
	printf(" \t\t*********************** LISTADO DE LIBROS DISPONIBLES *********************** \n\n ");
    printf(" ID |  \t\t\t\t\t TITULO    |  \t\t  AUTOR   |    PRECIO   | EDITORIAL \n\n");

    for(int i = 0; i < ll_len(pArrayList); i ++) //Recorro el array de datos
    {
        eLibros* this = (eLibros*)ll_get(pArrayList, i); //Le asigno al puntero eLibros "this" lo que retorna "ll_get()"
        mostrarLibros(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

/* ************************************************************************************************************* */
int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* text = fopen(path, "w");
    int retorno = 0, id;
    char titulo[50], autor[50], editorial[50];
    float precio;

    if(text != NULL && pArrayList != NULL)
    {
        fprintf(text,"id,titulo,autor,precio,editorial\n");
        for(int i = 0; i < ll_len(pArrayList); i ++)
        {
            eLibros* this = (eLibros*) ll_get(pArrayList, i);
            if(getters(this, &id, titulo, autor, &precio, editorial))
            {
                fprintf(text, "%d,%s,%s,%.1f,%s\n", id, titulo, autor, precio, editorial);
            }
        }
        retorno = 1;
        printf("\tArchivo (mapeado.csv) guardado exitosamente.\n\n");
    }
    else
    {
        printf("\nATENCIÓN! Archivo No Encontrado\n\n");
    }
    fclose(text);
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief Guarda los datos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "wb");
    int retorno = 0, datosLeidos;

    if(pArchivo != NULL && pArrayList != NULL)
    {
        rewind(pArchivo); //Voy al inicio del archivo
        for(int i = 0; i < ll_len(pArrayList); i ++)
        {
            eLibros* this = (eLibros*)ll_get(pArrayList,i);
            datosLeidos   = fwrite(this, sizeof(eLibros), 1, pArchivo);
            retorno       = 1;

            if(datosLeidos != 1)
            {
                printf("\nATENCIÓN! Error al escribir los datos en el archivo.\n\n");
            }
        }
        printf("\nDatos Guardados Con Exito\n\n");
    }
    else
    {
        printf("\n ATENCIÓN! No fue posible acceder al archivo.\n");
    }
    fclose(pArchivo);
    return retorno;
}
