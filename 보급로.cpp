#include<cstdio>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n;
int map[101][101];
int chk[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; //상하좌우
bool is_in(int r, int c)
{
	if (1 <= r&&r <= n && 1 <= c&&c <= n)
	{
		return true;
	}
	return false;
}

void bfs(int r,int c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	chk[1][1] = 0;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || n < nx || ny < 1 || n < ny)
				continue;

			if (chk[nx][ny] > chk[x][y] + map[nx][ny])
			{
				chk[nx][ny] = chk[x][y] + map[nx][ny];
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1;tc<=T;tc++)
	{
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) 
			{
				scanf("%1d", &map[i][j]);
				chk[i][j] = 987654321;
			}
		}

		bfs(1, 1);

		printf("#%d %d\n", tc, chk[n][n]);
	}
	return 0;
}
