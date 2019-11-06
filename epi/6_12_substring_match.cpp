#include <string>
#include "test_framework/generic_test.h"
using std::string;

// Returns the index of the first character of the substring if found, -1
// otherwise.
/* two nested loop --> O(N^2)
int RabinKarp(const string &t, const string &s) {
    if(s.empty()) return 0;
    int startIdx = -1;
    bool found = false;

    for(int i=0; i<t.size(); i++) {
        if (t[i] == s[0]) {
            // possible
            startIdx = i;
            found = true;
            int idx_ptr = i;

            for (int j = 1; j < s.size(); j++) {
                idx_ptr++;
                if (t[idx_ptr] != s[j]) {
                    found = false;
                    startIdx = -1;
                    break;
                }
            }
        }
        if(found) break;
    }
  return startIdx;
}*/

/* Linear Search using Rabin-Karp algorithm */
int RabinKarp(const string &t, const string &s) {
    if(s.size() > t.size()) return -1; // search string must be smaller than the text

    int text_size = t.size();
    int pattern_size = s.size();
    int hash_t = 0; // hash value for text
    int hash_p = 0; // hash value for pattern
    int h = 1;
    int num_chars = 256;
    int prime = 11;

    // the value of hash = pow(num_chars, pattern_size) % prime
    for(int i=1; i<pattern_size; i++){
        h = (num_chars * h) % prime;
    }

    // first window
    for(int i=0; i<pattern_size; i++){
        hash_t = (num_chars * hash_t + t[i]) % prime;
        hash_p = (num_chars * hash_p + s[i]) % prime;
    }

    // slide the pattern
    for(int i=0; i <= text_size-pattern_size; i++){
        if(hash_t == hash_p){
            // if their window hash values are the same, last check if they are actually the same
            // to avoid hash collision
            bool found = true;
            for(int j=0; j<pattern_size; j++){
                if(t[i+j] != s[j]){
                    found = false;
                    break;
                }
            }
            if(found) return i;
        }

        if(i < text_size-pattern_size){
            hash_t = (num_chars*(hash_t - t[i]*h) + t[i+pattern_size]) % prime;

            if(hash_t < 0) hash_t += prime;
        }
    }
    return -1;

}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"t", "s"};
  return GenericTestMain(args, "substring_match.cc", "substring_match.tsv",
                         &RabinKarp, DefaultComparator{}, param_names);
}
