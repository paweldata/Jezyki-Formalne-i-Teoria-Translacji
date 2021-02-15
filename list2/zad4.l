%{
#include <iostream>
#include <cmath>
#include <stack>

bool isError = false;

std::stack<int> stack;

struct Values {
	int first;
	int second;
};

bool isStackBigEnough() { return stack.size() >= 2; }

bool isOperationValid(){
	if (isError)
		return false;

	if (!isStackBigEnough()) {
		printf("Too few arguments\n");
		isError = true;
		return false;
	}

	return true;
}

Values getValues() {
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	return Values{.first = a, .second = b};
}

void push(int n) { stack.push(n); }

void add() {
	if (isOperationValid()) {
		Values values = getValues();
		stack.push(values.first + values.second);
	}
}

void sub() {
	if (isOperationValid()) {
		Values values = getValues();
		stack.push(values.second - values.first);
	}
}

void multiply() {
	if (isOperationValid()) {
		Values values = getValues();
		stack.push(values.first * values.second);
	}
}

void divide() {
	if (isOperationValid()) {
		Values values = getValues();
		
		if (values.first == 0) {
			printf("Division by zero\n");
			isError = true;
		}
		
		stack.push(values.second / values.first);
	}
}

void power() {
	if (isOperationValid()) {
		Values values = getValues();
		stack.push(std::pow(values.second, values.first));
	}
}

void modulo() {
	if (isOperationValid()) {
		Values values = getValues();
		
		if (values.first == 0) {
			printf("Modulo by zero\n");
			isError = true;
		}
		
		stack.push(values.second % values.first);
	}
}

void handleNewLine() {
	if (isError) {
		isError = false;
	} else if (stack.size() > 1) {
		printf("Too few operators\n");
	} else {
		printf("= %d\n", stack.top());
		stack.pop();
	}
	
	stack = std::stack<int>();
}

void handleWrongChar(char* c) {
	printf("Wrong char : '%c'\n", *c);
	isError = true;
}

%}

%s ERROR MULTI_LINE_COMMENT
%%

-?[0-9]+		push(std::stoi(yytext));

\+				add();
\-				sub();
\*				multiply();
\/				divide();
\^				power();
\%				modulo();

[[:blank:]]		;
\n				handleNewLine();
.				handleWrongChar(yytext);

%%

int yywrap() {}

int main() {
	yylex();
}
