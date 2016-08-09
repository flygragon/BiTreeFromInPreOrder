// BiTreeFromInPreOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"BiTreeFromInPreOrder.h"
#include"BiTreeLevelOutput.h"
using namespace std;

int main()
{
	int NodeNum;
	cin >> NodeNum;
	vector<int> inorder(NodeNum), preorder(NodeNum);
	for (int i = 0; i < NodeNum; i++)
		cin >> inorder[i];
	for (int i = 0; i < NodeNum; i++)
		cin >> preorder[i];
	BiTreeFromInPreOrder BTFIPO;
	TreeNode* TN = BTFIPO.buildTree(preorder, inorder);
	BiTreeLevelOutput BTLOP;
	BTLOP.LevelOutput(TN);
	exit(0);
    return 0;
}

