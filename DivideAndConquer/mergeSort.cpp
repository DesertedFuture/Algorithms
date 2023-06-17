//Scott Snyder
//learning working along textbook
#include <iostream>
#include <math.h>  
//divide
//conquer
//merge


void sort(int arr[], int leftIndex, int middle, int rightIndex){
	//create new array
	int const sizeLeft = middle - leftIndex +1;
	int const sizeRight = rightIndex - middle;
	auto *newLeft = new int[sizeLeft], 
		*newRight = new int[sizeRight];


	//copy into new arrays
	for(auto i = 0; i < sizeLeft; i++){
		newLeft[i] = arr[leftIndex + i];
	}

	for(auto j = 0; j < sizeRight;j++){
		newRight[j] = arr[middle+1+j];
	}

	auto index1 =0, index2 =0;
	int indexMerged = leftIndex;

	while(index1 < sizeLeft && index2 < sizeRight) {
		if(newLeft[index1] <= newRight[index2]){
			arr[indexMerged] = newLeft[index1];
			index1++;
		} else{
			arr[indexMerged] = newRight[index2];
			index2++;
		}
		indexMerged++;
		
	}


	while(index1 < sizeLeft){
		arr[indexMerged] = newLeft[index1];
		index1++;
		indexMerged++;
	}
	
	while(index2 < sizeRight){
		arr[indexMerged] = newRight[index2];
		indexMerged++;
		index2++;
	}

	//replace data
	delete[] newLeft;
	delete[] newRight;



}

void mergeSort(int arr[], int leftIndex, int rightIndex){
	std::cout<<"left index: " << leftIndex <<"  right index: " << rightIndex <<'\n';
	
	if(leftIndex < rightIndex){
		int middle = floor( ((rightIndex-leftIndex)/2))+leftIndex ; //index for seperation
		
		mergeSort(arr, leftIndex, middle); //recurse left half
		mergeSort(arr, middle+1, rightIndex); //recurse right half
		sort(arr, leftIndex, middle, rightIndex);
	}
}


int main(int argc, char const *argv[])
{
	//int arr[] = {5,2,4,7,1,3,2,6};
	//int arr[] = {2,1,0};
	int arr[] = {6,4,2};
	int arrSize = std::size(arr)-1;
	std::cout<<"size: "<<arrSize<<'\n';
	mergeSort(arr, 0, arrSize);

	std::cout<<"sorted arr: "<<'\n';
	for(int x : arr){
		std::cout<< x<< ' ';
	}
	std::cout<<'\n';
	//7 numbers
	return 0;
}