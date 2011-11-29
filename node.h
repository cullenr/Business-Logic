#include <iostream>
#include <vector>
#include <llvm/Value.h>

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

class CodeGenContext;

class Node 
{
public:
	virtual ~Node() {};
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NExpression : public Node 
{
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NStatement : public Node 
{
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NIdentifier : public NExpression
{
public:
	std::string name;
	NIdentifier(const std::string& name) : name(name) { std::cout << "Creating Identifier: " << name << std::endl; };
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NAssignment : public NExpression 
{
public:
	NIdentifier& lhs;
	NExpression& rhs;
	NAssignment(NIdentifier& lhs, NExpression& rhs) : lhs(lhs), rhs(rhs) { std::cout << "Creating Assignment: " << std::endl; };
	virtual llvm::Value* codeGen(CodeGenContext& context);
};


class NDouble : public NExpression
{
public:
	double value;
	NDouble(double value) : value(value) {std::cout << "Creating Double: " << value << std::endl; };
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NExpressionStatement : public NStatement
{
public:
	NExpression &expression;
	NExpressionStatement(NExpression &expression) : expression(expression) { std::cout << "Creating Expression Statement: " << std::endl;};
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NExpressionVariableDeclaration : public NStatement
{
public:
	NIdentifier &type;
	NExpression &assignExpression;

	NExpressionVariableDeclaration(NIdentifier type, NExpression &expression) : type(type), assignExpression(assignExpression) { std::cout << "Creating Expression variable declaration: " << std::endl;};
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBinaryOperation : public NExpression
{
public:
	NExpression &lhs;
	NExpression &rhs;
	char op;

	NBinaryOperation(NExpression &lhs, char op, NExpression &rhs) : lhs(lhs), op(op), rhs(rhs){ std::cout << "Creating Binary Operation " << std::endl;};
	virtual llvm::Value* codeGen(CodeGenContext& context);
};