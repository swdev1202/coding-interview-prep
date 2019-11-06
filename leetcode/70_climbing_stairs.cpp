class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;    
        }
        
        int prev_prev = 1;
        int prev = 2;
        int curr;
        
        for(int i=2; i<n; i++){
            curr = prev + prev_prev;
            prev_prev = prev;
            prev = curr;
        }
        
        return prev;
    }
};