bool symmetrical(struct TreeNode *left, struct TreeNode *right) {
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	if (left->val != right->val)
		return false;

	return symmetrical(left->left, right->right) && symmetrical(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root) {
	if (root == NULL) {
		return true;
	}

	return symmetrical(root->left, root->right);
}
