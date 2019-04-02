#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fileImput;
FILE *fileOutput;

int main(int argc, char *argv[]){
    char direccion[100];
    getcwd(direccion, sizeof(direccion))  ; //direccion del archivo en cuestion  tambien en la plantilla de nasm
    char nombre[50];
    if (argc == 1){
        printf("Error al encontrar ruta de archivo \n");
        return 1;
    }
    //printf("Introduzca el nombre del archivo: \n");
    strcat( direccion,"/");
    strcat( direccion,argv[1]);
    strcat( direccion,nombre);
    fileImput = fopen(direccion, "r");
    fileOutput = fopen("OUTPUT.txt","w");
    if(fileImput == NULL){
        fprintf(stderr,"Error al encontrar el archivo de entrada");
        exit(1);
    }
    system_goal(fileImput, fileOutput, 0);
    printf("%s\n", "Preproceso finalizado");
    fclose(fileImput);
    fclose(fileOutput);
    return 0;
}
