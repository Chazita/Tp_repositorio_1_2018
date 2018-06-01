#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}eMovie;

/**
 *  Crea el archivo binario
 *  @return retorna 1 si no pudo crear el archivo , 0 si pudo crearlo
 */
int crearArchivoBinario();
/**
 *  Agrega una pelicula al archivo binario
 *  @param recibe la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie*,int);

/**
 *  Borra una pelicula del archivo binario
 *  @param recibe la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie*,int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie*, char [],int );
/**
 *  Modificar la pelicula mediante un menu de opciones
 *  @param recibe la estructura a modificar y el tamaño
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
 int modificarPelicula(eMovie*,int);
 /**
 *  Guarda el archivo binario
 *  @param recibe la estructura y el tamaño de ella.
 *  @return retorna 1 si se guardo correctamente y 0 si se produjo algun error
 */
int guardarArchivoBinario(eMovie*,int,int*);
#endif // FUNCIONES_H_INCLUDED
