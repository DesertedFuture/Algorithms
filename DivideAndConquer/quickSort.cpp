//Scott Snyder
#include <iostream>
#include <vector>

int partition(std::vector<int> &a, int p, int r){
	int x = a[r]; //this is the pivot point
	int i = p-1; //
	for(int j = p; j < r; j++){
		if(a[j] <= x){
			i += 1;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	int temp = a[r];
	a[r] = a[i+1];
	a[i+1] = temp;
	}
	return i+1;
}

void quickSort(std::vector<int> &a, int p, int r){
	if (p < r){
		int q = partition(a, p, r); //
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}

}

int main(int argc, char const *argv[])
{
	std::vector<int> a = {2,8,7,1,3,5,6,4};
	quickSort(a,0,7);
	for(auto x : a){
		std::cout<< x<< " ";
	}
	std::cout<<std::endl;
	return 0;
}