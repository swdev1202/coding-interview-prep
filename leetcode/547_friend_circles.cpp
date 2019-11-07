class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size());
        int unique_circle = 0;
        queue<int> q;
        
        for(int i=0; i<M.size(); i++){
            if(visited[i] == false){
                q.emplace(i);
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    visited[curr] = true;
                    for(int j=0; j<M.size(); j++){
                        if(M[curr][j] == 1 && visited[j] == false){
                            q.emplace(j);
                        }
                    }
                }
                unique_circle++;
            }
        }
        
        return unique_circle;
    }
};