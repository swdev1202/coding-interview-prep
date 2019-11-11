
#include <vector>

using namespace std;

bool boundCheck(int row, int col, int row_max, int col_max);

vector<int> zigzagTraverse(vector<vector<int>> array) {
    if(array.empty()) return {};
    if(array.size() == 1) return array[0];

    vector<int> traversalPath;

    int row=0;
    int col=0;
    bool down = true;

    int row_max = array.size()-1;
    int col_max = array[0].size()-1;

    while(boundCheck(row,col,row_max,col_max)){
        traversalPath.push_back(array[row][col]);
        if(down){
            if(col == 0 || row == row_max){
                down = false;
                if(row == row_max) col++;
                else row++;
            }
            else{
                row++, col--;
            }
        }
        else{
            if(row == 0 || col == col_max){
                down = true;
                if(col == col_max) row++;
                else col++;
            }
            else{
                row--; col++;
            }
        }
    }

    return traversalPath;
}

bool boundCheck(int row, int col, int row_max, int col_max){
    return row >= 0 && row <= row_max && col >= 0 && col <= col_max;
}