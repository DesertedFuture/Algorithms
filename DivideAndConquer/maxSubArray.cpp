//Scott Snyder

#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>

void print(std::vector<int> a){
	for(auto x : a){
		std::cout<<x<<' ';
	}
	 std::cout<< '\n';
}

std::vector<int> generateDifference(std::vector<int> values) {
	std::vector<int> difference;
	for(int i = 1; i < values.size(); i++){
		difference.push_back(values[i] - values[i-1]);
	}
	return difference;
}
std::tuple<int, int, int> find_Max_Crossing_Subarray(std::vector<int> diffVector,int indexLow, int indexMiddle, int indexHigh){
	int leftSum = 0, sum =  0, rightSum = 0, leftMax, rightMax;
	for(int i = indexMiddle; i > indexLow; i--){
		sum = sum + diffVector[i];
		if(sum > leftSum){
			leftSum = sum;
			leftMax = i;
		}
	}

	sum = 0;

	for(int j = indexMiddle+1; j < indexHigh; j++) {
		sum += diffVector[j];
		if(sum > rightSum){
			rightSum = sum;
			rightMax = j;
		}
	}
	int addedSum = leftSum+rightSum;
	return std::tie(leftMax, rightMax, addedSum);
}



std::tuple<int, int, int> findMaxSubarray(std::vector<int> a,int indexLow, int indexHigh ){
	int leftLow, leftHigh, leftSum, crossLow, crossHigh, crossSum, rightLow, rightHigh, rightSum;
	//base case when there is only one element
	std::cout<<"indexLow: " << indexLow<< " indexHigh: " << indexHigh<< '\n';
	if(indexHigh == indexLow) {
		return std::tie(indexLow, indexHigh, a[indexLow]);
	} else {
		int indexMiddle = std::ceil( (indexLow + indexHigh)/2);
		std::tie(leftLow,leftHigh,leftSum) = findMaxSubarray(a, indexLow, indexMiddle);
		std::tie(rightLow, rightHigh, rightSum) = findMaxSubarray(a, indexMiddle+1, indexHigh);
		std::tie(crossLow, crossHigh, crossSum) = find_Max_Crossing_Subarray(a, indexLow, indexMiddle, indexHigh);

		if(leftSum >= rightSum && leftSum >= crossSum){
			return std::tie(leftLow, leftHigh, leftSum);
		} else if(rightSum >= leftSum && rightSum >= crossSum){
			return std::tie(rightLow, rightHigh, rightSum);
		} else {
			return std::tie(crossLow, crossHigh, crossSum);
		}
	}
	
}


int main(int argc, char const *argv[])
{
	int index0 = 0,index1 = 0,index2 = 0;
	std::vector<int> a = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
	std::vector<int> diff = generateDifference(a);
	
	print(diff);
	std::tie(index0, index1,index2) = findMaxSubarray(diff, 0, diff.size() );
	
	std::cout<< index0 << '\n' <<index1<< '\n'<<index2<<'\n';
	return 0;
}