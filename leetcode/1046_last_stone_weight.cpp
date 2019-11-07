#include <algorithm>

class Solution {
public:
    /* using std::make_heap
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty()) return 0;
        
        
        while(stones.size() > 1)
        {
            // make the given vector as a heap
            std::make_heap(stones.begin(), stones.end());
            std::sort_heap (stones.begin(),stones.end());
            
            // get the heaviest stone in a heap
            int heaviest = stones.back();
            stones.pop_back();
            int second_heaviest = stones.back();
            stones.pop_back();
            
            int smash_result = heaviest - second_heaviest;
            if(smash_result > 0) stones.push_back(smash_result);
        }
        
        return (stones.empty())? 0:stones.front();        
    }
    */
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1){
            int heavy1 = pq.top();
            pq.pop();
            int heavy2 = pq.top();
            pq.pop();
            
            if(heavy1 != heavy2) pq.push(heavy1 - heavy2);
        }
        
        return (pq.empty())? 0:pq.top();
    }
};