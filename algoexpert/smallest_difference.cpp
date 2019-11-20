/*
Write a function that takes in two non-empty arrays of integers. The function should find the pair of numbers 
(one from the first array, one from the second array) whose absolute difference is closest to zero.
The function should return an array containing these two numbers, with the number from the first array in the first position.
Assume that there will only be one pair of numbers with the smallest difference.

Sample input: [-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17]
Sample output: [28, 26]
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    /* naive solution 
    * Time Complexity O(N*M), where N is the size of the first array and M is the size of the second array
    * Space Complexity O(1)
    */
    vector<int> result;

    int first = 0;
    int second = 0;
    int abs_diff = INT_MAX;

    for(int i=0; i<arrayOne.size(); i++){
        for(int j=0; j<arrayTwo.size(); j++){
            int local_abs_diff = abs(arrayOne[i] - arrayTwo[j]);
            if(local_abs_diff < abs_diff){
                abs_diff = local_abs_diff;
                first = arrayOne[i];
                second = arrayTwo[j];
            }
        }
    }

    result.push_back(first);
    result.push_back(second);
    return result;
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    /* optimized solution
    * Time Complexity O(N*log(N) + M*log(M)), where N is the size of the first array and M is the size of the second array
    * Space Complexity O(1)
    */
    vector<int> result;

    int first_idx = 0;
    int second_idx = 0;

    int first = 0;
    int second = 0;
    int abs_diff = INT_MAX;

    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    while(first_idx < arrayOne.size() || second_idx < arrayTwo.size()){
        int local_abs_diff = abs(arrayOne[first_idx] - arrayTwo[second_idx]);
        
        if(local_abs_diff < abs_diff){
            abs_diff = local_abs_diff;
            first = arrayOne[first_idx];
            second = arrayTwo[second_idx];
        }

        if(arrayOne[first_idx] == arrayTwo[second_idx]) break;
        else if(arrayOne[first_idx] < arrayTwo[second_idx]) first_idx++;
        else second_idx++;
    }

    result.push_back(first);
    result.push_back(second);
    return result;
}