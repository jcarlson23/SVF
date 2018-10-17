//
// Source Sink Slice Analysis Code
//

#ifndef SOURCESINKSLICE_H_
#define SOURCESINKSLICE_H_

#include "SABER/CFLSolver.h"
#include "MSSA/SVFGOPT.h"
#include "SABER/ProgSlice.h"
#include "SABER/SaberSVFGBuilder.h"
#include "WPA/Andersen.h"
#include "SABER/SrcSnkDDA.h"
#include "SABER/SaberCheckerAPI.h"

/* 
 * Source Sink Analysis over a given Slice
 */
class SinkSourceSlice : public SrcSnkDDA, public llvm::ModulePass {

 public:
  typedef std::map<const SVFGNode*, llvm::CallSite> SVFGNodeToCSIDMap;
  typedef FIFOWorkList<llvm::CallSite> CSWorkList;
  typedef ProgSlice::VFWorkList WorkList;
  typedef NodeBS SVFGNodeBS;
  typedef PAG::CallSiteSet CallSiteSet;

  // pass ID
  static char ID;

  // constructor
  SinkSourceSlice(char id = ID): ModulePass(ID) {
  }

  virtual ~SinkSourceSlice() {
  }
  
  virtual llvm::StringRef getPassName() const {
        return "Static Memory Slice Leak Analysis";
   }
  
  virtual bool runOnModule(llvm::Module& module) {
    return runOnModule(module);
  }

  virtual bool runOnModule(SVFModule module) {
    analyze(module);
    return false;
  }
	
	virtual void initSrcs();
    virtual void initSnks();
  
  	virtual void reportBug(ProgSlice* slice);

    /// Whether the function is a heap allocator/reallocator (allocate memory)
    virtual inline bool isSourceLikeFun(const llvm::Function* fun) {
        return SaberCheckerAPI::getCheckerAPI()->isMemAlloc(fun);
    }
    /// Whether the function is a heap deallocator (free/release memory)
    virtual inline bool isSinkLikeFun(const llvm::Function* fun) {
        return SaberCheckerAPI::getCheckerAPI()->isMemDealloc(fun);
    }
    /// Identify allocation wrappers
    bool isInAWrapper(const SVFGNode* src, CallSiteSet& csIdSet);
    /// A SVFG node is source if it is an actualRet at malloc site
    inline bool isSource(const SVFGNode* node) {
        return getSources().find(node)!=getSources().end();
    }
    /// A SVFG node is source if it is an actual parameter at dealloca site
    inline bool isSink(const SVFGNode* node) {
        return getSinks().find(node)!=getSinks().end();
    }
    
    protected:
    
    PAG* getPAG() const {
        return PAG::getPAG();
    }
};


#endif
