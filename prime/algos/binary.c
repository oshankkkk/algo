#include <stdio.h>
int binary_search(int arr[],int size,int find){
	int lo=0;
	int hi=size-1;

	while (lo<=hi){

		int mid=lo+(hi-lo)/2;
		int val=arr[mid];

		if (val>find){
			hi=mid-1;
		}else if(val<find){
			lo=mid+1;	
		}else{
			return val;
		}
	}
	return -1;
}

//int tow_crystal_balls(int arr[],int size){}


int main(void) {
    int arr[] = {10, 20, 30, 40, 60};
    //int arr[] = {10, 20};

    int result = binary_search(arr, 5, 90);

	printf("rsult %d",result);

	return 0;
}


