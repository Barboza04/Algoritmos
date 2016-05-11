#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/** \brief Solicita una cadena de caracteres al usuario valida su longitud y que solo sean letras
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a mostrar para pedir la cedna
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mìnima de la cadena
 * \param hiLimit Longitud màxima de la cadena
 * \return Si obtuvo la cadena retorna 0 sino -1
 *
 */
int getLetterString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit)
 {
     int value=-1;
     int length;
     int i;
     int isLetter;
     char auxString[100];
     puts(message);
     setbuf(stdin,NULL);
     gets(auxString);
     length=strlen(auxString);
     for(i=0;i<length;i++)
     {
         isLetter=isalpha(auxString[i]);
         if(isLetter==0)
         {
             puts(eMessage1);
             break;
         }
     }
     if(length<lowLimit||length>hiLimit)
     {
         puts(eMessage2);
     }
     else
     {
         strcpy(input,auxString);
         value=0;
     }
     return value;
 }

 /** \brief Solicita un nùmero al usuario y lo valida
 * \param input Se carga el nùmero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage1 Es el mensaje a ser mostrado en caso de ingreso erroneo del dato
 * \param eMessage2 Es el mensaje a ser mostrado en caso de que el dato este fuera del rango
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero retorna 0 sino -1
 *
 */
int getInt(int* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit)
 {
     int value=-1;
     int auxInt;
     puts(message);
     setbuf(stdin,NULL);
     if(scanf("%d",&auxInt)!=1)
     {
         puts(eMessage1);
     }
     else if(auxInt<lowLimit||auxInt>hiLimit)
     {
        puts(eMessage2);
     }
     else
     {
         *input=auxInt;
        value=0;
     }
     return value;
 }

 /** \brief Pide una cadena de caracteres y valida su longitud y que solo sean numeros
  *
  * \param input Puntero al vector de caracteres
  * \param message Mensage para solicitar la cadena
  * \param eMessage1 Mensaje que informa si algun caracter no es numerico
  * \param eMessage2 Mensaje que informa si el largo de la cadena esta fuera de rango
  * \param lowLimit Valor minimo del rango de la cadena
  * \param hiLimit Vlor maximo del rango de la cadena
  * \return Si obtuvo la cadena numerica devuelve 0 sino -1
  *
  */
int getNumberString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit)
{
    int value=-1;
    int i;
    int length;
    int isNumber;
    char auxString[100];
    printf("%s",message);
    setbuf(stdin,NULL);
    gets(auxString);
    length=strlen(auxString);
    if(length>=lowLimit&&length<=hiLimit)
    {
        for(i=0;i<length;i++)
        {
            isNumber=isdigit(auxString[i]);
            if(isNumber==0)
            {
                puts(eMessage1);
                break;
            }
            else
            {
                strcpy(input,auxString);
                value=0;
            }
        }
    }
    else
    {
        puts(eMessage2);
    }
    return value;
}

/** \brief  Para indicar que todas las posiciones del array estan vacias
 *          esta funcion inicializa el campo isEmpty en 1
 * \param eStruct* pArray Puntero al array
 * \param int length Largo del array
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int initArray(eStruct* pArray, int length)
{
    int value=-1;
    int i;
    if(pArray!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            pArray[i].isEmpty=1;
        }
        value=0;
    }
    return value;
}

/** \brief Busca la primer posicion libre del array
 *
 * \param eStruct array Vector de personas donde busca el espacio libre
 * \param int length largo del array
 * \return int index devuelve -1 en caso de no encontrar una posicion libre y el indice de esa posicion en caso contrario
 *
 */

int findEmpty(eStruct array[], int length)
{
    int index=-1,i;
    for(i=0;i<length;i++)
    {
        if(array[i].isEmpty==-1)
        {
            index=i;
            break;
        }
    }
    return index;
}

