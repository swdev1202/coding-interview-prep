class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

/**** Recursive
int findClosestValueInBst(BST* tree, int target);
int findClosest(BST* tree, int target, long closest);

int findClosestValueInBst(BST* tree, int target) {
  // Write your code here.
	return findClosest(tree, target, INT_MAX);
}

int findClosest(BST* tree, int target, long closest){
	if(abs(tree->value - target) < abs(closest - target)){
		closest = tree->value;
		if(closest == target) return (int)closest;
	}
	
	if(target < tree->value && tree->left != NULL){
		return findClosest(tree->left, target, closest);
	}
	else if(target > tree->value && tree->right != NULL){
		return findClosest(tree->right, target, closest);
	}
	else{
		return (int)closest;
	}
}
*/

/* iterative */
int findClosestValueInBst(BST* tree, int target){
	long closest = INT_MAX;
	
	// when do we know we have found the closest value?
	while(true){
		// distance calculation
		int distance = abs(tree->value - target);
		if(distance == 0) return tree->value;
		else if(distance < abs(closest - target)){
			closest = tree->value;
		}
		
		// look for possible tree
		if(target > tree->value && tree->right != NULL){
			// look for right
			tree = tree->right;
		}
		else if(target < tree->value && tree->left != NULL){
			// look for left
			tree = tree->left;
		}
		else{
			break;
		}
	}
	
	return (int)closest;
}