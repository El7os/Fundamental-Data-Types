#pragma once
#include "CustomExceptions.h"

/*
* A templated class that implements circular queue functionality on an array.
* @param DataType - Type of the elements that the circular queue is going to contain.
* @param TSize - Size of the array which contains all of the elements.
*/
template<typename DataType, unsigned long long TSize>
class TCircularQueue
{

public :

	TCircularQueue()
		: Head(0)
		, Tail(0)
		, EmptyCell(TSize)
	{
	}

	explicit TCircularQueue(const DataType& Data)
		: Head(0)
		, Tail(0)
		, EmptyCell(TSize)
	{
		Enqueue(Data);
	}

	/*
	* Adds a new element to the queue, if it is possible. 
	* @param Data - The value that is going to be added at the end of the queue.
	* @warning Throws NoSpaceInQueue exception if there is no space in the queue
	*		   and still an element is wanted to be added to the queue.
	*/
	inline void Enqueue(const DataType& Data)
	{
		if (!EmptyCell)
			throw NoSpaceInQueue();

		Queue[Tail] = Data;
		Tail = Tail == TSize - 1 ? 0 : Tail + 1;
		--EmptyCell;
	}

	/* Clears the entire circular queue. */
	inline void Empty()
	{
		Head = Tail = 0;
		EmptyCell = TSize;
	}

	/*
	* Checks if the tree is empty.
	* @return Returns true if the queue is empty, false otherwise.
	*/
	inline bool IsEmpty() const
	{
		return EmptyCell == TSize;
	}

	/*
	* Pops the first element in the queue.
	* @return The value of the first element of the queue
	* @warning Throws ThereIsNoSuchElement exception if the queue is empty.
	*/
	inline DataType Dequeue()
	{
		if (EmptyCell == TSize)
			throw ThereIsNoSuchElement();

		DataType Temp = Queue[Head];
		Head = Head == TSize - 1 ? 0 : Head + 1;
		++EmptyCell;
		return Temp;
	}

	/*
	* Gives the first element that is going to be popped, without changing the queue.
	* @return The value of the first element of the queue.
	* @warning Throws ThereIsNoSuchElement exception if the queue is empty. Be sure that the queue is
	*          not empty before trying to use it.
	*/
	inline DataType Peek() const 
	{
		if (EmptyCell == TSize)
			throw ThereIsNoSuchElement();

		return Queue[Head]; 
	}

	/*
	* Gives the maximum possible number of items that can fit in the queue.
	* @return Maximum size of the queue.
	*/
	inline unsigned long long Size() const { return TSize; }

	/*
	* Gives the empty space count that can be used.
	* @return Empty space count.
	*/
	inline unsigned long long GetEmptySpaceCount() const { return EmptyCell; }

private:

	int Head = 0, Tail = 0;

	unsigned long long EmptyCell = TSize;

	DataType Queue[TSize];
};