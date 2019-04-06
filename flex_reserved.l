%{
int key = 0;
int op = 0;
int sp = 0;
int id = 0;
int cst = 0;
int str = 0;
FILE *fileOut;
char direccion[100];
%}

%%
"auto" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"break" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"case" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"char" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"const" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"continues" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"default" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"do" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"int" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"long" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"register" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"return" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"short" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"signed" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"sizeof" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"static" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"struct" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"switch" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"typedef" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"union" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"unsigned" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"void" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"volatile" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"while" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"double" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"else" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"enum" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"extern" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"float" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"for" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"goto" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"if" { key++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
"(" { sp++; fprintf(fileOut, "\\sethlcolor{yellow}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
")" { sp++; fprintf(fileOut, "\\sethlcolor{yellow}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"{" { sp++; fprintf(fileOut, "\\sethlcolor{yellow}\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"}" { sp++; fprintf(fileOut, "\\sethlcolor{yellow}\\hl{\\"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"=" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"+" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"-" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"*" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"/" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"%" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"<" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
">" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"&&" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"||" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"?" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
":" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"&" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"|" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"^" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"~" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"<<" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
">>" { op++; fprintf(fileOut, "\\sethlcolor{red}\\hl{"); fprintf(fileOut, yytext); fprintf(fileOut, "}");}
"\n" {fprintf(fileOut, "\n");fprintf(fileOut, "\\\\");fprintf(fileOut, "\n");}
"\t" {fprintf(fileOut, "\n");fprintf(fileOut, "\\tab\\quad");fprintf(fileOut, "\n");}
[\"][ \t]*[a-zA-Z0-9 ]*[ \t]*[\"]  {str++; fprintf(fileOut, "\\sethlcolor{azure}\\hl{\\textbf{\\"); yytext[strlen(yytext)-1] = '\\'; strcat(yytext,"\""); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
[a-zA-Z_][a-zA-Z0-9_]* {id++;fprintf(fileOut, "\\sethlcolor{green}\\hl{\\textit{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
[0-9]+ { cst++;fprintf(fileOut, "\\sethlcolor{amethyst}\\hl{\\textbf{"); fprintf(fileOut, yytext); fprintf(fileOut, "}}");}
. { }
%%

void flexPrueba(){
    yylex();
}

int main(int argc, char **argv){
    if(argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        return (1);
        }
    }
    fileOut = fopen("FINAL.txt","w");
    flexPrueba();
    /* printf("%d\n", key);
    printf("%d\n", op);
    printf("%d\n", sp);
    printf("%d\n", id);
    printf("%d\n", cst);
    printf("%d\n", str); */
    return 1;
}
