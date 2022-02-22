#include <stdio.h>
#include <stdlib.h>    // qsort �Լ��� ����� ��� ����

// 1 �� n �� 100000
// 1 �� x �� 2000000

/* -----------------------------------------------------------
������Ʈ ��� ��
-----------------------------------------------------------*/
/*
void ArraySwap(int *pArray, int n)
{
	int i, j, temp, start=0;

	for(j=start ; j<n-1 ; j++)
	{
		for(i=0 ; i<n-1 ; i++)
		{
			if(pArray[i] > pArray[i+1])
			{
				temp = pArray[i];
				pArray[i] = pArray[i+1];
				pArray[i+1] = temp;
			}
		}
		start++;
	}
}
*/

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
    int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
    int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

    if (num1 < num2)    // a�� b���� ���� ����
        return -1;      // -1 ��ȯ
    
    if (num1 > num2)    // a�� b���� Ŭ ����
        return 1;       // 1 ��ȯ
    
    return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int main()
{
	int i, cnt, sum, start, end, value=0, result=0;
	int Array[100000]={0, };

	// n = ���� ����
	scanf("%d", &cnt);

	// ����
	for(i=0 ; i<cnt ; i++)
	{
		scanf("%d", &Array[i]);
	}

	// x = �� ������ ��
	scanf("%d", &sum);

//	ArraySwap(Array,cnt);

	qsort(Array, cnt, sizeof(int), compare);
/*
	for(i=0 ; i<cnt ; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");
*/
	start = 0;
	end = cnt-1;
	
	while(start < end)
	{
		value = Array[start] + Array[end];
		
		if(value == sum)
		{
			result++;
		}
		
		if(value <= sum)	start++;
		else				end--;
	}

	printf("%d\n", result);
	return 0;
}
