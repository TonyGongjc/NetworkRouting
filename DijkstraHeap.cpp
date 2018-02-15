#include "DijkstraHeap.h"


vector<int> DijkstraHeap::DijkstraMaxHeap(UndirectedGraph G, int s, int t)
{
	MaxHeap maxHeap(MaxNumber);
	maxHeap.Nodes=vector<HeapNode>(MaxNumber*MaxNumber);
	Status status[MaxNumber];
	for(int i=0; i<MaxNumber; i++)
		status[i]=unseen;
	vector<int> dad(MaxNumber,-1);
	vector<int> bandwidth(MaxNumber,INT_MAX);
	
	status[s]=intree;
	Edge *cur=G.Vertices[s].adj;
	
	while(cur!=NULL)
	{
		int w=cur->destination;
		status[w]=fringe;
		bandwidth[w]=cur->weight;
		dad[w]=s;
		////////////////////////////////////
		HeapNode node;
		node.v=w;
		node.weight=bandwidth[w]; 
	//	cout<<"v= "<<node.v<<endl;
		maxHeap.Insert(node);
		////////////////////////////////////
		cur=cur->next;
	}

	while(status[t]!=intree)
	{
		HeapNode node=maxHeap.extractMax();
		int v=node.v;

		status[v]=intree;
	//	cout<<"checking vertex"<<v<<endl;
		Edge *curr=G.Vertices[v].adj;
		while(curr!=NULL)
		{
			int w=curr->destination;
			if (status[w]==unseen)
			{
				status[w]=fringe;
				dad[w]=v;
				bandwidth[w]=min(bandwidth[v], curr->weight);

				///////////////////
				node.v=w;
				node.weight=bandwidth[w];
				maxHeap.Insert(node);
			}
			else if(status[w]==fringe && bandwidth[w]<min(bandwidth[v], curr->weight))
			{
				node.v=w;
				node.weight=bandwidth[w];
				maxHeap.Delete(node);
				////////////////////////////////
				bandwidth[w]=min(bandwidth[v], curr->weight);
				dad[w]=v;
				///////////////////////////
				node.weight=bandwidth[w];
				maxHeap.Insert(node);
			}
			curr=curr->next;
		}
	}
	cout<<"max bandwidth is: "<<bandwidth[t]<<endl;
	return dad;
	
}

