#include <stdio.h>
#include <stdlib.h>



int main()
{
    int numero;
    long int resultado;
    printf("Ingrese numero: ");
    scanf("%d",&numero);
    resultado=factorial(numero);
    printf("El factorial de %d es: %ld",numero, resultado);
    return 0;
}
