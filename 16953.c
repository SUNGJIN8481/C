#include <stdio.h>
#include <string.h>

// 2�� ���Ѵ�.
// 1�� ���� ���� �����ʿ� �߰��Ѵ�.
// 1 <= A < B <= 10^9)

int main(void)
{
	long A, B, cnt=1 ;

	scanf("%d %d", &A, &B);

	while(B > A)
	{
		if(B % 2 == 0)
		{
			B /= 2;
			cnt++;
		}
		else
		{
			if(B % 10 == 1)
			{
				B--;
				B /= 10;
				cnt++;
			}
			else
			{
				printf("-1\n");
				return 0;
			}
				
		}
	}

	if(A == B)	printf("%lu\n", cnt);
	else		printf("-1\n");
	
	return 0;
}