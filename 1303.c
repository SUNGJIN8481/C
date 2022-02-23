#include <stdio.h>
#include <string.h>

// 전쟁터 가로 N (1 <= N <= 100)
// 전쟁터 세로 M (1 <= M <= 100)

#define true 	1
#define false	0

#define MAX_SIZE 100
char buff[MAX_SIZE+1][MAX_SIZE+1];
int DFS_Visit[MAX_SIZE+1][MAX_SIZE+1];
int N, M;
int result;

// 시작 행렬 체크하고 , 같은병사 다 찾을때까지 인접행렬 확인 후, 개수 확인.
// 방문체크 안된 것들만 다시 DFS 진행.
// DFS 진행 시, 시작행렬 체크 하고 시작.

int DFS(int i, int j, char key)
{
	int cnt=0;
	DFS_Visit[i][j] = true;
//	printf("[%d][%d][%c]\n", i, j, key);

	if(j > 0)	//좌
	{
		if(buff[i][j] == buff[i][j-1] && buff[i][j-1] == key && DFS_Visit[i][j-1] == false)
		{
		//	printf("-------------- left\n");
			cnt++;
			result += DFS(i, j-1, key);
		}
	}
	if(j < N)	//우
	{
		if(buff[i][j] == buff[i][j+1] && buff[i][j+1] == key && DFS_Visit[i][j+1] == false)
		{
		//	printf("-------------- right\n");
			cnt++;
			result += DFS(i, j+1, key);
		}
	}
	if(i > 0)	//상
	{
		if(buff[i][j] == buff[i-1][j] && buff[i-1][j] == key && DFS_Visit[i-1][j] == false)
		{
		//	printf("-------------- up\n");
			cnt++;
			result += DFS(i-1, j, key);
		}
	}
	if(i < M)	//하
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
