#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(void)
{
	int arrLength;
	scanf("%d", &arrLength);

	int arr[arrLength];
	
	for (int i = 0; i < arrLength; i++) {
		scanf("%d", &arr[i]);
	}
	
	int maxValue = 0;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] > maxValue) maxValue = arr[i];
	}
		
	int currentGCD = 1;
	int answer = INT_MAX;

	while (currentGCD <= maxValue / 2)
	{
		int deletedNumCount = 0;
		currentGCD++;

		if (currentGCD > 3)
		{
			if (currentGCD % 2 == 0 || currentGCD % 3 == 0)
			{
				continue;
			}
		}

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % currentGCD != 0)
			{
				deletedNumCount++;
			}	
		}
		
		if (deletedNumCount != 0 && deletedNumCount < arrLength && deletedNumCount < answer)
		{
			answer = deletedNumCount;
		}

	}
	
	if (answer == INT_MAX) printf("-1\n");
	else
	{
		printf("%d\n", answer);
	}

	return 0;
}
