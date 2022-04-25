//
// Created by yassine on 23/04/2022.
//

#include <cstdint>
#include <algorithm>
#include <iostream>
#include "FordFulkerson.h"

inline char int_to_alphabet( int i )
{
	return static_cast<char>('A' + i);
}

int FordFulkerson::ford_fulkerson(const Graph& m)
{
	int flux_max{0};
	std::vector<bool> visited(m.get_num_sommet(), false);
	std::vector<int> traject;
	while (int min =depth_fist_search(m,m.get_start(),INT16_MAX,visited,traject))
	{
		flux_max += min;
		print_traject(traject,min);
		std::replace(visited.begin(), visited.end(), true,false);
		traject.erase(traject.begin(), traject.end());
	}
	return flux_max;
}

int FordFulkerson::depth_fist_search(const Graph& m, int current_node, int min, std::vector<bool>& visited, std::vector<int>& traject)
{
	visited[current_node] = true;

	if (current_node == m.get_destination())
	{
		traject.push_back(current_node);
		return min;
	}


	for (int i = 0; i < m.get_num_sommet(); ++i)
	{
		int cap_flux = m.get_matrice_adjacence()[current_node][i] - matrice_flux_[current_node][i];
		if (!visited[i] && cap_flux > 0)
		{
			if (int sent = depth_fist_search(m,i, std::min(min,cap_flux),visited,traject))
			{
				traject.push_back(current_node);
				matrice_flux_[current_node][i] += sent;
				matrice_flux_[i][current_node] -= sent;
				return sent;
			}
		}
	}
	return false;
}

void FordFulkerson::print_traject(std::vector<int>& traject, int min)
{

	for (int i = traject.size()-1; i >= 0 ; --i)
	{
		if (i != 0)
			std::cout<<int_to_alphabet(traject[i])<<" -> ";
		else
			std::cout<<int_to_alphabet(traject[i])<<" : flux max local = "<<min<<std::endl;
	}
}

FordFulkerson::FordFulkerson(const Graph& m)
{
	for (const auto& i: m.get_matrice_adjacence())
	{
		std::vector<int> tmp(m.get_num_sommet(),0);
		matrice_flux_.push_back(tmp);
	}
}
