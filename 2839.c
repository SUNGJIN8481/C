#include <stdio.h>

// 3 <= N <= 50000

int Division(int n)
{
 	int i=0, m, r;

	i = n / 5;
	
	while(i >= 0)
	{
		r = n - (5*i);

	//	printf("i [%d] \n", i);
	//	printf("r [%d] \n\n", r);

		if(r != 0)
		{
			if((r % 3) == 0)
			{
				printf("%d\n", i + (r/3));
				return 0;
			}
			else
			{
				i--;
				if(i == 0)
				{
					if((n % 3) == 0)
					{
						printf("%d\n", n / 3);
						return 0;
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return -1;
}

int main(void)
{
	int n, result;
	int q_5, q_3, r_5, r_3;

	// ÀÔ·Â °ª
	scanf("%d", &n);

	if(Division(n) < 0)
		printf("-1\n");
	
	return 0;
}


