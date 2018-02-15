#pragma once
#include "undirected_graph.h"

using namespace std;

enum Status
{
	unseen, fringe, intree
};

class DijkstraNoHeap
{
public:
	vector<int> Dijkstra(UndirectedGraph G, int s, int t);
};