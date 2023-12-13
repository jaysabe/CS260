#include "table.h"

//Please put the impelementation of the required functions here
int countNodes (node * root){
	if (root == nullptr){
		return 0;
	}
	else {
		//Recursively count nodes of the required functions here:
		int leftCount = countNodes(root->left);
		int rightCount = countNodes(root->right);
	
		//add 1 for curr nodes
		return leftCount + rightCount + 1;
	}
}

int sumLeaves(node * root){
	if (root == nullptr){
		return 0;
	}
	else if (root->left == nullptr && root->right == nullptr){
		// Leaf node, return its data
		return root->data;
	}
	else {
		//Recursively sum leaves in the left and right subtrees
		int leftSum = sumLeaves(root->left);
		int rightSum = sumLeaves(root->right);

		//Return the sum of leaves in the tree
		return leftSum + rightSum;
	}
}

