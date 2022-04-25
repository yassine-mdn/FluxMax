//
// Created by yassine on 18/04/2022.
//

#ifndef FLUXMAX__GRAPH_H_
#define FLUXMAX__GRAPH_H_

#include<queue>
#include <list>




class Graph
{
 private:
	int numSommet_;            //le nombre de sommet
	std::vector<std::vector<int>> matrice_adjacence_;        //jutilise un pointeur sur des Listes chainer qui viene avec la bibliotheque list
	int start_;
	int destination_;

 public:
	explicit Graph(int numSommet);
	Graph();
	virtual ~Graph();
	void print();
	int number_of_digits(int n);
	int get_num_sommet() const;
	const std::vector<std::vector<int>>& get_matrice_adjacence() const;
	int get_start() const;
	int get_destination() const;
};

#endif //FLUXMAX__GRAPH_H_
