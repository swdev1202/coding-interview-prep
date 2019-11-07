#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  // Write your code here.
	int left = 0;
	int right = array.size() - 1;
	while(left <= right){
		int mid = (left+right) / 2;
		if(array[mid] == target){
			return mid;
		}
		
		if(array[mid] > target) right = mid-1;
		else left = mid+1;
	}
	
	return -1;
}
