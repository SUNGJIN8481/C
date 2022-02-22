#include <stdio.h>
#include <string.h>

// ������ȣ�� �����ͺ��� �湮. 
// �湮�� ���� ���� ��� ����
// ������ȣ : 1 ~ N

// ������ ���� N (1 <= N <= 1000)
// ������ ���� M (1 <= M <= 10000)
// �������� V

// (DFS / ���̿켱Ž�� / ����)
// (BFS / �ʺ�켱Ž�� / ť)

#define true 	1
#define false	0

#define _fail		-1
#define _success	0

#define MAX_SIZE 1000
int buff[MAX_SIZE+1][MAX_SIZE+1];

int DFS_Visit[MAX_SIZE+1];
int BFS_Visit[MAX_SIZE+1];
int queue[MAX_SIZE+1];

#if 0
// ���� ���� 
int top = -1;
int stack[MAX_SIZE];


int IsEmpty(void)
{
	if(top < 0)		return true;
	else			return false;
}

int IsFull(void)
{
	if(top >= (MAX_SIZE-1))		return true;
	else						return false;
}

void Push(int value)
{
	if(IsFull())	printf("Is Full \n");
	else			stack[top++] = value;
}

int Pop(void)
{
	if(IsEmpty())	printf("Is Empty\n");
	else			return stack[top--];
}

// ���� ť ���� (����ť�� �Ź� ������ ����� �Ѵٴ� ������ ����)
int head = -1;
int tail = -1;
int queue[MAX_SIZE];

int Is_Full(void)
{
	//���� ť���� tail+1 �� MAX�� �����µ�, head�� ������ ���� ť�� FULL ����
	if((tail+1)%MAX_SIZE == head)	return true;
	else							return false;
}

int Is_Empty(void)
{
	if(head == tail)	return true;
	else				return false;
}

int AddQueue(int value)
{
	if(Is_Full())
	{
		return _fail;
	}
	else
	{
		tail = (tail+1)%MAX_SIZE;
		queue[tail] = value;
		return _success;
	}
}

int DeleteQueue()
{
	if(Is_Empty())
	{
		return _fail;
	}
	else
	{
		head = (head+1)%MAX_SIZE;
		return queue[head];
	}
}

#endif


void DFS(int start, int N)
{
	int end;
	DFS_Visit[start] = true;	//�湮üũ
	printf("%d ", start);

	for(end=1 ; end<=N ; end++)
	{
		if(buff[start][end] == true && DFS_Visit[end] == false)	// ������ ��尡 �����鼭, �湮���� ���� ��츸
			DFS(end, N);	// DFS Ž������
	}
	printf("1111 %d\n", end);
}

void BFS(int start, int N)
{
	int head=-1, tail=-1;
	int end, check;

	memset(queue, 0x00, sizeof(queue));
	
	BFS_Visit[start] = true;	//�湮üũ
	queue[++tail] = start;		//ť�� ���۳�� �߰�
	printf("%d ", start);

	while(head < tail)
	{
		check = queue[++head];

		for(end=1 ; end<=N ; end++)
		{
			if(buff[check][end] == true && BFS_Visit[end] == false)	// ������ ��尡 �����鼭, �湮���� ���� ��츸
			{
				BFS_Visit[end] = true;
				queue[++tail] = end;	//ť�� ��� �߰�
				printf("%d ", end);
			}
		}
	}
}

int main(void)
{
	int i, x, y;
	int N, M, Start;

	memset(DFS_Visit, 0x00, sizeof(DFS_Visit));
	memset(BFS_Visit, 0x00, sizeof(BFS_Visit));

	scanf("%d %d %d", &N, &M, &Start);

	for(i=0 ; i<M ; i++)
	{
		scanf("%d %d", &x, &y);
		buff[x][y] = 1;
		buff[y][x] = 1;
	}

	DFS(Start, N);
	printf("\n");
	BFS(Start, N);
	printf("\n");
	return 0;
}
