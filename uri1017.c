#include <stdio.h>
 
int main() {
 
    int horas, vel, dist;
	float ans;

	scanf("%d", &horas);
	scanf("%d", &vel);

	dist = vel * horas;
	ans = (float)dist / 12;

	printf("%.3f\n", ans);
 
    return 0;
}