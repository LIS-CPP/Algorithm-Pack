#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* makeRandomNumbersArray(int size, int bitmask);
void insertionSort(int* array, int size);
void swap(int* x, int* y);
void printArray(int* array, int size);

int main(){
	int arrSize = 1024;
	int* array = makeRandomNumbersArray(arrSize, 0x7FFF);
	
	printArray(array, arrSize);
	printf("\n\n");
	
	insertionSort(array, arrSize);
	
	printArray(array, arrSize);
	printf("\n");
	
	free(array);
	
	return 0;
}

void insertionSort(int* arr, int size){
	for(int i = 1; i < size; ++i)
		for(int j = i; j > 0; --j)
			if(arr[j-1] > arr[j])
				swap(&arr[j-1], &arr[j]);
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
