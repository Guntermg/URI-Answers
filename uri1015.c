#include <stdio.h>
#include <math.h>
 
int main() {
 
    float x1, y1, x2, y2, aux1, aux2;
    float ans;
    
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
 
    aux1 = pow((x2 - x1), 2);
    aux2 = pow((y2 - y1), 2);
    
    ans = sqrt(aux1 + aux2);
    
    printf("%.4f\n", ans);
 
    return 0;
}