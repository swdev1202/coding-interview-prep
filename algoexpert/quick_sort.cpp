#include <vector>
using namespace std;

int partition(vector<int>& array, int low, int high){
    // end-pivot
    int pivot = array[high];

    int sm = low - 1;

    for(int i=low; i <= high-1; i++){
        if(array[i] < pivot){
            sm++;
            int temp = array[i];
            array[i] = array[sm];
            array[sm] = temp;
        }
    }
    int temp = array[sm+1];
    array[sm+1] = array[high];
    array[high] = temp;

    return sm+1;
}

void quickSortHelper(vector<int>& array, int low, int high){
    if(low < high){
        int pi = partition(array, low, high);

        quickSortHelper(array, low, pi-1);
        quickSortHelper(array, pi+1, high);

    }
}

vector<int> quickSort(vector<int> array) {
    if(array.empty()) return {};

    quickSortHelper(array, 0, array.size()-1);
    return array;
}
