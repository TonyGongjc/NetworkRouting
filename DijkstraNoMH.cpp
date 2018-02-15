#pragma once
#include "DijkstraNoMH.h"


vector<int> DijkstraNoHeap::Dijkstra(UndirectedGraph G, int s, int t)
{
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
		cur=cur->next;
	}

	while(status[t]!=intree)
	{
		int max_bw=-1;
		int v=-1;
		for(int i=0; i<MaxNumber;i++)
		{
			if(status[i]==fringe && bandwidth[i]>max_bw)
			{
				max_bw=bandwidth[i];
				v=i;
			}
		}
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
			}
			else if(status[w]==fringe && bandwidth[w]<min(bandwidth[v], curr->weight))
			{
				bandwidth[w]=min(bandwidth[v], curr->weight);
				dad[w]=v;
			}
			curr=curr->next;
		}
	}
	cout<<"max bandwidth is: "<<bandwidth[t]<<endl;
	return dad;
}
