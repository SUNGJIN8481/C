#include <stdio.h>

// �� �ڿ��� N, K�� �־���
// N�� ��� ���� , K��°�� ���� �� ���



int main(void)
{
	int i=1, j=0, n, k;
	int d[10000] = {0, };

	// �Է� N ��
	scanf("%d", &n);

	// �Է� K ��
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
