//
// Created by yassine on 18/04/2022.
//

#include <iostream>
#include <iomanip>
#include "Graph.h"

Graph::Graph(int numSommet) : numSommet_{ numSommet }
{
	matrice_adjacence_.resize(numSommet_);        //j'initialise le pointeur avec numSommet instance de list
	for (int i = 0; i < numSommet_; ++i)
	{
		for (int j = 0; j < numSommet_; ++j)
		{
			std::cout << "se trouve t\'il un aret entre " << i << " et " << j << " ?y:n" << std::endl;
			char c{};
			std::cin >> c;
			if (c == 'y')
			{
				int temp;
				std::cout << "poid du sommet :" << std::endl;
				std::cin >> temp;
				matrice_adjacence_[i][j] = temp;
			}
			else
				matrice_adjacence_[i][j] = 0;
		}
	}
	std::cout<<"Le Sommet source est :"<<std::endl;
	std::cin>>start_;
	std::cout<<"Le Sommet destination est :"<<std::endl;
	std::cin>>destination_;
}

Graph::Graph()
{
	numSommet_ = 6;
	matrice_adjacence_.resize(numSommet_);
	matrice_adjacence_ = {{ 0, 16, 13, 0, 0, 0 },
						  { 0, 0, 10, 12, 0, 0 },
						  { 0, 4, 0, 0, 14, 0 },
						  { 0, 0, 9, 0, 0, 20 },
						  { 0, 0, 0, 7, 0, 4 },
						  { 0, 0, 0, 0, 0, 0 } };
	start_ = 0;
	destination_ = 5;

}
Graph::~Graph()
{

}
void Graph::print()
{
	int maxColLen[numSommet_];
	for (int i = 0; i < numSommet_; ++i)
	{
		maxColLen[i] = 0;
	}
	for (int i = 0; i < numSommet_; ++i)
	{
		for (int j = 0; j < numSommet_; ++j)
		{
			const int num_length{ number_of_digits(matrice_adjacence_[i][j]) };
			if (num_length > maxColLen[j] )
				maxColLen[j] = num_length;
		}
	}

	for (auto& j: matrice_adjacence_)
	{
		for (int i = 0; i < j.size(); ++i)
		{
			std::cout << (i == 0 ? "\n| " : "") << std::setw((int)maxColLen[i]) << j[i] << (i == j.size() - 1 ? " |" : " ");
		}
	}
	std::cout << "\n";
}

int Graph::number_of_digits(int n)
{
	std::ostringstream str;
	str << n;
	return str.str().size();
}

int Graph::get_num_sommet() const
{
	return numSommet_;
}
const std::vector<std::vector<int>>& Graph::get_matrice_adjacence() const
{
	return matrice_adjacence_;
}
int Graph::get_start() const
{
	return start_;
}
int Graph::get_destination() const
{
	return destination_;
}
