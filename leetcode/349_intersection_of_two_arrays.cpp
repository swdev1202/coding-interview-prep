class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        if(nums2.size() > nums1.size()){
            result = intersection(nums2, nums1);
            return result;
        }
        
        // assume we always have nums1 larger
        
        // create a unordered set
        unordered_map<int, int> container;
        
        for(auto& val : nums2){
            if(!container.count(val)){
                container.emplace(val, 1);
            }
        }
        
        for(auto& val : nums1){
            if(container.count(val)){
                if(container.at(val) > 0){
                    result.push_back(val);
                    container.at(val)--;
                }
            }
        }
        
        
        return result;
    }
};