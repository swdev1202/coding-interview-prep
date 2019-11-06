class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        
        if(nums.size() == 0 || k == 0) return result;
        
        
        // brute force
        /*
        for(int i=0; i<nums.size()-k+1; i++){
            // build a max heap
            priority_queue<int> max_heap;
            for(int j=0; j<k; j++){
                max_heap.push(nums[i+j]);
            }
            
            // get the max out
            result.push_back(max_heap.top());
        }*/
        
        for(int i=0; i<nums.size()-k+1; i++){
            int max_val = nums[i];
            for(int j=0; j<k; j++){
                if(nums[i+j] > max_val) max_val = nums[i+j];
            }
            result.push_back(max_val);
        }
        
        return result;
    }
};