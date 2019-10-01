#include <stdio.h>
#include <cmath>

void update(int *a,int *b) {
    //temp is an integer, *a is a direferenced pointer
    int temp = *a;
    *a = temp+*b;
    *b = abs(temp-*b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

