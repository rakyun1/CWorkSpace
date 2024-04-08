#include <stdio.h>

void swap(int a, int b);
void swap_addr(int *a, int *b);

int mainPointer(void)
{
    // int 철수 = 1;
    // int 영희 = 2;
    // int 민수 = 3;

    // printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
    // printf("철수네 주소 : %d, 암호 : %d\n", &영희, 영희);
    // printf("철수네 주소 : %d, 암호 : %d\n", &민수, 민수);

    // int *미션맨; // 포인터 변수
    // 미션맨 = &철수;
    // printf("미션맨이 방무나는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

    // 미션맨 = &영희;
    // printf("미션맨이 방무나는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);
    
    // 미션맨 = &민수;
    // printf("미션맨이 방무나는 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);
    
    // // 각 암호에 3을 곱하라
    // 미션맨 = &철수;
    // *미션맨 = *미션맨 * 3;
    // printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

    // 미션맨 = &영희;

    // *미션맨 = *미션맨 * 3;
    // printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);


    // 미션맨 = &민수;

    // *미션맨 = *미션맨 * 3;
    // printf("미션맨이 암호를 바꾼 곳 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

    // int *스파이 = 미션맨;
    // printf("\n 스파이가 미션 수행하는 중...\n\n");
    // *스파이 -= 2;
    // printf("스파이가 방문하는 곳 주소 %d, 암호 : %d\n", 스파이, *스파이);

    // int arr[3] = {5, 10, 15};
    // int *ptr = arr;
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("배열 ptr[%d] 의 값 : %d\n", i, ptr[i]);
    // }

    // ptr[0] = 100;
    // ptr[1] = 200;
    // ptr[2] = 300;
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("배열 ptr[%d] 의 값 : %d\n", i, ptr[i]);
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("배열 arr[%d] 의 주소 : %d\n", i, &arr[i]);
    // }

    // printf("%d\n", arr);

    // int a = 5;
	// int b = 10;
	
	// swap(a, b);
	// printf("swap 함수 사용시 a 값 : %d, b 값 : %d\n", a, b);
	
	// swap_addr(&a, &b);
	// printf("swap_addr 함수 사용시 a 값 : %d, b 값 : %d\n", a, b);






    
    

    return 0;
}
// void swap(int a, int b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }

// void swap_addr(int *a, int *b)
// {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }