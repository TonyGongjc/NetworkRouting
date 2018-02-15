#include "MaxHeap.h"
#include <iostream>
#include <array>

MaxHeap::MaxHeap(int capacity)
{
	size=0;
	this->capacity=capacity;
	//this->array=vector<HeapNode*>(this->capacity,nullptr);
	pos=vector<int>(this->capacity,-1);
	vector<HeapNode> Nodes=vector<HeapNode>(this->capacity);
}

bool MaxHeap::isEmpty()
{
	return size==0;
}


void MaxHeap::HeapifyDOWN(int index)
{
	//cout<<"down"<<endl;
	int largest, left, right;
	largest = index;
	left = 2*index+1;
	right = 2*index+2;
	if(left<size && Nodes[left].weight> Nodes[largest].weight)
		largest=left;
	
	if(right<size && Nodes[right].weight > Nodes[largest].weight)
		largest=right;
	
	if(largest!=index)
	{
		swap(largest,index);
		HeapifyDOWN(largest);
	}
}



void MaxHeap::HeapifyUP(int index)
{
	//cout<<"up"<<endl;
	int parent=(index-1)/2;
	if(index == 0 || Nodes[index].weight<=Nodes[parent].weight)
		return;
	swap(index, parent);
	HeapifyUP(parent);
}


void MaxHeap::swap(int a, int b)
{
	//cout<<"swap"<<endl;
	HeapNode temp=Nodes[a];
	Nodes[a]=Nodes[b];
	Nodes[b]=temp;
	pos[Nodes[a].v]=a;
	pos[Nodes[b].v]=b;
}


void MaxHeap::Insert(HeapNode iNode)
{
	//cout<<"insert"<<endl;
	//cout<<size<<" "<<Nodes.size()<<endl;
	Nodes[size]=iNode;
	//cout<<"Nodes pass "<<iNode.v<<endl;
	pos[iNode.v]=size;
	HeapifyUP(size);
	size++;
};

bool MaxHeap::Delete(HeapNode dNode)
{
	//cout<<"delete"<<endl;
	int index=pos[dNode.v];
	if(index<0)return false;
	if(index==(size-1))
	{
		pos[dNode.v]=-1;
		size--;
		return true;
	}
	Nodes[index]=Nodes[size-1];
	pos[Nodes[index].v]=index;
	size--;
	int parent = (index-1)/2;
	if(Nodes[index].v>Nodes[parent].v && index!=0)
	{
		HeapifyUP(index);
	}else
	{
		HeapifyDOWN(index);
	}
	return true;
}

HeapNode MaxHeap::extractMax()
{
	//cout<<"extract"<<endl;
	if(isEmpty())
	{
		HeapNode node;
		return node;
	}	
	HeapNode maxNode=Nodes[0];
	Nodes[0]=Nodes[size-1];
	pos[Nodes[0].v]=0;
	size--;
	HeapifyDOWN(0);
	return maxNode;

}
