//
// Created by yassine on 23/04/2022.
//

#ifndef FLUXMAX__FORDFULKERSON_H_
#define FLUXMAX__FORDFULKERSON_H_

#include "Graph.h"
class FordFulkerson
{
 public:
	explicit FordFulkerson(const Graph& m);
	std::vector<std::vector<int>> matrice_flux_;
	int ford_fulkerson(const Graph& m);
 private:
	int depth_fist_search(const Graph& m,
		int current_node,
		int min,
		std::vector<bool>& visited,
		std::vector<int>& traject);
	void print_traject(std::vector<int>& traject,int min);
};

#endif //FLUXMAX__FORDFULKERSON_H_
