//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: Header class file for a singular template node for the linked list.
#ifndef NODE
#define NODE


template <class NODETYPE> class linked_list;

template <class NODETYPE>
class ListNode
{
    friend class linked_list<NODETYPE>; 
	public:
	  //Des: Constructs a node.
	  //Input: None.
	  //Output: None, but allots a node object for a linked list.
	  ListNode() {next=0;}
	  
	  //Des: Constructor of a single node of a given type.
	  //Input: a item of a given node type.
	  //Output: the allotment of node with that specficied type.
	  ListNode(const NODETYPE &);
	  
	  //Des: Returns the data stored on the node.
	  //Input: None.
	  //Output: The data of type NODETYPE.
      NODETYPE getData() const;
     private:
          NODETYPE data;
          ListNode <NODETYPE>*next;
};
#include "single_node.cpp"

#endif
