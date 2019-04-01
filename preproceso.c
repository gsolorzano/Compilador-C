#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

FILE *fp;
FILE *fo;
FILE *temp;
int contO;

extern char token_buffer[100] = "\0";
char token_buffer_2[100] = "\0";
char nombreI[100];
char nombreO[100];
char nombreT[100];
char inc[100][100];
int incCont = 0;
char direccion[200];
char incl[] = "include";
char def[] = "define";

void clear_buffer_2(){//borra el contenido de token_buffer y lo resetea a un string vacio
    memset(token_buffer_2, 0, sizeof(token_buffer_2));
}

void buffer_char_2(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(token_buffer_2);
    token_buffer_2[len] = c;
    token_buffer_2[len+1] = '\0';
}

void clear_buffer(){//borra el contenido de token_buffer y lo resetea a un string vacio
    memset(token_buffer, 0, sizeof(token_buffer));
}

void buffer_char(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(token_buffer);
    token_buffer[len] = c;
    token_buffer[len+1] = '\0';
}

void incAux(){
    for(int i = 0; i<incCont;i++){
        printf("%d\n", i);
        getcwd(direccion, sizeof(direccion));
        strcat( direccion,"/");
        strcat( direccion, inc[i]);
        printf("%s\n", direccion);
        FILE *inc = fopen(direccion, "r");
        if(inc == NULL){
            fprintf(stderr,"Error al encontrar el archivo");
            exit(1);
        }
        else{
            char nombre[100] = "\0";
            sprintf(nombre, "%d", contO);
            strcat(nombre,".txt");
            FILE *out = fopen(nombre,"w+");
            //system_goal(inc, out, contO+1, nombreI, nombreO);
            // fclose(inc);
            // fclose(out);
            // //----------
            // getcwd(direccion, sizeof(direccion));
            // strcat( direccion,"/");
            // strcat( direccion, nombre);
            // out = fopen(direccion,"r");
            // //----------
            // fclose(fo);
            // getcwd(direccion, sizeof(direccion));
            // strcat( direccion,"/");
            // strcat( direccion, nombreO);
            // fo = fopen(direccion, "w");
            // char c1;
            // while ((c1 = fgetc(out)) != EOF){
            //     fputc(c1, fo);
            // }
        }
    }
    // fclose(temp);
    // getcwd(direccion, sizeof(direccion));
    // strcat( direccion,"/");
    // strcat( direccion, nombreT);
    // temp = fopen(direccion, "r");
    // char c2;
    // while ((c2 = fgetc(temp)) != EOF){
    //     fputc(c2, fo);
    // }
//
//
//
//
//
//     int pos = ftell(fp);
//     getcwd(direccion, sizeof(direccion));
//     strcat( direccion,"/");
//     strcat( direccion, token_buffer);
//     FILE *inc = fopen(direccion, "r");
//     if(inc == NULL){
//         fprintf(stderr,"Error al encontrar el archivo");
//         exit(1);
//     }
//     else{
//         clear_buffer_2();
//         char nombre[100] = "\0";
//         sprintf(nombre, "%d", contO);
//         strcat(nombre,".txt");
//         FILE *out = fopen(nombre,"w+");
//         // for(int i = 0; i<strlen(nombre);i++){
//         //     printf("%c", nombre[i]);
//         // }
//         printf("\n");
//         printf("%s\n","Recursiva" );
//         system_goal(inc, out, contO+1, nombreI, nombreO);
//         fclose(inc);
//         fclose(out); //se llama de a analizar el archivo del include de conformar
//         //recursiva pues puede tener otros include adentro
//         //abrir el archivo temporal que genero la llamada recursiva para incluirlo en el archivo final
// //---------------------------------------------------------------------------------------------------------------------------------------------
//         // while ((c = fgetc(out)) != EOF){
//         //     printf("%c", c);
//         // }
//         // rewind(out);
//         // while ((c = fgetc(out)) != EOF){
//         //     printf("%c", c);
//         // }
//         //FILE *temp = fopen("temp.txt","w+");
//         // if(out == NULL){
//         //     fprintf(stderr,"Error al encontrar el archivo");
//         //     exit(1);
//         // }
//         //else{
//             //cerrar el fo y abrirlo en modo lectura
//             // char c;
//             fclose(fo);
//             getcwd(direccion, sizeof(direccion));
//             strcat( direccion,"/");
//             strcat( direccion, nombreO);
//             fo = fopen(direccion, "a+");
//
//             getcwd(direccion, sizeof(direccion));
//             strcat( direccion,"/");
//             strcat( direccion, nombre);
//             out = fopen(direccion,"r");
//             // //rewind(fo);
//             // //copiar lo que tiene fo a temp
//             // while ((c = fgetc(fo)) != EOF){
//             //     fputc(c, temp);
//             // }
//             // printf("\n");
//             //copiar contenido de out a temp
//
//
//             //AQUI-----------------------------------------------------
//
//
//             char c1;
//             while ((c1 = fgetc(out)) != EOF){
//                 fputc(c1, fo);
//             }
//             //printf("%s\n",codi );
//             //cerrar fo y abrirlo en blanco
//             // fclose(fo);
//             // getcwd(direccion, sizeof(direccion));
//             // strcat( direccion,"/");
//             // strcat( direccion, nombre);
//             // rewind(temp);
//             // fo = fopen(direccion, "w");
//             // while ((c = fgetc(temp)) != EOF){
//             //     printf("%c", c);
//             //     fputc(c, fo);
//             // }
//             //fclose(temp);
//         //}
// //-------------------------------------------------------------------------------------------------------------------------
//         fclose(fp);
//         getcwd(direccion, sizeof(direccion));
//         strcat( direccion,"/");
//         strcat( direccion, nombreI);
//         fp = fopen(direccion, "r");
//         fseek(fp,pos,SEEK_CUR);
//     }
}

