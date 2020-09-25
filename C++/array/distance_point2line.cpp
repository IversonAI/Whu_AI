#include<iostream>
#include<cmath>

struct point {
	float x, y;
};
float distance(point a, point b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx*dx + dy * dy);
}

float randFloat()
{
	return 1.0*rand() / RAND_MAX;
}
int main() {
	float d = 0.6;
	int i, j, cnt = 0, N = 10;
	point *a = (point *)malloc(N*(sizeof(*a)));
	for (int i= 0; i < N; i++)
	{
		a[i].x = randFloat();
		a[i].y = randFloat();
	}
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (distance(a[i], a[j]) < d)
				cnt++;
	printf("%d edges shorter than %f\n", cnt, d);
	system("pause");
}
