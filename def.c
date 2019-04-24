#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

FILE *fileIn;
FILE *fileOut;

char nomDefine[100] = "\0";
char nomDefine_val[100] = "\0";
char nomDefine_2[100] = "\0";

int visitedDef[100];
int visitedDefCount=0;


char def[] = "define";
int defineCont = 0;

struct defs{
    char nombre[100];
    char valor[150];
};

struct defs ldef[100];

void clean_v(){//borra el contenido de nomDef y lo resetea a un string vacio
    memset(nomDefine_val, 0, sizeof(nomDefine_val));
}

void addStr_v(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(nomDefine_val);
    nomDefine_val[len] = c;
    nomDefine_val[len+1] = '\0';
}

void clean_2(){//borra el contenido de nomDef y lo resetea a un string vacio
    memset(nomDefine_2, 0, sizeof(nomDefine_2));
}

void addStr_2(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(nomDefine_2);
    nomDefine_2[len] = c;
    nomDefine_2[len+1] = '\0';
}

void clean(){//borra el contenido de nomDef y lo resetea a un string vacio
    memset(nomDefine, 0, sizeof(nomDefine));
}

void addStr(char c){//Recibe un char para agregarlo al buffer y conformar palabras paevisadasra ser r
    int len = strlen(nomDefine);
    nomDefine[len] = c;
    nomDefine[len+1] = '\0';
}


//struct defs ldef[100]; --> es solo para saber como se llama el array de structs


int getMatch(char toSearch[30]){
    printf("\t \t GETMATCH: \t Valor %s Index: \t", toSearch);
    for(int i=0; i<defineCont; i++){
        if(!strcmp(toSearch, ldef[i].nombre)) {
                return i;
        }
    }
    return -1;
}


