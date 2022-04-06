#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 대기실 : 5개
// 응시자들 끼리 거리가 2 이하는 안됨.
// 응시자들 사이에 파티션이 있으면 2 이하도 가능
// 응시자 : P / 빈 테이블 : O / 파티션 : X 
// 거리두기를 지키고 있으면 1 아니면 0

#define MAX_ROW		5
#define MAX_COL		5

int visit[MAX_ROW][MAX_COL];
int P_check[MAX_ROW][MAX_COL];
char buff[MAX_ROW][MAX_COL];
bool fail_check;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


void Check_P(int sx, int sy, int cnt)
{
	visit[sx][sy] = 1;

	if(cnt > 2)
	{
		visit[sx][sy] = 0;
		return;	// P거리가 2 보다 크면 다 상관없음.
	}

	if(buff[sx][sy] == 'P' && cnt > 0 && P_check[sx][sy] == 0)
	{
		if(cnt < 3)     fail_check = true;	//누적거리가 3 이하면 실패

		P_check[sx][sy] = 1;	// P 위치 체크

		visit[sx][sy] = 0;
		return;
	}

	int nx, ny, k;
	
	for(k=0 ; k<4; k++)
	{
		nx = sx + dx[k];
		ny = sy + dy[k];

		if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && visit[nx][ny] == 0 
           && buff[nx][ny] != 'X')
		{
			Check_P(nx, ny, cnt+1);
		}
	}
	visit[sx][sy] = 0;
}

int* solution(const char*** places, size_t places_rows, size_t places_cols) {
    int i, x, y, z, cnt=0;
	int* answer = (int*)malloc(5);

	memset(answer, 0x00, sizeof(answer));

	for(z=0 ; z<5 ; z++)			//면
	{
		fail_check = false;
		
		memset(buff, 0x00, sizeof(buff));
		memset(visit, 0x00, sizeof(visit));
		memset(P_check, 0x00, sizeof(P_check));

		for(i=0 ; i<5; i++)
		{
			memcpy(buff[i], places[z][i], strlen(places[z][i]));
		}

		for(x=0 ; x<5 ; x++)		//열
		{
			for(y=0 ; y<5 ; y++)	//행
			{
				if(buff[x][y] == 'P')	//시작은 'P'일 경우만 시작.
				{
					Check_P(x, y, 0);
					memset(P_check, 0x00, sizeof(P_check));
				}
			}
		}

	if(fail_check == false)		answer[cnt++] = 1;
	else						answer[cnt++] = 0;

	}

    return answer;
}
