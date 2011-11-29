#include <iostream>
#import "node.h"

void NExpression::codeGen()
{
	std::cout << "Creating NExpression: " << endl;
}

void NStatement::codeGen()
{
	std::cout << "Creating NStatement: " << endl;
}

void NIdentifier::codeGen()
{
	std::cout << "Creating NIdentifier: " << endl;
}

void NDouble::codeGen()
{
	std::cout << "Creating NDouble: " << endl;
}

void NExpressionStatement::codeGen()
{
	std::cout << "Creating NExpressionStatement: " << endl;
}

void NExpressionVariableDeclaration::codeGen()
{
	std::cout << "Creating NExpressionVariableDeclaration: " << endl;
} 