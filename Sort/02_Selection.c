#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* makeRandomNumbersArray(int size, int bitmask);
void selectionSort(int* array, int size);
void swap(int* x, int* y);
void printArray(int* array, int size);

int main(){
	int arrSize = 1024;
	int* array = makeRandomNumbersArray(arrSize, 0x7FFF);
	
	printArray(array, arrSize);
	printf("\n\n");
	
	selectionSort(array, arrSize);
	
	printArray(array, arrSize);
	printf("\n");
	
	free(array);
	
	return 0;
}

void selectionSort(int* arr, int size){
	int selectionIndex;
	for(int i = 0; i < size; ++i){
		selectionIndex = i;
		for(int j = i + 1; j < size; ++j)
			if(arr[selectionIndex] > arr[j])
				selectionIndex = j;
		if(i != selectionIndex)
			swap(&arr[i], &arr[selectionIndex]);
	}
}

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void printArray(int* arr, int size){
	for(int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

int* makeRandomNumbersArray(const int size, int bitmask){
	int* array = (int*)malloc(sizeof(int)*size);
	srand(time(NULL));
	for(int i = 0; i < size; ++i)
		array[i] = rand() & bitmask;
	return array;
}
