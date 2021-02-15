all: parser lexer
	g++ -o calculator calculator.tab.c lex.yy.c -lfl

lexer:
	flex calculator.l

parser:
	bison -d calculator.y

clean:
	rm -f calculator.tab.* lex.*