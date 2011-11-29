%{
    #include <cstdio>
	#include <iostream>
    #include <cstdlib>
	#include <string>
	#include "node.h"
	
	extern int yylex();
	extern int yyparse();
	
	void yyerror(const char *s) 
	{ 
		std::printf("\033[0;31mSHIT!\033[0m : %s\n", s);
		std::exit(1);
	}
	
	int yywrap()
	{
		return 1;
	} 

	main()
	{
		yyparse();
	}
%}

%union 
{
	std::string *	string;
	int 			token;
	char 			op;
	
	NDouble *		number;
	NIdentifier *	identifier;
	NStatement *	statement;
	NExpression *	exp;
}

/* Terminal Tokens */
%token <string> IDENTIFIER DOUBLE NEWLINE 
%token <token> VARIBLE_DECLARATION

/* Non - Terminal Types */
%type <exp> exp primary_expression
%type <statement> statement
%type <op> op '+' '-' '*' '/'

/* 	
	Precedence is defined by the order in which these declarations are made, 
	the associativity is determined by the %left or %right
	
	consider		1 - 1 - 1
	%left 			(1 - 1) -1
	%right			1 - (1 - 1)
*/
%right '='
%left '-' '+'
%left '*' '/'

%%
program
	: program statement
	|
	;
	
statement
	: exp											{ $$ = new NExpressionStatement( *$1 );}
	| VARIBLE_DECLARATION IDENTIFIER '=' exp		{ $$ = new NExpressionVariableDeclaration(*$2, *$4); }
	;                                 

primary_expression
	: DOUBLE										{ std::cout << "OOOH" << std::endl; $$ = new NDouble(atof($1->c_str())); delete $1; }
	| IDENTIFIER									{ std::cout << "AAAH" << std::endl; $$ = new NIdentifier(*$1); delete $1;}
	;
                                 
exp	
	: primary_expression							{ $$ = $1; }
	| IDENTIFIER '=' exp							{ $$ = new NAssignment(*$<identifier>1, *$3); }//TODO : DO I NEED STILL TO TREAT ASSIGNMENT DIFFERENTLY TO OTHER OPERATORS?
	| primary_expression op exp						{ $$ = new NBinaryOperation(*$1, $2, *$3); }
	;
	
op
	: '+'											{ $$ = $1 }
	| '-'											{ $$ = $1 }
	| '*'											{ $$ = $1 }
	| '/'											{ $$ = $1 }
	;
%%