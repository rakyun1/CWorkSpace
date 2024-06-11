#include <stdio.h>
#include <stdlib.h>

void drainage(int* houseHeight, int* rainedDay, int houseCount);

int main() {
	int houseCount, startDay, endDay, rainySeasonDays;
	
	scanf("%d", &houseCount);
	int* houseHeight = (int*)malloc(houseCount * sizeof(int));
	
	scanf("%d", &rainySeasonDays);
	
	for (int i = 0; i < houseCount; i++) {
		int height;
		scanf("%d", &height);
		houseHeight[i] = height;
	}
	
	int rainedDay[houseCount];
	memset(rainedDay, 0, sizeof(rainedDay));
	
	int rained = 0;
	
	while (rainySeasonDays > 0) {
		scanf("%d", &startDay);
		scanf("%d", &endDay);
		
		for (int i = startDay - 1; i <= endDay - 1; i++) {
			rainedDay[i] = 1;
		}
		
		rained++;
		
		for (int i = startDay-1; i <= endDay-1; i++) {
			houseHeight[i]++;
		}
				
		if (rained == 3) {
			rained = 0;
			
			drainage(houseHeight, rainedDay, houseCount);
			
			memset(rainedDay, 0, sizeof(rainedDay));
		}
	
		rainySeasonDays--;
	}
	
	for (int i = 0; i < houseCount; i++) {
		printf("%d ", houseHeight[i]);
	}
	printf("\n");
	
	return 0;
}

void drainage(int* houseHeight, int* rainedDay, int houseCount)
{
	for (int i = 0; i < houseCount; i++) {
		if (rainedDay[i] == 1) houseHeight[i]--;
	}
		
}
