/*
벌통들의 크기 3<=N<=10
선택할 수있는 벌통의 개수 1<=M<=5
M<=N
꿀을 채취할 수 있는 최대 양 10<=C<=30
하나의 벌통에서 채취할 수 있는 꿀의양 1<=X<=9

1. M개의 벌통을 겹치지않게 선택한다 2명이. 가로로 연속되도록 M개의벌통
2. M개의 벌통에서 꿀의 최대양이 C이하이게 벌통을 선택한다
3. PROFIT을 계산한다. 
*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, C, honey;
int bee[11][11];
int t[10][10];

//x, y, 벌통갯수, 꿀, 꿀양
void getHoney(int x, int y, int m, int h, int hh)
{
	//모은꿀이 C이상
	if (h > C)
	{
		return;
	}
	honey = max(honey, hh);
	//벌통이 m개 이상
	if (m + 1 > M)
	{
		return;
	}

	// pass
	getHoney(x, y + 1, m + 1, h, hh);

	// get
	getHoney(x, y + 1, m + 1, h + bee[x][y + 1], hh + bee[x][y + 1] * bee[x][y + 1]);
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		memset(bee, 0, sizeof(bee));
		memset(t, 0, sizeof(t));
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> bee[i][j];
			}
		}
		honey = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				getHoney(i, j - 1, 0, 0, 0);
				t[i][j] = honey;
				honey = 0;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				for (int x = 0; x < N; x++)
				{
					for (int y = 0; y <= N - M; y++)
					{
						if (i == x && (j - y)*(j - y) <= M*M)
						{
							continue;
						}
						honey = max(honey, t[i][j] + t[x][y]);
					}
				}
			}
		}
		printf("#%d %d\n", tc, honey);
	}
	return 0;
}
