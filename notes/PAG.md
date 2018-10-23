### PAG Node

PAG, again, is Program Analysis Graph, is a graphical structure to understand
the assignments.

We have 9 kinds of PAG nodes

* Value - ValNode
* Memory Object - ObjNode
* Unique Return Node - RetNode
* Unique Node for Vararg parameter - Vararg
* Temporary GEP Value Node for field sensitivity - GepValueNode
* Temporary GEP Object Node for field sensitivity - GepObjNode
* Field insensitive Analysis Object Node - FIObjNode
* Non-LLVM value node - DummyValNode
* Non-LLVM object node - DummyObjNode

