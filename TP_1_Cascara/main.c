/******************************************************************
*Programa: TP 1- Calculadora
*
*Objetivo:
        Realizar cinco operaciones matematicas, suma, resta, division, multipilcacion
        y factorial, de los números ingresados por el usuario
*
*Versión 1.0 06/04/2016
*Autor: Alejandro Barboza
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char keepGoing;
    int option=0;
    int x;
    int y;
    int flagOp1=0;
    int flagOp2=0;

    do
    {
        option=menu(flagOp1, flagOp2, x, y);
        switch(option)
        {
            case 1:
                do
                {
                    printf("\nIngrese el 1er operando: ");
                    setbuf(stdin, NULL);
                } while(scanf("%d",&x)!= 1);
                flagOp1=1;
                break;
            case 2:
                do
                {
                    printf("\nIngrese el 2do operando: ");
                    setbuf(stdin, NULL);
                } while(scanf("%d",&y)!= 1);
                flagOp2=1;
                break;
            case 3:
                system("cls");
                addition(x,y, flagOp1, flagOp2);
                system("pause");
                break;
            case 4:
                system("cls");
                subtraction(x,y, flagOp1, flagOp2);
                system("pause");
                break;
            case 5:
                system("cls");
                division(x,y, flagOp1, flagOp2);
                system("pause");
                break;
            case 6:
                system("cls");
                multiplication(x,y, flagOp1, flagOp2);
                system("pause");
                break;
            case 7:
                system("cls");
                validateFactorial(flagOp1, x);
                system("pause");
                break;
            case 8:
                system("cls");
                printf("**********\nResultados\n**********\n");
                addition(x,y, flagOp1, flagOp2);
                subtraction(x,y, flagOp1, flagOp2);
                division(x,y, flagOp1, flagOp2);
                multiplication(x,y, flagOp1, flagOp2);
                validateFactorial(flagOp1, x);
                system("pause");
                break;
            case 9:
                keepGoing='n';
                break;
            default:
                printf("La opcion ingresada no es valida\n");
                system("pause");
                break;
        }
    }while(keepGoing!='n');
    return 0;
}
