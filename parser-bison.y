%{
# include <stdio.h>
# include <stdlib.h>
#include "stackC.h"
#include "symbolTable.h"
#include "symbolStack.h"
int errores = 0;
extern int yylineno;
extern FILE *fileOut;
extern FILE * declares;
extern FILE * finalEnsambler;
extern int beamer;
extern char linea[700];
extern int conteo;
extern char *yytext;
extern char idActual[200];

FILE * fileTemp1;
FILE * fileTemp2;

int as = 0;

int inFor = 0;

char temporal[200];
int tempAct = 0;

int lblIf = 1;
int lblWhile = 1;
int lblDoWhile = 1;
int lblFor = 1;
int lblSwitch = 1;
int cntSw = 0;

char labelswitch[20][200] = {"lblCase1","lblCase2","lblCase3","lblCase4","lblCase5"
							,"lblCase6","lblCase7","lblCase8","lblCase9","lblCase10"};


int numContxt = 1;
char sw[200];
enum tok{ID, TIPO, ERROR, DATAO, TOKEN, RES};
struct semantic_record* pila = NULL;
struct semantic_record* pila2 = NULL;

struct symbolT* symbolTable = NULL;

struct tableRegister* symbolStck = NULL;
%}

%define parse.lac full
%define parse.error verbose

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%
primary_expression
	: IDENTIFIER {process_id();}
	| CONSTANT {process_literal();}
	| STRING_LITERAL
	| '(' expression rparen
	| error
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' rparen
	| postfix_expression '(' argument_expression_list rparen
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP {process_op();eval_unary();}
	| postfix_expression DEC_OP {process_op();eval_unary();}
	| '(' type_name rparen '{' initializer_list '}'
	| '(' type_name rparen '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP {process_op();} unary_expression {eval_unary();}
	| DEC_OP {process_op();} unary_expression {eval_unary();}
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name rparen
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	| error
	;

cast_expression
	: unary_expression
	| '(' type_name rparen cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*'{process_op();}  cast_expression {eval_binary();}
	| multiplicative_expression '/' {process_op();} cast_expression {eval_binary();}
	| multiplicative_expression '%'{process_op();}  cast_expression {eval_binary();}
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+'{process_op();} multiplicative_expression {eval_binary();}
	| additive_expression '-' {process_op();} multiplicative_expression {eval_binary();}
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression {eval_if();} '?' expression {endIFdec();}':' {process_else();}conditional_expression{eval_else();} {printf("if ternario\n");}
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression {fin_assign();}
	;

assignment_operator
	: '=' {push(&pila, TOKEN, "=", NULL);}
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	| error
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';' {
		if(as == 0){fin_decl();}
		else{fin_declas();}
			}//Aqui se hace el int n; y int n = 5;
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	| function_specifier
	| function_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator {printf("\n");}
	| declarator '=' {as = 1; push(&pila, TOKEN, "=", NULL);} initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	| error
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT {guardar_tipo();}
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	| error
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	| error
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| error
	;

function_specifier
	: INLINE
	//| error
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;


direct_declarator
	: IDENTIFIER {guardar_id();}
	| '(' declarator rparen
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list ']'
	| direct_declarator '[' assignment_expression ']'
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_declarator '[' type_qualifier_list '*' ']'
	| direct_declarator '[' '*' ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list rparen
	| direct_declarator '(' identifier_list rparen
	| direct_declarator '(' rparen
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator rparen
	| '[' ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '[' '*' ']'
	| direct_abstract_declarator '[' '*' ']'
	| '(' rparen
	| '(' parameter_type_list rparen
	| direct_abstract_declarator '(' rparen
	| direct_abstract_declarator '(' parameter_type_list rparen
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	| initializer_list ',' designation initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE {process_case(cntSw);}constant_expression {genCmpSwitch(cntSw);} ':' statement
	| DEFAULT {process_default();}':' statement {endCase();}
	;

compound_statement
	: '{'{open_scope();pila = clearStack(pila);}'}'{close_scope();}
	| '{' {open_scope();pila = clearStack(pila);} block_item_list '}' {close_scope();} //Aqui se hacen los { } de una funcion
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';' {if(inFor == 0){pila = clearStack(pila);}}
	;

