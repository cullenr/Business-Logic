#include <iostream>
#import "node.h"

#include <stack>
#include <typeinfo>
#include <llvm/Module.h>
#include <llvm/Function.h>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/Instructions.h>
#include <llvm/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/IRBuilder.h>
//#include <llvm/ModuleProvider.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

llvm::Value* Node::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NExpression: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NExpression::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NExpression: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NStatement::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NStatement: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NIdentifier::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NIdentifier: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NDouble::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NDouble: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NExpressionStatement::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NExpressionStatement: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NExpressionVariableDeclaration::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NExpressionVariableDeclaration: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NBinaryOperation::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NExpressionVariableDeclaration: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}

llvm::Value* NAssignment::codeGen(CodeGenContext& context)
{
	std::cout << "Creating NExpressionVariableDeclaration: " << std::endl;
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), 2.0);
}