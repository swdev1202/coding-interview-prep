#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
	vector<vector<int>> result;
	sort(array.begin(), array.end());
	for(int i=0; i<array.size()-2; i++){
		int left = i+1;
		int right = array.size()-1;
		while(left < right){
			int sum = array[i]+array[left]+array[right];
			if(sum == targetSum){
				result.push_back({array[i],array[left],array[right]});
				left++;
				right--;
			}
			else if(sum < targetSum) left++;
			else right--;
		}
	}
	return result;
}