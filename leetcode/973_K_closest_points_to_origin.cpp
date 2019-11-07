class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        priority_queue<int, vector<int>, greater<int>> pq; // create a minHeap
        multimap<int, vector<int>> hash;
        
        for(vector<vector<int>>::iterator it = points.begin(); it != points.end(); it++)
        {
            // each vector<int>, find x^2 + y^2
            int x = (*it).at(0);
            int y = (*it).at(1);
            
            int distance = (x*x) + (y*y);
            
            // put it into hash map with the designated points
            hash.insert(std::pair<int, vector<int>>(distance, *it));
            pq.push(distance);
        }
        
        for(int i=0; i<K; i++)
        {
            // get the K number of minimum distances
            int get_distance = pq.top();
            pq.pop();
            
            auto itr = hash.find(get_distance);
            result.push_back(itr->second);
            hash.erase(itr);
        }
        
        return result;
    }
};