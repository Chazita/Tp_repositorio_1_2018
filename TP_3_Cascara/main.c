#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 15

int main()
{
    eMovie* peliculas;
    int pelis=TAM;
    int* pTAM=&pelis;
    char HTML[50]={"Peliculas.html"};
    char seguir='s';
    int agregar;
    int seElimino;
    int opcion=0;
    int modificar;
    int guardar;

    peliculas = (eMovie*)calloc(TAM,sizeof(eMovie));

    if(peliculas == NULL)
    {
        printf("No hay espacio\n");
    }

    if(crearArchivoBinario()==1)
    {
        printf("No se puedo crear el archivo\n");
    }
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregar = agregarPelicula(peliculas,TAM);
                if(agregar != 1)
                {
                    printf("Titulo de la pelicula ya existente\n");
                }
                else
                {
                    printf("Pelicula guardada exitosamente\n");
                }
                system("pause");
                break;
            case 2:seElimino = borrarPelicula(peliculas,TAM);
                if(seElimino == 1)
                {
                    printf("Se elimino la pelicula\n");
                }
                else
                {
                    printf("No se elimino la pelicula\n");
                }
                system("pause");
                break;
            case 3:modificar=modificarPelicula(peliculas,TAM);
                   if(modificar != 1)
                   {
                       printf("No se encontro pelicula a modificar\n");
                   }
                   else
                   {
                       printf("Se modifico la pelicula\n");
                   }
                   system("pause");
               break;
            case 4:guardar = guardarArchivoBinario(peliculas,TAM,pTAM);
                if(guardar != 0)
                {
                    printf("\nError!!No se pudo guardar el archivo binario\n");
                }
                generarPagina(peliculas,HTML,TAM);

                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("ERROR!Ingrese una opcion valida\n");
                break;
        }
    }

    return 0;
}
