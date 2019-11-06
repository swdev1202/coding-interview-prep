class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // nums.size() will give you the "n"
        // it starts from 0
        int expected_num = (nums.size() * (nums.size()+1)) / 2;
        for(int i=0; i<nums.size(); i++){
            expected_num -= nums[i];
        }
        
        return expected_num;
    }
};