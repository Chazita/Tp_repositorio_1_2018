#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>

int main()
{
    int TAM = 20; //El codeblocks no compila cuando pongo define!
    int index,dniBuscar,indexBorrar;
    int menor18,de19a35,mayorDe35,total;
    ePersona personas[TAM];
    char seguir='s';
   // inicializarDatos(personas,TAM);
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                index = obtenerEspacioLibre(personas,TAM);
                if(index >= 0)
                {
                    alta(personas,index);
                }
                else
                {
                    printf("\nNo hay mas espacio en memoria");
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                printf("\nIngrese DNI a buscar:");
                scanf("%d",&dniBuscar);
                indexBorrar = buscarPorDni(personas,dniBuscar,TAM);
                if(indexBorrar >= 0)
                {
                    borrar(personas,indexBorrar);
                }
                else
                {
                    printf("\nNo existe persona con ese dni");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                imprimirPersonas(personas,TAM);
                system("pause");
                break;
            case 4:
                system("cls");
                menor18 = 0;
                de19a35 = 0;
                mayorDe35 = 0;
                total = 0;
                graficoDatos(personas,menor18,de19a35,mayorDe35,total,TAM);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta ingrese opcion correcta");
                system("pause");
                break;
        }
    system("cls");
    }

    return 0;
}
