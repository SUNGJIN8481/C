#include <stdio.h>
#include <string.h>

// N = 세로길이 (1 <= N <= 100)
// M = 가로길이 (1 <= N <= 100)
// K = 음식물 쓰레기 개수(1 <= K <= N x M)

// (DFS / 깊이우선탐색 / 스택)
// (BFS / 너비우선탐색 / 큐)

#define true	1
#define false	0

#define MAX_SIZE 100
int buff[MAX_SIZE+1][MAX_SIZE+1];
int DFS_Visit[MAX_SIZE+1][MAX_SIZE+1];
int N, M, K;
int result;

void DFS(int x, int y)
{
	int i;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	DFS_Visit[x][y] = true;
	result++;
//	printf("[%d][%d]\n", x, y);

	for(i=0 ; i<4 ; i++)
	{
		if(x+dx[i] < 0 || x+dx[i] > N || y+dy[i] < 0 || y+dy[i] > M)	continue;
		if(buff[x+dx[i]][y+dy[i]] == 1 && DFS_Visit[x+dx[i]][y+dy[i]] == false)	//값이 1이고, 방문안한경우
		{
			DFS(x+dx[i], y+dy[i]);
		}
	}
	
}

int main(void)
{
	int i, j, q;
	int temp=0;

	memset(buff, 0x00, sizeof(buff));
	memset(DFS_Visit, 0x00, sizeof(DFS_Visit));

	scanf("%d %d %d", &N, &M, &K);

	for(q=1 ; q<=K ; q++)
	{
		scanf("%d %d", &i, &j);
		buff[i][j] = 1;
	}
/*
	for(i=1 ; i<=N ; i++)
	{
		for(j=1 ; j<=M ; j++)
		{
			printf("%d ",buff[i][j]);
		}
		printf("\n");
	}
*/
	for(i=1 ; i<=N ; i++)
	{
		for(j=1 ; j<=M ; j++)
		{
			if(buff[i][j] == 1)	//방문한적 없는 경우만 확인
			{
				DFS(i, j);
			}
			if(temp < result)	temp = result;
			result = 0;
		}
	}
	printf("%d\n", temp);
	return 0;
}
