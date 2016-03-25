/** \brief recibe un número y calcula su factorial usando recursividad
 *
 * \return la 1er sentencia inicia la recursividad multiplicando x por la propia funcion de x-1 hasta que x valga 1
 * \return la 2da sentencia al devolver 1 a la funcion, inicia el camino inverso de la anterior, devolviendo asi los valores para resolver todos los calculos de x * factorial(x-1)
 */
int factorial(int x)
{
    if(x>1)
    {
        return x * factorial(x-1);
    }
    return 1;
}
