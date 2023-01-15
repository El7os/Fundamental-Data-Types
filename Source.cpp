#include <iostream>
#include <unordered_set>

#include "TStack.h"
#include "TCircularQueue.h"
#include "TBinaryTree.h"
#include "TGraph.h"
#include "HelperFunctions.h"

int main()
{

//#define STACK // To test the stack and its functions, remove the leftmost comment. 
#ifdef STACK

	TStack<int> Stack;

	Stack.Push(12);
	Stack.Push(13);
	Stack.Push(14);

	std::cout << "Is Empty     : " << Stack.IsEmpty() << std::endl;
	std::cout << "Stack Size   : " << Stack.Size() << std::endl;
	std::cout << "Stack Top    : " << Stack.Top() << std::endl;
	std::cout << "Stack Pop(1) : " << Stack.Pop() << std::endl;
	std::cout << "Stack Pop(2) : " << Stack.Pop() << std::endl;
	std::cout << "Stack Pop(3) : " << Stack.Pop() << std::endl;
	std::cout << "Stack Size   : " << Stack.Size() << std::endl;
	std::cout << "Is Empty     : " << Stack.IsEmpty() << std::endl;

	


#endif

//#define CIRCULARQUEUE // To test the circular queue and its functions, remove the leftmost comment.
#ifdef CIRCULARQUEUE
	// A generic/template Queue example that implements Circular Queue on an array.
	TCircularQueue<int, 10> Queue;
	
	Queue.Enqueue(12);
	Queue.Enqueue(13);
	Queue.Enqueue(14);

	std::cout << "Total Size of The Queue        : " << Queue.Size() << std::endl;
	std::cout << "Empty Space Count              : " << Queue.GetEmptySpaceCount() << endl;
	std::cout << "First                          : " << Queue.Peek() << std::endl;
	std::cout << "Queue Dequeue(1)               : " << Queue.Dequeue() << std::endl;
	std::cout << "Queue Dequeue(2)               : " << Queue.Dequeue() << std::endl;
	std::cout << "Queue Dequeue(3)               : " << Queue.Dequeue() << std::endl;
	std::cout << "Empty Space Count              : " << Queue.GetEmptySpaceCount() << endl;


#endif

//#define BINARYTREE // To test binary tree traversal functions, remove the leftmost comment.
#ifdef BINARYTREE
	// A generic Binary Tree example.
	TBinaryTree<int> Tree(12);

	Tree.Add(17, Max);
	Tree.Add(5, Max);
	Tree.Add(4, Max);
	Tree.Add(6, Max);
	Tree.Add(15, Max);
	Tree.Add(20, Max);

	/*
	*         Current state of Tree
	*				 (12)
	*			 ____/  \____
    *           /            \
	*		 (5)            (17)
	*	    _/  \_        _/    \_
	*	   /      \      /        \
	*	 (4)      (6)  (15)       (20)
	*/

	std::cout << "Total Node Count : " << Tree.TotalNodeCount() << std::endl;

	std::cout << "==== Pre-Order Traverse ====" << std::endl;
	Tree.TraversePreOrder(PrintTreeNode<int>);

	std::cout << "==== In-Order Traverse ====" << std::endl;
	Tree.TraverseInOrder(PrintTreeNode<int>);

	std::cout << "==== Post-Order Traverse ====" << std::endl;
	Tree.TraversePostOrder(PrintTreeNode<int>);
#endif

#define GRAPH // To test graph traversal functions, remove the leftmost comment.
#ifdef GRAPH

	TGraph<char> A('A');
	TGraph<char> B('B');
	TGraph<char> C('C');
	TGraph<char> D('D');
	TGraph<char> E('E');
	TGraph<char> F('F');
	TGraph<char> G('G');
	TGraph<char> H('H');
	TGraph<char> I('I');
	TGraph<char> J('J');

	A.AssociateWith(&B);
	A.AssociateWith(&C);
	B.AssociateWith(&C);
	B.AssociateWith(&D);
	B.AssociateWith(&E);
	E.AssociateWith(&F);
	F.AssociateWith(&G);
	F.AssociateWith(&H);
	F.AssociateWith(&I);
	I.AssociateWith(&H);
	I.AssociateWith(&J);

	/*
	* Current state of the graph
	* 
	*	 B---D     I---J
    *   /|\	      /|
	*  / | \     / |
	* A  |  E---F  |
	*  \ |     / \ |
 	*   \|    /   \|
	*    C   G     H
	*/
	
	std::cout << "=========== Travel BFS ===========" << std::endl;
	A.TravelBFS(PrintGraphNode<char>);
	std::cout << "=========== Travel DFS ===========" << std::endl;
	A.TravelDFS(PrintGraphNode<char>);

#endif 

#if !defined STACK && !defined CIRCULARQUEUE  && !defined BINARYTREE  && !defined GRAPH
#define WARNING std::cout << "If you are seeing this message, it means that you didn't activated any of the test conditions." << \
"\nPlease go to Source.cpp file and activate at least one of the test conditions.\n\n\n";
#else 
#define WARNING
#endif
WARNING
}