%{
FILE *fileImput;
FILE *fileOutput;
FILE *declares;
FILE * finalEnsambler;
FILE * mergedFile;
int key = 0;
int op = 0;
int sp = 0;
int id = 0;
int cst = 0;
int str = 0;
int err = 0;
extern int errores;
extern struct semantic_record* pila;

extern struct symbolT* symbolTable;

extern struct tableRegister* symbolStck;
int conteo = 0;
int beamer = 0;
FILE *fileOut;
char linea[700];
char direccion[300];
char direccion2[300];
char direccion3[300];
char direccion4[300];int column = 0;

char idActual[200];

enum yytokentype
{
  IDENTIFIER = 258,
  CONSTANT = 259,
  STRING_LITERAL = 260,
  SIZEOF = 261,
  PTR_OP = 262,
  INC_OP = 263,
  DEC_OP = 264,
  LEFT_OP = 265,
  RIGHT_OP = 266,
  LE_OP = 267,
  GE_OP = 268,
  EQ_OP = 269,
  NE_OP = 270,
  AND_OP = 271,
  OR_OP = 272,
  MUL_ASSIGN = 273,
  DIV_ASSIGN = 274,
  MOD_ASSIGN = 275,
  ADD_ASSIGN = 276,
  SUB_ASSIGN = 277,
  LEFT_ASSIGN = 278,
  RIGHT_ASSIGN = 279,
  AND_ASSIGN = 280,
  XOR_ASSIGN = 281,
  OR_ASSIGN = 282,
  TYPE_NAME = 283,
  TYPEDEF = 284,
  EXTERN = 285,
  STATIC = 286,
  AUTO = 287,
  REGISTER = 288,
  INLINE = 289,
  RESTRICT = 290,
  CHAR = 291,
  SHORT = 292,
  INT = 293,
  LONG = 294,
  SIGNED = 295,
  UNSIGNED = 296,
  FLOAT = 297,
  DOUBLE = 298,
  CONST = 299,
  VOLATILE = 300,
  VOID = 301,
  BOOL = 302,
  COMPLEX = 303,
  IMAGINARY = 304,
  STRUCT = 305,
  UNION = 306,
  ENUM = 307,
  ELLIPSIS = 308,
  CASE = 309,
  DEFAULT = 310,
  IF = 311,
  ELSE = 312,
  SWITCH = 313,
  WHILE = 314,
  DO = 315,
  FOR = 316,
  GOTO = 317,
  CONTINUE = 318,
  BREAK = 319,
  RETURN = 320
};

int input_pos = 0;
int ini = 0;
int fin = 0;
%}

UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})
EXP ([Ee][-+]?[0-9]+)
ILEN ([Uu](L|l|LL|ll)?|(L|l|LL|ll)[Uu]?)

