//
// Created by yassine on 23/04/2022.
//

#include <cstdint>
#include <algorithm>
#include <iostream>
#include "FordFulkerson.h"

/**
 * convertie un entier en un char debutant de 'A'
 *
 * @param i entier a convertir
 * @return 'A' + i
 */
inline char int_to_alphabet( int i )
{
	return static_cast<char>('A' + i);
}

/**
 * Constructeur de FordFulkerson
 * permet de génerer une matrice_flux_ qui est nessaissaire pour le calcul de flux inverse
 *
 * @param m reference vers un object de type Graph
 */
FordFulkerson::FordFulkerson(const Graph& m)
{
	for (const auto& i: m.get_matrice_adjacence())
	{
		std::vector<int> tmp(m.get_num_sommet(),0);
		matrice_flux_.push_back(tmp);
	}
}

/**
 * resolution avec l'algorithme de ford fulkerson
 *
 * @param m reference vers un object de type Graph
 * @return la valeur du flux maximal
 */
int FordFulkerson::ford_fulkerson(const Graph& m)
{
	int flux_max{0};	//flux_max initialiser a zero
	std::vector<bool> visited(m.get_num_sommet(), false);	//bool pour marquer les sommet visiter sert a eviter les cycles
	std::vector<int> traject;		//le trajet du point d'arriver vert le debut
	while (int min =depth_fist_search(m,m.get_start(),INT16_MAX,visited,traject))	//tanque min != 0
	{
		flux_max += min;
		print_traject(traject,min);
		std::replace(visited.begin(), visited.end(), true,false);	//renitialisation de visited
		traject.erase(traject.begin(), traject.end());
	}
	std::cout<<"La solution est :"<<(coupe_min(m,traject,flux_max)?"correcte":"fausse");	//ne sert a rien vue la nature du DFS
	return flux_max;
}

/**
 * permet de retrouver un chemain qui part du sommet de depart vers le sommet finale d'out le flux min est > 0
 *
 * @param m reference vers un object de type Graph
 * @param current_node	Le sommet actif (za3ma ina sommet 7na fih)
 * @param min	Le flux min qui peut traverser notre traject
 * @param visited	sert a marquer les sommet deja visiter afin d'évité la création de cycles
 * @param traject	le trajet du point d'arriver vert le debut
 * @return la valeur de min ou bien 0 si il n'existe pas de traject
 */
int FordFulkerson::depth_fist_search(const Graph& m, int current_node, int min, std::vector<bool>& visited, std::vector<int>& traject)
{
	visited[current_node] = true;	//on marque chaque sommet qu'on visite

	if (current_node == m.get_destination() || min == 0)	//si la destination est atteinte on retourne le min et on retrace notre chemin
	{
		traject.push_back(current_node);
		return min;
	}


	for (int i = 0; i < m.get_num_sommet(); ++i)
	{
		int cap_flux = m.get_matrice_adjacence()[current_node][i] - matrice_flux_[current_node][i]; //le flux possible avec un arret donner
		if (!visited[i] && cap_flux > 0)		//pour eviter de revisiter u sommet et min soit toujours != 0
		{
			if (int sent = depth_fist_search(m,i, std::min(min,cap_flux),visited,traject))
			{
				traject.push_back(current_node);	//retrassage du traject
				matrice_flux_[current_node][i] += sent;	//permet de signifier le flux utiliser dans l'arrete [current_node]->[i]
				matrice_flux_[i][current_node] -= sent;	//permet d'avoir la possibility du flux inverse
				return sent;
			}
		}
	}
	traject.push_back(current_node);	//s'il n'existe pas de chemin
	return 0;
}

/**
 * Imprime le trajet choisi avec le flux qui le traverse
 * @param traject le trajet du point d'arriver vert le debut
 * @param min flux min du traject
 */
void FordFulkerson::print_traject(std::vector<int>& traject, int min)
{

	for (int i = traject.size()-1; i >= 0 ; --i)	//on itére à l'inverse
	{
		if (i != 0)
			std::cout<<int_to_alphabet(traject[i])<<" -> ";
		else
			std::cout<<int_to_alphabet(traject[i])<<" : flux max local = "<<min<<std::endl;
	}
}

/**
 * permet d'assurer que la solution retrouver est correcte
 *
 * @param m reference vers un object de type Graph
 * @param traject  le trajet du point de blockage vert le debut
 * @param flux_max le flux max du graph
 * @return true ssi flum_max == sum
 */
bool FordFulkerson::coupe_min(const Graph& m, std::vector<int>& traject, int flux_max)
{
	int sum{0};
	std::vector<bool> valid(m.get_num_sommet(), false);
	for (const auto& i:traject)
	{
		valid.at(i) = true;
	}
	for (const auto& i:traject)
	{
		for (int j = 0; j < m.get_matrice_adjacence().at(0).size(); ++j)
		{
			sum += !valid[j]?m.get_matrice_adjacence()[i][j]:0;
		}
	}
	return sum == flux_max;
}
