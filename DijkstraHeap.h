#pragma once
#include "undirected_graph.h"
#include "MaxHeap.h"
#include "DijkstraNoMH.h"

using namespace std;

class DijkstraHeap
{
public:
	MaxHeap* maxHeap;

	HeapNode* VtoNode(int w, vector<int>bandwidth);
	vector<int> DijkstraMaxHeap(UndirectedGraph G, int s, int t);
};