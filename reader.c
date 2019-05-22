#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

FILE *fileImput;
FILE *fileOutput;
FILE *temp;
FILE *files[200];
int currentFiles; //en donde estï¿½ el temp, antes del temp, estï¿½ el fuente
//y antes del fuente, estï¿½ el output

char fileList[1000][500];
int fileListCont=0;
int inListFlag=0;

char direccion[500] = "\0";
char dir1[] = "/usr/lib/gcc/x86_64-linux-gnu/8/include";
char dir2[] = "/usr/local/include";
char dir3[] = "/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed";
char dir4[] = "/usr/lib/gcc/x86_64-linux-gnu";
char dir5[] = "/usr/include";

char dir6[] = "/usr/include/x86_64-linux-gnu";
char dir7[] = "/usr/include/x86_64-linux-gnu/gnu";
//Este es extra
char token_buffer[100] = "\0";
char token_buffer_2[100] = "\0";
char incl[] = "include";

void clear_direccion(){//borra el contenido de token_buffer y lo resetea a un string vacio
    memset(direccion, 0, sizeof(direccion));
}

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

int isInFileList(){

    for(int i=0; i<fileListCont; i++){
     if ( !strcmp(fileList[i], direccion) ) return 1;
    }
    return 0;
}

void beginInclude(){

    if( isInFileList() ){
        //printf("\n En lista: %s \n", direccion);
        currentFiles++;//esto es para que no de error al terminar beginInlcude
        inListFlag=1;
        return;
    }

                        // fprintf("//",fileOutput);
                        // fprintf(fileOutput,"\t \t \t \t \t ///*EMPIEZA EL INCLUDE DE: ");
                        // fprintf(fileOutput,direccion);
                        // fprintf("// ",fileOutput);
                        // fprintf("\n",fileOutput);

    if(currentFiles==0) fprintf(fileOutput, "☼\n");
    inListFlag=0;
    strcat(fileList[fileListCont],direccion);
    fileListCont++;
    FILE * toInclude = fopen(direccion, "r");
    if(toInclude == NULL){
        fprintf(stderr,"Error al encontrar el archivo_bgin");
        exit(1);
    }else{
        system_goal(toInclude, files[currentFiles],currentFiles+1);
        if(currentFiles==1) fprintf(fileOutput, "☼\n");
    }

}

