#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fp;
FILE *fo;

int main(int argc, char *argv[]){
    char direccion[100];
    getcwd(direccion, sizeof(direccion))  ; //direccion del archivo en cuestion  tambien en la plantilla de nasm
    if (argc== 1){
        printf("Error al encontrar ruta de archivo \n");
        return 1;
    };
    strcat( direccion,"/");
    strcat( direccion,argv[1]);
    fp = fopen(direccion, "r");
    fo = fopen("output.txt","w");
    if(fp == NULL){
        fprintf(stderr,"Error al encontrar el archivo");
        exit(1);
    }
    system_goal(fp, fo, 1);
    fclose(fp);
    fclose(fo);
    return 0;
}
