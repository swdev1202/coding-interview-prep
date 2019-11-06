class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> max_sum;
        
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2){
            return (nums[0] > nums[1])? nums[0] : nums[1];
        }
        
        max_sum.push_back(nums[0]);
        max_sum.push_back(max(nums[0], nums[1]));
        
        for(int i=2; i<nums.size(); i++){
            int first = max_sum[i-1];
            int second = max_sum[i-2] + nums[i];
            max_sum.push_back(max(first,second));
        }
        
        return max_sum[nums.size()-1];
        //return find_greatest(max_sum);
    }
    
    int max(int a, int b){
        if(a >= b) return a;
        return b;
    }
    
    int find_greatest(vector<int>& v){
        int greatest = -1;
        for(auto& num : v){
            if(num > greatest){
                greatest = num;
            }
        }
        return greatest;
    }
};