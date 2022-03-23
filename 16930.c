#include <stdio.h>
#include <string.h>

// �Է� N(����), M(����), K (K = 1�ʿ� �̵��� �� �ִ� �ִ� ĭ ��)
// ����, �� �������� Kĭ�� �̵��� �� �ִ�.
// 2 �� N, M �� 1,000
// 1 �� K �� 1,000
// 1 �� x1, x2 �� N
// 1 �� y1, y2 �� M
// (x1, y1)���� (x2, y2)�� �̵��ϴ� �ּ� �ð��� ����Ѵ�. �̵��� �� ���� ��쿡�� -1�� ����Ѵ�.

#define true 	1
#define false	0

#define MAX_SIZE 1000
char buff[MAX_SIZE+1][MAX_SIZE+1];
int visit[MAX_SIZE+1][MAX_SIZE+1];

int N, M, K;

int BFS(int x1, int y1, int x2, int y2)
{
	int head=-1, tail=-1, cnt=0;
	int i, j, x=x1, y=y1, nx, ny;
	int queue[(MAX_SIZE*MAX_SIZE)+1][2];
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	memset(queue, 0x00, sizeof(queue));

	++tail;
	queue[tail][0] = x;
	queue[tail][1] = y;
	visit[x][y] = 1;	// 1 ���� �����Ͽ� ���ߵ�.

	while(head < tail)
	{
		++head;
		x = queue[head][0];
		y = queue[head][1];
	//	printf("---------check: [%d][%d]\n", x, y);
		cnt = visit[x][y];

	//	if(x == x2 && y == y2)	break;

		for(i=0 ; i<4 ; i++)	// �� ������� �� 4�������
		{
			for(j=1 ; j<=K ; j++)	// �ѹ������� �ִ� K��° ��������
			{
				nx = x+(dx[i]*j);
				ny = y+(dy[i]*j);
			//	printf("x : %d, y: %d \n", nx, ny);

				if(nx < 0 || nx > N || ny < 0 || ny > M)	break;

				if(buff[nx][ny] == '.')
				{
					if(visit[nx][ny] == 0)
					{
						++tail;
						queue[tail][0] = nx;
						queue[tail][1] = ny;
						visit[nx][ny] = visit[x][y] + 1;
					//	printf("q: [%d][%d]\n", nx, ny);
						if(nx == x2 && ny == y2)	return visit[nx][ny]-1;
					}
					else if(visit[nx][ny] <= visit[x][y])	break;	// ���� ������ ���� �ð��� �� ���ų�, ���ٸ� ���� �����ʴ´�. 
				}
				else
					break;
			}
		}
	}
	return -1;
}

int main(void)
{
	int i, j, result;
	int x1, y1, x2, y2;
	char input='\0';

	memset(buff, 0x00, sizeof(buff));
	memset(visit, 0x00, sizeof(visit));

	scanf("%d %d %d", &N, &M, &K);

	for(i=0 ; i<N ; i++)
	{
		scanf("%s", &buff[i+1][1]);
	}

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

/*
	for(i=0 ; i<N+3 ; i++)
	{
		for(j=0 ; j<M+3 ; j++)
		{
			printf("%c", buff[i][j]);
		}
		printf("\n");
	}
*/

	if((result = BFS(x1, y1, x2, y2)) <= 0)		printf("-1\n");
	else											printf("%d\n", result);

	return 0;
}