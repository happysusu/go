#include<cstdio>
#include<iostream>
using namespace std;
int n, m, r, c, l;
int map[51][51];
bool check[51][51] = {0};
int tn[8][4] = { {0,0,0,0}, {1,1,1,1},{1,1,0,0},{0,0,1,1},{1,0,0,1},{0,1,0,1},{0,1,1,0},{1,0,1,0} };
int cnt = 0;
bool is_in(int row, int col)
{
	if (0 <= row &&row <= n - 1 && 0 <= col&&col <= m - 1)
	{
		return true;
	}
	else
		return false;
}
bool calc(int row, int col, int time)
{
	if (time > l || is_in(row,col)==false)
	{
		return true;
	}
	
	if (check[row][col] == false)
	{
		check[row][col] = true;
		cnt++;

		if (tn[map[row][col]][0] == 1 && tn[map[row-1][col]][1]==1)
		{
			calc(row - 1, col, time + 1);
		}
		if (tn[map[row][col]][1] == 1 && tn[map[row + 1][col]][0] == 1)
		{
			calc(row + 1, col, time + 1);
		}
		if (tn[map[row][col]][2] == 1 && tn[map[row][col-1]][3] == 1)
		{
			calc(row, col - 1, time + 1);
		}
		if (tn[map[row][col]][3] == 1 && tn[map[row][col+1]][2] == 1)
		{
			calc(row, col + 1, time + 1);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &map[i][j]);
				check[i][j] = false;
			}
		}

		calc(r, c, 1);

		printf("#%d %d\n", tc, cnt);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d", check[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
