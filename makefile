process:
	flex flex_reserved.l
	gcc -w lex.yy.c BeamerProgram.c reader.c def.c -o lexscan -lfl
