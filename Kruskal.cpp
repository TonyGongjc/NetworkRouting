#include "Kruskal.h"
#include <queue>
#include <stack>


Kruskal::Kruskal(int capacity, UndirectedGraph G,int s, int t)
{
	p=vector<int>(capacity, 0);
	rank=vector<int>(capacity,0);
	T=vector<edge>(MaxNumber-1);
	EdgePush(G);
	cout<<"push finished!"<<endl;
	EdgeSort();
	cout<<"Sort finished!"<<endl;
//	cout<<"p size "<<p.size()<<"rank size "<<rank.size()<<endl;
	int j=0;
	for(int i=0; i<edges.size();i++)
	{
		int u=edges[i].start;
		int v=edges[i].end;
		int r1=Find(u);
		int r2=Find(v);
	//	cout<<"r1 "<<r1<<" r2 "<<r2<<" u "<<u<<" v "<<v<<endl;
		
		if(r1!=r2)
		{
			T[j]=edges[i];
			Union(r1,r2);
			j++;
		}
	}
	cout<<"Union finished!"<<endl;
	cout<<"Edge size "<<edges.size()<<"Tree size"<<T.size()<<endl;
	vector<bool>visited(MaxNumber,false);
	newG=newGraph();
	cout<<"new Graph created!"<<endl;
	DijkstraNoHeap DG;
	dad=DG.Dijkstra(G,s, t);
}



void Kruskal::Union(int r1, int r2)
{
	if (rank[r1]<rank[r2])
		p[r1]=r2;
	else if(rank[r1]>rank[r2])
		p[r2]=r1;
	else
	{
		p[r1]=r2;
		rank[r2]++;
	}
}

int Kruskal::Find(int v)
{
//	stack<int>Q;
	int w=v;
	while(p[w]!=0)
	{
//		Q.push(w);
		w=p[w];
	}
/*	while(!Q.empty())
	{
		int u = Q.top();
		Q.pop();
		p[u]=w;
	}
	*/
	return w;
}

void Kruskal::EdgeSort()
{
	for(int i=edges.size()/2; i>=0; i--)
	{
		Heap_build(i,edges.size());
	}
	for(int j =edges.size()-1; j>0; j--)
	{
		swap(0,j);
		Heap_build(0,j);
	}

}

void Kruskal::EdgePush(UndirectedGraph G)
{
	int length=MaxNumber;
	for(int i=0; i<length; i++)
	{		
		Edge* cur=G.Vertices[i].adj;
		while(cur!=nullptr)
		{
			int w=cur->destination;
			if(w>i){                         ////eliminate duplicated edges
				int weight=cur->weight;
				edge e;
				e.start=i; e.end=w; e.weight=weight;
				edges.push_back(e);
			}
			cur=cur->next;
		}
	}
}

void Kruskal::swap(int a, int b)
{
	edge temp=edges[a];
	edges[a]=edges[b];
	edges[b]=temp;
}

void Kruskal::Heap_build(int root, int length)
{
	int left_child=root*2+1;
	if(left_child<length)
	{
		int flag=left_child;
		int right_child=left_child+1;
		if(right_child<length)
		{
			if(edges[right_child].weight<edges[flag].weight)
			{
				flag=right_child;
			}
		}
		if(edges[root].weight>edges[flag].weight)
		{
			swap(root,flag);
			Heap_build(flag,length);
		}
	}
}



UndirectedGraph Kruskal::newGraph()
{
	UndirectedGraph newGraph;
	for(int i=0;i<T.size(); i++)
	{
		int first=T[i].start;
		int second=T[i].end;
		int weight=T[i].weight;
		
		Edge* edge=new Edge;
		edge->destination=first;
		edge->weight=weight;
		edge->next=NULL;
		
		
		Edge* edge2=new Edge;
		edge2->destination=second;
		edge2->weight=weight;
		edge2->next=NULL;

		Edge*cur = newGraph.Vertices[second].adj;
		Edge*cur2 = newGraph.Vertices[first].adj;

		if(cur==NULL)
		{
			cur=edge;
		}else
		{
			while(cur->next!=NULL)
			{
				cur=cur->next;
			}
			cur->next=edge;
		}
		
		if(cur2==NULL)
		{
			cur2=edge2;
		}else
		{
			while(cur2->next!=NULL)
			{
				cur2=cur2->next;
			}
			cur2->next=edge2;
		}
		
	}
	return newGraph;
}
void Kruskal::MakeSet(int capacity)
{
	p=vector<int>(capacity, 0);
	rank=vector<int>(capacity,0);
}


