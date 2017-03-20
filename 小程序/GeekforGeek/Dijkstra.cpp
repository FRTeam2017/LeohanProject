/*
	地杰斯特拉算法
		问题描述
			计算从某一个确定的点到其它的点的最短的距离
*/
#include<iostream>
#include<limits.h>
using namespace std;
#define V 9

/*
	minDistance 实现了从没有包含在最短路径树中找到最短的边的操作
*/
#ifdef __dijkstra

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printSolution(int dist[], int n)
{
	cout << "Vertex Distance from Source" << endl;
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	//包含了从源点到终点i的最短路径的长度
	bool sptSet[V];
	//如果点i被包含在了最短路径中，那么点sptSet[i]的值为TRUE
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;

	//寻找所有节点的最短路径
	for (int count = 0; count < V; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
		{
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	printSolution(dist, V);
}

// driver program to test above function
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = {
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph, 0);

	return 0;
}
#endif // __dijkstra
