#include <vector>
#include <iostream>
using namespace std;

class LinkedList {
  public:
    int value;
    LinkedList* next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
  // Write your code here.
	vector<int> totalNodes = head->getNodesInArray();
	int max = totalNodes.size();
	int position_prev = max - k -2;
	
	if(position_prev == -2){ // when target is head
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	
	while(position_prev >= 0){
		head = head->next;
		position_prev--;
	}
	
	LinkedList* target = head->next;
	head->next = target->next;
	target->next = NULL;
}
