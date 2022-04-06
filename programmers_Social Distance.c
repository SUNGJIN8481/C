#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// ���� : 5��
// �����ڵ� ���� �Ÿ��� 2 ���ϴ� �ȵ�.
// �����ڵ� ���̿� ��Ƽ���� ������ 2 ���ϵ� ����
// ������ : P / �� ���̺� : O / ��Ƽ�� : X 
// �Ÿ��α⸦ ��Ű�� ������ 1 �ƴϸ� 0

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
		return;	// P�Ÿ��� 2 ���� ũ�� �� �������.
	}

	if(buff[sx][sy] == 'P' && cnt > 0 && P_check[sx][sy] == 0)
	{
		if(cnt < 3)     fail_check = true;	//�����Ÿ��� 3 ���ϸ� ����

		P_check[sx][sy] = 1;	// P ��ġ üũ

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

	for(z=0 ; z<5 ; z++)			//��
	{
		fail_check = false;
		
		memset(buff, 0x00, sizeof(buff));
		memset(visit, 0x00, sizeof(visit));
		memset(P_check, 0x00, sizeof(P_check));

		for(i=0 ; i<5; i++)
		{
			memcpy(buff[i], places[z][i], strlen(places[z][i]));
		}

		for(x=0 ; x<5 ; x++)		//��
		{
			for(y=0 ; y<5 ; y++)	//��
			{
				if(buff[x][y] == 'P')	//������ 'P'�� ��츸 ����.
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
