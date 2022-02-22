#include <stdio.h>
#include <stdlib.h>    // qsort 함수가 선언된 헤더 파일

// 1 ≤ n ≤ 100000
// 1 ≤ x ≤ 2000000

/* -----------------------------------------------------------
투포인트 사용 문
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

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main()
{
	int i, cnt, sum, start, end, value=0, result=0;
	int Array[100000]={0, };

	// n = 원소 개수
	scanf("%d", &cnt);

	// 원소
	for(i=0 ; i<cnt ; i++)
	{
		scanf("%d", &Array[i]);
	}

	// x = 두 원소의 합
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
