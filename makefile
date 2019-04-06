process:
	flex flex_reserved.l
	gcc -w lex.yy.c -o prueba -lfl
