class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        
        unordered_set<char> str_container;
        string longest_str = "";
        string current_str = "";
        
        for(auto& c:s){
            if(str_container.find(c) != str_container.end()){
                // found the duplicate
                current_str += c;
                int start_idx = 0;
                for(int i=0; i<current_str.size(); i++){
                    start_idx++; //1
                    if(current_str[i] != c){
                        str_container.erase(current_str[i]);
                    }
                    else{
                        break;
                    }
                }
                current_str = current_str.substr(start_idx, current_str.size()-start_idx);
            }
            else{
                str_container.insert(c);
                current_str += c;
            }
            
            if(current_str.size() > longest_str.size()){
                longest_str = current_str;
            }
        }
        
        return longest_str.size();
    }
};