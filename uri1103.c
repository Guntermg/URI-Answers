#include <stdio.h>
 
int main() {
 
    int h1, m1, h2, m2, i, total;
    while(1) {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

        if(h2>h1) {
            int horas;
            h2 = h2 - 1;
            total = 60 - m1 + m2;
            horas = h2 - h1;
            total = total + horas * 60;
        } else if(h2 == h1 && m2 > m1) {
            total = m2 - m1;
        } else {
            int aux;
            total = m2 + h2 * 60;
            aux = 23 - h1;
            total = total + (aux * 60) + (60 - m1);
        }

        printf("%d\n", total);
    }
 
    return 0;
}