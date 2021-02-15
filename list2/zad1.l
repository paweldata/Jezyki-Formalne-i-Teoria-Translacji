%{
int lines = 0;
int words = 0;
%}

%s CONTENTLINE
%%

<INITIAL>{
\n				;
[\t ]			;
[^\n\t ]		{ ECHO; BEGIN(CONTENTLINE); }
}

<CONTENTLINE>{
[\t ]+			printf(" ");
\\\n			;
[^\n\t ]+		{ ECHO; words++; }
\n				{ ECHO; lines++; BEGIN(INITIAL); }
}

%%

int main() {
	yylex();
	printf("\nLines : %d\n", lines);
	printf("Words : %d\n", words);
}
