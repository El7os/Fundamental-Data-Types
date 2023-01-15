#pragma once

/*
* A templated class that implements stack behavior.
* @param DataType - The type of elements that the stack is going to contain.
*/
template<typename DataType>
class TStack
{
public:

	TStack()
		: FirstNode(nullptr)
		, LastNode(nullptr)
	{
	}

	/* A constructor that allows the user to create a stack with initial value
	* @param Data - The value that the newly created stack holds.
	*/
	explicit TStack(const DataType& Data)
	{
		LastNode = (FirstNode = new TNode(Data));
	}

	~TStack()
	{
		while (FirstNode)
		{
			TNode* Node = FirstNode;
			FirstNode = FirstNode->NextNode;

			delete Node;
		}
	}

	/*
	* Adds a new element to the end of the stack. Always allocates some memory.
	* @param Data - The value that is going to be added to the stack.
	*/
	void Push(const DataType& Data)
	{
		if (!FirstNode)
		{
			LastNode = FirstNode = new TNode(Data);
		}
		else
		{
			LastNode = LastNode->NextNode = new TNode(Data);
		}
	}

	/*
	* Pops the last added element and returns its value. This action always results in deallocation.
	* @return The value of the last added element.
	*/
	DataType Pop()
	{
		DataType Data = LastNode->Data;

		if (LastNode == FirstNode)
		{
			delete LastNode;
			LastNode = FirstNode = nullptr;
		}
		else
		{
			TNode* Indicator = FirstNode;

			while (Indicator->NextNode != LastNode)
				Indicator = Indicator->NextNode;
			
			delete LastNode;

			Indicator->NextNode = nullptr;
			LastNode = Indicator;
		}

		
		return Data;
	}

	/*
	* Returns the value of last added element without changing the stack.
	* @return The value of the last added element.
	*/
	inline DataType Top() const
	{
		return LastNode->Data;
	}

	/* Clears the entire stack and deallocates the memory occupied by the elements */
	void Empty()
	{
		while (LastNode)
			Pop();
	}

	/*
	* Checks if this stack is empty.
	* @return Returns true if the stack is empty, false otherwise.
	*/
	inline bool IsEmpty() const
	{
		return !FirstNode;
	}

	/*
	* Gives the current size of the stack.
	* @return Current size of the stack.
	*/
	unsigned long long int Size() const
	{
		unsigned long long int Size = 0;

		TNode* EndIndicator = FirstNode;
		while (EndIndicator)
		{
			Size++;
			EndIndicator = EndIndicator->NextNode;
		}

		return Size;
	}

private:

	struct TNode
	{
		TNode()
			: NextNode(nullptr)
		{
		}

		explicit TNode(const DataType& Data)
			: NextNode(nullptr)
			, Data(Data)
		{
		}

		explicit TNode(DataType&& Data)
			: NextNode(nullptr)
			, Data(Data)
		{
		}

		TNode* NextNode = nullptr;

		DataType Data;
	};

	TNode* FirstNode = nullptr, *LastNode = nullptr;

	/* Deleting the copy constructor */
	TStack(const TStack&) = delete;

	/* Deleting the move assignment operator */
	TStack& operator=(const TStack&) = delete;

};
