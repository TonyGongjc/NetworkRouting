#include <vector>

using namespace std;

struct HeapNode
{
	int v;
	int weight;
};

class MaxHeap
{
public:
	int size;
	int capacity;
	vector<int>pos;
	//vector<HeapNode*> array;
	vector<HeapNode> Nodes;

	MaxHeap(int capacity);
	bool isEmpty();
	//bool Delete(HeapNode* dNode);
	bool Delete(HeapNode dNode);
	
	void HeapifyDOWN(int index);
	void HeapifyUP(int index);
	//void Insert(HeapNode* iNode);
	void Insert(HeapNode iNode);
	void swap(int a, int b);
	//HeapNode* extractMax();
	HeapNode extractMax();
};