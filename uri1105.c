#include <stdio.h>
 
int main() {
 
    int b, n, i, aux;

    while(1) {
        scanf("%d %d", &b, &n);
        if(b==0 && n == 0) break;

        int reserva[b];
        int deb[n][3];
        int debTotal[b];
        int reservTotal[b];
        int reservaGlobal = 0;
        
        for(i = 0; i < b; i++) 
            scanf("%d", &reserva[i]);
        
        for(i = 0; i < b; i++) {
            reservaGlobal = reservaGlobal + reserva[i];
        }
        
        for(i = 0; i < n; i++)
            scanf("%d %d %d", &deb[i][0], &deb[i][1], &deb[i][2]);
        
        for(i = 0; i < b; i++) debTotal[i] = 0;
        for(i = 0; i < b; i++) reservTotal[i] = reserva[i];

        for(i = 0; i < n; i++) {
            aux = deb[i][0] - 1;
            debTotal[aux] = debTotal[aux] + deb[i][2];
        }
        for(i = 0; i < n; i++) {
            aux = deb[i][1] - 1;
            reservTotal[aux] = reservTotal[aux] + deb[i][2];
        }

        for(i = 0; i < b; i++) {
            if(debTotal[i] > reservTotal[i]){
                printf("N\n");
                break;
            }
        }
        if(i == b) printf("S\n");
    }
 
    return 0;
}