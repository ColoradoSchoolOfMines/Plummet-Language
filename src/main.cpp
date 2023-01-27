#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/Host.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

using namespace llvm;

int main() {
	LLVMContext context;
	IRBuilder<> builder(context);

	// Create module called "main" and set target triple

	auto module = new Module("main", context);
	module->setTargetTriple(sys::getDefaultTargetTriple());

	// Create function "add" with two arguments of type int32 and return type int32

	auto addFunc = Function::Create(
			FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), builder.getInt32Ty()}, false),
			GlobalValue::ExternalLinkage,
			"add",
			module
			);

	// Create inner code of function "add" and return result

	auto addEntry = BasicBlock::Create(context, "entry", addFunc);
	builder.SetInsertPoint(addEntry);
	auto addArg1 = addFunc->arg_begin();
	auto addArg2 = addArg1 + 1;
	auto addResult = builder.CreateAdd(addArg1, addArg2);
	builder.CreateRet(addResult);

	// Create function "main" with no arguments and return type int32

	auto mainFunc = Function::Create(
			FunctionType::get(builder.getInt32Ty(), false),
			GlobalValue::ExternalLinkage,
			"main",
			module
			);

	// Create inner code of function "main" and return result of function call to "add"

	auto entry = BasicBlock::Create(context, "entry", mainFunc);
	builder.SetInsertPoint(entry);
	auto mainArg1 = mainFunc->arg_begin();
	auto addCall = builder.CreateCall(addFunc, {builder.getInt32(1), builder.getInt32(2)});
	builder.CreateRet(addCall);

	// Print module to stdout

	module->print(outs(), nullptr);

	return 0;
}
