class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        std::map<string,int> count_map;
        
        for(int i=0; i<words.size(); i++){
            string get_word = words[i];
            
            string morse_converted = "";
            
            for(int j=0; j<get_word.size(); j++){
                morse_converted += morse[(int)get_word[j] - 97];
            }
            
            if(!count_map[morse_converted]){
                count_map[morse_converted] = 1;
            }
        }
        
        return count_map.size();
    }
};