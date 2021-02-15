%s SHORT1 SHORT2 LONG1 LONG2 COMMENT
%%

<INITIAL>{
#				BEGIN(COMMENT);
\'				{ ECHO; BEGIN(SHORT1); }
\"				{ ECHO; BEGIN(SHORT2); }
\'\'\'			{ ECHO; BEGIN(LONG1); }
\"\"\"			{ ECHO; BEGIN(LONG2); }
}

<COMMENT>{
.				;
\n				{ ECHO; BEGIN(INITIAL); }
}

<SHORT1,SHORT2,LONG1,LONG2>{
\\\'			ECHO;
\\\"			ECHO;
\\\\			ECHO;
}	

<SHORT1>\'		{ ECHO; BEGIN(INITIAL); }
<SHORT2>\"		{ ECHO; BEGIN(INITIAL); }
<LONG1>\'\'\'	{ ECHO; BEGIN(INITIAL); }
<LONG2>\"\"\"	{ ECHO; BEGIN(INITIAL); }		

%%

int main() {
	yylex();
}
