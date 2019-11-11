class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* O(n^2)
        int max = 0;
        for(int i=0; i<prices.size(); i++){
            for(int j=i+1; j<prices.size(); j++){
                int profit = prices[j] - prices[i];
                if(profit > max) max=profit;
            }
        }
        
        
        return max;
        */
        
        /* O(N) */
        int min_price = INT_MAX;
        int max_profit = 0;
        for(auto& p : prices){
            if(p < min_price) min_price = p;
            else if(p - min_price > max_profit) max_profit = p - min_price;
        }
        return max_profit;
        
    }
};