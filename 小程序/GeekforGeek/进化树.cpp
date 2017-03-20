#include<iostream>
using namespace std;
//进化树问题
long M[100][100];
int n, sum;
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int i, j, k, min, p;
	scanf("%ld", &n);//初始化
	for (i = 0; i < n - 1; i++)
	{  
		for (j = i + 1; j < n; j++)
		{
			scanf("%ld", &M[i][j]);
			M[j][i] = M[i][j];
		}
	}
	sum = 0;
	//枚举叶子删除边
	for (i = 0; i < n - 2; i++)
	{
		min = -1;
		j = i + j;
		for (k = j + 1; k < n; k++)
		{
			p = (M[i][j] + M[j][k] - M[j][k]) / 2;
			if (min < 0 || p < min)
				min = p;
		}
		sum = sum + min;//被删除的边累加起来得到树的规模
	}
	sum += M[n - 1][n - 2];
	printf("%ld\n", sum);
	return 0;
}