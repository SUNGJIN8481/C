#include <stdio.h>
#include <string.h>

// 정사각형 4개
// 4 <= N,M <= 500

#define true 	1
#define false	0

#define MAX_SIZE 500
int buff[MAX_SIZE+1][MAX_SIZE+1];
int visit[MAX_SIZE+1][MAX_SIZE+1];	// 해당 지점에서 상하좌우 체크
int check[MAX_SIZE+1][MAX_SIZE+1];	// 지금까지 선택된 지점 체크
int N, M;

// 해당 지점에서, 가장 큰값을 찾아서 들어가고, 총 4개가 되었을 때 종료.
int Solution(int sx, int sy)
{
	int i, j;
	int tx, ty, nx, ny;
	int temp = 0; 
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	int total_1 = 0, result_1 = 0;	// 연속 모양 찾는 변수
	int total_2 = 0, result_2 = 5, cnt = 0;	// ㅗ 모양 찾는 변수
	int flag = false;
	
	total_1 = total_2 = buff[sx][sy];
	visit[sx][sy] = check[sx][sy] = 1;
//	printf("[%d][%d]------------[%d]\n", sx, sy, buff[sx][sy]);

	for(i=0 ; i<3; i++)
	{
		for(j=0 ; j<4; j++)
		{
			nx = sx + dx[j];
			ny = sy + dy[j];
		//	printf("[%d][%d]\n", nx, ny);

			if(nx >= 0 && ny >= 0)
			{
				if(flag == false)	// ㅗ 모양 검색 -> 처음 지점 네곳을 모두 더하고, 가장 작은값을 뺌(최대값 3군데만 더함)
				{
					cnt++;
					temp = buff[nx][ny];
				//	printf("----------------[%d]\n", buff[nx][ny]);
					total_2 += buff[nx][ny];
					if(result_2 > temp)	result_2 = temp;		//가장 작은 값
				}
				
				if(visit[nx][ny] == 0 && check[nx][ny] == 0)	// 연속 모양 검색
				{
					temp = buff[nx][ny];
					visit[nx][ny] = 1;
					if(result_1 < temp)
					{
						tx = nx;			//가장 큰 값의 x
						ty = ny;			//가장 큰 값의 y
						result_1 = temp;	//가장 큰 값
					}
				}
			}
		}
		
		if(flag == false)	// ㅗ 모양은 한번만 찾으면 됨.
		{
			if(cnt > 3)	total_2 = total_2 - result_2;	// 네지점 모두 더한곳에서 가장 작은값 뺌.
			flag = true;
		}
		
		sx = tx;		//값이 가장 컷던 곳부터 다시 시작.
		sy = ty;
		check[sx][sy] = 1;
	//	printf("[%d][%d]--------[%d]\n", sx, sy, result_1);
		total_1 += result_1;
		result_1 = 0;
		
		memset(visit, 0x00, sizeof(visit));
	}
//	printf("total_1----------------[%d]\n", total_1);
//	printf("total_2----------------[%d]\n", total_2);
	return (total_1 < total_2) ? total_2 : total_1;
}

int main(void)
{
	int i, j, temp =0, result = 0;

	memset(buff, 0x00, sizeof(buff));
	memset(visit, 0x00, sizeof(visit));
	memset(check, 0x00, sizeof(check));

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
			temp = Solution(i, j);
		//	printf("-------------temp : %d\n", temp);
			if(result < temp)	result = temp;
			memset(check, 0x00, sizeof(check));
		}
	}
	printf("%d\n", result);	

	return 0;
}
