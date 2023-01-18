#include <stdio.h>

int divide(int dividend,int divisor) {
    int quotient = 0;
    int i;
    for (i = 31; i >= 0; i--) {
        quotient <<= 1;
        if ((dividend >> i) >= divisor) {
            dividend -= divisor << i;
            quotient |= 1;
        }
    }
    return quotient;
}

int main() {
    int dividend, divisor;
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    printf("Quotient: %u\n", divide(dividend, divisor));
    return 0;
}
