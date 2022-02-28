#include <stdio.h>
#include <string.h>

// N x M 크기의 배열 (2 <= N,M <= 100)
// 1은 이동가능, 0은 이동 불가능
// (1,1) 출발-> (N,M) 도착까지 이동하는 최소 칸 수

// (DFS / 깊이우선탐색 / 스택)
// (BFS / 너비우선탐색 / 큐)

#define MAX_SIZE 100
char buff[MAX_SIZE+1][MAX_SIZE+1];

int BFS_Visit[MAX_SIZE+1][MAX_SIZE+1];
int N, M;

int BFS(void)
{
	int head=-1, tail=-1, cnt=0;
	int i, x=0, y=0;
	char queue[(MAX_SIZE*MAX_SIZE)+1][2];
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	memset(queue, 0x00, sizeof(queue));

	++tail;
	queue[tail][0] = x;
	queue[tail][1] = y;
	BFS_Visit[x][y] = 1;

	while(head < tail)
	{
		++head;
		x = queue[head][0];
		y = queue[head][1];
	//	printf("---------check: [%d][%d]\n", x, y);
		cnt = BFS_Visit[x][y];

		if(x == N-1 && y == M-1)	break;

		for(i=0 ; i<4 ; i++)
		{
		//	printf("x : %d, y: %d \n", x+dx[i], y+dy[i]);
			if(x+dx[i] < 0 || x+dx[i] > N || y+dy[i] < 0 || y+dy[i] > M)	continue;
			if(buff[x+dx[i]][y+dy[i]] == '1' && BFS_Visit[x+dx[i]][y+dy[i]] == 0)
			{
				++tail;
				queue[tail][0] = x+dx[i];
				queue[tail][1] = y+dy[i];
				BFS_Visit[x+dx[i]][y+dy[i]] = BFS_Visit[x][y] + 1;
			//	printf("q: [%d][%d]\n", x+dx[i], y+dy[i]);
			}
		}
	}
	return cnt;
}

int main(void)
{
	int i, j, result;

	memset(buff, 0x00, sizeof(buff));
	memset(BFS_Visit, 0x00, sizeof(BFS_Visit));

	scanf("%d %d", &N, &M);

	for(i=0 ; i<N ; i++)
	{
		scanf("%s", buff[i]);
	}

	result = BFS();
	printf("%d\n", result);
	return 0;
}
