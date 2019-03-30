%%
"#include" { printf("include\n"); }
"auto" { printf("auto"); }
"break" { printf("break"); }
"case" { printf("case"); }
"char" { printf("char"); }
"const" { printf("const"); }
"continues" { printf("continues"); }
"default" { printf("default"); }
"do" { printf("do"); }
"int" { printf("int"); }
"long" { printf("long"); }
"register" { printf("register"); }
"return" { printf("return"); }
"short" { printf("short"); }
"signed" { printf("signed"); }
"sizeof" { printf("sizeof"); }
"static" { printf("static"); }
"struct" { printf("struct"); }
"switch" { printf("switch"); }
"typedef" { printf("typedef"); }
"union" { printf("union"); }
"unsigned" { printf("unsigned"); }
"void" { printf("void"); }
"volatile" { printf("volatile"); }
"while" { printf("while"); }
"double" { printf("double"); }
"else" { printf("else"); }
"enum" { printf("enum"); }
"extern" { printf("extern"); }
"float" { printf("float"); }
"for" { printf("for"); }
"goto" { printf("goto"); }
"if" { printf("if"); }
"//" { printf("comentario"); }
"/*" { printf("comentario inicio"); }
"*/" { printf("comentario inicio"); }
"=" { printf("EQUAL\n"); }
"+" { printf("PLUS\n"); }
"-" { printf("MINUS\n"); }
"*" { printf("TIMES\n"); }
"/" { printf("DIVIDE\n"); }
"|" { printf("ABS\n"); }
\n { printf("NEWLINE\n"); }
[ \t] { }
[a-z A-Z]+ {printf("variable\n");}
[a-z A-Z][a-z A-Z 0-9]+ {printf("variable\n");}
[0-9][a-z A-Z 0-9]+ {printf("variable no valida\n");}
[0-9]+ { printf("NUMBER %s\n", yytext); }
. { printf("Mystery character %s\n", yytext); }
%%

void flexPrueba(){
    yylex();
}

int main(int argc, char **argv){
    flexPrueba();
    return 1;
}
