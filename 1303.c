#include <stdio.h>
#include <string.h>

// ������ ���� N (1 <= N <= 100)
// ������ ���� M (1 <= M <= 100)

#define true 	1
#define false	0

#define MAX_SIZE 100
char buff[MAX_SIZE+1][MAX_SIZE+1];
int DFS_Visit[MAX_SIZE+1][MAX_SIZE+1];
int N, M;
int result;

// ���� ��� üũ�ϰ� , �������� �� ã�������� ������� Ȯ�� ��, ���� Ȯ��.
// �湮üũ �ȵ� �͵鸸 �ٽ� DFS ����.
// DFS ���� ��, ������� üũ �ϰ� ����.

int DFS(int i, int j, char key)
{
	int cnt=0;
	DFS_Visit[i][j] = true;
//	printf("[%d][%d][%c]\n", i, j, key);

	if(j > 0)	//��
	{
		if(buff[i][j] == buff[i][j-1] && buff[i][j-1] == key && DFS_Visit[i][j-1] == false)
		{
		//	printf("-------------- left\n");
			cnt++;
			result += DFS(i, j-1, key);
		}
	}
	if(j < N)	//��
	{
		if(buff[i][j] == buff[i][j+1] && buff[i][j+1] == key && DFS_Visit[i][j+1] == false)
		{
		//	printf("-------------- right\n");
			cnt++;
			result += DFS(i, j+1, key);
		}
	}
	if(i > 0)	//��
	{
		if(buff[i][j] == buff[i-1][j] && buff[i-1][j] == key && DFS_Visit[i-1][j] == false)
		{
		//	printf("-------------- up\n");
			cnt++;
			result += DFS(i-1, j, key);
		}
	}
	if(i < M)	//��
	{
		if(buff[i][j] == buff[i+1][j] && buff[i+1][j] == key && DFS_Visit[i+1][j] == false)
		{
		//	printf("-------------- down\n");
			cnt++;
			result += DFS(i+1, j, key);
		}
	}
//	printf("result : %d \n", result);
	return cnt;
}

int main(void)
{
	int i, j;
	int result_w=0, result_b=0;
	int w=0, b=0;
	char input='\0';

	memset(buff, 0x00, sizeof(buff));
	memset(DFS_Visit, 0x00, sizeof(DFS_Visit));

	scanf("%d %d", &N, &M);

	for(i=0 ; i<M ; i++)
	{
		scanf("%s", buff[i]);
	}
/*
	for(i=0 ; i<M ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			printf("%c", buff[i][j]);
		}
		printf("\n");
	}
*/
	for(i=0 ; i<M ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			if(DFS_Visit[i][j] == false)
			{
				if(buff[i][j] == 'W')
				{
					result = 1;
					result_w = result + DFS(i, j, 'W');
					w += (result_w*result_w);
				//	printf("result_w: %d \n", result_w);
				}
				else
				{
					result = 1;
					result_b = result + DFS(i, j, 'B');
					b += (result_b*result_b);
				//	printf("result_b: %d \n", result_b);
				}
			}
		}
	}

	printf("%d %d\n", w, b);
	return 0;
}
