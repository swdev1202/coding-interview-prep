#include <map>

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,bool> jewelHash;
        int numCount = 0;
        
        for(int i=0; i<J.size(); i++)
        {
            jewelHash.insert(std::pair<char,bool>(J[i],true));
        }
        
        for(int i=0; i<S.size(); i++)
        {
            if(jewelHash[S[i]]) numCount++;
        }
        
        return numCount;
    }
};