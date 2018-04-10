#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int PedirNumero()
{
    int numero;
    printf("Ingrese numero:");
    scanf("%d",&numero);
    return numero;
}
int sumar(int num1,int num2)
{
    int resultado;
    resultado = num1 + num2;

    return resultado;
}
int resta(int num1,int num2)
{
    int resultado;
    resultado = num1 - num2;

    return resultado;
}
float division(int num1,int num2)
{
    float resultado;
    float num1Float;
    float num2Float;
    num1Float = (float)num1;
    num2Float = (float)num2;

    if(num2Float == 0)
    {
        return 0;
    }
    resultado = num1Float/num2Float;

    return resultado;
}
int multiplicacion(int num1,int num2)
{
    int resultado;
    resultado = num1 * num2;

    return resultado;
}
int factorial(int num1)
{
    int resultado = 1;
    int i = num1;
    for(i;i>1;i--)
    {
        resultado = resultado*i;
    }
    return resultado;
}
