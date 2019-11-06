class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty()) return false;
        
        unordered_set<string> dict;
        for(auto& word : wordDict) dict.insert(word);
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<=i; j++){
                string candidate = s.substr(j, (i-j)+1);
                if(dict.find(candidate) != dict.end() && dp[j]){
                    cout << candidate << endl;
                    dp[i+1] = true;
                }
            }
        }
        
        return dp[s.size()];
        
    }
};