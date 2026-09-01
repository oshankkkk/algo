#include <stdio.h>
int bubble_sort(int arr[],int size){
	for (int x=0; x<size;x++) {
		for (int j=0; j<size-x-1;j++) {
			if(arr[j]>arr[j+1]){
			int temp=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
			}	
		}
	}	
	return 0;
}
int main(){
    //int arr[] = {10, 20, 30, 40, 60};
    int arr[] = {4,11,2,1,39,6};
    //int arr[] = {10, 20};

	for (int x=0; x<6;x++) {
		printf("array elemant, %d \n",arr[x]);
	}
    int result =bubble_sort(arr, 6);

	for (int i=0; i<6;i++) {
		printf("sorted array elemant, %d \n",arr[i]);
	}
	printf("rsult %d",result);

	return 0;
}
