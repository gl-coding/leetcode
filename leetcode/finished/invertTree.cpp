#include "convert.h"

TreeNode* invertTree(TreeNode* root) {
	if (!root){
		return NULL;
	}
	TreeNode * tmp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(root->left);
	return root;
}

TreeNode* invertTree(TreeNode* root) {
	queue<TreeNode *> treeque;
	if (!root){
		return NULL;
	}
	treeque.push(root);
	while (!treeque.empty()){
		TreeNode * node = treeque.front();
		treeque.pop();
		TreeNode * tmp = node->left;
		node->left = node->right;
		node->right = tmp;
		if (node->left){
			treeque.push(node->left);
		}
		if (node->right){
			treeque.push(node->right);
		}
	}
	return root;
}

int main()
{
    cout<<"asdfas"<<endl;
    return 1;
}