selection_statement
	: IF { process_if(); } '(' expression rparen { eval_if();} optionsIF
	//IF '(' expression rparen statement { printf("\n \t IF \n "); } ELSE { printf("\n \t ELSE \n "); }
	| SWITCH '(' expression {fileTemp1 = fopen("tempSwitch1.txt","w");process_switch();strcpy(sw, top(pila)->name);}rparen statement {endSwitch();}
	;

optionsIF
: statement {endIFdec();}ELSE { process_else(); } statement { eval_else(); }
| statement {endIFdec(); process_else(); eval_else();  }
;

rparen
	: ')'
	| error
	;

iteration_statement
	: WHILE {process_while();}'(' expression rparen {eval_while();} statement {end_while();}
	| DO {process_dowhile();}statement WHILE '(' expression rparen {eval_Dowhile();}';' {end_Dowhile();}
	| FOR {process_for();} optionsfor;

optionsfor
	: '(' expression_statement {genIn2();} optionsforIni
	| '(' declaration {genIn2();} optionsforIni;

optionsforIni
	: expression_statement {genIn3();genIn4();} rparen statement {end_for();}
	| expression_statement {genIn3();} expression {genIn4();} rparen statement {end_for();}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	| error
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

%%


void endSwitch(){
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, "Exit_Switch");
	strcat(buffer, buffer1);
	printf("JMP %s \n", buffer);

    // ensamblador
	fputs("\tjmp ", finalEnsambler);
	fputs(buffer, finalEnsambler);
	fputs("\n", finalEnsambler);

	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, "Exit_Switch");
	strcat(buffer, buffer1);
	fputs(buffer, fileTemp1);
	fputs(":\n", fileTemp1);
	fclose(fileTemp1);
	fileTemp1 = fopen("tempSwitch1.txt", "r");
	lblSwitch++;
	char ch;
	char restoPrgrama [5000];
	strcpy(restoPrgrama, "");
	while((ch = fgetc(fileTemp1)) != EOF){
      printf("%c", ch);
      putc(ch,finalEnsambler);
    }

}

void process_default(){
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, "Default");
	strcat(buffer, buffer1);
	printf("%s:\n", buffer);

    fputs(buffer, finalEnsambler);
	fputs(": \n", finalEnsambler);


	fputs("jmp ", fileTemp1);
	fputs(buffer, fileTemp1);
	fputs("\n", fileTemp1);

}

void endCase(){
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, "Exit_Switch");
	strcat(buffer, buffer1);
	printf("JMP %s \n", buffer);
	// ensamblador
	fputs("\tjmp ", finalEnsambler);
	fputs(buffer, finalEnsambler);
	fputs("\n", finalEnsambler);
}

void process_case(int i){
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, labelswitch[i]);
	strcat(buffer, buffer1);
	printf("%s:\n", buffer);

	fputs(buffer, finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void process_switch(){
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, "L_CMPSW");
	strcat(buffer, buffer1);
	printf("JMP %s\n", buffer);

	//ensamblador

	fputs("jmp ", finalEnsambler);
	fputs(buffer, finalEnsambler);
	fputs("\n", finalEnsambler);

	fputs(buffer, fileTemp1);
	fputs(":\n", fileTemp1);
}

void genCmpSwitch(int i){
	//printStack(pila);
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, labelswitch[i]);
	strcat(buffer, buffer1);
	cntSw++;
	//ensamblador

	fputs("\tmov eax, [", fileTemp1);
	fputs(sw, fileTemp1);
	fputs("]\n\tcmp eax, ", fileTemp1);
	fputs(top(pila)->name, fileTemp1);
	fputs("\n\tjz  ", fileTemp1);
	fputs(buffer, fileTemp1);
	fputs("\n", fileTemp1);

	/* strcpy(a[0], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblSwitch);
	strcat(buffer, "Exit_Dowhile");
	strcat(buffer, buffer1);
	strcpy(a[1], buffer);
	strcpy(a[2], "");
	strcpy(a[3], "");
	lblSwitch++;
	push(&pila, RES, yytext, a);
	printf("%s\n",a[0]); */
	//crear etiqueta ensamblador
}







/*Todo para abajo esta resuelto*/

