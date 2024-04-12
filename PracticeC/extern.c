#include <stdio.h>

void fun(int **p) {
    printf("ptr이 가리키는 대상의 주소: %d\n", **p);
}

int main() {
    int x = 10;
    int *ptr = &x;
    fun(&ptr); // ptr의 주소를 fun 함수에 전달

    return 0;
}
