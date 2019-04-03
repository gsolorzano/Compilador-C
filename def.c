#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

FILE *fileImput;
FILE *fileOutput;

char nomDef[100] = "\0";
char nomDef_val[100] = "\0";
char nomDef_2[100] = "\0";
char def[] = "define";
int defCont = 0;

struct defs{
    char nombre[100];
    char valor[150];
};

struct defs ldef[100];

void clean_v(){//borra el contenido de nomDef y lo resetea a un string vacio
    memset(nomDef_val, 0, sizeof(nomDef_val));
}

void addStr_v(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(nomDef_val);
    nomDef_val[len] = c;
    nomDef_val[len+1] = '\0';
}

void clean_2(){//borra el contenido de nomDef y lo resetea a un string vacio
    memset(nomDef_2, 0, sizeof(nomDef_2));
}

void addStr_2(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(nomDef_2);
    nomDef_2[len] = c;
    nomDef_2[len+1] = '\0';
}

void clean(){//borra el contenido de nomDef y lo resetea a un string vacio
    memset(nomDef, 0, sizeof(nomDef));
}

void addStr(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(nomDef);
    nomDef[len] = c;
    nomDef[len+1] = '\0';
}

void defFinder(){
    int in_char, c;
    clean();
    clean_2();
    if(feof(fileImput)){
        return;
    }
    while((in_char = fgetc(fileImput) ) != EOF){//lee todo el codigo hasta el final del archivo
        if(in_char == '#'){
            addStr_2(in_char);
            in_char = fgetc(fileImput);
            if(isspace(in_char)){
                addStr_2(in_char);
                in_char = fgetc(fileImput);
                continue; /* do nothin */
            }
            while(isalpha(in_char)){
                addStr_2(in_char);
                addStr(in_char);
                in_char = fgetc(fileImput);
            }
            for(int j = 0; j <= strlen(nomDef);j++){
                nomDef[j] = tolower(nomDef[j]);
            }
            //chequea si hay un include
            addStr_2(in_char);
            if(!strcmp(nomDef,def)){//si hay un include se har�a aqui
                clean();
                in_char = fgetc(fileImput);
                addStr_2(in_char);
                if(isspace(in_char)){
                    in_char = fgetc(fileImput);
                    addStr_2(in_char);
                    continue;
                }
                if(isalpha(in_char) || in_char == '_'){
                    addStr_2(in_char);
                    addStr(in_char);
                    in_char = fgetc(fileImput);
                    while(isalpha(in_char) || isdigit(in_char) || in_char == '_'){
                        addStr(in_char);
                        in_char = fgetc(fileImput);
                        addStr_2(in_char);
                    }
                    if(isspace(in_char) && in_char != '\n'){
                        in_char = fgetc(fileImput);
                        addStr_2(in_char);
                    }
                    if(in_char == '\n'){
                        struct defs d1;
                        //printf("%s\n",nomDef);
                        strcpy(d1.nombre, nomDef);
                        //printf("%s\n",nomDef_val);
                        strcpy(d1.valor, nomDef_val);
                        ldef[defCont] = d1;
                        defCont++;
                        clean_v();
                        clean_2();
                        clean();
                        continue;
                    }
                    else{
                        while(in_char != '\n'){//Se detecto un #include "archivo.c" por lo que se tiene que incluir
                            addStr_v(in_char);
                            in_char = fgetc(fileImput);
                        }
                        struct defs d1;
                        //printf("%s\n",nomDef);
                        strcpy(d1.nombre, nomDef);
                        //printf("%s\n",nomDef_val);
                        strcpy(d1.valor, nomDef_val);
                        printf("%d\n", strlen(ldef[0].valor) );
                        ldef[defCont] = d1;
                        defCont++;
                        clean_v();
                        clean_2();
                        clean();
                        continue;
                    }
                }
            }
            else{//si no es un include se manda a escribir tal cual
                fprintf(fileOutput, nomDef_2);
                continue;
            }
        }
        else{//DIFERENTE A #
            while(!isspace(in_char)){
                addStr(in_char);
                in_char = fgetc(fileImput);
            }
            for(int i = 0; i<defCont; i++){
                if(!strcmp(nomDef, ldef[i].nombre)){
                    printf("%s\n", ldef[i].valor);
                }
            }
            //printf("%s\n", nomDef);
            clean();
            fputc(in_char, fileOutput);
        }
    }
    if(feof(fileImput)){
        return;
    }
}

void doDefs(FILE *in, FILE *out){
    fileImput = in;
    fileOutput = out;
    defFinder();
}
