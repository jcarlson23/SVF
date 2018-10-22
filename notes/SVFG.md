### Graphical Structures

Here are some notes I want to keep for understanding the graphs created
by SVFG.


#### SVFG

From the file:

```included/MSSSA/SVFG.h```

So, from a top level, this is graph constructed from typical edges and
nodes.  The relevant nodes/edges are dumped via *dump* method.

More interesting methods are:

* _connectCallerAndCallee_ - looks to conenct the callsite to the function that calls the given callsite
* _getDefSVFGNode( PAGNode* pagNode )_ const - return the Def (definition) of the given PAGNode, looks  like this might resovle the def-use chain?
* _getStoreSVFGNode( StorePE * store)_ const - looks like it returns the corresponding the SVFGNode given the PAGEdge?


Note that I need to understand the PAG structure.

* _addIntraIndirectVFEdge_ - looks like this helps to define the use-def chain within a given memory region.
* _addCallIndirectVFEdge_ - similar
* _addRetIndirectVFEdge_ - for the return.
* _addThreadMHPIndirectVFEdge_ - unsure...

There are a number of methods to conenction parameters and RET instructions.

Ok, then we have MSSADef's and the associated SVFG nodes
* _setDef_(MRVer* mvar, SVFGNode * node)_
* _getDef_(const MRVer * mvar)_

We have various LOAD/STORE handling.

Looks like we have insertion of PHI nodes?  Looks like it'll be used for a given memory region?

