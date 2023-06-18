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
	return std::make_tuple(leftMax, rightMax, leftSum+rightSum);
}

std::tuple<std::vector<int>, int, int> findMaxSubarray(std::vector<int> a,int indexLow, int indexHigh ){
	//base case when there is only one element
	if(indexHigh == indexLow) {
		return std::make_tuple(a, indexLow, a[indexLow]);
	} else {
		int mid = std::ceil( (indexLow + indexHigh)/2);
		std::make_tuple(indexLow);
	}
		return std::make_tuple(a, indexLow, indexHigh);
}



/*
i want to find the maxmium sub array
i can create a an array that shows the change between each value (this would be n - 1 )
with new array that shows change between each value I have two solutions
	brute force solution:
		-try all buy and sell dates, which compares each dates and would be o(n^2)
We can do better by divide and conquering:
	divide into two
	find max sub array from start to middle and store index
	find max sub array from middle to end and store index
	see if there is cross over from both 
	return indexs

take array
create new array with differences
function to split into two sides and find indexes
function to see if there should be a split mid

*/
int main(int argc, char const *argv[])
{
	int first = 0;
	int last = 16;
	int index0, index1, index2, tempMiddle = std::ceil( (first + last)/2);

	std::vector<int> a = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
	std::vector<int> diff = generateDifference(a);
	
	print(a);
	print(diff);
	//std::tie(a, first, last) = findMaxSubarray(a, first, last);
	std::tie(index0, index1,index2) = find_Max_Crossing_Subarray(diff, 0, tempMiddle, diff.size() );
	std::cout<< index0 << '\n' <<index1<< '\n'<<index2<<'\n';
	return 0;
}

/*
find-max0crossing-subarray(Array, lowIndex, midIndex, highIndex)
	left-sum -inf
	sum = 0
	for(i = middle downto lowIndex)
		sum= sum + Array[i]
		if (sum  > left-sum)
			left-sum = sum
			max-left = i
	right-sum  -inf
	sum = 0
	for (j = mid + 1 to high)
		sum = sum + A[j]
		if ( sum > right-sum)
			right-sum = sum
			max-right = j
return(max-left, max-right, left-sum + right-sum)

Find-max-subarray
if high==low
	return (low, high, A[low])
else mid = ceiling( (low+high)/2 )
	(left-low, left-right, left-sum) = find-max-subarray(a,low,mid)
	(right-low, right-high, right-sum) = find-max-subarray(Amid+1,high)
	(cross-low, cross-high,cross-sum) = find-max-crossing-subarray(A, low, mid, high)
	if left-sum >= right-sum && left-sum >= cross-sum
		return (left-low, left-high, left-sum)
	else if ( right-sum >= left-sum && right-sum >= cross-sum)
		return (right-low, right-high, right-sum)
	else return(cross-low,cross-high,cross-sum)

start middle, find greatest from low section, find greated from right section
find,if both can be combined and return new indexes,
*/