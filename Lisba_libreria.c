#include "Lisba_libreria.h"

 /** \brief  Pide un numero entero al usuario y valida y retorna el numero entero ingresado.
 *
 * \param input int* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit int rango limite inferior.
 * \param highLimit int rango limite superior.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 */
int getInt(int* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able=0;
    char auxNumber[10];
    int numberReturn;
    int counterDash=0;
    int isInt;

    do
    {
        isInt = 1;
        counterDash = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%s", auxNumber);

        int i=0;
        while(auxNumber[i] != '\0')
        {
            if((auxNumber[i] < '0' || auxNumber[i] > '9') && (auxNumber[i] != '-'))
            {
               isInt = 0;
            }

            if(auxNumber[i] == '-')
            {
                if(i != 0)
                {
                    isInt = 0;
                }
            }

            if(auxNumber[i] == '-')
            {
                counterDash++;
            }

            i++;
        }

        if(counterDash > 1)
        {
            isInt = 0;
        }

        numberReturn = atoi(auxNumber);

        if((numberReturn < lowLimit) || (numberReturn > highLimit))
         {
             isInt = 0;
         }

        if(!isInt)
        {
            printf(eMessage);
        }

    } while (!isInt);

    *input = numberReturn;

    able = 1;

    return able;
}

int getLong(long* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able=0;
    char auxNumber[10];
    long numberReturn;
    int counterDash=0;
    int isInt;

    do
    {
        isInt = 1;
        counterDash = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%s", auxNumber);

        int i=0;
        while(auxNumber[i] != '\0')
        {
            if((auxNumber[i] < '0' || auxNumber[i] > '9') && (auxNumber[i] != '-'))
            {
               isInt = 0;
            }

            if(auxNumber[i] == '-')
            {
                if(i != 0)
                {
                    isInt = 0;
                }
            }

            if(auxNumber[i] == '-')
            {
                counterDash++;
            }

            i++;
        }

        if(counterDash > 1)
        {
            isInt = 0;
        }

        numberReturn = atol(auxNumber);

        if((numberReturn < lowLimit) || (numberReturn > highLimit))
         {
             isInt = 0;
         }

        if(!isInt)
        {
            printf(eMessage);
        }

    } while (!isInt);

    *input = numberReturn;

    able = 1;

    return able;
}

/** \brief  Pide un numero flotante al usuario y valida y retorna el numero flotante ingresado.
 *
 * \param input float* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit float rango limite inferior.
 * \param highLimit float rango limite superior.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getFloat(float* input, char message[], char eMessage[], float lowLimit, float highLimit)
{
    int able = 0;
    char auxChar[100];
    float floatReturn;
    int isFloat;
    int dotCounter;

    do
    {
        dotCounter = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%s", auxChar);

        int i=0;
        while(auxChar[i] != '\0')
        {
            if((auxChar[i] < '0' || auxChar[i] > '9') && (auxChar[i] != '.'))
            {
                isFloat = 0;
            }

            if(auxChar[i] == '.')
            {
                dotCounter++;
            }

            i++;
        }

        if(dotCounter == 1)
        {
            isFloat = 1;
        }
        else
        {
            isFloat = 0;
        }

        floatReturn = atof(auxChar);

        if((floatReturn < lowLimit) || (floatReturn > highLimit))
        {
            isFloat = 0;
        }

        if(!isFloat)
        {
            printf("%s", eMessage);
        }

    } while (!isFloat);

    *input = floatReturn;

    return able;
}

/** \brief Pide un caracter al usuario, valida y retorna el caracter ingresado.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit char rango limite inferior.
 * \param highLimit char rango limite superior.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getChar(char* input, char message[], char eMessage[], char lowLimit, char highLimit)
{
    int able = 0;
    char aux;
    int validation;

    do
    {
        printf("%s", message);
        fflush(stdin);
        validation = scanf("%c", &aux);

        if(!validation || aux < lowLimit || aux > highLimit)
        {
            printf("%s", eMessage);
        }

    } while (!validation || aux < lowLimit || aux > highLimit);

    *input = aux;

    return able;
}

/** \brief Pide una cadena de caracteres al usuario, valida y retorna la cadena de caracteres ingresada.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit int rango limite inferior de caracteres.
 * \param highLimit int rango limite superior de caracteres.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getString(char* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able = 0;
    char aux[highLimit];

    do
    {
        printf("%s", message);
        fflush(stdin);
        gets(aux);

        if( (strlen(aux) < (lowLimit)) || (strlen(aux) > (highLimit)) )
        {
            printf("%s", eMessage);
        }

    } while ( (strlen(aux) < (lowLimit)) || (strlen(aux) > (highLimit)) );

    strcpy(input, aux);

    return able;
}

int isNumeric(char* string)
{
    int isNum = 0;
    int i = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] < '0' || string[i] > '9')
            {
                break;
            }
            i++;
        }

        if(string[i] == '\0')
        {
            isNum = 1;
        }
    }

    return isNum;
}

int isAlphabetic(char* string)
{
    int isAlphabetic = 0;
    int i = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if( (string[i] < 'A' || string[i] > 'Z') && (string[i] < 'a' || string[i] > 'z') )
            {
                break;
            }
            i++;
        }

        if(string[i] == '\0')
        {
            isAlphabetic = 1;
        }
    }

    return isAlphabetic;
}

int getName(char* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able = 1;
    char aux[highLimit];

    do
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%s", aux);

        if( !isAlphabetic(aux) )
        {
            printf("%s", eMessage);
        }
        else if( (strlen(aux) < (lowLimit)) || (strlen(aux) > (highLimit)) )
        {
            printf("%s", eMessage);
        }

    } while ( !isAlphabetic(aux) || strlen(aux) < (lowLimit) || strlen(aux) > (highLimit) );

    strcpy(input, aux);

    return able;
}

/** \brief Pide un telefono al usuario, valida y retorna el telefono ingresado.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char Mensaje a mostrar al usuario.
 * \param eMessage[] char Mensaje a mostrar en caso de ingresar dato invalido.
 * \param lowLimit int Rango limite inferior.
 * \param highLimit int Ranfo limite superior.
 * \return int Devuelve un estado (1 o 0) indicando si pudo o no efectuar la operacion respectivamente.
 *
 */
