#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

const int MaxNumber=5000;
typedef string VerT;
typedef int Distance;

using namespace std;

struct Edge
{
	int destination;
	Distance weight;
	Edge *next;
};

struct Vertex
{
	VerT data;
	Edge *adj;
};

class UndirectedGraph
{
private:
	int numV;
	int numE;

public:
	UndirectedGraph();
	void CreateGraph(int n, int e, int kind);
	void PrintGraph();
	void Initialize();
	Vertex Vertices[MaxNumber];
};
inline UndirectedGraph::UndirectedGraph()
{
	for(int i=0; i<MaxNumber; i++)
	{
		Vertices[i].data="";
		Vertices[i].adj=NULL;
	}
	numE=0;
	numV=0;
}

inline void UndirectedGraph::Initialize()
{
	
	for(int k=0; k<MaxNumber-1;k++)
	{
		Distance we=rand()%6000;
		Edge *second=new Edge;
		second->destination=k+1;
		second->weight=we;
		second->next=NULL;

		Edge *first=new Edge;
		first->destination=k;
		first->weight=we;
		first->next=NULL;
		if(this->Vertices[k].adj==NULL){
			this->Vertices[k].adj=second;
		}
		else
		{
			this->Vertices[k].adj->next=second;
		}
		this->Vertices[k+1].adj=first;
	}
	//connect first and last vertex
	Distance we=rand()%6000;
	Edge *second=new Edge;
	second->destination=0;
	second->weight=we;
	second->next= Vertices[MaxNumber-1].adj;

	Edge *first=new Edge;
	first->destination=MaxNumber-1;
	first->weight=we;
	first->next=NULL;

	this->Vertices[0].adj->next=first;
	this->Vertices[MaxNumber-1].adj=second;

}

inline void UndirectedGraph::CreateGraph(int n, int e, int kind)
{
	int vi, vj;
	Distance w;
	numV=n;
	numE=e;
	Initialize();
	
	if(kind = 1){
		for(int j=0; j<numE; j++)
		{
			vi=rand()%5000;
			vj=rand()%5000;
			if(vi==vj) continue;
			w=rand()%6000;
			Edge *q= new Edge;
			q->destination=vj;
			q->weight=w;
			q->next=NULL;
			/*if(Vertices[vi].adj==NULL)
				Vertices[vi].adj=q;
			else
			{ */
			Edge *cur=Vertices[vi].adj;
			Edge *pre =NULL;
			while(cur!=NULL && cur->destination<vj)
			{
				pre=cur;
				cur=cur->next;
			}
			if(pre==NULL)
			{
				q->next=Vertices[vi].adj;
				Vertices[vi].adj=q;
			}
			else
			{
				q->next=pre->next;
				pre->next=q;
			}
			

			Edge *p= new Edge;
			p->destination=vi;
			p->weight=w;
			p->next=NULL;
			if(Vertices[vj].adj==NULL)
				Vertices[vj].adj=p;
			else
			{
				Edge *cur=Vertices[vj].adj;
				Edge *pre =NULL;
				while(cur!=NULL && cur->destination<vi)
				{
					pre=cur;
					cur=cur->next;
				}
				if(pre==NULL)
				{
					p->next=Vertices[vj].adj;
					Vertices[vj].adj=p;
				}
				else
				{
					p->next=pre->next;
					pre->next=p;
				}
			}
		}
	}
}

inline void UndirectedGraph::PrintGraph()
{
	Edge *cur;
	cout<<"The vertices and edges are: "<<endl;
	for(int i=0; i<MaxNumber; i++)
	{
		cur=Vertices[i].adj;
		while(cur!=NULL)
		{
			cout<<"Vertex "<<i<<" "<<"to "<<cur->destination<<" weight is: "<<cur->weight<<endl;
			
			cur=cur->next;
		}
		cout<<endl;
	}
	
}






void main()
{

	UndirectedGraph G;
	G.CreateGraph(5000, 15000,1);
	G.PrintGraph();
	system("pause");
}