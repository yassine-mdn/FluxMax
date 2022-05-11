#include <iostream>
#include "Graph.h"
#include "FordFulkerson.h"

/**
 * resolution du problème de flux maximale avec la methode de Ford Fulkerson
 * @return 0
 */
int main()
{
	Graph graph;
	graph.print();
	FordFulkerson ff(graph);
	std::cout<<"\nLe Flux max total est : "<<ff.ford_fulkerson(graph);
	return 0;
}
