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

	// Create "bubble_sort" function
	auto bubbleSort = Function::Create(
		FunctionType::get(builder.getVoidTy(), false),
		GlobalValue::LinkageTypes::ExternalLinkage,
		"bubble_sort",
		module
	);

	// Define "bubble_sort" function (non entry block)
	auto entry = BasicBlock::Create(context, "", bubbleSort);

	// Print module to stdout
	module->print(outs(), nullptr);
}
