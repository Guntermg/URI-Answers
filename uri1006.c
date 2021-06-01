#include <stdio.h>
 
int main() {
 
    double A, B, C;
    double ans;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
 
    ans = (A * 2 + B * 3 + C * 5)/10;
    
    printf("MEDIA = %.1lf\n", ans);
 
    return 0;
}