void totalValorMaker(int pos){ //Función para encontrar el valor de cada define resolviendo los defines internos
    visitedDef[visitedDefCount] = pos;
    visitedDefCount++;//Se guarda el índice del parámetro (significa que ldef[pos] ha sido visitado) para verificar autodefinición
                        //la verificación se debe hacer al final de cada palabra

    //strcat(ldef[pos].valor, " ");
    int isRecursive=0;
    int entreComillas=0;
    int size = strlen( ldef[pos].valor );
    char tempWord[30] ="\0";
    int tempWordCont=0;

    for(int k=0; k<size; k++){
            printf("\t \t \t Letra actual: %c \n", ldef[pos].valor[k]);
        //printf("%c", ldef[pos].valor[k] );
        if(isRecursive ){
            fputc(ldef[pos].valor[k],fileOut);
            continue;
        }
        else if (ldef[pos].valor[k]=='"' || entreComillas==1) { //aquí se escribe directo en el archivo mientras se encuentren
                //comillas o se esté en medio de algún par de comillas
                //ELSE IF3

                int defMatch=0;

                for(int p=0; p<visitedDefCount; p++){

                if(!strcmp(tempWord, ldef[visitedDef[p]].nombre )) {
                        defMatch++;
                        break;
                    }

                }//Verificar si algunos de los defines visitados se encuentra en el valor

            if( defMatch){//si se detectó recursión procede a escribir
                fprintf(fileOut,tempWord);
                isRecursive=1;
                memset(tempWord, 0, sizeof(tempWord));//ESTO SE PUEDE SACAR DESPUES DEL IF Y EL ELSE
                tempWordCont =0;
                fputc(ldef[pos].valor[k],fileOut);
                continue;
            }
            else{ //no es recursiva y tiene una definición de algo más
                int newPos = getMatch(tempWord);

                if(newPos != -1) {
                        totalValorMaker(newPos);
                        visitedDefCount--;
                }
                else fprintf(fileOut, tempWord);

                memset(tempWord, 0, sizeof(tempWord));
                tempWordCont =0;
                fputc(ldef[pos].valor[k],fileOut);//ESTO SE PUEDE SACAR DESPUES DEL IF Y EL ELSE
                continue;
            }

                if(ldef[pos].valor[k]=='"'){//IF2
                    entreComillas=entreComillas?0:1;
                    fputc(ldef[pos].valor[k],fileOut);
                    continue;
                }//IF2
                fputc(ldef[pos].valor[k],fileOut);
                continue;
        }//ELSE IF3


         if((ldef[pos].valor[k] == ' ' || ldef[pos].valor[k] == '\n') || k+1 == size )
        { //señal para evaluar la palabra // IF3

//            if( (isalpha(ldef[pos].valor[k]) || isdigit(ldef[pos].valor[k])) ){
//                tempWord[tempWordCont] = ldef[pos].valor[k];
//                tempWordCont++;
//                printf("Palabra actual: %s \n", tempWord);
//            }

            int defMatch=0;
            for(int p=0; p<visitedDefCount; p++){
                if(!strcmp(tempWord, ldef[visitedDef[p]].nombre )) {
                        defMatch++;
                        break;
                }
            }
            if( defMatch){//si se detectó recursión procede a escribir
                fprintf(fileOut,tempWord);
                isRecursive=1;
                memset(tempWord, 0, sizeof(tempWord));//ESTO SE PUEDE SACAR DESPUES DEL IF Y EL ELSE
                tempWordCont =0;
                fputc(ldef[pos].valor[k],fileOut);
                continue;
            }
            else{ //no es recursiva y tiene una definición de algo más
                int newPos = getMatch(tempWord);

                if(newPos != -1) {
                        totalValorMaker(newPos);
                        visitedDefCount--;
                }
                else fprintf(fileOut, tempWord);

                memset(tempWord, 0, sizeof(tempWord));
                tempWordCont =0;
                fputc(ldef[pos].valor[k],fileOut);//ESTO SE PUEDE SACAR DESPUES DEL IF Y EL ELSE
                continue;
            }
            //aquí se limpia el string temporal
//            memset(tempWord, 0, sizeof(tempWord));
//            tempWordCont =0;

        }//  IF3
        else if( (ldef[pos].valor[k]=='_' || isalpha(ldef[pos].valor[k]) || isdigit(ldef[pos].valor[k])) )
        {//IF2
            tempWord[tempWordCont] = ldef[pos].valor[k];
            tempWordCont++;
        }//IF2
        else{
            //fputc(ldef[pos].valor[k], fileOut);
            int defMatch=0;
            for(int p=0; p<visitedDefCount; p++){
                if(!strcmp(tempWord, ldef[visitedDef[p]].nombre )) {
                        defMatch++;
                        break;
                }
            }
            if( defMatch){//si se detectó recursión procede a escribir
                fprintf(fileOut,tempWord);
                isRecursive=1;
                memset(tempWord, 0, sizeof(tempWord));//ESTO SE PUEDE SACAR DESPUES DEL IF Y EL ELSE
                tempWordCont =0;
                fputc(ldef[pos].valor[k],fileOut);
                continue;
            }
            else{ //no es recursiva y tiene una definición de algo más
                int newPos = getMatch(tempWord);

                if(newPos != -1) {
                        totalValorMaker(newPos);
                        visitedDefCount--;
                }
                else fprintf(fileOut, tempWord);

                memset(tempWord, 0, sizeof(tempWord));
                tempWordCont =0;
                fputc(ldef[pos].valor[k],fileOut);//ESTO SE PUEDE SACAR DESPUES DEL IF Y EL ELSE
                continue;
            }
        }

    }//FOR
}//FUNCTION



