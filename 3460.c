#include <stdio.h>
#include <string.h>

// 1 <= t <= 10
// 1 <= n <= 10ÀÇ6½Â

int main(void)
{
	int i=0, j, k, t, n, q, r;
	int b[100] = {0, };
	
	scanf("%d", &t);

	for(k=0 ; k<t ; k++)
	{
		scanf("%d", &n);

		i=0;
		j=0;
		q = n;
		memset(b, 0x00, sizeof(b));

		while(q > 0)
		{
			r = q % 2;
			if(r == 1)	b[i++] = 1;
			else		b[i++] = 0;
			q = q / 2;
		}

		for(j=0 ; j<i ; j++)
		{
			if(b[j] == 1)
				printf("%d ", j);
		}
		printf("\n");
	}

	return 0;
}
