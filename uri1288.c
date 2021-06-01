#include <stdio.h>
#include <string.h>

int maior(int a, int b){
    if(a > b) return a;
    return b;
}

// Algoritmo de programacao dinamica: problema da mochila;
int DanoMax(int N, int K, int X[], int Y[]) {
    int i, j, aux;
    int m[N+1][K+1]; // N = numero de bolas, K = capacidade canhao; m[N][K] = dano total;

    memset(m, 0, sizeof(m[0][0]) * (N+1) * (K+1));

    for(i = 1; i <= K; i++) {
        for(j = 0; j < N; j++) {
            if(j > 0) {
                m[j][i] = m[j-1][i];
                if (Y[j] <= i) {
                    aux = X[j] + m[j-1][i-Y[j]];
                    m[j][i] = maior(m[j][i], aux);
                }
            }
            else {       // Preenche primeira posicao na coluna i;
                m[j][i] = 0;
                if(Y[j] <= i) m[j][i] = maior(m[j][i], X[j]);  // Preenche primeira posicao com zero ou dano da primeira bola;
            }
        }
    }
    return m[N-1][K];
}

int main()
{
    int i, caso, nCasos, N, K, R, danoCausado;
    scanf("%d", &nCasos);

    for(caso = 0; caso < nCasos; caso++) {
        scanf("%d", &N);

        int X[N+1];      // Dano da bola
        int Y[N+1];      // Peso da bola

        for(i=0; i<N; i++) {
            scanf("%d %d", &X[i], &Y[i]);
        }
        scanf("%d", &K);  // K = capacidade do canhao
        scanf("%d", &R);  // R = resistência do castelo

        danoCausado = DanoMax(N, K, X, Y);

        if(danoCausado >= R) printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    }

    return 0;
}