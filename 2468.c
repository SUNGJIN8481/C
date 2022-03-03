#include <stdio.h>
#include <string.h>

// N x N 크기의 배열 (2 <= N <= 100)
// 높이 : 1 이상 ~ 100 이하

// (DFS / 깊이우선탐색 / 스택)
// (BFS / 너비우선탐색 / 큐)

#define success 1
#define fail 	0

#define true	1
#define false	0

#define MAX_SIZE 100
int buff[MAX_SIZE+1][MAX_SIZE+1];
int DFS_Visit[MAX_SIZE+1][MAX_SIZE+1];
int N;
int cnt;

int DFS(int start, int end, int value)
{
	int i;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	DFS_Visit[start][end] = true;
//	printf("[%d][%d]/[%d]\n", start, end, buff[start][end]);

	if(buff[start][end] > value)
	{
		for(i=0 ; i<4 ; i++)
		{
			if(start+dy[i] < 0 || start+dy[i] > N || end+dx[i] < 0 || end+dx[i] > N)	continue;
			if(buff[start+dy[i]][end+dx[i]] > value && buff[start+dy[i]][end+dx[i]] <= 100 && DFS_Visit[start+dy[i]][end+dx[i]] == false)
			{
				DFS(start+dy[i], end+dx[i], value);
			}
		}
		return success;
	}
	else
		return fail;
}

int main(void)
{
	int i, j, h, result=0;

	memset(buff, 0x00, sizeof(buff));
	memset(DFS_Visit, 0x00, sizeof(DFS_Visit));

	scanf("%d", &N);

	for(j=0 ; j<N ; j++)
	{
		for(i=0 ; i<N ; i++)
		{
			scanf(" %d", &buff[j][i]);
		}
	}
/*
	for(j=0 ; j<N ; j++)
	{
		for(i=0 ; i<N ; i++)
		{
			printf("%d ", buff[j][i]);
		}
		printf("\n");
	}
*/

	for(h=0 ; h<=100 ; h++)	//높이 1 ~ 100까지 확인
	{
	//	printf("h: [%d]------------------------\n", h);
		cnt=0;
		memset(DFS_Visit, 0x00, sizeof(DFS_Visit));

		for(j=0 ; j<N ; j++)
		{
			for(i=0 ; i<N ; i++)
			{
				if(DFS_Visit[j][i] == false)
				{
					if(DFS(j, i, h) == success)
						cnt++;
				}
			}
		}
		if(result < cnt)	result = cnt;
	//	printf("cnt : %d\n", cnt);
	}
	printf("%d\n", result);
	return 0;
}