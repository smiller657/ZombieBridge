//Samantha Miller
//CPSC-340-01
//Zombie Bridge Project: 
// The specification of a template class of a linked list of type NODETYPE.    

#ifndef linked_list_H
#define linked_list_H
#include "single_node.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
class linked_list
{	
	public:
		//Des: Constructor for an instance of a linked list.
		//Input: None.
		//Output: None, but creates a linked list in memory.
		linked_list( );

		//Des: Deconstructs the linked list.
		//Input: None.
		//Output: Returns the allocated memory to the CPU.
		~linked_list( );	

		//Des: Constructs a linked list from a linked list of NODETYPE.
		//Input: A linked list of NODETYPE to copy.
		//Output: None, but constructs a copy of the list.
		linked_list(linked_list<NODETYPE> &originalList);

		//Des: Resets the linked list.
		//Input: None.
		//Output: None, but empties the list of its contents.
		void destroyList();

		//Des: Initializes the list.
		//Input: None. 
		//Output: None, but sets initial variables for a list.
		void initList();

		//Des: Prints the contents of the list to screen.
		//Input: None.
		//Output: None, but prints the data of each node of the list to screen.
		void PrintAll();

		//Des: Checks the list for a given value of the data of a node.
		//Input: Data that may match the data of a node.
		//Output: True if found, false if not found.
		bool Search(NODETYPE &value);

		//Des: Returns the number of nodes in the list.
		//Input: None.
		//Output: An integer for the number of nodes in the list.
		int length();
		
		//Des: Creates a deep copy of the current list.
		//Input: A list that will copy the data with its own pointers, passed by reference.
		//Output: True if copied successfully, false if copy is unsuccessful.
		bool CopyList(linked_list<NODETYPE> &copyList);
		
		//Des: Inserts data into a new last node of the list.
		//Input: Data of type NODETYPE to be added.
		//Output: True if successfully inserted, falsee if unsucessful.
		bool InsertLast(const NODETYPE value);
		
		//Des: Inserts data into the beginning of the list as a new node.
		//Input: Data of type NODETYPE to be added.
		//Output: True if successfully inserted, false if unsuccessful.
		bool InsertFirst(const NODETYPE value);
		
		//Des: Inserts data into the list, so the data of the list is pre-sorted.
		//Input: Data of type NODETYPE to be added.
		//Output: True if successfully inserted, false if unsuccessful.
		bool InsertInOrder(const NODETYPE value);
		
		//Des: Searches and removes the node with the given value from the list.
		//Input: Data of type NODETYPE to be removed.
		//Output: True if successfully removed, false if unsuccessful.
		bool Remove( NODETYPE & value);
		
		//Des: Checks if the list contains any nodes.
		//Input: None.
		//Output: True if the list has no nodes, false if the list contains nodes.
		bool IsEmpty( ) const;

	private:
		ListNode<NODETYPE> *first;   		
		ListNode<NODETYPE> *current;
		ListNode<NODETYPE> *last;
		int count;
};
#include "linked_list.cpp"
#endif
