//
// Created by yassine on 18/04/2022.
//

#include <iostream>
#include <iomanip>
#include "Graph.h"

/**
 * convertie un entier en un char debutant de 'A'
 *
 * @param i entier a convertir
 * @return 'A' + i
 */
inline char int_to_alphabet(int i)
{
	return static_cast<char>('A' + i);
}

/**
 * Constructeur avec param permet a l'utilisateur de génerer sa propre matrice_adjacence_
 * @param numSommet numero de sommet
 */
Graph::Graph(int numSommet) : numSommet_{ numSommet }
{
	for (int i = 0; i < numSommet_; ++i)
	{
		std::vector<int> tmp(numSommet_, 0);
		matrice_adjacence_.push_back(tmp);
	}
	for (int i = 0; i < numSommet_; ++i)
	{
		for (int j = 0; j < numSommet_; ++j)
		{
			std::cout << "se trouve t\'il un aret de " << int_to_alphabet(i) << " vers " << int_to_alphabet(j)
					  << " ?y:n" << std::endl;
			char c{};
			std::cin >> c;
			if (c == 'y')
			{
				int temp;
				std::cout << "poid de l\'arrete :" << std::endl;
				std::cin >> temp;
				matrice_adjacence_[i][j] = temp;
			}
		}
	}
	std::cout << "Le Sommet source est :" << std::endl;
	std::cin >> start_;
	std::cout << "Le Sommet destination est :" << std::endl;
	std::cin >> destination_;
}

/**
 * Constructeur vide crée pour des raison de debugage/test
 */
Graph::Graph()
{

	numSommet_ = 10;
	matrice_adjacence_.resize(numSommet_);
	matrice_adjacence_ = {{0,20,40,30,0,0,0,0,0,0},
						  {0,0,0,0,4,0,25,0,0,0},
						  {0,0,0,0,35,10,0,0,0,0},
						  {0,0,0,0,0,15,0,0,20,0},
						  {0,0,0,0,0,0,5,20,0,0},
						  {0,0,0,0,0,0,0,10,20,0},
						  {0,0,0,0,0,0,0,0,0,27},
						  {0,0,0,0,0,0,15,0,6,15},
						  {0,0,0,0,0,0,0,0,0,50},
						  {0,0,0,0,0,0,0,0,0,0}};
	start_ = 0;
	destination_ = 9;
}

/**
 * Destructeur par default
 */
Graph::~Graph()
{

}

/**
 * Methode qui permet d'afficher notre graphe sous forme de matrice d'adjacence dans le terminale
 */
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
			if (num_length > maxColLen[j])
				maxColLen[j] = num_length;
		}
	}

	for (auto& j: matrice_adjacence_)
	{
		for (int i = 0; i < j.size(); ++i)
		{
			std::cout << (i == 0 ? "\n| " : "") << std::setw((int)maxColLen[i]) << j[i]
					  << (i == j.size() - 1 ? " |" : " ");
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
