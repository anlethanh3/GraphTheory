#ifndef  _ADJACENCYGRAPH_H_
#define _ADJACENCYGRAPH_H_
#include <iostream>
class AdjacencyGraph
{
	protected:
		int type;
		int numVertex;
	public:
		AdjacencyGraph();
		virtual ~AdjacencyGraph();
		
		virtual void Read(std::istream& inDevice) = 0;
		virtual void Write(std::ostream& outDevice) = 0;
		
		int GetNumVertex();
		
		friend std::istream& operator >> (std::istream& inDevice, AdjacencyGraph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, AdjacencyGraph& graph);
};
#endif