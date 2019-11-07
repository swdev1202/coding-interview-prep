#include <vector>
using namespace std;

int find_river(vector<vector<int>>& mtrx, int i, int j){
	int size = 1;
	mtrx[i][j] = 0; // check it as visited
	
	// left check
	if(j-1 >= 0){
		if(mtrx[i][j-1] == 1){
			size += find_river(mtrx, i, j-1);
		}
	}
	
	// right check
	if(j+1 < mtrx[i].size()){
		if(mtrx[i][j+1] == 1){
			size += find_river(mtrx, i, j+1);
		}
	}
	
	// top check
	if(i-1 >= 0){
		if(mtrx[i-1][j] == 1){
			size += find_river(mtrx, i-1, j);
		}
	}
	
	// bottom check
	if(i+1 < mtrx.size()){
		if(mtrx[i+1][j] == 1){
			size += find_river(mtrx, i+1, j);
		}
	}

	return size;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
	vector<int> result;
	
	for(int row=0; row<matrix.size(); row++){
		for(int col=0; col<matrix[row].size(); col++){
			if(matrix[row][col] == 1){
				// look for neighbors
				int size = find_river(matrix, row, col);
				result.push_back(size);
			}
		}
	}
	
	return result;
}
