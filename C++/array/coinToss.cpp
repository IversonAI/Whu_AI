#include<iostream>
#include<cstdlib>

int heads() {
	return rand() < RAND_MAX / 2;
}

int main(int argc,char *argv[1])
{
	int i, j, cnt;
	int N = 100,M = 10000;//M为模拟次数，N为抛硬币次数
	int *f = (int*)malloc((N + 1) * sizeof(int));
	for (j = 0; j <N; j++)
		f[j] = 0;
	for (i = 0; i < M; i++, f[cnt]++)
		for(cnt=0,j=0;j<=N;j++)
			if (heads()) 
				cnt++;
	for (j = 0; j <= N; j++)
	{
		printf("%2d	", j);
		for (i = 0; i < f[j]; i += 10)
			printf("*");
		printf("\n");
	}
	system("pause");
	return 0;
}