process:
	bison -d parser-bison.y -Wnone
	flex flex_reserved.l
	gcc stackC.h
	gcc -w symbolTable.c lex.yy.c parser-bison.tab.c BeamerProgram.c reader.c def.c -o lexscan -lfl
