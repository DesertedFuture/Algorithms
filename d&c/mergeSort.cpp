//Scott Snyder
//learning working along textbook
#include <iostream>
#include <math.h>  
//divide
//conquer
//merge

void merge(int a[], int p, int q, int r){
	int n1 = q-p+1; //size for left array
	int n2 = r-q; 	//size for right array

	int left[ (n1+1)] = {}; //create left array
	int right[ (n2+1)] = {}; //create right array

	//fill left array with left values
	for(int i = 0; i < n1; i++){
		left[i] = a[p+i-1];
	}

	//fill right array with right values
	for(int j = 0; j < n2; j++){
		right[j] = a[q+j];
	}

	//set n+1 value to something too great for dataset
	left[(n1+1)] = 10000000000;
	right[(n2+1)] = 10000000000;

	int i = 0;
	int j =0;

	for( int k = p; k < r; k++){
		if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
		} else {
			a[k] = right[j];
			j++;
		}
	}
}

void mergeSort(int a[], int p, int r){
	if(p < r) {
		int q = floor((p+r)/2);
		mergeSort(a,p,q); 
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
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