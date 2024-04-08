#include <stdio.h>

struct GameInfo {
    char *name;
    int year;
    int price;
    char *company;
};

int main_struct(void)
{
    // struct GameInfo gameInfo1;
    // gameInfo1.name = "나도게임";
    // gameInfo1.price = 50;
    // gameInfo1.year = 2017;
    // gameInfo1.company = "나도회사";

    // printf("%d\n", gameInfo1.price);
    // printf("%d\n", gameInfo1.year);
    // printf("%s\n", gameInfo1.name);
    // printf("%s\n", gameInfo1.company);

    // struct GameInfo gameInfo2 = {"너도게임", 2017, 50, "너도회사"};

    // printf("%d\n", gameInfo2.price);
    // printf("%d\n", gameInfo2.year);
    // printf("%s\n", gameInfo2.name);
    // printf("%s\n", gameInfo2.company);
    // struct GameInfo gameArray[4] = {
	// 	{"어레이", 2017, 50, "너도게임"},
	// 	{"어레이", 2017, 50, "너도게임"},
	// 	{"어레이", 2017, 50, "너도게임"},
	// 	{"어레이", 2017, 50, "너도게임"}
	// };
    

    // for (int i = 0; i < sizeof(gameArray) / sizeof(gameArray[0]); i++)
    // {
    //     struct GameInfo gametemp = gameArray[i];
    //     printf("%d\n", gametemp.price);
    //     printf("%d\n", gametemp.year);
    //     printf("%s\n", gametemp.name);
    //     printf("%s\n", gametemp.company);
    // }
    struct GameInfo gameInfo1;
    gameInfo1.name = "나도게임";
    gameInfo1.price = 50;
    gameInfo1.year = 2017;
    gameInfo1.company = "나도회사";

    struct GameInfo *gamePtr;
    gamePtr = &gameInfo1;
    
    printf("게임명 :: %s\n", gamePtr->name);
    printf("발매년도 :: %d\n", gamePtr->year);
    printf("가격 :: %d\n", gamePtr->price);
    printf("제작사 :: %s\n", gamePtr->company);
    
    return 0;
}