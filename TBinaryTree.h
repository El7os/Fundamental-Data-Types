#pragma once

/*
* A templated class that behaves as an binary tree.
* @param DataType - Type of nodes that the tree is going to hold.
*/
template <typename DataType>
class TBinaryTree
{
public:

	using FPrioritizer = bool(*)(const DataType&, const DataType&);
	using FTraverser = void(*)(TBinaryTree<DataType>*);

	/* 
	* A constructor for TBinaryTree craetions with data.
	* @param Data - The value that the subtree is going to hold.
	*/
	explicit TBinaryTree(const DataType& Data) : TBinaryTree<DataType>(Data, nullptr, nullptr)
	{
	}

	/*
	* A constructor for TBinaryTree creations with Data and the LeftChild
	* @param Data - The value that the subtree is going to hold.
	* @param LeftTree - A subtree reference that is going to be the left child of the subtree.
	*/
	TBinaryTree(const DataType& Data, TBinaryTree<DataType>* LeftChild) : TBinaryTree<DataType>(Data, LeftChild, nullptr)
	{
	}

	/*
	* A constructor for TBinaryTree creations with Data and the LeftChild
	* @param Data - The value that the subtree is going to hold.
	* @param LeftTree - A subtree reference that is going to be the left child of the subtree.
	* @param RightTree - A subtree reference that is going to be the right child of the subtree.
	*/
	TBinaryTree(const DataType& Data, TBinaryTree<DataType>* LeftChild, TBinaryTree<DataType>* RightChild)
		: Data(Data)
		, LeftChild(LeftChild)
		, RightChild(RightChild)
	{
	}

	~TBinaryTree()
	{
		if (LeftChild)
			delete LeftChild;

		if (RightChild)
			delete RightChild;
	}

	/*
	* Adds a node to the tree.
	* @param Data - The value of the node that is going to be created.
	* @param Prioritizer - A function that is used to determine the correct location for the node.
	*                      Prioritizer must return true if the first parameter is grater than the second 
	*                      parameter, false otherwise.
	*/
	TBinaryTree* Add(const DataType& Data, FPrioritizer Prioritizer)
	{
		
		if (!Prioritizer(Data, this->Data))
		{
			if (LeftChild)
				return LeftChild->Add(Data, Prioritizer);
			else
				return LeftChild = new TBinaryTree(Data);
		}
		else
		{
			if (RightChild)
				return RightChild->Add(Data, Prioritizer);
			else
				return RightChild = new TBinaryTree(Data);
		}
	}

	/*
	* Traverses the tree in pre-ordered way and uses Func on every traversed node.
	* @param Func - A function that is going to be used on traversed tree nodes.
	*/
	void TraversePreOrder(FTraverser Func)
	{
		Func(this);
		if (LeftChild)
			LeftChild->TraversePreOrder(Func);
		if (RightChild)
			RightChild->TraversePreOrder(Func);
	}


	/*
	* Traverses the tree in in-orderedway and uses Func on every traversed node.
	* @param Func -  A function that is going to be used on traversed tree nodes.
	*/
	void TraverseInOrder(FTraverser Func)
	{
		if (LeftChild)
			LeftChild->TraverseInOrder(Func);
		Func(this);
		if (RightChild)
			RightChild->TraverseInOrder(Func);

	}

	/*
	* Traverses the tree in post-ordered way and uses Func on every traversed node.
	* @param Func -  A function that is going to be used on traversed tree nodes.
	*/
	void TraversePostOrder(FTraverser Func)
	{
		
		if (LeftChild)
			LeftChild->TraversePostOrder(Func);
		if (RightChild)
			RightChild->TraversePostOrder(Func);
		Func(this);

	}

	/*
	* Returns the total node count that the tree is holding at that time.
	* @return The total node count that the tree currently has.
	*/
	unsigned long long TotalNodeCount() const
	{
		unsigned long long Count = 1;
		if (LeftChild)
			Count += LeftChild->TotalNodeCount();
		if (RightChild)
			Count += RightChild->TotalNodeCount();
		return Count;
	}

	/*
	* Removes a child node.
	* @param bRightChild - Deletes the right child if it is true, left child otherwise.
	*/
	void RemoveChild(bool bRightChild)
	{
		if (bRightChild && RightChild)
		{
			delete RightChild;
			RightChild = nullptr;
		}
		else if (LeftChild)
		{
			delete LeftChild;
			LeftChild = nullptr;
		}
	}

	/*
	* Removes the whole tree and probably causes the whole array to be deallocated.
	* @warning This function does not changes the value of the node that this function is used on.
	*		   Since this function can cause deallocation, be careful for dangling pointers to the 
	*		   subtrees of this tree.
	*/
	void Clear()
	{
		RemoveChild(true);
		RemoveChild(false);
	}


	/*
	* Checks if the tree is empty.
	* @return Returns true if the tree is empty, false otherwise.
	*/
	inline bool IsEmpty() const
	{
		return (LeftChild || RightChild);
	}

	TBinaryTree<DataType>* LeftChild = nullptr, *RightChild = nullptr;

	DataType Data;

private:

	/* Deleting the copy constructor */
	TBinaryTree(const TBinaryTree&) = delete;

	/* Deleting the move assignment operator */
	TBinaryTree& operator=(const TBinaryTree&) = delete;



};