#include <stdio.h>
#include <string.h>

// 정점번호가 작은것부터 방문. 
// 방문할 점이 없는 경우 종료
// 정점번호 : 1 ~ N

// 정점의 개수 N (1 <= N <= 1000)
// 간선의 개수 M (1 <= M <= 10000)
// 시작정점 V

// (DFS / 깊이우선탐색 / 스택)
// (BFS / 너비우선탐색 / 큐)

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
// 스택 구현 
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

// 원형 큐 구현 (선형큐는 매번 정렬을 해줘야 한다는 단점이 있음)
int head = -1;
int tail = -1;
int queue[MAX_SIZE];

int Is_Full(void)
{
	//원형 큐에서 tail+1 을 MAX로 나눴는데, head랑 같으면 현재 큐는 FULL 상태
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
	DFS_Visit[start] = true;	//방문체크
	printf("%d ", start);

	for(end=1 ; end<=N ; end++)
	{
		if(buff[start][end] == true && DFS_Visit[end] == false)	// 인접한 노드가 있으면서, 방문하지 않은 경우만
			DFS(end, N);	// DFS 탐색진행
	}
	printf("1111 %d\n", end);
}

void BFS(int start, int N)
{
	int head=-1, tail=-1;
	int end, check;

	memset(queue, 0x00, sizeof(queue));
	
	BFS_Visit[start] = true;	//방문체크
	queue[++tail] = start;		//큐에 시작노드 추가
	printf("%d ", start);

	while(head < tail)
	{
		check = queue[++head];

		for(end=1 ; end<=N ; end++)
		{
			if(buff[check][end] == true && BFS_Visit[end] == false)	// 인접한 노드가 있으면서, 방문하지 않은 경우만
			{
				BFS_Visit[end] = true;
				queue[++tail] = end;	//큐에 노드 추가
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