%%
"auto" { strcat(linea, yytext);count();key++;if(beamer == 1){if(beamer == 1){latKey(2);}}; if(conteo == 1)return AUTO;}
"break" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return BREAK;}
"case" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return CASE;}
"char" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return CHAR;}
"const" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return CONST;}
"continue" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return CONTINUE;}
"default" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return DEFAULT;}
"do" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return DO;}
"int" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);};  if(conteo == 1)return INT;}
"long" {strcat(linea, yytext);count(); key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return LONG;}
"register" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return REGISTER;}
"return" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return RETURN;}
"short" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return SHORT;}
"signed" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return SIGNED;}
"sizeof" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return SIZEOF;}
"static" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return STATIC;}
"struct" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return STRUCT;}
"switch" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return SWITCH;}
"typedef" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return TYPEDEF;}
"union" {strcat(linea, yytext);count(); key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return UNION;}
"unsigned" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return UNSIGNED;}
"void" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return VOID;}
"volatile" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return VOLATILE;}
"while" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return WHILE;}
"double" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return DOUBLE;}
"else" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return ELSE;}
"enum" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return ENUM;}
"extern" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return EXTERN;}
"float" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return FLOAT;}
"for" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return FOR;}
"goto" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return GOTO;}
"if" { strcat(linea, yytext);count(); key++;if(beamer == 1){latKey(2);}; if(conteo == 1)return IF;}
"bool" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(1);};if(conteo == 1)return BOOL; }
"_Bool" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(1);};if(conteo == 1)return BOOL; }
"_Complex" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(1);};if(conteo == 1)return COMPLEX; }
"_Imaginary" { strcat(linea, yytext);count();key++;if(beamer == 1){latKey(1);};if(conteo == 1)return IMAGINARY; }
"(" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return '(';}
")" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return ')';}
"\\" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(3);}; if(conteo == 1)return '\\';}
"{" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(2);}; if(conteo == 1)return '{';}
"}" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(2);}; if(conteo == 1)return '}';}
";" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return ';';}
"," { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return ',';}
"." { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return '.';}
"?" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return '?';}
"!" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return '!';}
"@" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return '@';}
"[" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return '[';}
"]" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return ']';}
":" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);}; if(conteo == 1)return ':';}
"=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '=';}
"+" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '+';}
"-" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '-';}
"*" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '*';}
"/" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '/';}
"%" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(2);}; if(conteo == 1)return '%';}
"<" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '<';}
">" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '>';}
"|" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '|';}
"&" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(2);}; if(conteo == 1)return '&';}
"^" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(2);}; if(conteo == 1)return '^';}
"~" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return '~';}
"..." { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);} if(conteo == 1)return ELLIPSIS;}
"->" { strcat(linea, yytext);count();sp++;if(beamer == 1){latSp(1);} if(conteo == 1)return PTR_OP;}
"+=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return ADD_ASSIGN;}
"-=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return SUB_ASSIGN;}
"%=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(2);}; if(conteo == 1)return MOD_ASSIGN;}
"/=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return DIV_ASSIGN;}
"*=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return MUL_ASSIGN;}
"<<=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return LEFT_ASSIGN;}
">>=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return RIGHT_ASSIGN;}
"&=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(2);}; if(conteo == 1)return AND_ASSIGN;}
"|=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return OR_ASSIGN;}
"^=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(2);}; if(conteo == 1)return XOR_ASSIGN;}
"<=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return LE_OP;}
">=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return GE_OP;}
"!=" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return NE_OP;}
"==" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return EQ_OP;}
"++" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return INC_OP;}
"--" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return DEC_OP;}
"||" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return OR_OP;}
"&&" { strcat(linea, yytext);count();op++;if(beamer == 1){latOpSP('&');}; if(beamer == 1){latOpSP('&');}; return AND_OP;}
"<<" { strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return LEFT_OP;}
">>" { strcat(linea, yytext);strcat(linea, yytext);count();op++;if(beamer == 1){latOp(1);}; if(conteo == 1)return RIGHT_OP;}
"\n" {strcat(linea, yytext);count(); memset(linea, 0, sizeof(linea));if(conteo == 1){yylineno++;};fprintf(fileOut, "\\leavevmode\\\\"); fprintf(fileOut, "\n");column = 0;}
" " {fprintf(fileOut, " ");}
"\t" {}
"¬" {if(beamer == 1){fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{$\\neg$}}");}; }
\'([^'\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})+\' { strcat(linea, yytext);count();if(beamer == 1){strSpecial();}; str++; if(conteo == 1)return CONSTANT;}
L?\"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})*\"  {strcat(linea, yytext);count();if(beamer == 1){strSpecial();}; str++; if(conteo == 1)return STRING_LITERAL;}
[ñáéíóúÑÁÉÍÓÚäëöüÄÖÜ`]+[a-zA-ZñáéíóúÑÁÉÍÓÚäëöüÄÖÜ]* {strcat(linea, yytext);count();err++; if(beamer == 1){fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{"); fputs(yytext,fileOut); fprintf(fileOut, "}}");};}
[a-zA-Z_]+[ñáéíóúÑÁÉÍÓÚäöüÄÖÜ]+[a-zA-Z_]* {strcat(linea, yytext);count();err++;if(beamer == 1){fprintf(fileOut, "\\fcolorbox{pink}{pink}{\\textbf{"); fputs(yytext,fileOut); fprintf(fileOut, "}}");};}
([_a-zA-Z]|{UCN})([_a-zA-Z0-9]|{UCN})* {strcat(linea, yytext);count();id++; if(beamer == 1){strIde();}; if(conteo == 1)strcpy(idActual,yytext);return IDENTIFIER;}
0[0-7]*{ILEN}? { strcat(linea, yytext);count();cst++;if(beamer == 1){latNum();};if(conteo == 1)return CONSTANT;}
[1-9][0-9]*{ILEN}? { strcat(linea, yytext);count();cst++;if(beamer == 1){latNum();};if(conteo == 1)return CONSTANT;}
0[Xx][0-9a-fA-F]+{ILEN}? { strcat(linea, yytext);count();cst++;if(beamer == 1){latNum();};if(conteo == 1)return CONSTANT;}
([0-9]*\.[0-9]+|[0-9]+\.){EXP}?[flFL]? {strcat(linea, yytext);count(); cst++;if(beamer == 1){latNum();};if(conteo == 1)return CONSTANT;}
[0-9]+{EXP}[flFL]? { strcat(linea, yytext);count(); cst++;if(beamer == 1){latNum();};if(conteo == 1)return CONSTANT;}
0[Xx]([0-9a-fA-F]*\.[0-9a-fA-F]+|[0-9a-fA-F]+\.?)[Pp][-+]?[0-9]+[flFL]? { strcat(linea, yytext);count();cst++;if(beamer == 1){latNum();};if(conteo == 1)return CONSTANT;}
"☼" {if(conteo == 1){conteo = 0;}else{conteo = 1;yylineno--;};}
. {strBad(); /*printf("%s\n\n\n", "ERROR");*/ }
%%

void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
}

int check_type(void){

	return IDENTIFIER;
}


int getToken(){
    yylex();
}

void latNum(){
    fprintf(fileOut, "\\setstcolor{amethyst}\\sethlcolor{amethyst}\\Oricolor\\hl{\\textbf{");
    fprintf(fileOut, yytext);
    fprintf(fileOut, "}}");
}

void latOp(int n){
    if(n==1){
        fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{");
        fprintf(fileOut, yytext);
        fprintf(fileOut, "}");
    }
    else{
        fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\");
        fputs(yytext,fileOut);
        fprintf(fileOut, "}");
    }
    return;
}

void latOpSP(char c){
    fprintf(fileOut, "\\setstcolor{red}\\sethlcolor{red}\\Oricolor\\hl{\\");
    fputc(c,fileOut);
    fprintf(fileOut, "}");
}

void latSp(int n){
    if(n==1){
        fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{");
        fprintf(fileOut, yytext);
        fprintf(fileOut, "}");
    }
    else if(n==2){
        fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{\\");
        fprintf(fileOut, yytext);
        fprintf(fileOut, "}");
    }
    else{
        fprintf(fileOut, "\\setstcolor{yellow}\\sethlcolor{yellow}\\Oricolor\\hl{");
        fprintf(fileOut, "\\textbackslash");
        fprintf(fileOut, "}");
    }
    return;
}

void latKey(int n){
    if(n==1){
        fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{\\");
        fprintf(fileOut, yytext);
        fprintf(fileOut, "}}");
    }
    else{
        fprintf(fileOut, "\\setstcolor{azure}\\sethlcolor{azure}\\Oricolor\\hl{\\textit{");
        fprintf(fileOut, yytext);
        fprintf(fileOut, "}}");
    }
    return;
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
    if(yyleng >= 511){
        printf("%s","string length 'XXX' is greater than the length '509' ISO C90 compilers are required to support");
        exit(1);
    }
    char str2[2000] = "\0";
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
        fprintf(stderr,"Error al encontrar el archivo de entrada\n\n");
        printf("%s\n\n", "**Guía de como usar el programa**");
        printf("\t%s\n\n", "Para correr el programa se utiliza el comando: lexscan");
        printf("\t%s\n", "El programa recibe un parámetro obligatorio:");
        printf("\t\t%s\n\n", "Archivo de texto que contiene código a parsear");
        printf("\t%s\n", "El programa recibe una bandera opcional:");
        printf("\t\t%s\n\n", "-B es la bandera que permite crear un beamer con la información del preproceso y parsing");
        printf("\t%s\n", "Ejemplo de ejecución:");
        printf("\t\t%s\n\n", "lexscan programa.c");
        printf("\t%s\n", "Ejemplo de ejecución con Beamer:");
        printf("\t\t%s\n", "lexscan programa.c -B");
        exit(1);
    }
    fprintf(fileOutput, "☼\n");
    system_goal(fileImput, fileOutput, 0);
    fclose(fileImput);
    fclose(fileOutput);
}

void defines(){
    getcwd(direccion, sizeof(direccion));
    strcat( direccion,"/OUTPUT.txt");
    fileImput = fopen(direccion,"r");
    fileOutput = fopen("prepo.c","w");
    doDefs(fileImput, fileOutput);
    printf("%s\n", "Preproceso finalizado");
    fclose(fileImput);
    fclose(fileOutput);
}


void compile(){
char ch;
    printf("%s","Parsing:\n\n");
    /* FLEX */

    getcwd(direccion, sizeof(direccion));
    getcwd(direccion2, sizeof(direccion2));
    getcwd(direccion3, sizeof(direccion3));
    getcwd(direccion4, sizeof(direccion4));

    declares   =  fopen("declares.txt","w");
    putc('%',  declares);
    fputs("include 'bib.asm'  \nsection .bss \n", declares);
    finalEnsambler =  fopen("ensambler.txt","w");
    fputs("section .data \n  \t menos db 45 \n \t dosPuntos db 58 \n section .text \n \t global _start \n_start: \n", finalEnsambler);

    strcat( direccion,"/prepo.c");
    yyin = fopen(direccion, "r");
    fileOut = fopen("FINAL.txt","w");
    yylineno = 1;
    pushSymbol(&symbolStck,symbolTable, 1);
    yyparse();
    if(errores != 0){
        printf("%s","Proceso de parsing finalizo con errores. Total de errores sintácticos: ");
        printf("%d\n",errores);
    }
    else{
        printf("%s\n","Proceso de parsing finalizo satisfactoriamente sin errores.");
    }
    fclose(fileOut);
    fclose(declares);
    fclose(finalEnsambler);

    strcat( direccion2,"/declares.txt");
    strcat( direccion3,"/ensambler.txt");
    strcat( direccion4,"/file.asm");



    declares = fopen(direccion2, "r");
    finalEnsambler = fopen(direccion3, "r");
    mergedFile = fopen(direccion4, "w");

    while((ch = fgetc(declares)) != EOF) fputc(ch,mergedFile);

    while((ch = fgetc(finalEnsambler)) != EOF) fputc(ch,mergedFile);
    haltProgram();
    verificacionNegativo();
    fclose(declares);
    fclose(finalEnsambler);
    fclose(mergedFile);

   // remove("declares.txt");
   // remove("ensambler.txt");
   // ejecutarFile();
}

void haltProgram(){
    fputs("\tmov  ebx, 0 \n" , mergedFile);
    fputs("\tmov  eax, 1 \n" , mergedFile);
    fputs("\tint  80h\n" , mergedFile);
    fputs("\tret \n" , mergedFile);
}


void verificacionNegativo(){
  fputs("\n\n\nverificarNegativo: \n" , mergedFile);
  fputs("\tcmp eax, 0 \n" , mergedFile);
  fputs("\tjge .return \n" , mergedFile);
  fputs("\tpush eax \n" , mergedFile);
  fputs("\tmov eax, 4\n" , mergedFile);
  fputs("\tmov ebx, 1\n" , mergedFile);
  fputs("\tmov ecx, menos\n" , mergedFile);
  fputs("\tmov edx, 1\n" , mergedFile);
  fputs("\tint 80h\n" , mergedFile);
  fputs("\tpop eax \n" , mergedFile);
  fputs("\tneg eax\n" , mergedFile);
  fputs("\t.return:\n" , mergedFile);
  fputs("\tret\n" , mergedFile);
}

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("%s\n\n", "**Guía de como usar el programa**");
        printf("\t%s\n\n", "Para correr el programa se utiliza el comando: lexscan");
        printf("\t%s\n", "El programa recibe un parámetro obligatorio:");
        printf("\t\t%s\n\n", "Archivo de texto que contiene código a parsear");
        printf("\t%s\n", "El programa recibe una bandera opcional:");
        printf("\t\t%s\n\n", "-B es la bandera que permite crear un beamer con la información del preproceso y parsing");
        printf("\t%s\n", "Ejemplo de ejecución:");
        printf("\t\t%s\n\n", "lexscan programa.c");
        printf("\t%s\n", "Ejemplo de ejecución con Beamer:");
        printf("\t\t%s\n", "lexscan programa.c -B");
        return 1;
    }
    if (argc == 2){
        includes(argv[1]);
        defines();
        compile();
        ejecutarFile();
        remove("FINAL.txt");
        remove("OUTPUT.txt");
    }
    else if (argc == 3){
        if(!strcmp(argv[2],"-B")){
            beamer = 1;
            includes(argv[1]);
            defines();
            compile();
            /* BEAMER */
            int nums[7];
            nums[0] = key;
            nums[1] = id;
            nums[2] = str;
            nums[3] = cst;
            nums[4] = sp;
            nums[5] = op;
            nums[6] = err;
            createBeamer(nums);
        }
        else{
            printf("%s\n\n", "**Guía de como usar el programa**");
            printf("\t%s\n\n", "Para correr el programa se utiliza el comando: lexscan");
            printf("\t%s\n", "El programa recibe un parámetro obligatorio:");
            printf("\t\t%s\n\n", "Archivo de texto que contiene código a parsear");
            printf("\t%s\n", "El programa recibe una bandera opcional:");
            printf("\t\t%s\n\n", "-B es la bandera que permite crear un beamer con la información del preproceso y parsing");
            printf("\t%s\n", "Ejemplo de ejecución:");
            printf("\t\t%s\n\n", "lexscan programa.c");
            printf("\t%s\n", "Ejemplo de ejecución con Beamer:");
            printf("\t\t%s\n", "lexscan programa.c -B");
        }
    }
    else{
        printf("%s\n\n", "**Guía de como usar el programa**");
        printf("\t%s\n\n", "Para correr el programa se utiliza el comando: lexscan");
        printf("\t%s\n", "El programa recibe un parámetro obligatorio:");
        printf("\t\t%s\n\n", "Archivo de texto que contiene código a parsear");
        printf("\t%s\n", "El programa recibe una bandera opcional:");
        printf("\t\t%s\n\n", "-B es la bandera que permite crear un beamer con la información del preproceso y parsing");
        printf("\t%s\n", "Ejemplo de ejecución:");
        printf("\t\t%s\n\n", "lexscan programa.c");
        printf("\t%s\n", "Ejemplo de ejecución con Beamer:");
        printf("\t\t%s\n", "lexscan programa.c -B");
    }
    return 1;
}


void ejecutarFile(){
  int flag=0;
    printf("Procesando...\n");
    printf("The program result is: \n");
/* COMPILAR PARA 32
nasm -f elf32 myprog.asm
ld -melf_i386 -o myprog myprog.o

COMPILAR PARA 64 EN RUNNER DE NASM
*/
   char FILENAME[] = "file"; //-->PONER NOMBRE DEL ARCHIVO ACÁ
   char str[350];
   strcpy(str, "nasm -f elf32 ");
   strcat(str, FILENAME);
   strcat(str, ".asm");
   strcat(str, " && ld -melf_i386 -o ");
   strcat(str, FILENAME);
   strcat(str, " ");
   strcat(str, FILENAME);
   strcat(str, ".o");
   strcat(str, " && ./");
   strcat(str, FILENAME);

   flag = system(str);
   printf("\n");
   if (!flag){
     printf("Proceso terminado exitosamente\n");
   }
   else {printf("Erro en ejecucion de archivo\n");}

}
