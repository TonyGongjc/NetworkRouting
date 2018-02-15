#include <vector>
#include "undirected_graph.h"
#include "DijkstraNoMH.h"

using namespace std;

struct edge
{
	int start;
	int end;
	int weight;
};
class Kruskal
{
public:
	vector<int>p;
	vector<int>rank;
	vector<edge>edges;
	vector<edge>T;
	UndirectedGraph newG;
	vector<int>dad;

	Kruskal(int capacity, UndirectedGraph G, int s, int t);
	void Union(int r1, int r2);
	int Find(int v);
	void MakeSet(int capacity);
	void EdgeSort();
	void EdgePush(UndirectedGraph G);
	void HeapSort(vector<edge>& edges);
	void swap(int a, int b);
	void Heap_build(int root, int length);
	UndirectedGraph newGraph();
};
