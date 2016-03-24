#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1;
    int factorial=1;
    int x=1;

    while(x<=100)
    {
        for(i;i<=x;i++)
        {
            factorial=factorial*i;
        }
        printf("El factorial de %d es: %d\n",x,factorial);
        x++;
    }
    return 0;
}
