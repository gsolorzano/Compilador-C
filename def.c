#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

FILE *fileIn;
FILE *fileOut;

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
    if(feof(fileIn)){
        return;
    }
    while((in_char = fgetc(fileIn) ) != EOF){//lee todo el codigo hasta el final del archivo
        if(in_char == '#'){
            addStr_2(in_char);
            in_char = fgetc(fileIn);
            if(isspace(in_char)){
                addStr_2(in_char);
                in_char = fgetc(fileIn);
                continue;
            }
            while(isalpha(in_char)){
                addStr_2(in_char);
                addStr(in_char);
                in_char = fgetc(fileIn);
            }
            for(int j = 0; j <= strlen(nomDef);j++){
                nomDef[j] = tolower(nomDef[j]);
            }
            //chequea si hay un declare
            addStr_2(in_char);
            if(!strcmp(nomDef,def)){//si hay un declare se hace aqui
                clean();
                in_char = fgetc(fileIn);
                addStr_2(in_char);
                if(isspace(in_char)){ // se come todos los espacios
                    in_char = fgetc(fileIn);
                    addStr_2(in_char);
                    continue;
                }

                if(isalpha(in_char) || in_char == '_'){ //busca a ver si el nombre de la variable es valido solo _ o letras
                    addStr_2(in_char);
                    addStr(in_char);
                    in_char = fgetc(fileIn);
                    while(isalpha(in_char) || isdigit(in_char) || in_char == '_'){ //busca todo el contenido del nombre de la variable _ o letras o nums
                        addStr(in_char);
                        in_char = fgetc(fileIn);
                        addStr_2(in_char);
                    }
                    while(isspace(in_char) && in_char != '\n'){ // se come todos los espacios
                        in_char = fgetc(fileIn);
                        //printf("%c\n", in_char);
                        addStr_2(in_char);
                    }
                    if(in_char == '\n'){ // si no hay valor mete el nombre y blanco en el valor
                        int band = 0;
                        for(int i = 0; i<=defCont;i++){
                            if(!strcmp(nomDef,ldef[i].nombre)){
                                strcpy(ldef[i].valor, nomDef_val);
                                clean_v();
                                clean_2();
                                clean();
                                band = 1;
                                break;
                            }
                        }
                        if(band == 1){
                            continue;
                        }
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
                        while(in_char != '\n'){//lee todo lo que falta hasta encontrar un new line
                            addStr_v(in_char);
                            in_char = fgetc(fileIn);
                        }
                        int band = 0;
                        for(int i = 0; i<=defCont;i++){
                            if(!strcmp(nomDef,ldef[i].nombre)){
                                strcpy(ldef[i].valor, nomDef_val);
                                clean_v();
                                clean_2();
                                clean();
                                band = 1;
                                break;
                            }
                        }
                        if(band == 1){
                            continue;
                        }
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
                }
            }
            else{//si no es un include se manda a escribir tal cual
                fprintf(fileOut, nomDef_2);
                continue;
            }
        }
        else{//DIFERENTE A #
            if(isalpha(in_char) || in_char == '_'){ //busca a ver si el nombre de la variable es valido solo _ o letras
                addStr(in_char);
                in_char = fgetc(fileIn);
                while(isalpha(in_char) || isdigit(in_char) || in_char == '_'){ //busca todo el contenido del nombre de la variable _ o letras o nums
                    addStr(in_char);
                    in_char = fgetc(fileIn);
                }
                int band = 0;
                for(int i = 0; i<defCont; i++){
                    if(!strcmp(nomDef, ldef[i].nombre)){// chequea a ver si lo formado está dentro del array de structs, si esta lo cambia
                        //Chequear si no hay que cambiar algo.
                        checkBefore(i);//Funcion que verifica si hay una variable que sustituir
                        fprintf(fileOut, ldef[i].valor);
                        band = 1;
                    }
                }
                if(band == 0){
                    fprintf(fileOut, nomDef);
                }
                fputc(in_char, fileOut);
            }
            else{
                fputc(in_char, fileOut);
            }
            //printf("%s\n", nomDef);
            clean();
        }
    }
    // for(int i = 0; i<defCont; i++){
    //     printf("%s\n", ldef[i].nombre);
    //     printf("%s\n", ldef[i].valor);
    // }
    if(feof(fileIn)){
        return;
    }
}

void checkBefore(int pos){//Recibe la posición del valor a verificar
    //Se limpian los strings a usar
    clean_2();
    clean_v();
    for(int i = 0; i<strlen(ldef[pos].valor);i++){//Se recorre el valor a verificar char por char
        if(isalpha(ldef[pos].valor[i]) || ldef[pos].valor[i] == '_'){ //busca a ver si el nombre de la variable es valido solo _ o letras
            addStr_2(ldef[pos].valor[i]);
            i++;
            while(isalpha(ldef[pos].valor[i]) || isdigit(ldef[pos].valor[i]) || ldef[pos].valor[i] == '_'){ //busca todo el contenido del nombre de la variable _ o letras o nums
                addStr_2(ldef[pos].valor[i]);//Guarda todo el nombre de la variale en nomDef_2
                i++;
            }
            int band = 0;//bandera para ver si se encontro algo igual
            for(int j = 0; j<=defCont;j++){
                if(!strcmp(nomDef_2, ldef[j].nombre)){//compara si el nombre de la variable está en la lista de structs
                    printf("%s\n", "yes");
                    strcat(nomDef_val, ldef[j].valor);//Agrega el valor del struct envez de la variable
                    band = 1;//cambia bandera
                    break;
                }
            }
            if(band == 0){//Si la bandera no se cambio meta en nomDef_val el nombre de la variable
                strcat(nomDef_val, nomDef_2);
            }
        }
        else{
            addStr_v(ldef[pos].valor[i]);//Si no es una variable lo que se leyo solo escribalo en nomDef_val directamente
        }
    }
    fprintf(fileOut, nomDef_val);
}

void doDefs(FILE *in, FILE *out){
    fileIn = in;
    fileOut = out;
    defFinder();
}
