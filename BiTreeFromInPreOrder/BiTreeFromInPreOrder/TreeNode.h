#pragma once
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x =0) : val(x), left(nullptr), right(nullptr) {}
};