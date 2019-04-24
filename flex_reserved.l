%{
FILE *fileImput;
FILE *fileOutput;
int key = 0;
int op = 0;
int sp = 0;
int id = 0;
int cst = 0;
int str = 0;
int err = 0;
FILE *fileOut;
char direccion[300];

typedef enum token_types{
    KEYWORD = 1, SPECIAL = 2, OPERATOR = 3, STRING = 4, IDENTIFIER = 5, CONSTANT = 6
} token;

int input_pos = 0;
int ini = 0;
int fin = 0;

%}

UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
EXP ([Ee][-+]?[0-9]+)
ILEN ([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

%%
"_Bool" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"_Complex" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"_Imaginary" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"auto" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"break" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"case" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"char" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"const" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"continues" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"default" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"do" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"int" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");  return KEYWORD;}
"long" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"register" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"return" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}} "); return KEYWORD;}
"short" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"signed" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"sizeof" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"static" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"struct" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"switch" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"typedef" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"union" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"unsigned" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"void" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"volatile" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"while" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"double" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"else" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"enum" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"extern" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"float" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"for" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"goto" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"if" { key++;fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}"); return KEYWORD;}
"(" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
")" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"\\" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, "\\textbackslash"); fprintf(fileOut, "}"); return SPECIAL;}
"{" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"}" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
";" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"," { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"." { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"?" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"!" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"@" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"[" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"]" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
":" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"->" { sp++;fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return SPECIAL;}
"=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"+" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"+=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"-=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"%=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fputs(yytext,fileOut); fprintf(fileOut, "}"); return OPERATOR;}
"/=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"*=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"<<=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
">>=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"<=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
">=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"!=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"==" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"++" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"--" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"-" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"*" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"/" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"%" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fputs(yytext,fileOut); fprintf(fileOut, "}"); return OPERATOR;}
"<" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
">" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"||" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"&" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"&=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"|" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"|=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"?:" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"^" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"^=" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"~" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"<<" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
">>" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}"); return OPERATOR;}
"%>" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fputs(yytext,fileOut); fprintf(fileOut, "}"); return OPERATOR;}
"%:" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fputs(yytext,fileOut); fprintf(fileOut, "}"); return OPERATOR;}
"<:" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fputs(yytext,fileOut); fprintf(fileOut, "}"); return OPERATOR;}
":>" { op++;fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\"); fputs(yytext,fileOut); fprintf(fileOut, "}"); return OPERATOR;}
"\n" {fprintf(fileOut, "\\\\"); fprintf(fileOut, "\n");}
" " {fprintf(fileOut, " ");}
"¬" {fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{$\\neg$}}"); }
[ñáéíóúÑÁÉÍÓÚäëöüÄÖÜ`]+[a-zA-ZñáéíóúÑÁÉÍÓÚäëöüÄÖÜ]* {err++; fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{"); fputs(yytext,fileOut); fprintf(fileOut, "}}");}
[a-zA-Z_]+[ñáéíóúÑÁÉÍÓÚäöüÄÖÜ]+[a-zA-Z_]* {err++;fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{"); fputs(yytext,fileOut); fprintf(fileOut, "}}");}
L?\"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})*\"  { strSpecial(); str++; return STRING;}
\'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\' { strSpecial(); str++; return STRING;}
[a-zA-Z_][a-zA-Z0-9_]* {id++; strIde(); return IDENTIFIER;}
0[0-7]*{ILEN}? { cst++;fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");return CONSTANT;}
[1-9][0-9]*{ILEN}? { cst++;fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");return CONSTANT;}
0[Xx][0-9a-fA-F]+{ILEN}? { cst++;fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");return CONSTANT;}
([0-9]*\.[0-9]+|[0-9]+\.){EXP}?[flFL]? { cst++;fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");return CONSTANT;}
[0-9]+{EXP}[flFL]? { cst++;fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");return CONSTANT;}
0[Xx]([0-9a-fA-F]*\.[0-9a-fA-F]+|[0-9a-fA-F]+\.?)[Pp][-+]?[0-9]+[flFL]? { cst++;fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");return CONSTANT;}
. {strBad();}
%%

int getToken(){
    yylex();
}

void strBad(){
    char str2[200] = "\0";
    int t = 0;
    for(int i = 0; i<yyleng;i++){
        if(yytext[i] == '$'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
    }
    fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{");
    fputs(str2,fileOut);
    fprintf(fileOut, "}}");
}

void strIde(){
    char str2[200] = "\0";
    int t = 0;
    for(int i = 0; i<yyleng;i++){
        if(yytext[i] == '_'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '$'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else{
            str2[t] = yytext[i];
            t++;
        }
    }
    fprintf(fileOut, "\\setstcolor{green}\\sethlcolor{green}\\Oricolor\\hl{\\textbf{");
    fputs(str2,fileOut);
    fprintf(fileOut, "}}");
    return;
}

void strSpecial(){
    char str2[200] = "\0";
    int t = 0;
    for(int i = 0; i<yyleng;i++){
        if(yytext[i] == '%'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '\"'){
            str2[t] = '\'';
            t++;
            str2[t] = '\'';
            t++;
        }
        else if(yytext[i] == '\n'){
        }
        else if(yytext[i] == '\\'){
            strcat(str2,"\\textbackslash ");
            t+=15;
        }
        else if(yytext[i] == '#'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '$'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '}'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '{'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '^'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '_'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else if(yytext[i] == '&'){
            str2[t] = '\\';
            t++;
            str2[t] = yytext[i];
            t++;
        }
        else{
            str2[t] = yytext[i];
            t++;
        }
    }
    fprintf(fileOut, "\\fcolorbox{orange}{orange}{\\textbf{");
    fputs(str2,fileOut);
    fprintf(fileOut, "}}");
}

void scan(){
    int tok;
    while(tok = yylex()) {
        printf("%d", tok);
    }
}


void includes(char nom[]){
    getcwd(direccion, sizeof(direccion))  ; //direccion del archivo en cuestion  tambien en la plantilla de nasm
    strcat( direccion,"/");
    strcat( direccion,nom);
    fileImput = fopen(direccion, "r");
    fileOutput = fopen("OUTPUT.txt","w");
    if(fileImput == NULL){
        fprintf(stderr,"Error al encontrar el archivo de entrada");
        exit(1);
    }
    system_goal(fileImput, fileOutput, 0);
    fclose(fileImput);
    fclose(fileOutput);
    cleanCode();
    fclose(fileImput);
    fclose(fileOutput);
}

void defines(){
    getcwd(direccion, sizeof(direccion));
    strcat( direccion,"/OUTPUT2.txt");
    fileImput = fopen(direccion,"r");
    fileOutput = fopen("prepo.c","w");
    doDefs(fileImput, fileOutput);
    printf("%s\n", "Preproceso finalizado");
    fclose(fileImput);
    fclose(fileOutput);
}


int main(int argc, char *argv[]){
    if (argc == 1){
        printf("Error al encontrar ruta de archivo \n");
        return 1;
    }
    if (argc == 2){
        includes(argv[1]);
        defines();
        /* FLEX */
        getcwd(direccion, sizeof(direccion));
        strcat( direccion,"/prepo.c");
        //strcat( direccion,"/OUTPUT2.txt");
        yyin = fopen(direccion, "r");
        /* if(argc > 1){
            if(!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return (1);
            }
        } */
        fileOut = fopen("FINAL.txt","w");
        //scan();
        while(getToken());
        fclose(fileOut);
        int nums[7];
        nums[0] = key;
        nums[1] = id;
        nums[2] = str;
        nums[3] = cst;
        nums[4] = sp;
        nums[5] = op;
        nums[6] = err;
        /* BEAMER */
        createBeamer(nums);
    }
    else{
        includes(argv[1]);
        defines();
        /* FLEX */
        getcwd(direccion, sizeof(direccion));
        strcat( direccion,"/prepo.c");
        yyin = fopen(direccion, "r");
        /* if(argc > 1){
            if(!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return (1);
            }
        } */
        fileOut = fopen("FINAL.txt","w");
        scan();

        fclose(fileOut);
        while(ini!=fin){
            getToken();
        }
    }
    return 1;
}

