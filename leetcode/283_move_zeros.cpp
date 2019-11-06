class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int zero_idx = 0;
        int next_idx = 0;
        
        while(true){
            if(nums[zero_idx] == 0){
                // only move the next index
                next_idx++;
            }
            else{
                // move the zero index
                zero_idx++;
            }
            
            if(next_idx >= nums.size() || zero_idx >= nums.size()) return;
            if(nums[next_idx] != 0 && zero_idx < next_idx){
                swap(nums, zero_idx, next_idx);
            }
        }
    }
    
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};