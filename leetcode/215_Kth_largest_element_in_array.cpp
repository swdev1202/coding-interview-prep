class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // create a max heap
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(int val : nums){
            if(min_heap.size() < k){
                min_heap.emplace(val);
            }
            else{
                if(val > min_heap.top()){
                    min_heap.pop();
                    min_heap.emplace(val);
                }
            }
        }
        
        return min_heap.top();
    }
};