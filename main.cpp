#include <iostream>
#include "Graph.h"
#include "FordFulkerson.h"

int main()
{
	Graph graph;
	FordFulkerson ff(graph);
	std::cout<<"\nLe Flux max total est : "<<ff.ford_fulkerson(graph);
	return 0;
}
