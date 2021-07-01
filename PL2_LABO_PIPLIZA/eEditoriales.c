#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eEditoriales.h"
#include "utn.h"

/* ************************************************************************************************************* */
eLibros* new()
{
    eLibros* this = malloc(sizeof(eLibros)); //Creo un nuevo editorial con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("ATENCIÓN! Sin lugar para almacenar datos.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
    	this->var_1 = 0;
        strcpy(this->var_2, "");
        strcpy(this->var_3, "");
        this->var_4 = 0;
        this->var_5 = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

/* ************************************************************************************************************* */
eLibros* setters(char* var_1,char* var_2, char* var_3, char* var_4, char* var_5)
{//asigno los valores
    eLibros* this = new();
    int retorno = 0;

    if(setId(this,atoi(var_1)))
    {
        retorno = 1;
    }

    if(setTitulo(this,var_2) && retorno)
    {
        retorno = 1;
    }

    if(setAutor(this,var_3) && retorno)
    {
        retorno = 1;
    }

    if(setPrecio(this,atof(var_4)) && retorno)
    {
        retorno = 1;
    }

    if(setIdEditorial(this,atoi(var_5)) && retorno)
    {
        retorno = 1;
    }

    if(!retorno)
    {
        printf("\nATENCIÓN! Error al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

/* ************************************************************************************************************* */
int getters(eLibros* this, int* var_1, char* var_2, char* var_3, float* var_4, char* var_5)
{
    int retorno = 0;

    if (this != NULL)
    {
        if (getId(this, var_1))
        {
            retorno = 1;
        }
        if (getTitulo(this, var_2) && retorno)
        {
            retorno = 1;
        }
        if (getAutor(this, var_3) && retorno)
        {
            retorno = 1;
        }
        if (getPrecio(this, var_4) && retorno)
        {
            retorno = 1;
        }
        if (getIdEditorial(this, var_5) && retorno)
        {
            retorno = 1;
        }
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setId(eLibros* this,int var_1)
{
    int retorno = 0;

    if(this != NULL && var_1 >= 0)
    {
        this->var_1 = var_1;
        retorno     = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getId(eLibros* this,int* var_1)
{
    int retorno = 0;

    if(this != NULL && var_1 != NULL)
    {
        *var_1  = this->var_1;
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setTitulo(eLibros* this,char* var_2)
{
    int retorno = 0;

    if(this != NULL)
    {
        strncpy(this->var_2, var_2, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getTitulo(eLibros* this,char* var_2)
{
    int retorno = 0;

    if (this != NULL)
    {
        strncpy(var_2, this->var_2, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setAutor(eLibros* this,char* var_3)
{
    int retorno = 0;

    if(this != NULL)
    {
        strncpy(this->var_3, var_3, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getAutor(eLibros* this,char* var_3)
{
    int retorno = 0;

    if (this != NULL)
    {
        strncpy(var_3, this->var_3, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setIdEditorial(eLibros* this,int var_5)
{
    int retorno=0;

    if(this != NULL && var_5 >= 0)
    {
        this->var_5 = var_5;
        retorno     = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getIdEditorial(eLibros* this,char* var_5)
{
    int retorno = 0;

    if(this != NULL && var_5 != NULL)
    {
        switch(this->var_5)
        {
			case 1:
				strncpy(var_5, "PLANETA", 50);
			break;

			case 2:
				strncpy(var_5, "SIGLO XXI EDITORES", 50);
			break;

			case 3:
				strncpy(var_5, "PEARSON", 50);
			break;

			case 4:
				strncpy(var_5, "MINOTAURO", 50);
			break;

			case 5:
				strncpy(var_5, "SALAMANDRA", 50);
			break;

			case 6:
				strncpy(var_5, "PENGUIN BOOKS", 50);
			break;
        }
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setPrecio(eLibros* this,float var_4)
{
    int retorno=0;
    if(this != NULL && var_4 > 0)
    {
        this->var_4 = var_4;
        retorno=1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getPrecio(eLibros* this,float* var_4)
{
    int retorno = 0;
    if(this != NULL && var_4 != NULL)
    {
        *var_4 = this->var_4;
        retorno=1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int mostrarLibros(eLibros* this)
{
    int retorno = 0;
    int var_1;
    float var_4;
    char  var_2[50];
    char  var_3[50];
    char  var_5[50];

    if (getters(this, &var_1, var_2, var_3, &var_4, var_5))
    {
        printf(" %3d | %50s  | %20s | $%10.2f | %3s \t\t \n", var_1, var_2, var_3, var_4, var_5);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief ordena por id libro var_1
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (-1) si punteroA menor a punteroB
               (0) si punteroA igual a punteroB
               (1) si punteroA manor a punteroB
               (-2) If NULL pointer
 *
 */
int ordenrPorID(void* punteroA, void* punteroB)
{
    int retorno = -2;

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        getId(punteroA, &id_A);
        getId(punteroB, &id_B);

        if((id_A) < (id_B)) //Si var_1 de A en menor que var_1 de B cambio al retorno retorno a 1
        {
            retorno = 1 ;
        }
        else
        {
        	if((id_A) == (id_B)) //Si var_1 de A igual que var_1 de B dejo la retorno igual
        	{
        		retorno = 0;
        	}
			else
			{
				retorno = -1;
			}
        }
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief ordena por nombre Autor
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
int ordenarPorAutor(void* punteroA, void* punteroB)
{
    int retorno = 1;

    if(punteroA != NULL && punteroB != NULL)
    {
        char aux_A[50];
        char aux_B[50];

        getAutor(punteroA, aux_A);
        getAutor(punteroB, aux_B);
        retorno = strcmp(aux_A, aux_B);
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief Asigna el var_4 de det libros
 *
 * \param void* this
 * \return Retorna -1 si hay error y si no 0.
 *
 */
void mapPrecio(void* this)
{
    float var_4;
    char var_5[50];

    if (this != NULL)
    {
        getIdEditorial(this, var_5);
        getPrecio(this, &var_4);

        if(!strcmp(var_5, "PLANETA") && var_4 >= 300)
        {
            setPrecio(this, var_4 * 0.8);
        }
        else
        {
        	if(!strcmp(var_5, "SIGLO XXI EDITORES") && var_4 <= 200)
        	{
        		setPrecio(this, var_4 * 0.9);
        	}
        }
    }
}

