#ifndef editorial_h_INCLUDED
#define editorial_h_INCLUDED

#endif

typedef struct
{
    int   var_1;
    char  var_2[50];
    char  var_3[50];
    float var_4;
    int   var_5;
}eLibros;

eLibros* new();
eLibros* setters(char* var_1,char* var_2, char* var_3, char* var_4, char* var_5);

void mapPrecio(void* this);
int  mostrarLibros(eLibros* this);
int  getters(eLibros* this, int* var_1, char* var_2, char* var_3, float* var_4, char* var_5);

int setId(eLibros* this,int var_1);
int getId(eLibros* this,int* var_1);

int setTitulo(eLibros* this,char* var_2);
int getTitulo(eLibros* this,char* var_2);

int setAutor(eLibros* this,char* var_3);
int getAutor(eLibros* this,char* var_3);

int setPrecio(eLibros* this,float var_4);
int getPrecio(eLibros* this,float* var_4);

int setIdEditorial(eLibros* this,int var_5);
int getIdEditorial(eLibros* this,char* var_5);

int ordenrPorID(void* datoA, void* datoB);
int ordenarPorAutor(void* punteroA, void* punteroB);