int file_exist(const char *filename){
    FILE *file;
    if(file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}

void scanner(){
    int in_char, temp;
    clear_buffer();
    clear_buffer_2();
    if(feof(fileImput)){
        return;
    }
    int bandera = 0;
    int bandera2 = 0;
    while((in_char = fgetc(fileImput) ) != EOF){//lee todo el codigo hasta el final del archivo


//        while( isspace(in_char) ){
//
//            in_char = fgetc(fileImput);
//        }

        if(in_char == '#' && bandera == 0){
            buffer_char_2(in_char);
            in_char = fgetc(fileImput);
            while(isspace(in_char)){
                buffer_char_2(in_char);
                in_char = fgetc(fileImput);
                continue; /* do nothin */
            }
            while(isalpha(in_char) ){
                buffer_char_2(in_char);
                buffer_char(in_char);
                in_char = fgetc(fileImput);
            }
            for(int j = 0; j <= strlen(token_buffer);j++){
                token_buffer[j] = tolower(token_buffer[j]);
            }
            //chequea si hay un include
            buffer_char_2(in_char);

            //printf("\n \t Primero: %s", token_buffer);
            //printf("\n \t Segundo: %s", token_buffer_2);
            //printf("\n \t \t Archivo actual: %s", direccion);
            //printf("\n \t Antes de StringCMP %c", in_char);
            if(!strcmp(token_buffer,incl)){//si hay un include se harï¿½a aqui
                clear_buffer();
                temp = in_char;
                in_char = fgetc(fileImput);
                buffer_char_2(in_char);

                //printf("\n Antes de isspace %c", in_char);
                while(isspace(in_char)){
                    in_char = fgetc(fileImput);
                    buffer_char_2(in_char);
                    //printf("\n Entró isspace %c", in_char);
                    continue;
                }

                //printf("\n IN_CHAR %c", in_char);
                //printf("\n TEMP %c", temp);
                if(in_char == '<' || temp == '<'){
                    int char_verificar = temp; // ES PARA DESPUES EN EL IF QUE CORRIGE
                    temp = in_char;

                    //printf("\n INCLUDE EXTRANO \n");
                    in_char = fgetc(fileImput);
                    //printf("\n Entry1 %c \t %c", in_char, temp);
                    buffer_char_2(in_char);
                    while(isalpha(in_char) || isdigit(in_char) || in_char == '.' || in_char == '_' || in_char == '-'
                            || isspace(in_char) || in_char == '/' ){

                        //printf("\n CHAR: %c", in_char);
                        if( !isspace(in_char) ){
                            buffer_char(in_char);
                            in_char = fgetc(fileImput);
                            buffer_char_2(in_char);
                        }
                    }
                    if(char_verificar == '<'){//corrige los caracteres que se come
                        int len = strlen(token_buffer);
                        int temp_char = token_buffer[0];
                        token_buffer[0] = temp;
                        for(int i=1; i<len+1;i++){
                            temp = token_buffer[i];
                            token_buffer[i] = temp_char;
                            temp_char = temp;
                        }
                        token_buffer[len+1] = '\0';
                    }

                    //printf("\n \t \t Primero:--> %s", token_buffer);
                    //printf("\n \t \t Segundo:--> %s \n ", token_buffer_2);
                    if(in_char == '>'){//Se detecto un #include <archivo.c> por lo que se tiene que incluir
                        //Empezar el include
                        //printf("\nENTRO\n");
                        char dirtemp[400];
                        char dirtemp2[400];
                        char dirtemp3[400];
                        char dirtemp4[400];
                        char dirtemp5[400];

                        char dirtemp6[400];
                        char dirtemp7[400];

                        strcpy(dirtemp,dir1);
                        strcpy(dirtemp2,dir2);
                        strcpy(dirtemp3,dir3);
                        strcpy(dirtemp4,dir4);
                        strcpy(dirtemp5,dir5);
                        strcpy(dirtemp6, dir6);
                        strcpy(dirtemp7, dir7);

                        if(token_buffer[0] != "/"){
                            strcat(dirtemp,"/");
                            strcat(dirtemp,token_buffer);

                            strcat(dirtemp2,"/");
                            strcat(dirtemp2,token_buffer);

                            strcat(dirtemp3,"/");
                            strcat(dirtemp3,token_buffer);

                            strcat(dirtemp4,"/");
                            strcat(dirtemp4,token_buffer);

                            strcat(dirtemp5,"/");
                            strcat(dirtemp5,token_buffer);

                            strcat(dirtemp6,"/");
                            strcat(dirtemp6,token_buffer);
                        }
                        clear_direccion();
                        //printf("%s\n", dirtemp);
                        if(file_exist(dirtemp)){
                            strcat(direccion,dirtemp);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else if(file_exist(dirtemp2)){
                            strcat(direccion,dirtemp2);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else if(file_exist(dirtemp3)){
                            strcat(direccion,dirtemp3);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else if(file_exist(dirtemp4)){
                            strcat(direccion,dirtemp4);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else if(file_exist(dirtemp5)){
                            strcat(direccion,dirtemp5);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else if(file_exist(dirtemp6)){
                            strcat(direccion,dirtemp6);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else if(file_exist(dirtemp7)){
                            strcat(direccion,dirtemp7);
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else{
                            char err[100] = "Error al encontrar archivo: ";
                            strcat(err,token_buffer);
                            printf("%s\n",err);
                            exit(0);
                        }

                        //printf("HACIENDO PRINT");
                        if(!inListFlag){
                            // fprintf("//",fileOutput);
                            // fprintf(fileOutput,"\t \t \t \t \t  ///*TERMINO EL INCLUDE DE: ");
                            // fprintf(fileOutput,direccion);
                            // fprintf("// ",fileOutput);
                            // fprintf("\n",fileOutput);
                        }
                        //printf("TERMINO PRINT");

//ESTOS PRINT SON PARA SABER QUE HIZO LOS INCLUDE DE <ARCHIVO>
                        clear_buffer();
                        clear_buffer_2();
                    }
                }//HASTA AQUÍ SE HACE EL INCLUDE <ARCHIVO>
                else if(in_char == '"'){
                    in_char = fgetc(fileImput);
                    buffer_char_2(in_char);
                    while(isalpha(in_char) || isdigit(in_char) || in_char == '.' || in_char == '_' || in_char == '-' || in_char == '/'){
                        buffer_char(in_char);
                        in_char = fgetc(fileImput);
                        buffer_char_2(in_char);
                    }
                    if(in_char == '"'){//Se detecto un #include "archivo.c" por lo que se tiene que incluir
                        //Empezar el include
                        direccion[0] = '\0';
                        getcwd(direccion, sizeof(direccion));
                        strcat( direccion,"/");
                        strcat( direccion, token_buffer);
                        if(file_exist(direccion)){
                            beginInclude();
                            currentFiles--;
                            fileImput = files[currentFiles+1];
                        }
                        else{
                            char err[100] = "Error al encontrar archivo: ";
                            strcat(err,token_buffer);
                            printf("%s\n",err);
                            exit(0);
                        }
                        clear_buffer();
                        clear_buffer_2();
                    }
                    else{//NO HAY " SEGUNDO
                        clear_buffer();
                        //fprintf(temp, token_buffer_2);
                        fputs(token_buffer_2,fileOutput);
                        clear_buffer_2();
                        continue;
                    }
                }//no empieza con comillas
                else{ //NO HAY include
                    fputs(token_buffer_2,fileOutput);
                    clear_buffer();
                    clear_buffer_2();
                    continue;
                }
            }//no es igual a include
            else if ( !strcmp(token_buffer,"ifndef") || !strcmp(token_buffer,"ifdef") || !strcmp(token_buffer,"endif")
            || !strcmp(token_buffer,"if") || !strcmp(token_buffer,"else") || !strcmp(token_buffer,"elif")
            || !strcmp(token_buffer,"warning") || !strcmp(token_buffer,"error") || !strcmp(token_buffer,"undef") ){

                clear_buffer_2();
                clear_buffer();
                while(in_char != '\n'){
                    in_char = fgetc(fileImput);
                }
                //fprintf(fileOutput, "///* Borramos \n \n");
                continue;


            }
            else{//si no es un include u otro de los que se evitan escribir se manda a escribir tal cual
                fputs(token_buffer_2,fileOutput);
                //printf("\n \t \t PUT Primero:--> %s", token_buffer);
                //printf("\n \t \t PUT Segundo:--> %s", token_buffer_2);
                clear_buffer_2();
                clear_buffer();
                continue;
            }
        }

        // else if(in_char == '|'){
        //
        //             if( (in_char = fgetc(fileImput)) == '|' ){
        //                 while(in_char != '\n') in_char = fgetc(fileImput);
        //                 //fprintf(fileOutput,"///*Se Borro || \n");
        //             }
        //
        // }
        // else if(in_char == '&'){
        //
        //             if( (in_char = fgetc(fileImput)) == '&' ){
        //                 while(in_char != '\n') in_char = fgetc(fileImput);
        //                 //fprintf(fileOutput,"///*Se Borro || \n");
        //             }
        //
        // }

        else if(in_char == '/'){
            buffer_char_2(in_char);
            in_char = fgetc(fileImput);
            buffer_char_2(in_char);
            if(in_char == '/'){
                clear_buffer();
                clear_buffer_2();
                while(in_char != '\n') in_char = fgetc(fileImput);
                fputc('\n',fileOutput);
            }else if(in_char == '*'){
                clear_buffer();
                clear_buffer_2();
                int sigueComentario = 1;
                while(sigueComentario && in_char != EOF) {
                    in_char = fgetc(fileImput);
                    if(in_char == '\n'){
                        fputc('\n',fileOutput);
                    }
                    if( in_char == '*'){
                        if( (in_char = fgetc(fileImput) ) == '/' ) sigueComentario=0;
                    }
                }
                if(in_char == EOF){
                    printf("%s\n", "Comentario no finalizado.");
                    exit(1);
                }
                fputc(' ',fileOutput);
            }
            else{//DIFERENTE A // y /*
                fputs(token_buffer_2,fileOutput);
                clear_buffer();
                clear_buffer_2();
            continue;
            }
        }
        else if(in_char == '\n'){
                bandera = 0;
                bandera2 = 0;
                fputc(in_char, fileOutput);
        }
        else if(in_char == ' ' && bandera2 == 0){
            bandera = 0;
        }
        else{
            bandera = 1;
            bandera2 = 1;
            fputc(in_char, fileOutput);
        }
    }
    fputc(' ',fileOutput);
    if(feof(fileImput)){
        return;
    }
}

void system_goal(FILE *in, FILE *out, int n){
    currentFiles = n;
    if(n==0) files[n] = out;
    else fileOutput = files[0];
    files[n+1] = in;
    fileImput = in;
    scanner();
    printf("                                  \n");
    /*for(int i=0; i<fileListCont;i++){
        printf("%s \n", fileList[i]);
    }*/
}
