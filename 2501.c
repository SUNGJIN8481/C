#include <stdio.h>

// 두 자연수 N, K가 주어짐
// N의 약수 들중 , K번째로 작은 수 출력



int main(void)
{
	int i=1, j=0, n, k;
	int d[10000] = {0, };

	// 입력 N 값
	scanf("%d", &n);

	// 입력 K 값
	scanf("%d", &k);
	
	while(i <= n)
	{
	//	printf("i [%d]\n", i);
		if((n % i) == 0)
			d[j++] = i;
		i++;
	}

	printf("%d", d[k-1]);

	return 0;
}
