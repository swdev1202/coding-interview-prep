class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // consider nums1 is always larger than nums
        if(nums2.size() > nums1.size()){
            return intersect(nums2, nums1);
        }
        
        vector<int> result;
        std::unordered_map<int,int> hashmap;
        
        for(int i=0; i<nums2.size(); i++)
        {
            if(!hashmap[nums2[i]])
            {
                hashmap[nums2[i]] = 1;
            }
            else
            {
                hashmap[nums2[i]] +=1;
            }
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            if(hashmap[nums1[i]] > 0)
            {
                result.push_back(nums1[i]);
                hashmap[nums1[i]] -= 1;
            }
        }
        
        return result;
    }
};