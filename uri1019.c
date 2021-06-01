#include <stdio.h>
 
int main() {
 
    int N, horas, minutos, segundos;
	scanf("%d", &N);
	minutos = N / 60;
	segundos = N - (minutos * 60);
	horas = minutos / 60;
	minutos = minutos - (horas * 60);
	printf("%d:%d:%d\n", horas, minutos, segundos);
 
    return 0;
}