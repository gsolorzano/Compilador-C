process:
	bison -d parser-bison.y -Wnone
	flex flex_reserved.l
	gcc -w lex.yy.c parser-bison.tab.c BeamerProgram.c reader.c def.c -o lexscan -lfl
	sudo cp lexscan /usr/bin/
