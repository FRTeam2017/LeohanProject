#ifdef _ROT_ORANGE
#include<iostream>
#include<queue>
#define R 3
#define C 5
using namespace std;
bool isvalid(int i, int j)
{
	return (i >= 0 && j >= 0 && i < R && j < C);
}

struct ele
{
	int x, y;
};

bool isdelim(ele temp)
{
	return (temp.x == -1 && temp.y == -1);
}

//����Ƿ������ʵ�����
bool checkall(int arr[][C])
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 1)
				return true;
		}
	return false;
}

int rotOrange(int arr[][C])
{
	queue<ele> Q;
	ele temp;
	int ans = 0;

	//�����е������Ӽ��뵽������
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 2)
			{
				temp.x = i;
				temp.y = j;
				Q.push(temp);
			}
		}
	}

	temp.x = -1;
	temp.y = -1;
	Q.push(temp);//�����־�����ǲ�ͬ���֮��ķָ���

	while (!Q.empty())
	{
		bool flag = false;
		while (!isdelim(Q.front()))
		{
			temp = Q.front();
			if (isvalid(temp.x + 1, temp.y) && arr[temp.x + 1][temp.y] == 1)
			{
				//�����ұߵ����Ӽ���ĸ��õĶ�����
				if (!flag)
				{
					ans++;//���õ�ʱ��
					flag = true;
				}
				arr[temp.x + 1][temp.y] = 2;
				temp.x++;
				Q.push(temp);//�����õ����Ӽ��뵽�׶�����
				temp.x--;
			}
			if (isvalid(temp.x - 1, temp.y) && arr[temp.x - 1][temp.y] == 1)
			{
				if (!flag)
				{
					ans++;
					flag = true;
				}
				arr[temp.x - 1][temp.y] = 2;
				temp.x--;
				Q.push(temp);
				temp.x++;
			}
			if (isvalid(temp.x, temp.y + 1) && arr[temp.x][temp.y + 1] == 1)
			{
				if (!flag)
				{
					ans++;
					flag = true;
				}
				arr[temp.x][temp.y + 1] = 2;
				temp.y++;
				Q.push(temp);
				temp.y--;
			}
			if (isvalid(temp.x, temp.y - 1) && arr[temp.x][temp.y - 1] == 1)
			{
				if (!flag)
				{
					ans++;
					flag = true;
				}
				arr[temp.x][temp.y - 1] = 2;
				temp.y--;
				Q.push(temp);
			}
			Q.pop();
		}
		Q.pop();
		if (!Q.empty())
		{
			temp.x = -1;
			temp.y = -1;
			Q.push(temp);
		}
	}
	return (checkall(arr)) ? -1 : ans;
}

// Drive program
int main()
{
	int arr[][C] = { { 2, 1, 0, 2, 1 },
	{ 1, 0, 1, 2, 1 },
	{ 1, 0, 0, 2, 1 } };
	int ans = rotOrange(arr);
	if (ans == -1)
		cout << "All oranges cannot rot\n";
	else
		cout << "Time required for all oranges to rot => " << ans << endl;
	return 0;
}
#endif // _ROT_ORANGE