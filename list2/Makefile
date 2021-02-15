main: zad1 zad2 zad3 zad4 clean

zad1: zad1.c
	gcc lex.yy.c -o zad1 -lfl

zad1.c: zad1.l
	flex zad1.l

zad2: zad2.c
	gcc lex.yy.c -o zad2 -lfl

zad2.c: zad2.l
	flex zad2.l

zad3: zad3.c
	g++ lex.yy.c -o zad3 -lfl

zad3.c: zad3.l
	flex zad3.l

zad4: zad4.c
	g++ lex.yy.c -o zad4 -lfl

zad4.c: zad4.l
	flex zad4.l

clean:
	rm -f *.c
