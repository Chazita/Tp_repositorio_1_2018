#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int num1 = 0,num2 = 0,rSuma = 0,rResta = 0,rMultiplicacion=0,rFactorial;
    float rDivision= 0;
    int true1=0;
    int true2=0;
    int opcion=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%d)\n",num1);
        printf("2- Ingresar 2do operando (B=%d)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            num1 = PedirNumero();
            true1 = 1;
            break;
        case 2:
            num2 = PedirNumero();
            true2 = 1;
            break;
        case 3:
            if(true1 == 1 && true2 == 1)
            {
                rSuma = sumar(num1,num2);
                printf("Resultado de la suma es %d\n",rSuma);

            }
            else
            {
                printf("Falta Ingresar un operador \n");
            }
            system("pause");
            break;
        case 4:
            if(true1 == 1 && true2 == 1)
            {
                rResta = resta(num1,num2);
                printf("Resultado de la resta es %d\n",rResta);

            }
            else
            {
                printf("Falta Ingresar un operador \n");
            }
            system("pause");
            break;
        case 5:
            if(true1 == 1 && true2 == 1)
            {
                rDivision = division(num1,num2);

                if(rDivision == 0)
                {
                    printf("Es imposible hacer dividir por 0\n ");
                }
                else
                {
                    printf("Resultado de la division es %f\n",rDivision);
                }
            }
            else
            {
                printf("Falta Ingresar un operador \n");
            }

            system("pause");
            break;
        case 6:
            if(true1 == 1 && true2 == 1)
            {
                rMultiplicacion = multiplicacion(num1,num2);
                printf("Resultado de la multiplicacion es %d\n",rMultiplicacion);

            }
            else
            {
                printf("Falta Ingresar un operador \n");
            }
            system("pause");
            break;
        case 7:
            if(true1 == 1)
            {
                rFactorial = factorial(num1);
                printf("Resultado del factorial es %d\n",rFactorial);

            }
            else
            {
                printf("Falta Ingresar un operador \n");
            }
            system("pause");
            break;
        case 8:
            if(true1 == 1 && true2 == 1)
            {
                rSuma = sumar(num1,num2);
                rResta = resta(num1,num2);
                rDivision = division(num1,num2);
                rMultiplicacion = multiplicacion(num1,num2);
                rFactorial = factorial(num1);

                printf("Resultado de la suma es %d\n",rSuma);
                printf("Resultado de la resta es %d\n",rResta);

                if(rDivision == 0)
                {
                    printf("Es imposible hacer dividir por 0\n ");
                }
                else
                {
                    printf("Resultado de la division es %f\n",rDivision);
                }
                printf("Resultado de la multiplicacion es %d\n",rMultiplicacion);
                printf("Resultado del factorial es %d\n",rFactorial);


            }
            else
            {
                printf("Falta Ingresar un operador \n");
            }
            system("pause");
            break;
        case 9:
            seguir = 'n';
            break;
        }


    }
    return 0;
}
