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
	int V, E;//图中顶点的数目和边的数目
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

//通过路径压缩技术来找元素i的集合
int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
	{
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

//求集合x和集合y的并集
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
		//如果两个集合的rank相同的话，将y集合添加到x集合中
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
	struct Edge * result = (struct Edge *)malloc(sizeof(struct Edge)*V);//存储最小生成树
	int e = 0;
	int i = 0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);//查询一下qsort
	struct subset * subsets = (struct subset *)malloc(V * sizeof(struct subset));
	for (int v = 0; v < V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	while (e < V-1)
	{
		struct Edge next_edge = graph->edge[i++];//因为边是经过排序的，所以每一次选择的都是当前\
		权重最小的边
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		//如果两条边与最小生成树没有形成circle，则将这条边添加到集合中
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