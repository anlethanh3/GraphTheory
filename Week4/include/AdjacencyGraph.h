#ifndef  _ADJACENCYGRAPH_H_
#define _ADJACENCYGRAPH_H_
#include <iostream>
class AdjacencyGraph
{
	protected:
		int type;
		int numVertex;
		int numEdge;
	public:
		AdjacencyGraph();
		AdjacencyGraph(const int& numVertex, const int& numEdge);
		virtual ~AdjacencyGraph();
		
		virtual void Read(std::istream& inDevice) = 0;
		virtual void Write(std::ostream& outDevice) = 0;
		
		int GetNumVertex();
		int GetNumEdge();
		
		friend std::istream& operator >> (std::istream& inDevice, AdjacencyGraph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, AdjacencyGraph& graph);
};
#endif