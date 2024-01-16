#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/Host.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <iostream>
#include <string>

using namespace llvm;

int main(int argc, char **argv) {

	// Check for incorrect number of cli arguments

	if (argc > 2) {
		std::cerr << "Usage: " << argv[0] << " [file name] (optional)\n";
		return 1;
	}

	// Check for file name in cli arguments, if none use main

	std::string fileName = "main";
	if (argc == 2) { fileName = argv[1]; }

	LLVMContext context;
	IRBuilder<> builder(context);

	// Create module with name from cli arguments or main by default

	auto module = new Module(fileName + std::string(".ll"), context);
	module->setTargetTriple(sys::getDefaultTargetTriple());

	// extern a function called add

	auto addNumsFunc = Function::Create(
			FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), builder.getInt32Ty()}, false),
			Function::ExternalLinkage,
			"addNums",
			module
			);

	// extern a function called readInt

	auto readIntFunc = Function::Create(
			FunctionType::get(builder.getInt32Ty(), false),
			Function::ExternalLinkage,
			"readInt",
			module
			);

	// extern a function called printInt

	auto printIntFunc = Function::Create(
			FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty()}, false),
			Function::ExternalLinkage,
			"printInt",
			module
			);

	// Create function main with no arguments and return type void

	auto mainFunc = Function::Create(
			FunctionType::get(builder.getInt32Ty(), false),
			GlobalValue::ExternalLinkage,
			"main",
			module
			);

	// Create inner code of function main and print result of call to add function

	auto entry = BasicBlock::Create(context, "entry", mainFunc);
	builder.SetInsertPoint(entry);
	auto mainArg1 = mainFunc->arg_begin();
	auto mainArg2 = builder.CreateCall(readIntFunc);
	auto mainArg3 = builder.CreateCall(readIntFunc);
	auto mainArg4 = builder.CreateCall(addNumsFunc, {mainArg2, mainArg3});
	auto mainArg5 = builder.CreateCall(printIntFunc, mainArg4);
	builder.CreateRet(builder.getInt32(0));

	// Print module to stdout

	module->print(outs(), nullptr);

	return 0;
}
