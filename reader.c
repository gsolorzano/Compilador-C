#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define A1111 B_-1.(

FILE *fileImput;
FILE *fileOutput;
FILE *temp;
FILE *files[200];
int currentFiles; //en donde est� el temp, antes del temp, est� el fuente
//y antes del fuente, est� el output

char direccion[300] = "\0";
char token_buffer[100] = "\0";
char token_buffer_2[100] = "\0";
char incl[] = "include";

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

void beginInclude(){

    FILE * toInclude = fopen(direccion, "r");
    if(toInclude == NULL){
        fprintf(stderr,"Error al encontrar el archivo");
        exit(1);
    }else{
        system_goal(toInclude, files[currentFiles],currentFiles+1);
        //+2, por que el asunto va sumando de 2 en dos para que
        //el nuevo temp, sea el nuevo output de la nueva llamada
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
    int in_char, c;
    clear_buffer();
    clear_buffer_2();
    if(feof(fileImput)){
        return;
    }
    while((in_char = fgetc(fileImput) ) != EOF){//lee todo el codigo hasta el final del archivo
        if(in_char == '#'){
            buffer_char_2(in_char);
            in_char = fgetc(fileImput);
            if(isspace(in_char)){
                buffer_char_2(in_char);
                in_char = fgetc(fileImput);
                continue; /* do nothin */
            }
            while(isalpha(in_char)){
                buffer_char_2(in_char);
                buffer_char(in_char);
                in_char = fgetc(fileImput);
            }
            for(int j = 0; j <= strlen(token_buffer);j++){
                token_buffer[j] = tolower(token_buffer[j]);
            }
            //chequea si hay un include
            buffer_char_2(in_char);
            if(!strcmp(token_buffer,incl)){//si hay un include se har�a aqui
                clear_buffer();
                in_char = fgetc(fileImput);
                buffer_char_2(in_char);
                if(isspace(in_char)){
                    in_char = fgetc(fileImput);
                    buffer_char_2(in_char);
                    continue;
                }
                if(in_char == '"'){
                    in_char = fgetc(fileImput);
                    buffer_char_2(in_char);

                    while(isalpha(in_char) || isdigit(in_char) || in_char == '.' || in_char == '_' || in_char == '-'){
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
                    }
                    else{//NO HAY " SEGUNDO
                        clear_buffer();
                        //fprintf(temp, token_buffer_2);
                        fprintf(fileOutput, token_buffer_2);
                        continue;
                    }
                }
                else{ //NO HAY
                    fprintf(fileOutput, token_buffer_2);
                    continue;
                }
            }
            else{//si no es un include se manda a escribir tal cual
                fprintf(fileOutput, token_buffer_2);
                continue;
            }
        }
        else{//DIFERENTE A #
            fputc(in_char, fileOutput);
        }
    }
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
}
