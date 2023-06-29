//Scott Snyder
#include <iostream>
#include <vector>
#include <random>
int partition(std::vector<int> &a, int p, int r){
	int x = a[r]; //this is the pivot point
	int i = p-1; //
	for(int j = p; j < r; j++){
		if(a[j] <= x){
			i ++;
			std::swap(a[i],a[j]);
		}
	}
	std::swap(a[i+1], a[r]);
	return (i+1);
}

void quickSort(std::vector<int> &a, int p, int r){
	if (p < r){
		int q = partition(a, p, r); //
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}
}

int randomizedPartition(std::vector<int> &a, int p, int r){
	int i = std::rand()%(r-p+1)+p;
	std::swap(a[r], a[i]);
	return partition(a,p,r);
}

void randomQuickSort(std::vector<int> &a, int p, int r){
	if(p < r){
		int q = randomizedPartition(a,p,r);
		randomQuickSort(a, p, q-1);
		randomQuickSort(a, q+1, r);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> a = {2,8,7,1,3,5,6,4};
	std::vector<int> arr = { 10, 7, 8, 9, 1, 5 };

	quickSort(a,0,a.size()-1);
	for(auto x : a){
		std::cout<< x<< " ";
	}
	std::cout<<std::endl;

	randomQuickSort(arr,0,arr.size()-1);
	for(auto x : arr){
		std::cout<< x<< " ";
	}
	std::cout<<std::endl;

	return 0;
}