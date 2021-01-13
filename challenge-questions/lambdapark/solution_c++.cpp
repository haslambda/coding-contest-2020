#include <stdio.h>

int main() {
    int children;
    scanf("%d", &children);
    int adults;
    scanf("%d", &adults);
    int discount;
    if (children + adults >= 10) {
        discount = 10;
        if (children >= 5) {
            discount = 20;
        }
    }

    int total = 10000 * adults + 8000 * children;
    total = total * (100 - discount) / 100;
    printf("%d", total);
    return 0;
}
