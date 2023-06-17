//Scott Snyder

#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>

std::tuple<std::vector<int>, int, int> findMaxSubarray(std::vector<int> a,int indexLow, int indexHigh ){
	if(indexHigh == indexLow) {
		return std::make_tuple(a, indexLow, a[indexLow]);
	} else {
		int mid = ceiling( (indexLow + indexHigh)/2);
		std::make_tuple(indexLow)
	}
	else {
		return std::make_tuple(a, indexLow, indexHigh);
	}
}

void print(std::vector<int> a){
	for(auto x : a){
		std::cout<<x<<' ';
	}
	 std::cout<< '\n';
}
int main(int argc, char const *argv[])
{
	int first = 0;
	int last = 16;

	std::vector<int> a = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
	std::tie(a, first, last) = findMaxSubarray(a, first, last);
	print(a);
	
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