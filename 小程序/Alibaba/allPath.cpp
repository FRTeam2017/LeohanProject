//找到所有路径应该是一个动态规划问题
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
	void printAllPathUtil(int s, int d,bool [],int [], int &,vector<int> necess);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void printAllPaths(int s, int d, vector<int> necess);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::printAllPaths(int s, int d,vector<int> necess)
{
	bool *visited = new bool[V];
	int *path = new int[V];
	int path_index = 0;
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	printAllPathUtil(s, d, visited, path, path_index,necess);
}

void Graph::printAllPathUtil(int u, int d, bool visited[], int path[], int &path_index, vector<int> necess)
{
	visited[u] = true;
	path[path_index] = u;
	path_index++;
	if (u == d)
	{
		int flag = 0;
		for (int i = 0; i < path_index; i++)
		{
			vector<int>::iterator position = std::find(necess.begin(), necess.end(), path[i]);
			if (position == necess.end()) // == myVector.end() means the element was not found
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			for (int i = 0; i < path_index; i++)
			{
				cout << path[i] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (!visited[*i])
			{
				printAllPathUtil(*i, d, visited, path, path_index, necess);
			}
		}
	}
	path_index--;
	visited[u] = false;
}

// Driver program
#ifdef __PATH_
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 0);
	g.addEdge(2, 1);
	g.addEdge(1, 3);
	vector<int> mess;
	mess.push_back(2);
	mess.push_back(1);
	mess.push_back(3);
	int s = 2, d = 3;
	cout << "Following are all different paths from " << s
		<< " to " << d << endl;
	g.printAllPaths(s, d, mess);
	return 0;
}
#endif