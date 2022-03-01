#include <stdio.h>
#include <string.h>

// N = ���α��� (1 <= N <= 100)
// M = ���α��� (1 <= N <= 100)
// K = ���Ĺ� ������ ����(1 <= K <= N x M)

// (DFS / ���̿켱Ž�� / ����)
// (BFS / �ʺ�켱Ž�� / ť)

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
		if(buff[x+dx[i]][y+dy[i]] == 1 && DFS_Visit[x+dx[i]][y+dy[i]] == false)	//���� 1�̰�, �湮���Ѱ��
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
			if(buff[i][j] == 1)	//�湮���� ���� ��츸 Ȯ��
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
