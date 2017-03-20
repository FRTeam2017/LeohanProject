#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct Edge
{
	int src,
		dest,
		weight;
};
struct Graph
{
	int V, E;//ͼ�ж������Ŀ�ͱߵ���Ŀ
	struct Edge *edge;
};
struct Graph * createGraph(int V, int E)
{
	struct Graph * graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->E = E;
	graph->V = V;
	graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
	return graph;
}

//???
struct subset {
	int parent;
	int rank;
};

//ͨ��·��ѹ����������Ԫ��i�ļ���
int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
	{
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

//�󼯺�x�ͼ���y�Ĳ���
void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank)
	{
		subsets[xroot].parent = yroot;
	}
	else if (subsets[xroot].rank > subsets[yroot].rank)
	{
		subsets[yroot].parent = xroot;
	}
	else
	{
		//����������ϵ�rank��ͬ�Ļ�����y������ӵ�x������
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void * a, const void * b)
{
	struct Edge * a1 = (struct Edge *)a;
	struct Edge * b1 = (struct Edge *)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph * graph)
{
	int V = graph->V;
	struct Edge * result = (struct Edge *)malloc(sizeof(struct Edge)*V);//�洢��С������
	int e = 0;
	int i = 0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);//��ѯһ��qsort
	struct subset * subsets = (struct subset *)malloc(V * sizeof(struct subset));
	for (int v = 0; v < V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	while (e < V-1)
	{
		struct Edge next_edge = graph->edge[i++];//��Ϊ���Ǿ�������ģ�����ÿһ��ѡ��Ķ��ǵ�ǰ\
		Ȩ����С�ı�
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		//�������������С������û���γ�circle������������ӵ�������
	}
	cout << "Following are the edges in the constructed MST" << endl;
	for (i = 0; i < e; i++)
	{
		cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
	}
	return;
}

int Kruskal()
{
	/* Let us create following weighted graph
	10
	0--------1
	|  \     |
	6|   5\   |15
	|      \ |
	2--------3
	4       */
	int V = 4;  // Number of vertices in graph
	int E = 5;  // Number of edges in graph
	struct Graph* graph = createGraph(V, E);


	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;

	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;

	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;

	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 15;

	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	KruskalMST(graph);

	return 0;
}