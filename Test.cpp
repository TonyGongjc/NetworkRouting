#include "DijkstraHeap.h"
#include "Kruskal.h"
#include "DijkstraNoMH.h"
#include <time.h>

void PrintPath(int start, int end, vector<int>dad)
{
	int i=end;
		while(i!=start)
		{
			if(i==end)
				cout<<"The path begin with: "<<i<<" -> ";
			else if(dad[i]==start)
				cout<<i<<" -> "<<dad[i]<<" The path ends"<<endl;
			else
				cout<<i<<" -> ";
			i=dad[i];
		}
}

void main()
{
	
	UndirectedGraph G;
	DijkstraHeap DH;
	DijkstraNoHeap DJ;

	cout<<"Creating Graph"<<endl;
	G.Initialize();
	G.CreateGraph(5000, 15000,2);
//	G.PrintGraph();
	//int start_array[]={623,1,200,300,4000};
	//int end_aray[]={3700,30, 4500,139,221};
		
	for(int mm=0; mm<5;mm++){
		//int start=start_array[mm];
		//int end=end_aray[mm];
		srand(time(NULL));
		int start=rand()%5000;
		int end=rand()%5000;
		while(start==end)
		{
			start=rand()%5000;
			end=rand()%5000;
		}
		cout<<"\n"<<endl;
		cout<<"start point: "<<start<<" end point: "<<end<<endl;
		cout<<"Kruskal============================"<<endl;
		time_t begin, stop;
		begin=time(NULL);
		Kruskal kruskal(MaxNumber, G, start,end);
		kruskal.MakeSet(MaxNumber);
		vector<int>dad=kruskal.dad;
		PrintPath(start, end, dad);
		stop = time(NULL);
		long duration =stop - begin;
		printf("Use Time:%ld minutes, %ld seconds\n ",int(duration/60), duration%60);

		cout<<endl;
		cout<<"Dijkstra with heap================="<<endl;
		begin=time(NULL);
		vector<int>dad2=DH.DijkstraMaxHeap(G, start, end);
		PrintPath(start, end, dad2);
		stop = time(NULL);
		duration =stop - begin;
		printf("Use Time:%ld minutes, %ld seconds\n ",int(duration/60), duration%60);
		
		cout<<endl;
		cout<<"Dijakstra without heap============="<<endl;
		begin=time(NULL);
		vector<int>dad3=DJ.Dijkstra(G, start, end);
		PrintPath(start, end, dad3);
		stop = time(NULL);
		duration =stop - begin;
		printf("Use Time:%ld minutes, %ld seconds\n ",int(duration/60), duration%60);
	}

	system("pause");
	

}

