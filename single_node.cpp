//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Implementation file for single node of template time class methods
#include "single_node.h"
#ifndef NODE_CPP
#define NODE_CPP

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
{	
	data=info;
	next = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const 
{
	return data;
}
#endif
