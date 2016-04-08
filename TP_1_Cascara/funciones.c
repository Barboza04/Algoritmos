#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

/** \brief Muestra el menu, y lo modifica cuando el usuario ingresa los operandos
 *
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param x es la primer variable ingresada
 * \param y es la segunda variable ingresada
 * \param choice guarda la opcion elegida por el usuario
 * \return devuelve el valor de choice para entrar en el switch
 *
 */
int menu(int a, int b, int x, int y)
{
    int choice;
    system("cls");
    printf("***********\nCalculadora\n***********\n");
    if(a)
    {
        printf("1- 1er operando ingresado (A = %d)\n",x);
    }
    else
    {
        printf("1- Ingresar 1er operando (A = sin definir)\n");
    }
    if(b)
    {
        printf("2- 2do operando ingresado (B = %d)\n",y);
    }
    else
    {
        printf("2- Ingresar 2do operando (B = sin definir)\n");
    }
    printf("3- Calcular la suma (A+B)\n"
            "4- Calcular la resta (A-B)\n"
            "5- Calcular la division (A/B)\n"
            "6- Calcular la multiplicacion (A*B)\n"
            "7- Calcular el factorial(A!)\n"
            "8- Calcular todas las operacione\n9- Salir\n");
    do
    {
        printf("\nSeleccione una opcion: ");
        setbuf(stdin, NULL);
    } while(scanf("%d",&choice)!= 1);
    return choice;
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las suma
 *
 * \param x es el operando recibido
 * \param y es el operando recibido
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param addition guarda el resultado de la operacion
 *
 */
void addition(int x, int y, int a, int b)
{
    if(a&&b)
    {
        int addition;
        addition=x+y;
        printf("%d+%d = %d\n",x,y,addition);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos para calcular la suma\n");
        }
    }
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las resta
 *
 * \param x es el operando recibido
 * \param y es el operando recibido
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param subtraction guarda el resultado de la operacion
 *
 */
void subtraction(int x, int y, int a, int b)
{
    if(a&&b)
    {
        int subtraction;
        subtraction=x-y;
        printf("%d-%d = %d\n",x,y,subtraction);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos para calcular la resta\n");
        }
    }
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las divide
 *
 * \param x es el operando recibido
 * \param y es el operando recibido
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param division guarda el resultado de la operacion
 *
 */
void division(int x, int y, int a, int b)
{
    if(a&&b)
    {
        if(y!=0)
        {
            float division;
            division=(float)x/y;
            printf("%d/%d = %.2f\n",x,y,division);
        }
        else
        {
            printf("La division por 0 no esta definida\n");
        }
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos para calcular la division\n");
        }
    }
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las multiplica
 *
 * \param x es el operando recibido
 * \param y es el operando recibido
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param multiplication guarda el resultado de la operacion
 *
 */
void multiplication(int x, int y, int a, int b)
{
    if(a&&b)
    {
        int multiplication;
        multiplication=x*y;
        printf("%d*%d = %d\n",x, y,multiplication);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos para calcular la multiplicacion\n");
        }
    }
}
/** \brief Recibe una variable int para verificar el ingreso del operando
 *         y evalua que sea mayor a 0
 *
 * \param a es la variable de verificación
 * \param x es el operando recibido
 * \param f guarda el resultado de la funcion factorial
 *
 */
void validateFactorial(int a, int x)
{
    int f;
    if(a)
    {
        if(x>=0)
        {
            f=factorial(x);
            printf("%d! = %d\n",x,f);
        }
        else
        {
            if(x<0)
            {
                printf("El factorial de numeros negativos no esta definido\n");
            }
        }
    }
    else
    {
        printf("Falta el operando para calcula calcular el factorial\n");
    }
}
/** \brief Recibe una variable int, verifica que haya sido ingresada y calcula su factorial
 *
 * \param x es el operando recibido
 * \param result guarda el resultado de la operacion
 * \return retorna el producto del factoreo
 *
 */
int factorial(int x)
{
    int result;
    if(x>1)
    {
        result=x*factorial(x-1);
    }
    else
    {
        result=1;
    }
    return result;
}