void process_for(){
	inFor =1;
	char a[4][200];
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblFor);
	strcat(buffer, "L_inst2");
	strcat(buffer, buffer1);
	strcpy(a[0], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblFor);
	strcat(buffer, "L_inst3");
	strcat(buffer, buffer1);
	strcpy(a[1], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblFor);
	strcat(buffer, "BodyLbl");
	strcat(buffer, buffer1);
	strcpy(a[2], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblFor);
	strcat(buffer, "Exit_for");
	strcat(buffer, buffer1);
	strcpy(a[3], buffer);
	lblFor++;
	push(&pila2, RES, yytext, a);
}


void genIn2(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s\n",a->eti[0]);
	fputs(a->eti[0], finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void genIn3(){
	struct semantic_record* Res = top(pila);
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s","CMP 0 ");
	printf("%s\n",Res->name);
	printf("%s ","JZ");
	printf("%s\n",a->eti[3]);
	printf("%s ","JMP");
	printf("%s\n",a->eti[2]);
	printf("%s\n",a->eti[1]);

	fputs("\tmov eax, [", finalEnsambler);
	fputs(Res->name, finalEnsambler);
	fputs("]\n\tcmp eax, 0 \n", finalEnsambler);
	fputs("\tjz  ", finalEnsambler);
	fputs(a->eti[3] , finalEnsambler);
	fputs("\n", finalEnsambler);
	fputs("\tjmp ", finalEnsambler);
    fputs(a->eti[2], finalEnsambler);
    fputs("\n", finalEnsambler);
    fputs(a->eti[1], finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void genIn4(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s ","JMP");
	printf("%s\n",a->eti[0]);
	printf("%s\n",a->eti[2]);
	//ensamblador
	fputs("\tjmp ", finalEnsambler);
    fputs(a->eti[0], finalEnsambler);
    fputs("\n", finalEnsambler);
    fputs(a->eti[2], finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void end_for(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s ","JMP");
	printf("%s\n",a->eti[1]);
	printf("%s\n",a->eti[3]);
	pila2 = pop(&pila2);

	//ensamblador
	fputs("\tjmp ", finalEnsambler);
    fputs(a->eti[1], finalEnsambler);
    fputs("\n", finalEnsambler);
    fputs(a->eti[3], finalEnsambler);
	fputs(": \n", finalEnsambler);
}


void process_dowhile(){
	char a[4][200];
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblDoWhile);
	strcat(buffer, "Exp_Dowhile");
	strcat(buffer, buffer1);
	strcpy(a[0], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblDoWhile);
	strcat(buffer, "Exit_Dowhile");
	strcat(buffer, buffer1);
	strcpy(a[1], buffer);
	strcpy(a[2], "");
	strcpy(a[3], "");
	lblDoWhile++;
	push(&pila2, RES, yytext, a);
	printf("%s\n",a[0]);
    fputs(a[0], finalEnsambler);
	fputs(": \n", finalEnsambler);

	//crear etiqueta ensamblador
}

void eval_Dowhile(){
	//printStack(pila2);
	struct semantic_record* Res = top(pila);
	struct semantic_record* a = retrieve(pila2,RES);
	pila = pop2(&pila);
	//pila = pop(&pila);
	/* printStack(pila); */
	printf("%s","CMP 0 ");
	printf("%s\n",Res->name);
	printf("%s ","JNZ");
	printf("%s\n",a->eti[0]);

	fputs("\tmov eax, [", finalEnsambler);
	fputs(Res->name, finalEnsambler);
	fputs("]\n\tcmp eax, 0 \n", finalEnsambler);
	fputs("\tjnz  ", finalEnsambler);
	fputs(a->eti[0] , finalEnsambler);
	fputs("\n", finalEnsambler);
	free(Res);
}

void end_Dowhile(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s\n",a->eti[1]);
	pila2 = pop(&pila2);
	fputs(a->eti[1], finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void process_while(){
	char a[4][200];
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblWhile);
	strcat(buffer, "Exp_While");
	strcat(buffer, buffer1);
	strcpy(a[0], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblWhile);
	strcat(buffer, "Exit_while");
	strcat(buffer, buffer1);
	strcpy(a[1], buffer);
	strcpy(a[2], "");
	strcpy(a[3], "");
	/* printf("%s\n",a[0]);
	printf("%s\n",a[1]); */
	lblWhile++;
	push(&pila2, RES, yytext, a);
	printf("%s\n",a[0]);
	//crear etiqueta ensamblador
	fputs(a[0], finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void eval_while(){
	/* printStack(pila); */
	struct semantic_record* Res = top(pila);
	struct semantic_record* a = retrieve(pila2,RES);
	pila = pop2(&pila);
	//pila = pop(&pila);
	/* printStack(pila); */
	printf("%s","CMP 0 ");
	struct semantic_record* n = retrieve(pila,DATAO);
	printf("%s\n",Res->name);
	printf("%s ","JZ");
	printf("%s\n",a->eti[1]);

	//código para if ensamblador
	fputs("\tmov eax, [", finalEnsambler);
	fputs(Res->name, finalEnsambler);
	fputs("]\n\tcmp eax, 0 \n", finalEnsambler);
	fputs("\tjz  ", finalEnsambler);
	fputs(a->eti[1] , finalEnsambler);
	fputs("\n", finalEnsambler);
	free(Res);
}

void end_while(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s ","JMP");
	printf("%s\n",a->eti[0]);
	printf("%s\n",a->eti[1]);
	pila2 = pop(&pila2);
	fputs("\tjmp ", finalEnsambler);
    fputs(a->eti[0], finalEnsambler);
    fputs("\n", finalEnsambler);
    fputs(a->eti[1], finalEnsambler);
	fputs(": \n", finalEnsambler);

}

void process_if(){
	char a[4][200];
	char buffer [200];
	char buffer1 [200];
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblIf);
	strcat(buffer, "L_Else");
	strcat(buffer, buffer1);
	strcpy(a[0], buffer);
	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblIf);
	strcat(buffer, "Exit_if");
	strcat(buffer, buffer1);
	strcpy(a[1], buffer);
	strcpy(a[2], "");
	strcpy(a[3], "");
	/* printf("%s\n",a[0]);
	printf("%s\n",a[1]); */



	memset(buffer, 0, sizeof(buffer));
	snprintf(buffer1, 200, "%d", lblIf);
	strcat(buffer, yytext);
	strcat(buffer, buffer1);

	lblIf++;
	push(&pila2, RES, buffer, a);

	//crear etiquetas ensamblador
}

void eval_if(){
	/* printStack(pila); */
	struct semantic_record* Res = top(pila);
	struct semantic_record* a = retrieve(pila2,RES);
	pila = pop2(&pila);
	//pila = pop(&pila);
	/* printStack(pila); */
	printf("%s","CMP 0 ");
	struct semantic_record* n = retrieve(pila,DATAO);
	printf("%s\n",Res->name);
	printf("%s ","JZ");
	printf("%s\n",a->eti[0]);
//código para if ensamblador
	fputs("\tmov eax, [", finalEnsambler);
	fputs(Res->name, finalEnsambler);
	fputs("]\n\tcmp eax, 0 \n", finalEnsambler);
	fputs("\t jz  ", finalEnsambler);
	fputs(a->eti[0] , finalEnsambler);
	fputs("\n", finalEnsambler);
	free(Res);
}

void process_else(){
	/* printf("%s\n",yytext);
	push(&pila, RES, yytext, NULL); */
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s\n",a->eti[0]);
	//crear etiquetas ensamblador
	fputs(a->eti[0], finalEnsambler);
	fputs(": \n", finalEnsambler);

}

void eval_else(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s\n",a->eti[1]);
	pila2 = pop(&pila2);
	//pila = pop(&pila);
	//etiqueta de salida
	fputs(a->eti[1], finalEnsambler);
	fputs(": \n", finalEnsambler);
}

void endIFdec(){
	struct semantic_record* a = retrieve(pila2,RES);
	printf("%s ","JMP");
	printf("%s\n",a->eti[1]);
    // codigo ensamblador
    fputs("\tjmp ", finalEnsambler);
    fputs(a->eti[1], finalEnsambler);
    fputs("\n", finalEnsambler);
}


void fin_assign(){

	struct semantic_record* assin = retrieve(pila,TOKEN);
	struct semantic_record* val;
	int b = 0;
	if(retrieve(pila,DATAO) != NULL){
		val = retrieve(pila,DATAO);
	}
	else{
		printStack(pila);
		val = top(pila);
		pila = pop2(&pila);
		printStack(pila);
		b = 1;
	}
	while(retrieve(pila, ID) != NULL){
		struct semantic_record* identificador = retrieveDelete(pila,ID);
		struct symbolT* smb = topSymbol(&symbolStck);
		if(!(lookup(smb, identificador->name)) == 1){
			printf("%s","Error semántico, ");
			printf("%s",identificador->name);
			printf("%s\n"," no ha sido declarado antes, este error solo será reportado 1 vez por cada variable");
			insert(&smb, "error",identificador->name);
			symbolStck = popSymbol(&symbolStck);
			pushSymbol(&symbolStck, smb);
		}

		char oper1 [100];
        char oper2 [100];
        strcpy(oper1, identificador->name);


		if (!isdigit(val->name[0]) ){
			  strcpy(oper2, "[");
	          strcat(oper2, val->name);
	          strcat(oper2, "]");
		}
		else {
			strcpy(oper2, val->name);
		}

		// guardamos el valor en el identificador
		storeVal(oper1 , oper2);
		printf("%s ",identificador->name);
		printf("%s ",assin->name);
		printf("%s\n",val->name);
		free(identificador);
	}
	pila = clearStack(pila);
	if(b == 1)free(val);
}


void eval_binary(){
	struct semantic_record* OP1 = top(pila);
	pila = pop2(&pila);
	struct semantic_record* OPERATOR = top(pila);
	pila = pop2(&pila);
	struct semantic_record* OP2 = top(pila);
	pila = pop2(&pila);
	//crear funcion que crea temporales
	createTemp();
	if(OP1->type == ERROR){
		push(&pila,ERROR,temporal,NULL);
		return;
	}
	else if(OP2->type == ERROR){
		push(&pila,ERROR,temporal,NULL);
		return;
	}
	else{
		push(&pila,DATAO,temporal,NULL);
	}
	if(!strcmp(OPERATOR->name,"-")||!strcmp(OPERATOR->name,"/")){
		struct semantic_record* temp = OP1;
		OP1 = OP2;
		OP2 = temp;
	}
	//insertar el temp;
    writeTempEnsambler();
	//generar codigo ensamblador para OP1 OPERATOR OUTPUT2 = TEMP1
	//Manejo de varaibles para ensamblador
    char oper1 [100];
    char oper2 [100];
    if(!isdigit(OP1->name[0]) ) {
          strcpy(oper1, "[");
          strcat(oper1, OP1->name);
          strcat(oper1, "]");
	}
	else{
		strcpy(oper1, OP1->name);
	}

	if (!isdigit(OP2->name[0]) ){
		  strcpy(oper2, "[");
          strcat(oper2, OP2->name);
          strcat(oper2, "]");

	}
	else {
		strcpy(oper2, OP2->name);
	}

	switch (OPERATOR->name[0]){
		case '+':
			suma(oper1, oper2);

		break;
		case '-':
			resta(oper1, oper2);
		break;
		case '*':
			multiplicacion(oper1, oper2);

		break;
		case '/':
			division(oper1, oper2);
		break;
	}
	printf("%s = ",temporal);
	printf("%s ",OP1->name);
	printf("%s ",OPERATOR->name);
	printf("%s\n",OP2->name);
	free(OP1);
	free(OPERATOR);
	free(OP2);
}

void clear_temp(){//borra el contenido de token_buffer y lo resetea a un string vacio
    memset(temporal, 0, sizeof(temporal));
}

void createTemp(){
	clear_temp();
	char buffer [200];
	snprintf(buffer, 200, "%d", ++tempAct);
	strcat(temporal, "Temp");
	strcat(temporal, buffer);
}

void eval_unary(){
	struct semantic_record* OP1 = top(pila);
	pila = pop2(&pila);
	struct semantic_record* OPERATOR = top(pila);
	pila = pop2(&pila);

	//crear funcion que crea temporales
	//createTemp();
	if(OP1->type == ERROR){
		push(&pila,ERROR,temporal, NULL);
		return;
	}

	if(OP1->type == TOKEN){
		//generar codigo ensamblador para a++
		// el OPERATOR contiene el id
		// el OP1 contiene el ++
		if (!strcmp(OP1->name ,"++")){
			sumaUno(OPERATOR->name);
		}else{
			restaUno(OPERATOR->name);
		}
		push(&pila,DATAO,OPERATOR->name, NULL);
		printf("%s = ",OPERATOR->name);
		printf("%s ",OPERATOR->name);
		printf("%s\n",OP1->name);
	}
	else{
		//generar codigo ensamblador para ++a
		// el OPERATOR contiene el ++
		// el OP1 contiene el id
        if (!strcmp(OPERATOR->name ,"++")){
        	sumaUno(OP1->name);
		}else{
			restaUno(OP1->name);
		}
		push(&pila,DATAO,OP1->name, NULL);
		printf("%s = ",OP1->name);
		printf("%s ",OPERATOR->name);
		printf("%s\n",OP1->name);
	}
	free(OP1);
	free(OPERATOR);
}


void process_literal(){
	push(&pila, DATAO, yytext, NULL);
}

void process_op(){
	push(&pila, TOKEN, yytext, NULL);
}

void process_id(){
	struct tableRegister* smb = symbolStck;
	//DECISION isnertar variable que no ha sido declarada a la tabla de simbolos
	//y dejar que si se usa de nuevo se pueda usar?
	//o agregarle una AND al if y que pregunte si el tipo de la variable es != de error
	int ban = 0;
	while(smb->next != NULL){
		if(!(lookup(smb->symbolT, idActual) != 1)){
			push(&pila, ID, idActual, NULL);
			ban = 1;
			break;
		}
		smb = smb->next;
	}
	if(ban == 0){
		push(&pila, ERROR, idActual, NULL);
		struct semantic_record* identificador = top(pila);
		printf("%s","Error semántico, ");
		printf("%s",identificador->name);
		printf("%s"," no ha sido declarado antes, este error solo será reportado 1 vez por cada variable. ");
		printf("En la línea: %d\n\n", yylineno);
		insert(&smb, "error",identificador->name);
		symbolStck = popSymbol(&symbolStck);
		pushSymbol(&symbolStck, smb);
	}
}

void guardar_id(){
	push(&pila, ID, yytext, NULL);
}

void guardar_tipo(){
	push(&pila, TIPO, yytext, NULL);
}

void fin_decl(){
	struct semantic_record* tipo = retrieve(pila,TIPO);
	while(top(pila)->type==ID){
		struct semantic_record* identificador = retrieve(pila,ID);  // es este
		struct symbolT* smb = topSymbol(&symbolStck);
		if(lookup(smb, identificador->name) == 1){
			printf("Error semántico, %s ya ha sido declarado antes. ", identificador->name);
			printf("En la línea: %d\n\n", yylineno);
			exit(1);
		}
		// inserto el delcare de la variable  le asigno identificador
		writeValEnsambler(identificador->name);
		insert(&smb, tipo->name,identificador->name);
		symbolStck = popSymbol(&symbolStck);
		pushSymbol(&symbolStck, smb);
		pila = pop(&pila);
	}
	pila = pop(&pila);
	pila = clearStack(pila);
}


void fin_declas(){
	struct semantic_record* tipo = retrieve(pila,TIPO);
	struct semantic_record* assin = retrieve(pila,TOKEN);
	struct semantic_record* val = retrieve(pila,DATAO);  // le asigno este val
	while(retrieve(pila, ID) != NULL){
		struct semantic_record* identificador = retrieveDelete(pila,ID);  //  este es el identificador
		struct symbolT* smb = topSymbol(&symbolStck);
		if(lookup(smb, identificador->name) == 1){
			printf("Error semántico, %s ya ha sido declarado antes. ", identificador->name);
			printf("En la línea: %d\n\n", yylineno);
			exit(1);
		}
		/// insert crear un declare del identificador  asignar el valor que esta en val
		writeValEnsambler(identificador);
		char oper1 [100];
        char oper2 [100];
        strcpy(oper1, identificador->name);


		if (!isdigit(val->name[0]) ){
			  strcpy(oper2, "[");
	          strcat(oper2, val->name);
	          strcat(oper2, "]");
		}
		else {
			strcpy(oper2, val->name);
		}

		// guardamos el valor en el identificador
		storeVal(oper1 , oper2);

		insert(&smb, tipo->name,identificador->name);
		symbolStck = popSymbol(&symbolStck);
		pushSymbol(&symbolStck, smb);
		printf("%s ",identificador->name);
		printf("%s ",assin->name);
		printf("%s\n",val->name);
		free(identificador);
	}
	as = 0;
	pila = clearStack(pila);
}

void open_scope(){
	struct symbolT* newSymbolTable = NULL;
	pushSymbol(&symbolStck, newSymbolTable);
}

void close_scope(){
	symbolStck = popSymbol(&symbolStck);
}

extern char *yytext;

extern int column;

void yyerror(char *s){
	fflush(stdout);
	if(beamer == 1){
		fprintf(fileOut, "\\\\\\setstcolor{er}\\sethlcolor{er}\\Oricolor\\hl{Syntax Error, in line:");
		fprintf(fileOut, "%d",yylineno);
		fprintf(fileOut, "}\\\\");
	}
	printf("%s",linea);
	printf("\n%*s\n%*s ", column, "^", column, s);
	if(conteo == 1){
		printf("in line: %d\n\n", yylineno);
	}
	else{
		printf("%s", "\n\n");
	}
	errores++;
}





/*
 Funciones de ensamblador
*/

void writeValEnsambler(char* val){
		fputs(val , declares);
		fputs("  resb 2048 \n", declares);
}


void writeTempEnsambler(){
		fputs(temporal, declares);
		fputs("  resb 2048 \n", declares);
}

void storeVal(char* OP1 ,  char* OP2){
	fputs("\tmov eax, ", finalEnsambler);
	fputs(OP2 , finalEnsambler);
	fputs("\n\tmov [", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("] , eax \n ", finalEnsambler);
}

void suma (char* OP1 ,  char* OP2){
	fputs("\tmov eax, ", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("\n\tmov ebx, ", finalEnsambler);
	fputs(OP2, finalEnsambler);
	fputs("\n\tadd eax, ebx\n ", finalEnsambler);
	fputs("\tmov [", finalEnsambler);
	fputs(temporal, finalEnsambler);
    fputs("] ,eax \n", finalEnsambler);
}



void resta (char* OP1 ,  char* OP2){
	fputs("\tmov eax, ", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("\n\tmov ebx, ", finalEnsambler);
	fputs(OP2, finalEnsambler);
	fputs("\n\tsub eax, ebx\n ", finalEnsambler);
	fputs("\tmov [", finalEnsambler);
	fputs(temporal, finalEnsambler);
    fputs("] ,eax \n", finalEnsambler);
}


void multiplicacion(char* OP1 ,  char* OP2){
	fputs("\tmov eax, ", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("\n\tmov ebx, ", finalEnsambler);
	fputs(OP2, finalEnsambler);
	fputs("\n\tmul ebx\n ", finalEnsambler);
	fputs("\tmov [", finalEnsambler);
	fputs(temporal, finalEnsambler);
    fputs("] ,eax \n", finalEnsambler);
}

void division(char* OP1 ,  char* OP2){
	fputs("\tmov eax, ", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("\n\tmov ebx, ", finalEnsambler);
	fputs(OP2, finalEnsambler);
	fputs("\n\tdiv ebx\n ", finalEnsambler);
	fputs("\tmov [", finalEnsambler);
	fputs(temporal, finalEnsambler);
    fputs("] ,eax \n", finalEnsambler);
}



void sumaUno (char * OP1){
	fputs("\tmov eax, [", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("] \n\tmov ebx, ", finalEnsambler);
	fputs("1", finalEnsambler);
	fputs("\n\tadd eax, ebx\n ", finalEnsambler);
	fputs("\tmov [", finalEnsambler);
	fputs(OP1, finalEnsambler);
    fputs("] ,eax \n", finalEnsambler);
}



void restaUno(char * OP1){
	fputs("\tmov eax, [", finalEnsambler);
	fputs(OP1, finalEnsambler);
	fputs("] \n\tmov ebx, ", finalEnsambler);
	fputs("1", finalEnsambler);
	fputs("\n\tsub eax, ebx\n ", finalEnsambler);
	fputs("\tmov [", finalEnsambler);
	fputs(OP1, finalEnsambler);
    fputs("] ,eax \n", finalEnsambler);
}
