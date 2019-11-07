#include <vector>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
  public:
    string name;
    vector<Node*> children;

    Node(string str) {
      name = str;
    }

    vector<string> depthFirstSearch(vector<string>* array) {
			// I am at node
			(*array).push_back(this->name);
			// the question is... how to pass a child node?
			for(int i=0; i<this->children.size(); i++){
				Node* child = this->children[i];
				child->depthFirstSearch(array);
			}
			
			return *array;
    }

    Node* addChild(string name) {
      Node* child = new Node(name);
      children.push_back(child);
      return this;
    }
};
