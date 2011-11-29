#include <iostream>

//http://stackoverflow.com/questions/19132/expression-versus-statement
//
//Expression: Something which evaluates to a value. Example: 1+2/x
//Statement: A line of code which does something. Example: GOTO 100

//http://www.lysator.liu.se/c/ANSI-C-grammar-y.html
//http://www.lysator.liu.se/c/ANSI-C-grammar-l.html
//
//lex grammar for ANSI C! 
//Yacc grammar for ANSI C!
//
//written in C! paradox!?

class Node 
{
public:
	virtual ~Node() {}
	virtual void codeGen() { }
};

class NExpression : public Node 
{
};

class NStatement : public Node 
{
};

class NIdentifier : public NExpression
{
public:
	std::string name;
	NIdentifier(const std::string& name) : name(name) { std::cout << "Creating Identifier: " << std::endl; }
};

class NAssignment : public NExpression 
{
public:
	NIdentifier& lhs;
	NExpression& rhs;
	NAssignment(NIdentifier& lhs, NExpression& rhs) : lhs(lhs), rhs(rhs) { std::cout << "Creating Assignment: " << std::endl; }
};


class NDouble : public NExpression
{
public:
	double value;
	NDouble(double value) : value(value) {std::cout << "Creating Double: " << std::endl; }
};

class NExpressionStatement : public NStatement
{
public:
	NExpression &expression;
	NExpressionStatement(NExpression &expression) : expression(expression) { std::cout << "Creating Expression Statement: " << std::endl;}
};

class NExpressionVariableDeclaration : public NStatement
{
public:
	NIdentifier &type;
	NExpression &assignExpression;

	NExpressionVariableDeclaration(NIdentifier type, NExpression &expression) : type(type), assignExpression(assignExpression) { std::cout << "Creating Expression variable declaration: " << std::endl;}
};

class NBinaryOperation : public NStatement
{
public:
	NIdentifier &type;
	NExpression &assignExpression;

	NExpressionVariableDeclaration(NIdentifier type, NExpression &expression) : type(type), assignExpression(assignExpression) { std::cout << "Creating Expression variable declaration: " << std::endl;}
};


