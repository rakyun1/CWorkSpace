#include <stdio.h>
#include <string.h>

int main(void)
{
    int studentNumber[23];
    memset(studentNumber, 0, 23 * sizeof(int));

    int callCount = 0;
    scanf("%d", &callCount);

    for (int i = 0; i < callCount; i++) {
        int callNumber = 0;
        scanf("%d", &callNumber);

        studentNumber[callNumber - 1]++;
    }

    for (int i = 0; i < 23; i++) {
        printf("%d ", studentNumber[i]);
    }
    return 0;
}
