#include <stdbool.h>
#include <stdio.h>

int linear_search(int haystack[],int size,int needle){
	for(int x=0;x<size;x++){
		if (haystack[x]==needle){
			return true;
		}	
	}	
return false;
}
int main(void) {
    int arr[] = {10, 20, 30, 40, 50};

    int result = linear_search(arr, 5, 30);
	printf("value %d",result);
return 0;
}


