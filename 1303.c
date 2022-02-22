#include <stdio.h>
#include <string.h>

// 전쟁터 가로 N (1 <= N <= 100)
// 전쟁터 세로 M (1 <= M <= 100)

#define true 	1
#define false	0

#define _fail		-1
#define _success	0

#define MAX_SIZE 100
char buff[MAX_SIZE+1][MAX_SIZE+1];
int DFS_Visit[MAX_SIZE+1][MAX_SIZE+1];

// 시작 행렬 체크하고 , 같은병사 다 찾을때까지 인접행렬 확인 후, 개수 확인.
// 방문체크 안된 것들만 다시 DFS 진행.
// DFS 진행 시, 시작행렬 체크 하고 시작.

void DFS(int y, int x, char key)
{
	int i;
	DFS_Visit[y][x] = true;

	if(y > 0) //상
	{
		if(buff[y][x] == buff[y-1][x] == key && DFS_Visit[y][x] == false)	DFS(y-1, x, key);
	}
	if(y < )
}

int main(void)
{
	int x, y, N, M;
	int result_w, result_b;
	char input='\0';

	memset(buff, 0x00, sizeof(buff));
	memset(DFS_Visit, 0x00, sizeof(DFS_Visit));

	scanf("%d %d", &N, &M);
	
	for(y=0 ; y<M ; y++)
	{
		for(x=0 ; x<N ; x++)
		{
			scanf(" %c", &input);
			if(input == 'W')	buff[y][x] = 'W';
			else				buff[y][x] = 'B';
		}
	}

	for(y=0 ; y<M ; y++)
	{
		for(x=0 ; x<N ; x++)
		{
			if(buff[y][x] == 'W')	DFS(y, x, 'W');
			else					DFS(y, x, 'B');
		}
	}
	
	return 0;
}
