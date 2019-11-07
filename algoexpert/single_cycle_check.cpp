#include<queue>
#include<iostream>
using namespace std;

bool hasSingleCycle(vector<int> array) {
	if(array.empty()) return false; // return false if array is empty
	
	queue<int> q;
	vector<int> visited(array.size());
	
	// first, queue the first index (starting index)
	q.emplace(0);
	while(!q.empty()){
		int curr = q.front(); // get the front element from the queue
		q.pop(); // remove it from the queue
		if(visited[curr] == 0){
			visited[curr] = 1; // mark the current index as visited
		}
		else{
			if(curr != 0) return false;
			
			for(int i=0; i<visited.size(); i++){
				if(visited[i] == 0) return false;
			}
			return true;
		}
		int next_index = curr + array[curr];
		if(next_index < 0){
			int k = (-1 * next_index) % array.size();
			if(k == 0) k = array.size();
			next_index = array.size() - k;
		}
		else{
			next_index = next_index % array.size();
		}
		q.emplace(next_index);
	}
}