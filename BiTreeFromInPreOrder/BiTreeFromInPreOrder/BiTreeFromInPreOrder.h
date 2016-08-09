#pragma once
#include<vector>
#include"TreeNode.h"

class BiTreeFromInPreOrder {
private:
	int Search(std::vector<int>& inorder, int i, int j, int target) {
		while (i <j && inorder[j] != target) j--;
		return j;
	}
	TreeNode* Convert(std::vector<int>& inorder, std::vector<int>& preorder, std::vector<int>& index) {
		int i(index[0]), j(index[1]), k(index[2]), l(index[3]), temp;
		TreeNode* root = new TreeNode(preorder[k]);
		temp = Search(inorder, i, j, preorder[k]);
		if (temp >i) {
			index[1] = temp - 1, index[2] = k + 1;
			index[3] = index[2] + index[1] - index[0];
			root->left = Convert(inorder, preorder, index);
		}
		if (temp <j) {
			index[0] = temp + 1, index[1] = j;
			index[2] = k + 1 + temp - i;
			index[3] = l;
			root->right = Convert(inorder, preorder, index);
		}
		return root;
	}
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;
		std::vector<int> indices(4);
		indices[0] = indices[2] = 0;
		indices[1] = indices[3] = inorder.size() - 1;
		return Convert(inorder, preorder, indices);
	}
};