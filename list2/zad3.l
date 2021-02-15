%{
#include <stdbool.h>
#include <string>

bool print_doc = false;
%}

%s STRING
%s COMMENT_ONE_LINE
%s COMMENT_MULTI_LINES
%s DOCS_ONE_LINE
%s DOCS_MULTI_LINES 
%%

<INITIAL>{
\"				{ ECHO; BEGIN(STRING); }
\/\/			BEGIN(COMMENT_ONE_LINE);
\/\*			BEGIN(COMMENT_MULTI_LINES);
\/\/\/|\/\/!	{ if(print_doc) ECHO; BEGIN(DOCS_ONE_LINE); }
\/\*\*|\/\*!	{ if(print_doc) ECHO; BEGIN(DOCS_MULTI_LINES); }
}

<STRING>{
\\\"			ECHO;
\\\\			ECHO;
\"				{ ECHO; BEGIN(INITIAL); }
}

<COMMENT_ONE_LINE>{
.				;
\\\n			;
\n				{ ECHO; BEGIN(INITIAL); }
}

<COMMENT_MULTI_LINES>{
.				;
\n				;
\*\/			BEGIN(INITIAL);
}

<DOCS_ONE_LINE>{
.				if(print_doc) ECHO;
\\\n			if(print_doc) ECHO;
\n				{ ECHO; BEGIN(INITIAL); }
}

<DOCS_MULTI_LINES>{
.				if(print_doc) ECHO;
\n				if(print_doc) ECHO;
\*\/			{ if(print_doc) ECHO; BEGIN(INITIAL); }
}

%%

int yywrap() {}

int main(int argc, char** argv) {
	if (argc > 1 && std::string(argv[1]) == "docs")
		print_doc = true;
	yylex();
}