/** \brief Agrega en una lista los valores recividos como parametros
 *
 * \param eStruct* pArray Puntero al array
 * \param int length Largo del array
 * \param int index indice de la primer posicion libre
 * \param char name[] nombre de la persona a ingresar en la lista
 * \param int age edad de la persona a ingresar en la lista
 * \param int dni dni de la persona a ingresar en la lista
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int addStructItem(eStruct* pArray, int length, int index, char name[], int age, int dni)
{
    int value=-1;
    if(pArray!=NULL&&length>0)
    {
        if(index!=-1)
        {
            strcpy(pArray[index].name,name);
            pArray[index].age=age;
            pArray[index].dni=dni;
            pArray[index].isEmpty=0;
            value=0;
        }
    }
    return value;
}

/** \brief Ecuentra un item por su id
 *
 * \param eStruct* pArray Puntero al array
 * \param int length Largo del array
 * \param int dni dni de la persona a buscar en la lista
 * \return eStruct* Retorna un puntero a una persona si no hay error y un puntero NULL si hay error [largo invalido o puntero NULL recivido o persona no encontrada]
 *
 */
eStruct* findById(eStruct* pArray, int length,int dni)
{
    int i;
    eStruct* value=NULL;
    if(pArray!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(!pArray[i].isEmpty&&pArray[i].dni==dni)
            {
                value=&pArray[i];
                break;
            }
        }
    }
    return value;
}

/** \brief Borra un item de la lista por su id
 *         (cambia el valor de la bandera isEmpty a 1)
 *
 * \param eStruct* pArray Puntero al array
 * \param int length Largo del array
 * \param int dni dni de la persona a borrar de la lista
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL o si no puede encontrar a la persona] y 0 si no hay error
 *
 */
int removeItem(eStruct* pArray, int length, int dni)
{
    int value=-1;
    eStruct* auxItem=NULL;
    auxItem=findById(pArray,length,dni);
    if(auxItem!=NULL)
    {
        auxItem->isEmpty=1;
        value=0;
    }
    return value;
}

/** \brief Ordena los elementos del aray por nombre
 *
 * \param eStruct* pArray Puntero al array
 * \param int length Largo del array
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int sortItemsByName(eStruct* pArray, int length)
{
    int i;
    int j;
    eStruct auxiliar;
    int value=-1;
    if(pArray!=NULL&&length>0)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(strcmp(pArray[i].name,pArray[j].name)>0)
                {
                    auxiliar=pArray[i];
                    pArray[i]=pArray[j];
                    pArray[j]=auxiliar;
                    value=0;
                }
            }
        }
    }
    return value;
}

/** \brief Imprime los elementos del array
 *
 * \param eStruct* pArray Puntero al array de personas
 * \param int length Largo del array
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int printItems(eStruct* pArray, int length)
{
    int i;
    int value=-1;
    printf("\n\nName\t  \tAge\t \tDNI\n");
    if(pArray!=NULL&&length>0)
    {
        for(i=0; i<length; i++)
        {
            if(!pArray[i].isEmpty)
            {
                printf("\n%s  \t%d\t \t%d\n\n",pArray[i].name,pArray[i].age,pArray[i].dni);
            }
        }
        value=0;
    }
    return value;
}

/** \brief Calcula el maximo entre tres enteros
 *
 * \param int x primer entero recivido
 * \param int y segundo entero recivido
 * \param int z tercer entero recivido
 * \return int maxNumber devuelve el numero maximo
 *
 */

int calculateMax(int x, int y, int z)
{
    int maxNumber;
    if(x>y && x>z)
    {
        maxNumber=x;
    }
    else
    {
        if(y>=x && y>z)
        {
            maxNumber=y;
        }
        else
        {
            maxNumber=z;
        }
    }
    return maxNumber;
}

/** \brief Cuenta cuantos elementos del array estan dentro de cada rango
 *
 * \param eStruct* pArray Puntero al array de personas
 * \param int length Largo del array
 * \param int* x puntero al contador del primer rango
 * \param int* y puntero al contador del segundo rango
 * \param int* z puntero al contador del tercer rango
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */

