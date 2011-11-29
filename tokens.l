%{
#include <iostream>
#include <string>
#include "node.h"
#include "parser.hpp"

extern "C" int yywrap() { }

%}

int checkKeyword(string identifier);

%%

[ \t]+               	{ 	
							std::cout << "WHITE_SPACE" << std::endl;
						}
[0-9]+(\.[0-9]*)?       {	
							yylval.string = new std::string(yytext, yyleng); 
							std::cout << "NUMBAR " << *yylval.string << std::endl; 
							
							
							return DOUBLE; 
						}
\n						{	
							std::cout << "NEWLINE " << std::endl; }
[a-zA-Z_][a-zA-Z0-9_]*  {	
							int id;
							std::string* value = new std::string(yytext, yyleng);
							
							if(value->compare("var") == 0)
							{
								id = VARIBLE_DECLARATION;								
								std::cout << "VARIABLE_KEYWORD " << std::endl;	
							}
							else
							{	
								id = IDENTIFIER;
								yylval.string = value;
								std::cout << "IDNETIFIER " << *yylval.string << std::endl;	
							}
															
							return id;
						}
\+						{   std::cout << "ADD " << yytext[0] << std::endl; return ADD; }
.             			{
							std::cout << "SINGLE " << yytext[0] << std::endl;	
							return yytext[0];/* all ASCII characters are defined for us alrea, all other tokens we create are assigned IDS > 256 (the last ASCII character)*/
						}

%%