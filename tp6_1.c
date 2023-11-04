/*Realizar un programa que solicite el ingreso de los datos de UNA persona: Apellido, Nombre, día, mes y
año de nacimiento; debe utilizar una estructura para contener dichos datos. Luego el programa deberá
escribir la estructura en un archivo binario llamado archivoBinario.dat*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dia, mes , anio;
} fecha;

typedef struct {
    char apellido[MAX], nombre[MAX];
    fecha nacimiento;
} datos;

void controlApertura(char nombre[]);
void escritura(char nombre[]);
void cargarNombresPropios(char cadena[]);
int controlPositivo();

int main(int argc, char *argv[]){
    char nombre = "archivoBinario.dat";

    controlApertura(nombre);
    escritura(nombre);

    return 0;
}

void controlApertura(char nombre[]){
    FILE *p;

    p = fopen(nombre, "rb");
    if (p == NULL){
        printf("\nEl archivo no existe, se intentará crear uno nuevo...\n\n");
        p = fopen("lenguajeC.txt", "wb");
        if (p = NULL){
            printf("\nOcurrió algún error inesperado durante la ejecución, finalizando el programa\n\n");
            exit(0);
        }
    }
    else {
        printf("\nEl archivo ya existe, no es necesario crearlo\n");
    }
    fclose(p);
}

void escritura(char nombre[]){
    datos unaPersona;
    FILE *p;

    p = fopen(nombre, "ab");
    printf("\nA continuación deberá ingresar los datos de una persona:\n");
    printf("Nombre: ");
    cargarNombresPropios(unaPersona.nombre);
    printf("Apellido: ");
    cargarNombresPropios(unaPersona.apellido);
    printf("Fecha de nacimiento\nDia: ");
    unaPersona.nacimiento.dia = controlPositivo();
    printf("Mes: ");
    unaPersona.nacimiento.mes = controlPositivo();
    printf("Año: ");
    unaPersona.nacimiento.anio = controlPositivo();
    
}

void cargarNombresPropios(char cadena[]){
    int longCadena;
    do {
        fgets(cadena, MAX, stdin);
        cadena[strcspn(cadena, "\n")] = '\0';
        if (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 3)
            printf("Solo puede contener caracteres alfabéticos y un máximo de 3 espacios, intente nuevamente: ");
    } while (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 3);
    
    cadena[0] = toupper(cadena[0]);
    longCadena = strlen(cadena);
    for (int i = 1; i < longCadena; i++){
        if (cadena[i] == ' ')
            cadena[i + 1] = toupper(cadena[i + 1]);
    }
}

int controlPositivo(){
    char num[MAX];
    int numero;
    do {
        fgets(num, MAX, stdin);
        num[strlen(num) - 1] = '\0';
        if (!strspn(num, "1234567890"))
            printf("El valor ingresado debe ser un número positivo, intente nuevamente: ");
    } while (!strspn(num, "1234567890"));
    numero = atoi(num);
    return numero;
}