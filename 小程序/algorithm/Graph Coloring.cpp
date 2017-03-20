#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;
#ifdef GraphColoring
class Graph
{
	int V;
	list<int> * adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	~Graph()
	{
		delete[] adj;
	}

	void addEdge(int v, int w);

	void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
//为所有的节点赋予一种颜色，并且打印出颜色的分配
void Graph::greedyColoring()
{
	int * result = (int *)malloc(sizeof(int)*V);
	result[0] = 0;
	for (int u = 1; u < V; u++)
	{
		result[u] = -1;//这个时候其他节点还没有被着色
	}
	bool *avaiable = (bool *)malloc(sizeof(bool)*V);
	//用一个临时的数组来存储当前可以用的颜色
	for (int cr = 0; cr < V; cr++)
	{
		avaiable[cr] = false;
	}
	//为剩下的n-1个节点赋予颜色
	for (int u = 1; u < V; u++)
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (result[*i] != -1)//如果节点i已经被着色
				avaiable[result[*i]] = true;//被着的颜色已经被占用
		}
		//找到一种可以用的颜色
		int cr;
		for (cr = 0; cr < V; cr++)
		{
			if (avaiable[cr] == false)
				break;
		}
		result[u] = cr;

		for (i = adj[u].begin();i != adj[u].end();++i)
			if (result[*i] != -1)
				avaiable[result[*i]] = false;
	}
	for (int u = 0; u < V; u++)
	{
		cout << "Vertex " << u << "----> Color " << result[u] << endl;
	}
}

void GraphColorTesting()
{
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	cout << "Coloring of graph 1 \n";
	g1.greedyColoring();
}
#endif // GraphColoring

