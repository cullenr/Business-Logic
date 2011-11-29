%{
    #include <cstdio>
	#include <iostream>
    #include <cstdlib>
	#include <math.h>
	#include "node.h"
	
	extern int yylex();
	extern int yyparse();
	
	void yyerror(const char *s) 
	{ 
		std::printf("Error: %s\n", s);
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
%token <string> IDENTIFIER DOUBLE NEWLINE VARIBLE_DECLARATION

/* Non - Terminal Types */
%type <exp> exp
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
program:
	program statement
	|
	;
	
statement:
	exp												{ $$ = new NExpressionStatement( *$1 ); std::cout << "Creating Identifier: " << std::endl;}
	| VARIBLE_DECLARATION IDENTIFIER '=' exp		{ $$ = new NExpressionVariableDeclaration(*$2, *$4); }
	;                                 
                                      
exp:                                  
	DOUBLE											{ $$ = new NDouble(atof($1->c_str())); delete $1; }
	| IDENTIFIER '=' exp							{ $$ = new NAssignment(*$<identifier>1, *$3); }//TODO : DO I NEED STILL TO TREAT ASSIGNMENT DIFFERENTLY TO OTHER OPERATORS?
	| IDENTIFIER operator IDENTIFIER				{ $$ = new NBinaryOperation(*$1, *$2, *$3,); }
	| IDENTIFIER									{ $$ = new NIdentifier(*$1); delete $1; }
	;
	
operator:
	'+'												{$$ = $1}
	'-'												{$$ = $1}
	'/'												{$$ = $1}
	'*'												{$$ = $1}
%%