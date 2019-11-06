#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        unordered_map<int,int> diff_map;
        for(int i=0; i<nums.size(); i++){ 
            diff_map.insert(pair<int,int>(nums[i], i));
        }
        
        for(int i=0; i<nums.size(); i++){
            if(diff_map.find(target-nums[i]) != diff_map.end() && diff_map[target-nums[i]] != i){
                result.push_back(i);
                result.push_back(diff_map[target-nums[i]]);
                break;
            }
        }
        return result;
    }
};