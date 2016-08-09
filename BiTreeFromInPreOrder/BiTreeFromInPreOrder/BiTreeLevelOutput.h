#pragma once
#include<iostream>
#include"TreeNode.h"
#include<queue>
using namespace std;

class BiTreeLevelOutput {
public:
	void LevelOutput(TreeNode*root) {
		if (root) {
			int len = 0;
			queue<TreeNode*> temp;
			temp.push(root), len++;
			while (!temp.empty()) {
				len = temp.size();
				while (len) {
					if (temp.front()) {
						temp.push(temp.front()->left);
						temp.push(temp.front()->right);
						cout << temp.front()->val << " ";
					}
					else cout << "Null" << " ";
					temp.pop();
					len--;
				}

			}
				cout << endl;
		}
	}
};