void defFinder(){
    int in_char;
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
//            for(int j = 0; j <= strlen(nomDef);j++){
//                nomDef[j] = tolower(nomDef[j]);
//            }
            //chequea si hay un declare
            addStr_2(in_char);
            if(!strcmp(nomDefine,def)){//si hay un declare se hace aqui
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
                        for(int i = 0; i<=defineCont;i++){
                            if(!strcmp(nomDefine,ldef[i].nombre)){
                                strcpy(ldef[i].valor, nomDefine_val);
                                clean_v();
                                clean_2();
                                clean();
                                band = 1;
                                break;
                            }
                        }
                        if(band == 1){
                            fputc(' ', fileOut);
                            continue;
                        }
                        struct defs d1;
                        //printf("%s\n",nomDef);
                        strcpy(d1.nombre, nomDefine);
                        //printf("%s\n",nomDef_val);
                        strcpy(d1.valor, nomDefine_val);
                        ldef[defineCont] = d1;
                        defineCont++;
                        clean_v();
                        clean_2();
                        clean();
                        fputc(' ', fileOut);
                        continue;
                    }
                    else{
                        while(in_char != '\n'){//lee todo lo que falta hasta encontrar un new line
                            addStr_v(in_char);
                            in_char = fgetc(fileIn);
                        }
                        int band = 0;
                        for(int i = 0; i<=defineCont;i++){
                            if(!strcmp(nomDefine,ldef[i].nombre)){
                                strcpy(ldef[i].valor, nomDefine_val);
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
                        strcpy(d1.nombre, nomDefine);
                        //printf("%s\n",nomDef_val);
                        strcpy(d1.valor, nomDefine_val);
                        strcat(d1.valor, " ");
                        ldef[defineCont] = d1;
                        defineCont++;
                        clean_v();
                        clean_2();
                        clean();
                        continue;
                    }
                }
                else{
                    while(in_char != '\n'){
                        in_char = fgetc(fileIn);
                    }
                    continue;
                }
            }//HASTA AQUÍ SE TRABAJA EL DEFINE (CONFECCIONARLO)
            else{//si no es un include se manda a escribir tal cual
                fprintf(fileOut, nomDefine_2);
                continue;
            }
        }
        else{//DIFERENTE A # --> BUSCAR POR EL NOMBRE DE UN DEFINE
            if(isalpha(in_char) || in_char == '_'){ //busca a ver si el nombre de la variable es valido solo _ o letras
                addStr(in_char);
                in_char = fgetc(fileIn);
                while(isalpha(in_char) || isdigit(in_char) || in_char == '_'){ //busca todo el contenido del nombre de la variable _ o letras o nums
                    addStr(in_char);
                    in_char = fgetc(fileIn);
                }
                int band = 0;
                for(int i = 0; i<defineCont; i++){
                    if(!strcmp(nomDefine, ldef[i].nombre)){// chequea a ver si lo formado está dentro del array de structs, si esta lo cambia
                        //Chequear si no hay que cambiar algo.
                        //printf("\nBueno: Word: "); printf("%s \t",nomDefine); printf("Name: "); printf("%s \t", ldef[i].nombre);
                        //printf("Valor: ");printf("%s \n", ldef[i].valor);
                        //checkBefore(i);//Funcion que verifica si hay una variable que sustituir
                        //checkBefore(i);//Funcion que verifica si hay una variable que sustituir
                        totalValorMaker(i); //Se encarga de expandir la el define hasta ser resuelto o hasta ser recurrente
                        //fprintf(fileOut, totalValorMakerString); //LO QUITÉ PARA HACER EL FPRINT EN LAS FUNCIONES
                        visitedDefCount = 0;
                        //visitedDef[0] = -1;
                        band = 1;
                    }
                }
                if(band == 0){
                    fprintf(fileOut, nomDefine);
                }
                fputc(in_char, fileOut); //CREO QUE ESTE HACE QUE SE PRODUZCA UN ERROR
            }
            else{
                fputc(in_char, fileOut);
            }
//            printf("%s\n", nomDef);
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
            for(int j = 0; j<=defineCont;j++){
                if(!strcmp(nomDefine_2, ldef[j].nombre)){//compara si el nombre de la variable está en la lista de structs
                    strcat(nomDefine_val, ldef[j].valor);//Agrega el valor del struct envez de la variable
                    band = 1;//cambia bandera
                    break;
                }
            }
            if(band == 0){//Si la bandera no se cambio meta en nomDef_val el nombre de la variable
                strcat(nomDefine_val, nomDefine_2);
            }
        }
        else{
            addStr_v(ldef[pos].valor[i]);//Si no es una variable lo que se leyo solo escribalo en nomDef_val directamente
        }
    }
    fprintf(fileOut, nomDefine_val);
}

void doDefs(FILE *in, FILE *out){
    fileIn = in;
    fileOut = out;
    defFinder();
}