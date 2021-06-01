#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 1010
#define MAXSIZEG (((MAXSIZE) * (MAXSIZE-1)) >> 1)

///////////////////// ESTRUTURAS
typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAXSIZEG];
    int n;
} edge_list;

//////////////////// VARIAVEIS GLOBAIS
edge_list listaOrdenada;
edge_list arvGeradoraMin;
int grafo[MAXSIZE][MAXSIZE];
int vis[MAXSIZE];

//////////////////////////// DECLARACAO DE FUNC
int kruskal(int n);
int compare(const void *a, const void *b);
void uniao(int pertence[], int c1, int c2, int n);
void buscaProfundidade(int key, int n);
inline void troca(int *a, int *b);

//// MAIN //////////////////////////////
int main()
{
    int i;
    int n;        // n = numero de predios;
    long int m;   // m = numero de conexoes;
    int a, b, c;  // Para receber os valores;

    while(1) {
        memset(grafo, 0, sizeof(grafo));   // Inicializa grafo[][] com zeros;

        if(scanf("%d %ld", &n, &m) == EOF) break;             // recebe N e M e verifica EOF;
        
        listaOrdenada.n = 0;
        for (i = 0; i < m; i++) {                            // recebe os valores dos caminhos;
            scanf("%d %d %d", &a, &b, &c);
            grafo[a][b] = c;
            listaOrdenada.data[i].u = a;
            listaOrdenada.data[i].v = b;
            listaOrdenada.data[i].w = c;
            listaOrdenada.n++;
        }

        // 
        // CALCULO DE IMPOSSIBILIDADE
        //
        int compConexas = 0;
        memset(vis, 0, sizeof(vis));

        for(i = 1; i <=n; i++) {
            if(!vis[i]) {                // Se entrar aqui mais de 1 vez: Grafo desconexo;
                compConexas++;
                buscaProfundidade(i, n); // a busca preencherá o vetor vis (não sei o q é "vis");
            }
        }

        if(compConexas > 1) {         // Encontrou mais de uma componente conexa no grafo,
            printf("impossivel\n");   // signifca que a arvore geradora minima eh impossivel.
            continue;
        }
        
        // Executa algoritmo de kruskal;
        qsort(listaOrdenada.data, m, sizeof(edge), compare);
        int result = kruskal(n);

        printf("%d\n", result);  // printa resultado do algoritmo;
        
    }

    return 0;
}

/////////////////////////// KRUSKAL!!
int kruskal(int n) {
    
    int pertence[MAXSIZE], i, j, custoNo1, custoNo2, total;
    total = 0;

    for (i = 0; i <= n; i++) pertence[i] = i;

    arvGeradoraMin.n = 0;     // inicializa lista de respostas finais;

    for (i = 0; i <= listaOrdenada.n; i++) {
        custoNo1 = pertence[listaOrdenada.data[i].u];
        custoNo2 = pertence[listaOrdenada.data[i].v];

        if (custoNo1 != custoNo2) {
            arvGeradoraMin.data[arvGeradoraMin.n] = listaOrdenada.data[i];
            arvGeradoraMin.n = arvGeradoraMin.n + 1;
            uniao(pertence, custoNo1, custoNo2, n);
        }
    }

    // Calcula valor custo final da arvore geradora minima:
    for (i = 0; i < arvGeradoraMin.n; i++) {
        total = total + arvGeradoraMin.data[i].w;
    }
    return total;
    
}

int compare(const void *a, const void *b) {
    int ans = ((edge*)a)->w - ((edge*)b)->w;
    return ans;
}

void uniao(int pertence[], int c1, int c2, int n) {
  int i;

  for (i = 0; i <= n; i++) {
    if (pertence[i] == c2) pertence[i] = c1;
  }
}

void buscaProfundidade(int key, int n) {
    int i;

    vis[key] = 1;
    for(i = 1; i <=n; i++) {
        if(grafo[key][i] && !vis[i]) buscaProfundidade(i, n);
    }
}

inline void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}