/*
	问题描述 弗洛伊德算法
		算法的目的  在一个图中，找到任意两个点之间的最短距离
*/
#ifdef _Floyd
#include<iostream>
using namespace std;
#define V 4
#define INF 99999

void printSolution(int dist[][V])
{
	cout << "Following matrix shows the shortest distances between every pair vertices" << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				cout << "INF" << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

void floydWarshall(int graph[][V])
{
	int ** dist = (int **)malloc(sizeof(int *)*V);
	for (int i = 0; i < V; i++)
	{
		dist[i] = (int *)malloc(sizeof(int)*V);
	}
	int i, j, k;
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] = dist[k][j];
				}
			}
		}
	}
	printSolution(graph);
}
// driver program to test above function
int main()
{
	/* Let us create the following weighted graph
	10
	(0)------->(3)
	|         /|\
	5 |          |
	|          | 1
	\|/         |
	(1)------->(2)
	3           */
	int graph[V][V] = { { 0,   5,  INF, 10 },
	{ INF, 0,   3, INF },
	{ INF, INF, 0,   1 },
	{ INF, INF, INF, 0 }
	};
	floydWarshall(graph);
	// Print the solution
	return 0;
}
#endif // _Floyd