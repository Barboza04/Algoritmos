#include <stdio.h>
#include <stdlib.h>

    int main(void)
{
    signed int numero;
    do
    {
        printf("Numero : ");
        setbuf(stdin, NULL);
    } while(scanf("%d", &numero) != 1);
    printf("{%d}\n", numero);
    return 0;
}
