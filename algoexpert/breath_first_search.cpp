#include <vector>
#include <queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
  public:
    string name;
    vector<Node*> children;

    Node(string str) {
      name = str;
    }

    vector<string> breadthFirstSearch(vector<string>* array) {
			queue<Node*> q; // construct a queue for Node*
			q.push(this); // start off with pushing the very first Node given
				
			while(!q.empty()){ // until queue is empty
				Node* front = q.front(); // take out the front Node* in the queue
				for(auto& child : front->children){ 
					q.push(child); // add all of its children to the queue
				}
				array->push_back(front->name); // then, record this current Node's name into the array
				q.pop(); // remove the current node from the queue
			}
			
			return *array;
    }

    Node* addChild(string name) {
      Node* child = new Node(name);
      children.push_back(child);
      return this;
    }
};
