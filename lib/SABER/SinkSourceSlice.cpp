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

