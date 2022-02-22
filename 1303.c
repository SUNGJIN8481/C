#include <stdio.h>
#include <string.h>

// ������ ���� N (1 <= N <= 100)
// ������ ���� M (1 <= M <= 100)

#define true 	1
#define false	0

#define _fail		-1
#define _success	0

#define MAX_SIZE 100
char buff[MAX_SIZE+1][MAX_SIZE+1];
int DFS_Visit[MAX_SIZE+1][MAX_SIZE+1];

// ���� ��� üũ�ϰ� , �������� �� ã�������� ������� Ȯ�� ��, ���� Ȯ��.
// �湮üũ �ȵ� �͵鸸 �ٽ� DFS ����.
// DFS ���� ��, ������� üũ �ϰ� ����.

void DFS(int y, int x, char key)
{
	int i;
	DFS_Visit[y][x] = true;

	if(y > 0) //��
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
