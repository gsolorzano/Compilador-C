#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

FILE *fp;
FILE *fo;
int contO;

extern char token_buffer[100] = "\0";
char token_buffer_2[100] = "\0";
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

void scanner(void){
    int in_char, c;
    clear_buffer();
    if(feof(fp)){
        return;
    }
    while((in_char = fgetc(fp) ) != EOF){//lee todo el codigo hasta el final del archivo
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
                                    printf("\n");
                                    char direccion[200];
                                    getcwd(direccion, sizeof(direccion));
                                    strcat( direccion,"/");
                                    strcat( direccion,token_buffer);
                                    printf("\n");
                                    FILE *inc = fopen(direccion, "r");
                                    if(inc == NULL){
                                        fprintf(stderr,"Error al encontrar el archivo");
                                        exit(1);
                                    }
                                    else{
                                        clear_buffer_2();
                                        char nombre[100] = "\0";
                                        sprintf(nombre, "%d", contO);
                                        strcat(nombre,".txt");
                                        FILE *out = fopen(nombre,"w");
                                        system_goal(inc, out, contO++); //se llama de a analizar el archivo del include de conformar
                                        //recursiva pues puede tener otros include adentro
                                        //abrir el archivo temporal que genero la llamada recursiva para incluirlo en el archivo final
                                        FILE *temp = fopen("temp.txt","w");
                                        if(out == NULL){
                                            fprintf(stderr,"Error al encontrar el archivo");
                                            exit(1);
                                        }
                                        else{
                                            while ((c = fgetc(fo)) != EOF){
                                                fputc(c, temp);
                                            }
                                            while ((c = fgetc(out)) != EOF){
                                                fputc(c, temp);
                                            }
                                            fo = temp;
                                            fclose(temp);
                                        }
                                    }
                                    printf("%s\n", "si");
                                }
                                else{
                                    clear_buffer();
                                }
                            }
                            else{
                                clear_buffer();
                            }
                        }
                        else{
                            clear_buffer();
                            printf("%s\n", "no");
                        }
                    }
                    else{
                        fprintf(fo, token_buffer_2);
                        continue;
                    }
                }
                else{//si no es un include se manda a escribir tal cual
                    printf("%s\n", "no");
                }
            }
            else{
                fprintf(fo, in_char);
                return;
            }
        }
        else{
            fputc(in_char,fo);
        }
    }
    //     else if(isalpha(in_char)){
    //         /*
    //         * ID ::= LETTER | ID LETTER
    //                         | ID DIGIT
    //                         | ID UNDERSCORE
    //         */
    //         buffer_char(in_char);
    //         for(c = fgetc(fp) ; isalnum(c) || c == '_'; c = fgetc(fp) )
    //             buffer_char(c);
    //             ungetc(c, fp);
    //             return check_reserved();
    //     }
    //     else if(isdigit(in_char)){
    //         /*
    //          * INLITERAL ::= DIGIT |
    //          *               INLITERAL DIGIT
    //          */
    //         buffer_char(in_char);
    //         for(c = fgetc(fp); isdigit(c); c = fgetc(fp))
    //             buffer_char(c);
    //             ungetc(c, fp);
    //             return INTLITERAL;
    //
    //     }
    //     else if(in_char == '('){
    //         return LPAREN;
    //     }
    //     else if(in_char == ')'){
    //         return RPAREN;
    //     }
    //     else if(in_char == ';'){
    //         return SEMICOLON;
    //     }
    //     else if(in_char == ','){
    //         return COMMA;
    //     }
    //     else if(in_char == '+'){
    //         return PLUSOP;
    //     }
    //     else if(in_char == '|'){
    //         return PIPE;
    //     }
    //     else if(in_char == ':'){
    //         /* lookig for ":=" */
    //         c = fgetc(fp);
    //         if(c == '='){
    //             return ASSIGNOP;
    //         }
    //         else{
    //             ungetc(c, fp);
    //             lexical_error(in_char);
    //         }
    //     }
    //     else if(in_char == '-'){
    //         /* is it --, comment start */
    //         c = fgetc(fp);
    //         if(c == '-'){
    //             while(in_char != '\n'){
    //                 in_char = fgetc(fp);
    //             }
    //         }
    //         else{
    //             ungetc(c, fp);
    //             return MINUSOP;
    //         }
    //     }
    //     else{
    //         lexical_error(in_char);
    //     }
    if(feof(fp)){
        return;
    }
}

void system_goal(FILE *in, FILE *out, int n){
    fp = in;
    fo = out;
    contO = n;
    scanner();
}
