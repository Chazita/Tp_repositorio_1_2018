#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>
#include <ctype.h>

void inicializarEstado(ePersona personas[],int TAM)
{
    for(int i=0;i<TAM;i++)
    {
        personas[i].estado = 0;
    }
}
int obtenerEspacioLibre(ePersona lista[],int TAM)
{
    int libre = -1;
    for(int i=0;i<TAM;i++)
    {
        if(lista[i].estado == 0)
        {
            libre = i;
            break;
        }
    }
    return libre;
}

void alta(ePersona personas[],int index)
{
    ePersona auxPersona;

    printf("Ingrese nombre:");
    fflush(stdin);
    gets(auxPersona.nombre);

    printf("Ingrese edad:");
    scanf("%d",&auxPersona.edad);

    printf("Ingrese dni:");
    scanf("%d",&auxPersona.dni);

    auxPersona.estado = 1;

    personas[index] = auxPersona;

}

void borrar(ePersona personas[],int index)
{
    char confirmar;
    printf("%s\t %d\t %d",personas[index].nombre,personas[index].edad,personas[index].dni);
    printf("\nEsta seguro que quiere borrar a la persona S/N:");
    confirmar = getche();
    confirmar = tolower(confirmar);
    if(confirmar == 's')
    {
        personas[index].estado = 0;
    }
}

int buscarPorDni(ePersona persona[], int dni,int TAM)
{
    int lugar = -1;
    for(int i=0;i<TAM;i++)
    {
        if(dni == persona[i].dni)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}
void ordenar(ePersona persona[],int TAM)
{
    ePersona auxPersona;
    for(int i=0;i<TAM-1;i++)
    {
        for(int j=i+1;j<TAM;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre) >= 1)
            {
                auxPersona = persona[i];
                persona[i] = persona[j];
                persona[j] = auxPersona;
            }
        }
    }
}

void imprimirPersonas(ePersona persona[],int TAM)
{
    ordenar(persona,TAM);
    printf("Nombre\t DNI\t EDAD\n");
    for(int i=0;i<TAM;i++)
    {
        if(persona[i].estado == 1)
        {
            printf("%s\t %d\t %d \n",persona[i].nombre,persona[i].dni,persona[i].edad);
        }
    }
}

void graficoDatos(ePersona lista[], int menor18,int de19a35, int mayorDe35,int total,int TAM) //Arma un grafico por edades.
{
    int i,flag;
    for(i=0; i<TAM; i++)
    {
        flag=0;

        if(lista[i].estado == 1)
        {
            if(lista[i].edad<=18)
            {
                menor18++;
            }
            else
            {
                if(lista[i].edad>35)
                {
                    de19a35++;
                }
                else
                {
                    mayorDe35++;
                }
            }

        }
    }
    if(menor18 >= de19a35 && menor18 >= mayorDe35)
    {
        total = menor18;
    }
    else
    {
        if(de19a35 >= menor18 && de19a35 >= mayorDe35)
        {
            total = de19a35;
        }
        else
        {
            total = mayorDe35;
        }
    }
    for(i=total; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d",i);
        }
        if(i<=menor18)
        {
            printf("*");
        }
        if(i<=de19a35)
        {
            flag = 1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag == 0)
            {
                printf("\t\t*");
            }
            if(flag == 1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("--------------------");
    printf("\n  |<18\t19-35\t>35");
}
void inicializarDatos(ePersona lista[], int TAM) //Se hardcodean para facilitar el testeo del programador.
{
    char nombre[][50]= {"Roberto","Marcela","Julian","Tomas","Agustin","Augusto","Luna","Chiara","Florencia","Sofia","Julieta","Sofia","Luna","Matias","Juan Pablo","Rigoberto","Roberta","Roberto","Saturnino","Mariana"};
    float edad[]= {18,20,7,52,52,61,12,2,13,25,24,38,65,5,18,89,2,20,60,90};
    int estado[]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int dni[]= {123,312,142,1232,5125,5123,5123,5634,6757,85467,4235,342534,34253245,346346,23462346,34263246,23463426,23462346,23462346,5473457};

    int i;

    for(i=0; i<TAM; i++)
    {
        lista[i].dni = dni[i];
        lista[i].edad = edad[i];
        lista[i].estado = estado[i];
        strcpy(lista[i].nombre,nombre[i]);
    }

}

