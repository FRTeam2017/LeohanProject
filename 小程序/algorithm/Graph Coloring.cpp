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
//Ϊ���еĽڵ㸳��һ����ɫ�����Ҵ�ӡ����ɫ�ķ���
void Graph::greedyColoring()
{
	int * result = (int *)malloc(sizeof(int)*V);
	result[0] = 0;
	for (int u = 1; u < V; u++)
	{
		result[u] = -1;//���ʱ�������ڵ㻹û�б���ɫ
	}
	bool *avaiable = (bool *)malloc(sizeof(bool)*V);
	//��һ����ʱ���������洢��ǰ�����õ���ɫ
	for (int cr = 0; cr < V; cr++)
	{
		avaiable[cr] = false;
	}
	//Ϊʣ�µ�n-1���ڵ㸳����ɫ
	for (int u = 1; u < V; u++)
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			if (result[*i] != -1)//����ڵ�i�Ѿ�����ɫ
				avaiable[result[*i]] = true;//���ŵ���ɫ�Ѿ���ռ��
		}
		//�ҵ�һ�ֿ����õ���ɫ
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

