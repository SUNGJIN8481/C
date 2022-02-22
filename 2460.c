#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	int in[10], out[10], result[10], r=0;

	memset(in, 0x00, sizeof(in));
	memset(out, 0x00, sizeof(out));
	memset(result, 0x00, sizeof(result));
	
	for(i=0 ; i<10 ; i++)
		scanf("%d %d", &out[i], &in[i]);

	result[0] = in[0];

	for(i=1 ; i<10 ; i++)
	{
		result[i] = result[i-1] - out[i] + in[i];
		if(r < result[i])	r = result[i];
	}

	printf("%d", r);

	return 0;	
}