int getPhone(char* input, char message[], char eMessage[], int lowLimit, int highLimit)
{
    int able=0;
    char auxNumber[21];
    int counterDash;
    int counterSpace;
    int isPhone;

    do
    {
        isPhone = 1;
        counterDash = 0;
        counterSpace = 0;

        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]", auxNumber);

        int i=0;
        while(auxNumber[i] != '\0')
        {
            if((auxNumber[i] < '0' || auxNumber[i] > '9') && (auxNumber[i] != '-') && (auxNumber[i] != ' '))
            {
               isPhone = 0;
            }

            if(auxNumber[i] == ' ')
            {
                counterSpace++;
            }

            if(auxNumber[i] == '-')
            {
                counterDash++;
            }

            i++;
        }

        if(counterDash > 2)
        {
            isPhone = 0;
        }

        if(counterSpace > 2)
        {
            isPhone = 0;
        }

        if((strlen(auxNumber) < lowLimit) || (strlen(auxNumber) > highLimit))
         {
             isPhone = 0;
         }

        if(!isPhone)
        {
            printf(eMessage);
        }

    } while (!isPhone);

    strcpy(input, auxNumber);

    able = 1;

    return able;
}

/** \brief  Pide, valida y retorna un numero de DNI.
 *
 * \param input char* Variable puntero origen-destino.
 * \param message[] char mensaje a mostrar al usuario.
 * \param eMessage[] char mensaje a mostrar en caso de ingresar dato invalido.
 * \return int retorna un estado en caso de poder o no ejecutar la operacion.
 *
 */
int getDni(char* input, char message[], char eMessage[])
{
    int able = 0;
    char aux[11];
    int i=0;

    do
    {
        printf("%s", message);
        fflush(stdin);
        gets(aux);

        while(aux[i] != '\0')
        {
            if( (strlen(aux) < (6) || strlen(aux) > (10)) && (aux[i] < '0' || aux[i] > '9') )
            {
                printf("%s", eMessage);
            }

            i++;
        }

    } while ( (strlen(aux) < (6)) || (strlen(aux) > (10)) );

    strcpy(input, aux);
    able = 1;

    return able;
}

/** \brief Caclula la suma entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la suma de ambos números.
 *
 */
float add(float number1, float number2)
{
    float result;

    result = number1 + number2; // Cálculo de la suma de ambos números recibidos como parámetros.

    return result;
}

/** \brief Caclula la resta entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la resta de ambos números.
 *
 */
float subtract(float number1, float number2)
{
    float result;

    result = number1 - number2; // Cálculo de la resta del primer número menos el segundo número recibido como parámetro.

    return result;
}

/** \brief Caclula la división entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la división entre ambos números.
 *
 */
float divide(float number1, float number2)
{
    float result;

    if(number2 == 0)
    {
        result = 0.00;
    }else
    {
        result = number1 / number2; // Cálculo de la división entre ambos números recibidos como parámetros.
    }

    return result;
}

/** \brief Caclula la multiplicación entre dos números.
 *
 * \param number1 float Primer operando.
 * \param number2 float Segundo operando.
 * \return float El resultado de la multiplicación entre ambos números.
 *
 */
float multiply(float number1, float number2)
{
    float result;

    result = number1 * number2; // Calculo del producto de ambos números recibidos como parámetros.

    return result;
}

/** \brief Caclula el factorial de un número.
 *
 * \param number float Operando a calcular.
 * \return long El factorial del número.
 *
 */
long int factorial(float number) //Recibe un flotante pero toma en cuenta solo la parte entera del número y calcula su factorial.
{
    long int result=1;
    int i;

    for(i=number; i>=1; i--) //Iteración para calcular el producto del número recibido como parámetro por cada uno de sus números naturales inferiores hasta 1 (en forma decreciente).
    {
        result *= i;
    }

    return result;
}

/** \brief Pide un nombre y un apellido al usuario y lo muestra concatenado separado por una coma un un espacio.
 *
 * \param nameLastName[] char Vector donde se guardará el nombre y apellido.
 * \return void
 *
 */
void getNameLastName(char nameLastName[])
{
    char nombre[23];
    char apellido[11];
    char aux[50];

    do
    {
        printf("Ingrese nombre: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR. Ingrese un nombre de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(nombre, aux);

    do
    {
        printf("Ingrese apellido: ");
        gets(aux);

        if(strlen(aux) > 10)
        {
            printf("ERROR! Ingrese un apellido de 10 caracteres o menos: ");
            gets(aux);
        }
    } while (strlen(aux) > 10);

    strcpy(apellido, aux);

    strcpy(nameLastName, nombre);
    strcat(nameLastName, ", ");
    strcat(nameLastName, apellido);
}
