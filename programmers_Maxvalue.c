#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENTH	100000
#define MAX_SIZE	1000

int compare(const void *a, const void *b)
{
	int temp_a = *(int *)a;
	int temp_b = *(int *)b;
	
	int len_a, len_b, ret;
	char str_a[4+1] = {0, };
	char str_b[4+1] = {0, };
	char temp[2][8+1] = {0, };

	//숫자를 문자열로
	sprintf(str_a, "%d", temp_a);
	sprintf(str_b, "%d", temp_b);

	len_a = strlen(str_a);
	len_b = strlen(str_b);

	// a 뒤에 b 붙이기
	memcpy(temp[0], str_a, len_a);
	memcpy(&temp[0][len_a], str_b, len_b);
	

	// b 뒤에 a 붙이기
	memcpy(temp[1], str_b, len_b);
	memcpy(&temp[1][len_b], str_a, len_a);

	ret = strcmp(temp[0], temp[1]);

	if(ret > 0)				return -1;
	else if(ret == 0)		return 0;
	else					return 1;
}

char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(MAX_LENTH*MAX_SIZE);
	int i, j, len = 0;
	char temp[4+1] = {0, };
	int key;

	memset(answer, 0x00, sizeof(answer));

	//퀵 정렬
	qsort(numbers, numbers_len, sizeof(int), compare);

	//최종값 문자열로 변환
	for(i=0 ; i<numbers_len ; i++)
	{
		memset(temp, 0x00, sizeof(temp));
		sprintf(temp, "%d", numbers[i]);	//문자열로 변환
		memcpy(&answer[len], temp, sizeof(temp));
		len += strlen(temp);
	}
	//	printf("%s\n", answer);
	
	if(numbers[0] == 0)
	{
		answer[0] = '0';
		answer[1] = '\0';
	}

//	free(answer);
    return answer;
}

int main(void)
{
	int input[5+1] = {3, 30, 34, 5, 9};
	
	solution(input, 5);
}

