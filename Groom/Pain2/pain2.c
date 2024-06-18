#include <stdio.h>
#include <limits.h>

int main() {
	int target, aItem, bItem, count = 0, result = INT_MAX, temp = 0;
	
	scanf("%d", &target);
	scanf("%d", &aItem);
	scanf("%d", &bItem);
	
	int remainder = target; 
	
	if (aItem > bItem) {
		while (1)
		{
			remainder -= aItem;
			count ++;
			
			if (remainder <= 0) break;
			
			if (remainder % bItem == 0) {
				temp = count + remainder / bItem;
				
				if (result > temp) result = temp;
			}
		}
		
		if (result == INT_MAX && remainder == 0) result = count;
	}
	else 
	{
		while (1)
		{
			remainder -= bItem;
			count ++;
			
			if (remainder <= 0) break;

			
			if (remainder % aItem == 0) {
				temp = count + remainder / aItem;
				
				if (result > temp) result = temp;
			}
		}
		
		if (result == INT_MAX && remainder == 0) result = count;
	}
	
	if (result == INT_MAX) printf("-1\n");
	else
	{
		printf("%d\n", result);
	}
	
	return 0;
}
