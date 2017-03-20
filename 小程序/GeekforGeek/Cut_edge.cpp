#include<stdio.h>
#include<string.h>
const int max_node = 201;
char a[max_node][max_node];//��¼���ͼ�еı�
int f[max_node], rank[max_node], father[max_node];
int g[max_node];
int n, m, pre_counter, post_counter;

void read_data()
{
	int x, y, z;
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	while (m--)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (z == 2)
		{
			a[x][y] = a[y][x] = 2;
		}
		else
		{
			a[x][y] = 1;
			a[y][x] = 1;
		}
	}
}

//��ָ���ڵ�u����������ȱ�������ͼ���ҳ����
void find_bridge(int u)
{
	int v;
	rank[u] = f[u];
	for (v = 1; v < n; v++)
	{
		if (!a[u][v])
			continue;
		if (f[v])
		{
			//���v�Ѿ�����չ��
			if (v != father[u])
			{
				if (f[u] < rank[u])
					rank[u] = f[v];
			}
		}
		else
		{
			//���vû�б���չ��
			father[v] = u;
			f[v] = f[u] + 1;
			find_bridge(v);
			if (rank[v] > f[u])
			{
				printf("%d %d 2\n", u, v);
				a[u][v] = a[v][u] = 0;
			}
			else if (rank[v] < rank[u])
				rank[u] = rank[v];
		}
	}
}

void dfs(int u)
{
	int v;
	f[u] = pre_counter++;
	rank[u] = f[u];
	for (v = 1; v <= n; v++)
	{
		if (a[u][v] <= 0)
			continue;
		if (f[v]) {
			if (f[v] < f[u] && v != father[u]) {
				if (a[u][v] == 2)
				{
					printf("%d $d 1 \n", u, v);//�ı���Ϊ˫���
				}
				if (g[v])
					rank[u] = 1;
				else if (f[v] < rank[u])
					rank[u] = f[v];
			}
		}
		else
		{
			//���v��û�б���չ�������u��v�ĸ��ף���v��ʼ�ݹ�����޸ı�
			father[v] = u;
			dfs(v);
			if (rank[v] <= f[u])
			{
				//��һ������һ����Ծ��
				if (a[u][v] == 2)
				{
					printf("%d %d 1 \n", u, v);
					a[v][u] = 0;
				}
				if (rank[v] < rank[u])
					rank[u] = rank[v];
			}
			else
			{
				printf("%d %d 1\n", v, u);
			}
		}
	}
	g[u] = post_counter++;
}

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int i;
	read_data();
	memset(f, 0, sizeof(f));
	f[1] = 1;
	find_bridge(1);
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	for (i = 1; i <= n; i++)
	{
		if (!f[i])
		{
			pre_counter = post_counter = 1;
			dfs(i);
		}
	}
	return 0;
}