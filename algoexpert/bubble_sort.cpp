#include <vector>
using namespace std;

void swap(vector<int>& a, const int i, const int j){
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

vector<int> bubbleSort(vector<int> array) {
    for(int i=0; i<array.size(); i++){
        bool swapped = false;
        for(int j=0; j<array.size()-i-1; j++){
            if(array[j] > array[j+1]){
                swap(array, j, j+1);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return array;
}
