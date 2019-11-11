#include <unordered_map>
#include <vector>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int total = 0;
        int sum = 0;
        
        unordered_map<int,int> sumMap;
        sumMap[0]++;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sumMap.find(sum-k) != sumMap.end()) total += sumMap[sum-k];
            sumMap[sum]++;
        }
        return total;
    }
};