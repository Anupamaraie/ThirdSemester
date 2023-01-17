#include <stdio.h>

unsigned int divide(unsigned int dividend, unsigned int divisor) {
    unsigned int quotient = 0;
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
    unsigned int dividend, divisor;
    printf("Enter the dividend: ");
    scanf("%u", &dividend);
    printf("Enter the divisor: ");
    scanf("%u", &divisor);
    printf("Quotient: %u\n", divide(dividend, divisor));
    return 0;
}
