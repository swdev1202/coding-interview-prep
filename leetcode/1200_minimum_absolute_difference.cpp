class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        if(arr.empty() || arr.size() == 1){
            return result;
        }
        
        // I have to sort
        priority_queue<int, vector<int>, greater<int>> min_heap;
        queue<vector<int>> stack_storage;
        
        for(int a : arr){
            min_heap.emplace(a);
        }
        
        // take two out
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();
        
        int first_min = abs(a-b);
        int min_checker = first_min;
        int first = b;
        
        stack_storage.push({a,b});
        
        while(!min_heap.empty()){
            int second = min_heap.top();
            min_heap.pop();
            
            // compare
            int res = abs(first-second);
            if(res < min_checker){
                min_checker = res; // new min
                while(!stack_storage.empty()){
                    stack_storage.pop();
                }
                stack_storage.push({first,second});
            }
            else if(res == min_checker){
                stack_storage.push({first,second});
            }
            
            first = second;
        }
        
        while(!stack_storage.empty()){
            result.push_back(stack_storage.front());
            stack_storage.pop();
        }
        
        return result;
    }
};