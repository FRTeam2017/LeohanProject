#include<iostream>
#include<list>
#include<stack>

using namespace std;
#ifdef _toplogicSort

class Graph
{
	int V;
	list<int> * adj;
	void topologicSortUtil(int v, bool visited[], stack<int> &Stack);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topologicSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i])
			topologicSortUtil(*i, visited, Stack);
	}
	Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;

	//标记所有没有被访问的节点
	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
			topologicSortUtil(i, visited, Stack);
	}

	while (Stack.empty()==false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int Toplogic()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();

	return 0;
}
#endif // _toplogicSort
