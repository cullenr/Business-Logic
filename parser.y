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
		std::printf("NO! yoo Error'd wiv a : %s\n", s);
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

	NDouble *		number;
	NIdentifier *	identifier;
	NStatement *	statement;
	NExpression *	exp;
}

/* Terminal Tokens */
%token <string> IDENTIFIER DOUBLE NEWLINE 
%token <token> VARIBLE_DECLARATION ADD

/* Non - Terminal Types */
%type <exp> exp primary_expression
%type <statement> statement 

/* 	
	Precedence is defined by the order in which these declarations are made, 
	the associativity is govoured by the %left or %right 
*/
%nonassoc '='
%left '-' '+'
%left '*' '/'
%left NEG     /* negation--unary minus */
%right '^'    /* exponentiation */


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
	| primary_expression ADD exp					{ $$ = new NBinaryOperation(*$1, '+', *$3); }
	;
%%