int file_exist(const char *filename){
    FILE *file;
    if(file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}

void scanner(void){
    int in_char, c;
    clear_buffer();
    clear_buffer_2();
    if(feof(fp)){
        return;
    }
    while((in_char = fgetc(fp) ) != EOF){//lee todo el codigo hasta el final del archivo
        // printf("%c", in_char);
        // if(isspace(in_char)){
        //     continue; /* do nothin */
        // }
        if(in_char == '#'){
            buffer_char_2(in_char);
            in_char = fgetc(fp);
            if(isspace(in_char)){
                buffer_char_2(in_char);
                in_char = fgetc(fp);
                continue; /* do nothin */
            }
            while(isalpha(in_char)){
                buffer_char_2(in_char);
                buffer_char(in_char);
                in_char = fgetc(fp);
            }
            for(int j = 0; j <= strlen(token_buffer);j++){
                token_buffer[j] = tolower(token_buffer[j]);
            }
            //chequea si hay un include
            if(token_buffer[0] == 'i'){
                int band = 0;
                if(!strcmp(token_buffer,incl)){
                    band = 1;
                }
                buffer_char_2(in_char);
                if(band == 1){//si hay un include se haría aqui
                    clear_buffer();
                    in_char = fgetc(fp);
                    buffer_char_2(in_char);
                    if(isspace(in_char)){
                        in_char = fgetc(fp);
                        buffer_char_2(in_char);
                        continue; /* do nothin */
                    }
                    if(in_char == '"'){
                        in_char = fgetc(fp);
                        buffer_char_2(in_char);
                        while(isalpha(in_char) || isdigit(in_char)){
                            buffer_char(in_char);
                            in_char = fgetc(fp);
                            buffer_char_2(in_char);
                        }
                        if(in_char == '.'){
                            buffer_char(in_char);
                            in_char = fgetc(fp);
                            buffer_char_2(in_char);
                            if(in_char == 'c'){
                                buffer_char(in_char);
                                in_char = fgetc(fp);
                                buffer_char_2(in_char);
                                if(in_char == '"'){//Se detecto un #include "archivo.c" por lo que se tiene que incluir
                                    // while((in_char = fgetc(fp) ) != EOF){
                                    //     printf("%c", in_char);
                                    // }
                                    getcwd(direccion, sizeof(direccion));
                                    strcat( direccion,"/");
                                    strcat( direccion, token_buffer);
                                    if(file_exist(direccion)){
                                        int ig = 0;
                                        for(int i = 0; i<incCont;i++){
                                            if(!strcmp(token_buffer, inc[i])){
                                                ig = 1;
                                            }
                                        }
                                        if(ig == 0){
                                            strcpy(inc[incCont],token_buffer);
                                            incCont++;
                                        }
                                    }
                                    else{
                                        fprintf(temp, token_buffer_2);
                                    }
                                    clear_buffer_2();
                                    clear_buffer();
                                    continue;
                                }
                                else{
                                    clear_buffer();
                                    fprintf(temp, token_buffer_2);
                                    continue;
                                }
                            }
                            else{
                                clear_buffer();
                                fprintf(temp, token_buffer_2);
                                continue;
                            }
                        }
                        else{
                            clear_buffer();
                            fprintf(temp, token_buffer_2);
                            continue;
                            printf("%s\n", "no");
                        }
                    }
                    else{
                        fprintf(temp, token_buffer_2);
                        continue;
                    }
                }
                else{//si no es un include se manda a escribir tal cual
                    printf("%s\n", "no");
                    fprintf(temp, token_buffer_2);
                    continue;
                }
            }
            else{
                fprintf(temp, token_buffer_2);
                continue;
            }
        }
        else{
            //printf("%c",in_char );
            fputc(in_char,temp);
        }
    }
    for(int i = 0; i<incCont;i++){
        printf("%s\n",inc[i] );
    }
    if(feof(fp)){
        return;
    }
}

void system_goal(FILE *in, FILE *out, int n, char *nomI, char *nomO){
    fp = in;
    fo = out;
    char nombre[100] = "temp";
    char num[100] = "\0";
    sprintf(num, "%d", contO);
    strcat(nombre,num);
    strcat(nombre,".txt");
    temp = fopen(nombre,"w");
    strcpy(nombreI, nomI);
    strcpy(nombreO, nomO);
    strcpy(nombreT, nombre);
    contO = n;
    scanner();
    incAux();
}
