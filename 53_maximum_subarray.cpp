/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int largest_sum = nums[0];
        for(int i=0; i<size(nums); i++)
        {
            int sum = nums[i];
            if(sum > largest_sum){
                largest_sum = sum;
            }
            for(int j=i+1; j<size(nums); j++)
            {
                sum += nums[j];
                if(sum > largest_sum) largest_sum = sum;
            }
        }
        
        return largest_sum;
    }
};*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int result_max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            curr_sum += nums[i];
            if(curr_sum > result_max_sum) result_max_sum = curr_sum;

            curr_sum = (curr_sum < 0)? 0:curr_sum;
        }
        
        return result_max_sum;
    }
};