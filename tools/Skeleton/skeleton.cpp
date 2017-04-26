// 
//                      Sample: Sample SVF based tool
//
// 

/*
 // Sample
 //
 // Author: Jared Carlson
 */

#include "SABER/FileChecker.h"

#include <llvm/Support/CommandLine.h>
#include <llvm/Bitcode/BitcodeWriterPass.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Support/Signals.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/PrettyStackTrace.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Bitcode/ReaderWriter.h>

using namespace llvm;

static cl::opt<std::string> InputFilename(cl::Positional,
					  cl::desc("<input bitcode file>"),
					  cl::init("~"));


/*
 * This all just acts as a pass manager
 * that will call each pass to perform the
 * desired analysis.
 *
 */
int main(int argc, char **argv ) {

  sys::PrintStackTraceOnErrorSignal();
  llvm::PrettyStackTraceProgram X(argc, argv);
  
  LLVMContext &Context = getGlobalContext();
  
  std::string OutputFilename;
  cl::ParseCommandLineOptions(argc, argv, "Bug Check\n");

  PassRegistry &Registry = *PassRegistry::getPassRegistry();
  
  initializeCore(Registry);
  initializeScalarOpts(Registry);
  initializeIPO(Registry);
  initializeAnalysis(Registry);
  initializeTransformUtils(Registry);
  initializeInstCombine(Registry);
  initializeInstrumentation(Registry);
  initializeTarget(Registry);

  llvm::legacy::PassManager Passes;
  
  SMDiagnostic Err;

  std::unique_ptr<Module> M = parseIRFile( InputFilename, Err, Context );
  
  if ( !M ) {
    Err.print(argv[0], errs());
    return 1;
  }

  Passes.run( *M.get() );

  outs() << "Finished running skeleton pass\n";

  return 0;

}
