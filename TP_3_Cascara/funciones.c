#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <conio.h>
#include <ctype.h>
int crearArchivoBinario()
{
    FILE *archivo;

    archivo = fopen("peliculas.dat","rb");

    if(archivo == NULL)
    {
        archivo = fopen("peliculas.dat","wb");

        if(archivo == NULL)
        {
            return 1;
        }
    }
    return 0;
}
int agregarPelicula(eMovie* peliculas,int TAM)
{
    int flag=0;
    int i,j;
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[150];
    int letras;

    for(i=0; i<TAM; i++)
    {
        if((peliculas+i)->estado == 0)
        {
            printf("Ingrese titulo de la pelicula:");
            fflush(stdin);
            gets(auxTitulo);
            letras = strlen(auxTitulo);

            for(j=0; i<letras; i++)
            {
                auxTitulo[j] = toupper(auxTitulo[j]);
            }

            for(j=0; j<TAM; j++)
            {
                if(strcmp(auxTitulo,(peliculas+j)->titulo)==0 && (peliculas+j)->estado == 1)
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                printf("Ingrese generos de la pelicula:");
                fflush(stdin);
                gets(auxGenero);

                printf("Ingrese duracion de la pelicula:");
                scanf("%d",&auxDuracion);

                printf("Ingrese descripcion de la pelicula:");
                fflush(stdin);
                gets(auxDescripcion);

                printf("Ingrese puntaje de la pelicula 0/100:");
                scanf("%d",&auxPuntaje);
                while(auxPuntaje < 0 || auxPuntaje > 100)
                {
                    printf("Porfavor reingrese puntaje:");
                    scanf("%d",&auxPuntaje);
                }

                printf("Ingrese link de la imagen:");
                fflush(stdin);
                gets(auxLinkImagen);

                strcpy((peliculas+i)->titulo,auxTitulo);
                strcpy((peliculas+i)->genero,auxGenero);
                (peliculas+i)->duracion = auxDuracion;
                (peliculas+i)->puntaje = auxPuntaje;
                (peliculas+i)->estado = 1;
                strcpy((peliculas+i)->descripcion,auxDescripcion);
                strcpy((peliculas+i)->linkImagen,auxLinkImagen);

                return 1;
            }
            break;
        }
    }
    return 0;
}
int borrarPelicula(eMovie* peliculas, int TAM)
{
    char searchTitulo[20];
    char opcion = 'n';
    int i,j;
    printf("Listado de Peliculas\n");
    for(i=0; i<TAM; i++)
    {
        if((peliculas+i)->estado == 1)
        {
            printf("%s\n",(peliculas+i)->titulo);
        }
    }

    printf("Ingrese pelicula a eliminar:");
    fflush(stdin);
    gets(searchTitulo);

    for(j=0; j<TAM; j++)
    {
        if(strcmp((peliculas+j)->titulo,searchTitulo)==0 && (peliculas+j)->estado != 0)
        {
            printf("Desea eliminar la pelicula s/n:");
            opcion=getche();
            opcion = tolower(opcion);

            if(opcion == 's')
            {
                (peliculas+j)->estado = 0;
                return 1;
            }
            break;
        }
    }
    return 0;
}

