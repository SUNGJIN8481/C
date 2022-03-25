#include <stdio.h>
#include <string.h>

// 정사각형 4개
// 4 <= N,M <= 500

#define true 	1
#define false	0

#define MAX_SIZE 500
int buff[MAX_SIZE+1][MAX_SIZE+1];
int visit[MAX_SIZE+1][MAX_SIZE+1];
int N, M;
int result = 0;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void Solution(int sx, int sy, int sum, int cnt)
{
	if(cnt == 4)
	{
		result = (result < sum) ? sum : result;
		return;
	}
	
	int nx, ny, k;

	visit[sx][sy] = 1;
	
	for(k=0 ; k<4; k++)
	{
		nx = sx + dx[k];
		ny = sy + dy[k];

		if(nx >= 0 && ny >= 0 && visit[nx][ny] == 0)
		{
			Solution(nx, ny, sum + buff[sx][sy], cnt+1);
		}
	}
	visit[sx][sy] = 0;
}

void Other_Case(int sx, int sy)
{
	int temp =0, max = 0;

	if(sy-1 >= 0 && sy+1 <= M && sx-1 >= 0)
	{
		// ㅗ
		temp = buff[sx][sy] + buff[sx][sy-1] + buff[sx][sy+1] + buff[sx-1][sy];
		max = (temp > max)? temp : max;
	}
	if(sy+1 <= M && sx-1 >= 0 && sx+1 <= N)
	{
		// ㅏ
		temp = buff[sx][sy] + buff[sx-1][sy] + buff[sx][sy+1] + buff[sx+1][sy];
		max = (temp > max)? temp : max;
	}
	if(sy-1 >= 0 && sy+1 <= M && sx+1 <= N)
	{
		// ㅜ
		temp = buff[sx][sy] + buff[sx][sy-1] + buff[sx][sy+1] + buff[sx+1][sy];
		max = (temp > max)? temp : max;
	}
	if(sy-1 >= 0 && sx-1 >= 0 && sx+1 <= N)
	{
		// ㅓ
		temp = buff[sx][sy] + buff[sx][sy-1] + buff[sx-1][sy] + buff[sx+1][sy];
		max = (temp > max)? temp : max;
	}

	result = (result < max) ? max : result;
}

int main(void)
{
	int i, j, temp =0;

	memset(buff, 0x00, sizeof(buff));
	memset(visit, 0x00, sizeof(visit));

	scanf("%d %d", &N, &M);

	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<M ; j++)
		{
			scanf(" %d", &buff[i][j]);
		}
	}

/*
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j<m ; j++)
		{
			printf("%d ", buff[i][j]);
		}
		printf("\n");
	}
*/
	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<M ; j++)
		{
			Solution(i, j, 0, 0);
			Other_Case(i, j);
		}
	}
	
	printf("%d\n", result);	

	return 0;
}
