#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int k = 1;
	int N, M, *x, *y, i;

	scanf("%d", &k);

	while(k > 0){
		x = (int*) malloc(k * sizeof(int));
		y = (int*) malloc(k * sizeof(int));

		scanf("%d %d", &N, &M);
		for(i = 0; i < k; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		for(i = 0; i < k; i++) {
			if(x[i] == N || y[i] == M) printf("divisa\n");
			else if(x[i] > N && y[i] > M) printf("NE\n");
			else if(x[i] > N && y[i] < M) printf("SE\n");
			else if(x[i] < N && y[i] > M) printf("NO\n");
			else if(x[i] < N && y[i] < M) printf("SO\n");
		}
		scanf("%d", &k);
	}
 
    return 0;
}