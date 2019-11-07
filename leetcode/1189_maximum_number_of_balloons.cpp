class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.empty()) return 0;
        
        std::map<char, int> hashmap;
        
        for(int i=0; i<text.size(); i++)
        {
            char letter = text[i];
            if(letter == 'b' || letter == 'a' || letter == 'l' || letter == 'o' || letter == 'n'){
                hashmap[letter]++;
            }
        }
        
        // divide 'l' and 'o' by 2 to make it as a one occuruence
        hashmap['l'] /= 2;
        hashmap['o'] /= 2;
        
        int balloon_counter = hashmap['b'];
        
        for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
            if(it->second < balloon_counter){
                balloon_counter = it->second;
            }
        }
        return balloon_counter;
    }
};