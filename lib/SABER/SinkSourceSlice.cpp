#include "SABER/SinkSourceSlice.h"
#include "Util/AnalysisUtil.h"
#include <llvm/Support/CommandLine.h>

using namespace llvm;
using namespace analysisUtil;

char SinkSourceSlice::ID = 0;

static RegisterPass<SinkSourceSlice> SINKSOURCESLICE("sink-source-slicer","Sink Source Slicer");

void SinkSourceSlice::initSrcs() {

  PAG* pag = getPAG();
}

void SinkSourceSlice::initSnks() {

  PAG* pag = getPAG();
  
}

bool SinkSourceSlice::isInAWrapper(const SVFGNode* src, CallSiteSet& csIdSet) {

  bool reachFunExit = false;
  
  return false;
}

void SinkSourceSlice::reportBug(ProgSlice* slice) {

}

bool SinkSourceSlice::process(SVFModule module) {
    
    llvm::outs() << "processing...\n";
    
    initialize( module );
    // ContextCond::setMaxCxtLen(cxtLimit); - default would be "3" but I'm going to omit
    // for now.

    SVFGNodeSet Sources = getSources();
    llvm::outs() << "we have " << Sources.size() << " sources.\n";
    SVFGNodeSet Sinks   = getSinks();
    llvm::outs() << " we have " << Sinks.size() << " sinks.\n";
    
    // Here we grab the sources as a SET and begin to iterate over them.
    for ( SVFGNodeSetIter iter = sourcesBegin(), eiter = sourcesEnd(); iter != eiter; ++iter) {

      setCurSlice(*iter);
      llvm::outs() << "Analyzing slice: " << (*iter)->getId() << "\n";
  
      ContextCond cxt;
      DPIm item ( (*iter)->getId(), cxt);
        
    }
    
    return false;
}
