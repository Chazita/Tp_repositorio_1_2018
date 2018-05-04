#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[51];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[],int );

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni . Si no encuentra
 el dni devuelve -1.
 */
int buscarPorDni(ePersona lista[], int dni, int );

/**
 * Da de alta a la persona.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 */
void alta(ePersona [],int);

/**
 * Elimina a una persona del array.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 */
void borrar(ePersona [],int);

/**
 * Inicializa el estado de las personas en 0.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 */
void inicializarEstado(ePersona personas[],int TAM);

/**
 * Imprime en consola todas las personas del array.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 */
void imprimirPersonas(ePersona [],int);

/**
 * Ordena por nombre a las personas.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 */
void ordenar(ePersona [],int);

/**
 * Grafico por edad de las pesonas.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 */
void graficoDatos(ePersona [],int ,int,int,int,int);

/** Inicializa el vector para no tener que ingresar datos para el testeo.
 * \param El vector de personas
 * \param El tamaño del vector
 */
void inicializarDatos(ePersona lista[], int TAM);
#endif // FUNCIONES_H_INCLUDED