int modificarPelicula(eMovie* peliculas,int TAM)
{
    char searchTitulo[20];
    int i,j;
    char seguir = 's';
    int opcion;
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLinkImagen[150];
    int flag = 0;

    printf("Listado de Peliculas\n");
    for(i=0; i<TAM; i++)
    {
        if((peliculas+i)->estado == 1)
        {
            printf("%s\n",(peliculas+i)->titulo);
        }
    }

    printf("Ingrese pelicula a modificar:");
    fflush(stdin);
    gets(searchTitulo);

    for(i=0; i<TAM; i++)
    {
        if(strcmp(searchTitulo,(peliculas+i)->titulo)== 0 && (peliculas+i)->estado == 1)
        {
            while(seguir == 's')
            {
                printf("¿Que informacion desea cambiar?\n");
                printf("1- Desea cambiar el titulo\n");
                printf("2- Desea cambiar el genero\n");
                printf("3- Desea cambiar la duracion\n");
                printf("4- Desea cambiar la descripcion\n");
                printf("5- Desea cambiar el puntaje\n");
                printf("6- Desea cambiar el link de imagen\n");
                printf("5- salir\n");

                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1:
                    printf("\nIngrese Titulo:\n");
                    fflush(stdin);
                    gets(auxTitulo);

                    for(j=0; j<TAM; j++)
                    {
                        if(strcmp((peliculas+j)->titulo,auxTitulo)== 0 && (peliculas+j)->estado == 1)
                        {
                            flag = 1;
                        }
                    }
                    if(flag != 1)
                    {
                        strcpy((peliculas+i)->titulo,auxTitulo);
                        printf("Se cambio exitosamente\n");
                    }
                    else
                    {
                        printf("Titulo ya existente ingrese otro\n");
                    }
                    system("pause");
                    break;
                case 2:
                    printf("Ingrese Genero");
                    fflush(stdin);
                    gets(auxGenero);
                    strcpy((peliculas+i)->genero,auxGenero);
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese Duracion");
                    scanf("%d",&auxDuracion);
                    while(auxPuntaje < 0 || auxPuntaje > 100)
                    {
                        printf("Porfavor reingrese puntaje:");
                        scanf("%d",&auxPuntaje);
                    }
                    (peliculas+i)->duracion = auxDuracion;
                    system("pause");
                    break;
                case 4:
                    printf("Ingrese Descripcion");
                    fflush(stdin);
                    gets(auxDescripcion);
                    strcpy((peliculas+i)->descripcion,auxDescripcion);
                    system("pause");
                    break;
                case 5:
                    printf("Ingrese Puntaje");
                    scanf("%d",&auxPuntaje);
                    while(auxPuntaje>=0 && auxPuntaje <=100)
                    {
                        printf("Porfavor reingrese puntaje:");
                        scanf("%d",&auxPuntaje);
                    }
                    (peliculas+i)->puntaje = auxPuntaje;
                    system("pause");
                    break;
                case 6:
                    printf("Ingrese Link de la imagen");
                    fflush(stdin);
                    gets(auxLinkImagen);
                    strcpy((peliculas+i)->linkImagen,auxLinkImagen);
                    system("pause");
                    break;
                case 7:
                    seguir = 'n';
                    return 1;
                    break;
                default:
                    printf("Ingrese una opcion");
                    break;
                }

            }
        }
    }
    return 0;
}
int guardarArchivoBinario(eMovie* peliculas,int TAM,int* pTAM)
{
    FILE* archivo;
    archivo = fopen("peliculas.dat","wb");
    if(archivo!=NULL)
    {
        fwrite(pTAM,sizeof(int),1,archivo);

        fwrite(peliculas,sizeof(eMovie),TAM,archivo);

        fclose(archivo);
        return 0;
    }
    else
    {
        return 1;
    }
}
void generarPagina(eMovie* peliculas, char HTML[50],int contarPelis)
{
    FILE* archivo;
    int i;
    archivo=fopen(HTML,"w");

    if(archivo!=NULL)
    {
        fprintf(archivo,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
        for(i=0; i<contarPelis; i++)
        {
            if((peliculas+i)->estado == 1)
            {
                fprintf(archivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(peliculas+i)->linkImagen);
                fprintf(archivo,"<h3><a href='#'>%s</a></h3>\n",(peliculas+i)->titulo);
                fprintf(archivo,"<ul><li>Genero:%s</li>\n<li>Puntaje 0/100:%d</li>\n<li>Duracion:%d</li></ul>\n",(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion);
                fprintf(archivo,"<p>%s</p></article>",(peliculas+i)->descripcion);
            }
        }
        fprintf(archivo,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
        fclose(archivo);
        printf("Se creo el archivo html\n");
    }
    else
    {
        printf("No se pudo escribir en el archivo");
    }
}
