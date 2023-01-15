#pragma once

template <class _Kty, class _Hasher, class _Keyeq, class _Alloc>
class std::unordered_set;

/*
* A templated class that implements graph functionality by using recursion.
* @param DataType - The type of the elements that the graph is going to contain.
*/
template<typename DataType>
class TGraph
{
public:

	using Map = std::unordered_set<TGraph<DataType>*>;
	using FTraverser = void(*)(TGraph<DataType>*);

	explicit TGraph(const DataType& Data) 
		: Data(Data)
	{
	}

	/*
	* Travels through the entire graph by using breadth first search
	* algorithm and applies Func to each traveled graph node.
	* @param Func - The function that TravelBFS is going to use on each and every node
	*				of the graph.
	*/
	void TravelBFS(FTraverser Func)
	{
		std::unordered_set<TGraph<DataType>*> VisitMap, ExploreMap;
		Func(this);
		VisitMap.insert(this);

		TravelBFS_Internal(Func, VisitMap,ExploreMap);
		
	}

	/*
	* Travels through the entire graph by using depth first search
	* algorithm and applies Func to each traveled graph node.
	* @param Func - The function that TravelDFS is going to use on each and every node
	*				of the graph.
	*/
	void TravelDFS(FTraverser Func)
	{
		std::unordered_set<TGraph<DataType>*> MarkMap;
		TravelDFS_Internal(Func, MarkMap);
	}

	/*
	* Creates an edge between this and Vertex. This action changes
	* the both of the vertices.
	* @param Vertex - The vertex that is going to be associated with
	*				  this graph node.
	*/
	inline void AssociateWith(TGraph<DataType>* Vertex)
	{
		if (Neighbours.find(Vertex) == Neighbours.end())
			Neighbours.insert(Vertex);

		if (Vertex->Neighbours.find(this) == Vertex->Neighbours.end())
			Vertex->Neighbours.insert(this);
	}

	DataType Data;

private:

	/*
	* The real function that travels through the graph with DFS algorithm.
	* TravelDFS function makes some initializations and delegates the work
	* to this function.
	* @param Func - The function that TravelDFS_Internal is going to use on each and every node
	*				of the graph.
	* @param MarkMap - The list of the graphs that is already travelled. 
	*/
	void TravelDFS_Internal(FTraverser Func, Map& MarkMap)
	{
		Func(this);
		MarkMap.insert(this);

		for (TGraph<DataType>* i : Neighbours)
			if (MarkMap.find(i) == MarkMap.end())
				i->TravelDFS_Internal(Func, MarkMap);
	}

	/*
	* The real function that travels through the graph with BFS algorithm.
	* TravelBFS function makes some initializations and delegates the work
	* to this function.
	* @param Func - The function that TravelBFS_Internal is going to use on each and every node
	*				of the graph.
	* @param VisitMap - The list of the pre-visited graphs.
	* @param ExploreMap - The list of the pre-explored graphs.
	*/
	void TravelBFS_Internal(
		FTraverser Func,
		Map& VisitMap,
		Map& ExploreMap)
	{
		for (TGraph<DataType>* i : Neighbours)
		{
			if (VisitMap.find(i) == VisitMap.end())
			{
				Func(i);
				VisitMap.insert(i);
			}
		}

		ExploreMap.insert(this);
			
		for (TGraph<DataType>* i : Neighbours)
			if (ExploreMap.find(i) == ExploreMap.end())
				i->TravelBFS_Internal(Func, VisitMap,ExploreMap);
	}

	/* Deleting the copy constructor */
	TGraph(const TGraph&) = delete;

	/* Deleting the move assignment operator */
	TGraph& operator=(const TGraph&) = delete;

	Map Neighbours;

};