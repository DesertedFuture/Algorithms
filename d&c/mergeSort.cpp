//Scott Snyder
//learning working along textbook
#include <iostream>
#include <math.h>  
//divide
//conquer
//merge

void merge(int a[], int left, int middle, int right){
	//sizes to create arrays
	int const subLeft = middle - left + 1; //size of how many is in left half
	int const subRight = right - middle; // size of how many is in right half

	//arrays used to copy data into
	int *leftArray = new int[subLeft];
	int *rightArray = new int[subRight];

	//copied arrays used to do comparisons 
	for(int i =0; i < subLeft; i++){
		leftArray[i] = a[left+i];
	}
	for(int j =0; j< subRight; j++){
		rightArray[j] = a[middle + 1 + j];
	}

	int leftIndex,rightIndex = 0;


}

void mergeSort(int a[], int left, int right){
	if(left < right) {
		int middle = floor((left+right)/2);
		mergeSort(a,left,middle); 
		mergeSort(a,middle+1,right);
		merge(a,left,middle,right);
	}
}


int main(int argc, char const *argv[])
{
	//int arr[] = {5,2,4,7,1,3,2,6};
	int arr[] = {0,1, 2};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, arrSize);
	for(int x : arr){
		std::cout<< x<< ' ';
	}
	std::cout<<'\n';
	//7 numbers
	return 0;
}

/*
mergesort
divide and conquer
merge sort is broken into dividing, merging, sorting
one recursive function
fucntion for merging and sorting

how do i want to divide:
i want two array of equal length then to call merge on those
	-i accomplish this by getting beging to middle, then middle +1 to end
i then call merge on the whole array which takes array, left middle and end
	-array to actually sort what i want
	-left to know where to start
	-middle to know where right hand start is
	-right to know where to end

*/