class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        
        int max = INT_MIN;
        while(start != end){
            int width = end-start;
            
            int start_h = height[start];
            int end_h = height[end];
            int height = min(start_h, end_h);
            if(width*height > max) max = width*height;
            
            if(start_h >= end_h){
                // move the right one if they are the same
                end--;
            }
            else{
                start++;
            }
        }
        
        return max;
    }
};