int getRanges(eStruct* pArray, int length, int* x, int* y, int* z)
{
    int i;
    int value=-1;
    int range1=0;
    int range2=0;
    int range3=0;
    if(pArray!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(pArray[i].age<18&&!pArray[i].isEmpty)
            {
                range1++;
                *x=range1;
            }
            else
            {
                if(pArray[i].age>17&&pArray[i].age<36&&!pArray[i].isEmpty)
                {
                    range2++;
                    *y=range2;
                }
                else if(pArray[i].age>35&&!pArray[i].isEmpty)
                {
                    range3++;
                    *z=range3;
                }
            }
        }
        value=0;
    }
    return value;
}

/** \brief Imprime un grafico de los rangos
 *
 * \param int x contador del primer rango
 * \param int y contador del segundo rango
 * \param int z contador del tercer rango
 * \return void
 *
 */

void printRanges(int x, int y, int z)
{
    int mayor;
    int i;
    int j;
    int vec[]={x,y,z};
    mayor=calculateMax(x,y,z);
    char matriz[mayor][3];
    for(j=0;j<mayor;j++)
    {
        for(i=0;i<3;i++)
        {
            if(vec[i]>j)
            {
                matriz[j][i]='*';
            }
            else
            {
                matriz[j][i]=' ';
            }
        }
    }
    for(j=mayor-1;j>=0;j--)
    {
        printf(" %c    %c    %c\n",matriz[j][0],matriz[j][1],matriz[j][2]);
    }
    printf("<18 18-35 >35\n");
}

/**
 *\brief Solicita una cadena de texto con formato de mail y lo valida
 *
 *\param  char* input Puntero char donde se guardara la cadena
 *\param char message Mensage para solicitar la cadena
 *\param char eMessage1 Mensaje de error si el largo de la cadena esta fuera de rango
 *\param char eMessage2 Mensaje de error si se ingresa un caracter invalido
 *\param char eMessage3 Mensaje de error si el formato es incorrecto
 *\param int lowLimit Longitud minima de la cadena
 *\param int hiLimit Longitud maxima la cadena
 *\return value devuelve -1 en caso de error y 0 si no hay error
 */
int getMail(char* input,char message[],char eMessage1[],char eMessage2[],char eMessage3[],int lowLimit,int hiLimit)
{
    int value=-1;
    int i;
    int getFlag=0;
    int length;
    int isAlphaNumeric;
    int countAt=0;
    int countDot=0;
    int countSymbols=0;
    char auxChar[100];

    if(input!=NULL&&lowLimit>0)
    {
        setbuf(stdin,NULL);
        getFlag=getString(auxChar,message,eMessage1,lowLimit, hiLimit);
        length=strlen(auxChar);
        if(length>=lowLimit&&length<=hiLimit&&getFlag!=-1)
        {
            for(i=0;i<length;i++)
            {
                isAlphaNumeric=isalnum(auxChar[i]);
                printf("%d",isAlphaNumeric);
                system("pause");
                if(!isAlphaNumeric&&auxChar[i]=='@')
                {
                    countAt++;
                }
                else if(!isAlphaNumeric&&auxChar[i]=='.')
                {
                    countDot++;
                }
                else if(!isAlphaNumeric&&(auxChar[i]!='@'&&auxChar[i]!='.'&&auxChar[i]!='-'&&auxChar[i]!='_'))
                {
                    countSymbols++;
                }
            }
            if(countSymbols)
            {
                printf("%s",eMessage2);
            }
            if(countAt==1&&countDot>=1&&!countSymbols)
            {
                strcpy(input,auxChar);
                value=0;
            }
            else if(!countAt||!countDot)
            {
                printf("%s",eMessage3);
            }
        }
        else
        {
            printf("%s",eMessage1);
        }
    }
    return value;
}
