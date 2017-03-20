/*求出一个图的割边*/
#include<iostream>
#include<list>
#include<math.h>
#include<algorithm>
#define NIL -1
using namespace std;
class Gaph
{
public:
	Gaph(int V);
	void addEdge(int v, int w);
	void bridge();
private:
	int V;//图中节点的个数
	list<int> * adj;
	void  bridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);

};

Gaph::Gaph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Gaph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

//使用深度优先遍历找到割边
void Gaph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
	static int time = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;
		if (!visited[v])
		{
			parent[v] = u;
			bridgeUtil(v, visited, disc, low, parent);
			low[u] = min(low[u], low[v]);
			if (low[v] > disc[u])
				cout << u << " " << v << endl;
		}
		else if (v != parent[u])
		{
			low[u] = min(low[u], disc[v]);
		}
	}
}

void Graph::bridge()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];

	// Initialize parent and visited arrays
	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
	}

	// Call the recursive helper function to find Bridges
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			bridgeUtil(i, visited, disc, low, parent);
}

