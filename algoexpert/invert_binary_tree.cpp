#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
    if(tree->left == NULL && tree->right == NULL) return;

    if(tree->left != NULL) invertBinaryTree(tree->left);
    if(tree->right != NULL) invertBinaryTree(tree->right);
	
    BinaryTree *temp = tree->right;
    tree->right = tree->left;
    tree->left = temp;
}
