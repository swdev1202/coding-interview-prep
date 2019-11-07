#include <vector>
#include <unordered_set>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	vector<int> result;
	
	/* time O(n^2)
	for(int i=0; i<array.size(); i++){
		for(int j=i+1; j<array.size(); j++){
			if(array[i] + array[j] == targetSum){
				if(array[i] > array[j]){
					result.push_back(array[j]);
					result.push_back(array[i]);
				}
				else{
					result.push_back(array[i]);
					result.push_back(array[j]);
				}
				return result;
			}
		}
	}*/
	
	// using unordered_set
	unordered_set<int> intBin;
	for(int i=0; i<array.size(); i++){
		int currentNum = array[i];
		int expected = targetSum - currentNum;
		if(intBin.count(expected)){
			if(currentNum > expected){
				result.push_back(expected);
				result.push_back(currentNum);
			}
			else{
				result.push_back(currentNum);
				result.push_back(expected);
			}
			return result;
		}
		else{
			intBin.emplace(currentNum);
		}
	}
	
	return result;
}
