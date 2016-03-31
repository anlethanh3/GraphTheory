#ifndef  _ADJACENCYGRAPH_H_
#define _ADJACENCYGRAPH_H_
#include <iostream>
class AdjacencyGraph
{
	protected:
		int type;
	public:
		AdjacencyGraph();
		virtual ~AdjacencyGraph();
		
		virtual int 		CountEdges() 						= 0;
		virtual void 	GetDegrees(int*& degrees)	= 0;
		virtual int 		GetTypeOfGraph() 				= 0;
		virtual int 		GetType()								= 0;
		
		virtual void 	SetPath(int edge1, int edge2, bool hasPath) = 0;
		
		virtual void 	Read(std::istream& inDevice){};
		virtual void 	Write(std::ostream& outDevice){};
		
		friend std::istream& operator >> (std::istream& inDevice, AdjacencyGraph& graph){
			graph.Read(inDevice);
			return inDevice;
		}
		friend std::ostream& operator << (std::ostream& outDevice, AdjacencyGraph& graph){
			graph.Write(outDevice);
			return outDevice;
		}
};
#endif